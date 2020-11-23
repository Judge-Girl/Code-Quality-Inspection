#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <ctype.h>
#define assignNode(node,L,M,R)  ((node)->left = L, (node)->mid = M, (node)->right = R)

typedef struct _node {
  int len;
  struct _node* left;
  struct _node* mid;
  struct _node* right;
  char ch;
} node;

int getK(char inp[]) {
  scanf("%s", inp);
  if (isdigit(inp[0]))
    return atoi(inp) - 1;
  if (inp[0] == 'l') return 0;
  return -1;
}

static inline int getLength(node* root) {
  if (root == NULL) return 0;
  return root->len;
}

node* getTreeNode(int len) {
  static const int chunkSize = 32768;
  static node* nodeBuf;
  static int nodeCnt;

  if (nodeCnt == chunkSize)
    nodeCnt = 0;
  if (nodeCnt == 0)
    nodeBuf = (node*) malloc(chunkSize * sizeof(node));

  node* ret = &nodeBuf[nodeCnt++];
  ret->len = len;
  return ret;
}

node* insertTree(node* root, node* q, int pos) {
  if (root == NULL) return q;
  if (root->left != NULL) {
    // internal node
    int x = getLength(root->left);
    root->len += q->len;
    if (pos < x) {
      // insert to left branch
      root->left = insertTree(root->left, q, pos);
    } else {
      int y = getLength(root->mid);
      if (y == 0 && pos == x) {
        // middle is empty (special case)
        // place in the middle of the two
        root->mid = q;
      } else if (pos < x + y) {
        // insert to middle branch
        root->mid = insertTree(root->mid, q, pos - x);
      } else {
        // insert to right branch
        root->right = insertTree(root->right, q, pos - x - y);
      }
    }
    return root;
  } else {
    // leaf
    // the node's length is the sum of the two
    node* newNode = getTreeNode(root->len + q->len);
    if (pos > 0 && pos < root->len) {
      // split to [0, pos), q, [pos, num)
      // a node w/ 3 leaves
      node* split = (node*) getTreeNode(root->len - pos);
      split->ch = root->ch;
      assignNode(newNode, root, q, split);
      // truncate
      root->len = pos;
    } else {
      // a node with 2 leaves
      if (pos == 0) {
        // insert at left-most
        assignNode(newNode, q, NULL, root);
      } else {
        // insert at right-most
        assignNode(newNode, root, NULL, q);
      }
    }
    return newNode;
  }
}

void printTree(node* root, node* buf) {
  if (root == NULL) return;
  if (root->left != NULL) {
    // internal node
    printTree(root->left, buf);
    printTree(root->mid, buf);
    printTree(root->right, buf);
  } else {
    // leaf
    if (root->len == 0) return;

    if (buf->ch == root->ch) {
      buf->len += root->len;
    } else {
      if (buf->len > 0)
        printf("%c %d ", buf->ch, buf->len);
      *buf = *root;
    }
  }
}

int main() {
  char oper[32], x;
  node* root = NULL;

  while (scanf("%s", oper) != EOF) {
    if (oper[0] == 'i') {
      // insert (left | right | <k>) x n
      int k = getK(oper);
      if (k < 0) k = getLength(root);
      getchar();  // ' '
      x = getchar();
      int n;
      scanf("%d", &n);
      // printf("insert k=%d x=%c n=%d\n", k, x, n);
      node* newLeaf = getTreeNode(n);
      newLeaf->ch = x;
      root = insertTree(root, newLeaf, k);
    } else {
      // print
      node buf = {};
      printTree(root, &buf);
      if (buf.len > 0)
        printf("%c %d ", buf.ch, buf.len);
      printf("$\n");
    }
  }
}


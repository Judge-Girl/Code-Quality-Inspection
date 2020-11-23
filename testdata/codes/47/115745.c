#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define assignNode(node,L,M,R) ( \
  (node)->left  = (nodeBase*) L, \
  (node)->mid   = (nodeBase*) M, \
  (node)->right = (nodeBase*) R \
)

typedef struct {
  char type;
} nodeBase;

typedef struct {
  nodeBase type;  // 0
  int len;
  nodeBase* left;
  nodeBase* mid;
  nodeBase* right;
} node;

typedef struct {
  nodeBase type;  // 1
  char ch;
  int num;
} leaf;

int getK(char inp[]) {
  scanf("%s", inp);
  if (isdigit(inp[0]))
    return atoi(inp) - 1;
  if (inp[0] == 'l') return 0;
  return -1;
}

static inline int getLength(nodeBase* _root) {
  if (_root == NULL) return 0;
  if (_root->type == 0) {
    return ((node*) _root)->len;
  } else {
    return ((leaf*) _root)->num;
  }
}

node* getInternalNode(int len) {
  static const int chunkSize = 65536;
  static node* buf;
  static int cnt;

  if (cnt == 0)
    buf = (node*) malloc(chunkSize * sizeof(node));

  node* ret = &buf[cnt++];
  ret->len = len;

  if (cnt == chunkSize)
    cnt = 0;
  return ret;
}

leaf* getLeafNode(char ch, int num) {
  static const int chunkSize = 131072;
  static leaf* buf;
  static int cnt;

  if (cnt == 0) {
    buf = (leaf*) malloc(chunkSize * sizeof(leaf));
  }

  leaf* ret = &buf[cnt++];
  ((nodeBase*) ret)->type = 1;
  ret->ch = ch;
  ret->num = num;

  if (cnt == chunkSize)
    cnt = 0;
  return ret;
}

node* insertTree(nodeBase* _root, leaf* q, int pos) {
  if (_root->type == 0) {
    // internal node
    node* root = (node*) _root;
    int x = getLength(root->left);
    root->len += q->num;
    if (pos < x) {
      // insert to left branch
      root->left = (nodeBase*) insertTree(root->left, q, pos);
    } else {
      int y = getLength(root->mid);
      if (y == 0 && pos == x) {
        // middle is empty (special case)
        // place in the middle of the two
        root->mid = (nodeBase*) q;
      } else if (pos < x + y) {
        // insert to middle branch
        root->mid = (nodeBase*) insertTree(root->mid, q, pos - x);
      } else {
        // insert to right branch
        root->right = (nodeBase*) insertTree(root->right, q, pos - x - y);
      }
    }
    return root;
  } else {
    // leaf
    leaf* root = (leaf*) _root;
    // the node's length is the sum of the two
    node* newNode = getInternalNode(root->num + q->num);
    if (pos > 0 && pos < root->num) {
      // split to [0, pos), q, [pos, num)
      // a node w/ 3 leaves
      leaf* split = getLeafNode(root->ch, root->num - pos);
      assignNode(newNode, root, q, split);
      root->num = pos;
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

void printTree(nodeBase* _root, leaf* buf) {
  if (_root == NULL) return;
  if (_root->type == 0) {
    node* root = (node*) _root;
    // internal node
    printTree(root->left, buf);
    printTree(root->mid, buf);
    printTree(root->right, buf);
  } else {
    // leaf
    leaf* root = (leaf*) _root;
    if (root->num == 0) return;

    if (buf->ch == root->ch) {
      buf->num += root->num;
    } else {
      if (buf->num > 0)
        printf("%c %d ", buf->ch, buf->num);
      *buf = *root;
    }
  }
}

int main() {
  char oper[32], x;
  nodeBase* root = NULL;

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
      leaf* newLeaf = getLeafNode(x, n);
      if (root == NULL) {
        // the first insert
        root = (nodeBase*) newLeaf;
      } else {
        root = (nodeBase*) insertTree(root, newLeaf, k);
      }
    } else {
      // print
      leaf buf = {};
      printTree((nodeBase*) root, &buf);
      if (buf.num > 0)
        printf("%c %d ", buf.ch, buf.num);
      printf("$\n");
    }
  }
}


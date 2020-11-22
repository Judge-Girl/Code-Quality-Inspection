#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

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

nodeBase* getTreeNode(char type) {
  nodeBase* ret;
  if (type == 0) {
    // internal node
    ret = (nodeBase*) calloc(1, sizeof(node));
  } else {
    // leaf
    ret = (nodeBase*) malloc(sizeof(leaf));
    ret->type = 1;
  }
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
    node* newNode = (node*) getTreeNode(0);
    // the node's length is the sum of the two
    newNode->len = root->num + q->num;
    if (pos > 0 && pos < root->num) {
      // split to [0, pos), q, [pos, num)
      // a node w/ 3 leaves
      int rem = root->num - pos;
      root->num = pos;
      leaf* split = (leaf*) getTreeNode(1);
      split->ch = root->ch;
      split->num = rem;
      newNode->left = (nodeBase*) root;
      newNode->mid = (nodeBase*) q;
      newNode->right = (nodeBase*) split;
    } else {
      // a node with 2 leaves
      newNode->mid = NULL;
      if (pos == 0) {
        // insert at left-most
        newNode->left = (nodeBase*) q;
        newNode->right = (nodeBase*) root;
      } else {
        // insert at right-most
        newNode->left = (nodeBase*) root;
        newNode->right = (nodeBase*) q;
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
  node* root = (node*) getTreeNode(1);
  ((nodeBase*) root)->type = 2;  // dummy

  while (scanf("%s", oper) != EOF) {
    if (oper[0] == 'i') {
      // insert (left | right | <k>) x n
      int k = getK(oper);
      if (k < 0) k = root->len;
      getchar();  // ' '
      x = getchar();
      int n;
      scanf("%d", &n);
      // printf("insert k=%d x=%c n=%d\n", k, x, n);
      leaf* newLeaf = (leaf*) getTreeNode(1);
      newLeaf->ch = x;
      newLeaf->num = n;
      if (((nodeBase*) root)->type == 2) {
        // the first insert
        root = (node*) newLeaf;
      } else {
        root = insertTree((nodeBase*) root, newLeaf, k);
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


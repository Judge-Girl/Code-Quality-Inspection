#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Treenode{
  char alphabet;
  int num;
  int left_num, right_num;
  int height;
  struct Treenode *left;
  struct Treenode *right;
}Treenode;

int left_count = 0, right_count = 0, left = 0, right = 0, count = 0, have = 0;

void traverse(Treenode *root)
{
  if(root != NULL)
    {
      if(root->left != NULL)
	left_count++;
      if(root->right != NULL)
	right_count++;
      traverse(root->left);
      printf("%c %d ", root->alphabet, root->num);
      //printf("%c %d %d ", root->alphabet, root->num, root->start_index);
      traverse(root->right);
    }
  else return;
}

int height(Treenode *root)
{
  if(root == NULL)
    return 0;
  else
    return root->height;
}

int bfactor(Treenode *p)
{
  return height(p -> right) - height(p -> left);
}

void fixheight(Treenode *p)
{
  int hl = height(p -> left);
  int hr = height(p -> right);
  p -> height = (hl > hr? hl : hr) + 1;
  return;
}

Treenode* rotateleft(Treenode *q)
{
  Treenode *p = q -> right;
  q -> right = p -> left;
  p -> left = q;

  if(q->right != NULL)
    q->right_num = q->right->right_num + q->right->left_num + q->right->num;
  else
    q->right_num = 0;
  if(p->left != NULL)
    p->left_num = p->left->right_num + p->left->left_num + p->left->num;
  else
    p->left_num = 0;
  fixheight(q);
  fixheight(p);
  return p;
}
Treenode* rotateright(Treenode *p)
{
  Treenode *q = p -> left;
  p -> left = q -> right;
  q -> right = p;

  if(p->left != NULL)
    p->left_num = p->left->right_num + p->left->left_num + p->left->num;
  else
    p->left_num = 0;
  if(q->right != NULL)
    q->right_num = q->right->right_num + q->right->left_num + q->right->num;
  else
    q->right_num = 0;
  fixheight(p);
  fixheight(q);
  return q;
}

Treenode* balance(Treenode *p)
{
  
  fixheight(p);
  if(bfactor(p) == 2)
    {
      if(bfactor(p -> right) < 0)
	{
	  p -> right = rotateright(p -> right);
	}    
      return rotateleft(p);
    }
  if(bfactor(p) == -2)
    {
      if(bfactor(p -> left) > 0)
	{
	  p -> left = rotateleft(p -> left);
	}
      return rotateright(p);
    }
  if(p->left != NULL)
    p->left_num = p->left->right_num + p->left->left_num + p->left->num;
  else
    p->left_num = 0;
  if(p->right != NULL)
    p->right_num = p->right->right_num + p->right->left_num + p->right->num;
  else
    p->right_num = 0;
  return p;
}

Treenode* insert(Treenode *root, int position, char x, int n, int temp)
{
  Treenode *node_move = NULL, *node = NULL, *t = NULL;
  int position_move = 0, n_move = 0;
  char x_move;
  have = 1;
  if(root == NULL)
    {
      root = (Treenode *)malloc(sizeof(Treenode));
      root->alphabet = x;
      root->num = n;
      root->left_num = 0;
      root->right_num = 0;
      root->height = 1;
      root->left = NULL;
      root->right = NULL;
      return root;
      //printf("hello\n");
      //printf("123%c %d %d\n", root->alphabet, root->num, root->start_index);
    }
  else if(position <= root->left_num + root->num && position > root->left_num + 1)
    {
      //printf("hello\n");
      //printf("%c %d %d\n", root->alphabet, root->num, root->start_index);
      if(x == root->alphabet)
	{
	  root->num += n;
	  return root;
	}
	  position_move = position + n;
	  n_move = root->left_num + 1 + root->num - position;
	  x_move = root->alphabet;
	  root->num -= n_move;
    }
  else if(position == root->left_num + root->num + 1 || position == root->left_num + 1)
    {
      if(x == root->alphabet)
	{
	  root->num += n;
	  return root;
	}
    }
  else {}
  if(position <= root->left_num + 1 && have == 1)
    {
      if(root->left == NULL)
	{
	  if(x == root->alphabet)
	    {
	      root->num += n;
	      return root;
	    }
	  //left++;
	}
      root->left_num += n;
      root->left = insert(root->left, position, x, n, 0);
    }
  else
    {
      if(root->right == NULL)
	{
	  if(x == root->alphabet)
	    {
	      root->num += n;
	      return root;
	    }
	  //right++;
	}
      root->right_num += n;
      position = position - root->left_num - root->num;
      position_move = position_move - root->left_num - root->num;
      if(position < 1)
	printf("error\n");
      root->right = insert(root->right, position, x, n, 0);
    }
  //printf("zzz\n");
  /* if(have == 1) */
  /*   return balance(root); */
  /* else */
  if(n_move != 0)
    root->right = insert(root->right, position_move, x_move, n_move, 0);
  return balance(root);
}

int main(void)
{
  char s[4][16], c, x;
  int i = 0, flag, n, ans[100] = {}, position, length = 0, need_adjust, j, k;
  Treenode *root = NULL, *temp = NULL;
  //printf("hello\n");
  while(scanf("%s", s[i]) != EOF)
    {
      //printf("hello\n");
      flag = 0;
      c = getchar();
      if(c == '\n')
	{
	  flag = 1;
	  i = 0;
	}
      if(flag == 0)
	{
	  i++;
	  continue;
	}
      else
	{
	  if(strncmp(s[0], "print", 5) == 0)
	    {
	      left_count = 0;
	      right_count = 0;
	      if(root != NULL)
		traverse(root);
	      printf("$\n");
	      //printf("hello\n");
	      continue;
	    }
	  else
	    {
	      need_adjust = 1;
	      x = s[2][0];
	      n = atoi(s[3]);
	      if(strncmp(s[1], "left", 4) == 0)
		{
		  position = 1;
		}
	      else if(strncmp(s[1], "right", 5) == 0)
		{
		  position = length + 1;
		  //need_adjust = 0;
		}
	      else
		position = atoi(s[1]);
	      length += n;
	      // printf("%d %c %d\n", position, x, n);
	      root = insert(root, position, x, n, 0);
	      /* if(root != NULL) */
	      /* 	printf("%c\n", root->alphabet); */
	      //fflush(stdout);
	      /* if(need_adjust == 1) */
	      /* 	{ */
	      /* 	  root = adjust(root, n, position, x); */
	      /* 	} */
	      /* printf("after adjust\n"); */
	      /* // printf("%c\n", root->alphabet);  */
	       /* traverse(root); */
	       /*  printf("$\n"); */
	    }
	    /* if(right >= left + left / 2) */
	    /*   { */
	    /* 	temp = root; */
	    /* 	while(count != (right - left) / 2) */
	    /* 	  { */
	    /* 	    temp = temp->right; */
	    /* 	    if(temp->left != NULL) */
	    /* 	      temp->right = temp->left; */
	    /* 	    count++; */
	    /* 	  } */
	    /* 	root = temp; */
	    /*   } */
	}
    }

  return 0;
}


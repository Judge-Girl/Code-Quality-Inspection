#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <math.h>

enum searchStatus {outer, inner};

typedef struct node{
	int x, y;
	struct node *left;
	struct node *right;
	struct node *subtree;
}Node;

int distance(int x1, int y1, int x2, int y2){
	return abs(x1 - x2) + abs(y1 - y2);
}

int min(int a, int b){
	return (a > b)? b:a;
}

Node *insert(Node *tree, int x, int y, int status){
	if(tree == NULL){
		tree = (Node *)malloc(sizeof(Node));
		tree -> x = x;
		tree -> y = y;
		tree -> left = tree -> right = tree -> subtree = NULL;
	}
	if(status == outer){
		if(tree -> x == x){
			tree -> subtree = insert(tree -> subtree, x, y, inner);
			return tree;
		}else if(x > tree -> x)
			tree -> right = insert(tree -> right, x, y, outer);
		else
			tree -> left = insert(tree -> left, x, y, outer);
	}else if(status == inner){
		if(y == tree -> y)
			return tree;
		if(y < tree -> y)
			tree -> left = insert(tree -> left, x, y, inner);
		else
			tree -> right = insert(tree -> right, x, y, inner);
	}
	return tree;
}

int minD;

int minManhattanDis(Node *tree, int x, int y, int status){
	if(status == outer){
		int dis = minManhattanDis(tree -> subtree, x, y, inner);
		if(x == tree -> x){
			if(tree -> left != NULL)
				dis = min(dis, minManhattanDis(tree -> left, x, y, outer));
			if(tree -> right != NULL)
				dis = min(dis, minManhattanDis(tree -> right, x, y, outer));
		}else if(x > tree -> x){
			if(tree -> right != NULL)
				dis = min(dis, minManhattanDis(tree -> right, x, y, outer));
			if(tree -> left != NULL && abs(x - tree -> x) < minD)
				dis = min(dis, minManhattanDis(tree -> left, x, y, outer));
		}else{
			if(tree -> left != NULL)
				dis = min(dis, minManhattanDis(tree -> left, x, y, outer));
			if(tree -> right != NULL && abs(x - tree -> x) < minD)
				dis = min(dis, minManhattanDis(tree -> right, x, y, outer));	
		}
		return dis;
	}else{
		int dis = distance(x, y, tree -> x, tree -> y);
		minD = min(dis, minD);
		if(y == tree -> y)
			return dis;
		if(y > tree -> y){
			if(tree -> right != NULL)
				return min(dis, minManhattanDis(tree -> right, x, y, inner));
			return dis;
		}else if(y < tree -> y){
			if(tree -> left != NULL)
				return min(dis, minManhattanDis(tree -> left, x, y, inner));
			return dis;
		}
	}
	/* debug */
	return -1;
}

int main(){
	int inputPair, x, y;
	scanf("%d", &inputPair);
	Node *odd = NULL, *even = NULL;
	scanf("%d%d", &x, &y);
	odd = insert(odd, x, y, outer);
	for(int step = 1; step < inputPair; step++){
		scanf("%d%d", &x, &y);
		even = insert(even, x, y, outer);
		minD = INT32_MAX;
		printf("%d\n", minManhattanDis(odd, x, y, outer));
		scanf("%d%d", &x, &y);
		odd = insert(odd, x, y, outer);
		minD = INT32_MAX;
		printf("%d\n", minManhattanDis(even, x, y, outer));
	}
	scanf("%d%d", &x, &y);
	minD = INT32_MAX;
	printf("%d\n", minManhattanDis(odd, x, y, outer));
	return 0;
}


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#define MAXNODE 10000
#define MAXCOL 128
#define MAXN 128
struct DancingLinks {
    int left, right, ch, rid;
} DL[MAXNODE];
int o[MAXCOL], used[MAXCOL] = {};
int row_head[MAXN], col_remain, who_erase[MAXN];
int head, size, Ans;
void Remove(int c, int x) {
	if (who_erase[c])
		return ;
    who_erase[c] = x, col_remain--;
    DL[DL[c].right].left = DL[c].left;
    DL[DL[c].left].right = DL[c].right;
}
void Resume(int c, int x) {
	if (who_erase[c] != x)
		return ;
    who_erase[c] = 0, col_remain++;
    DL[DL[c].right].left = c;
    DL[DL[c].left].right = c;
}
void DFS(int k) {
    if (k + col_remain <= Ans)
		return;
	if (DL[head].right == head) {
		Ans = k;
		return ;
	}
	
    int c, i, j;
    c = DL[DL[head].right].ch;
    i = row_head[c];
        
    Remove(c, c);
    for (j = DL[i].right; j != i; j = DL[j].right)
		Remove(DL[j].ch, c);
    DFS(k+1);
    for (j = DL[i].left; j != i; j = DL[j].left)        
		Resume(DL[j].ch, c);
    Resume(c, c);
    
    Remove(c, c);
    DFS(k);
    Resume(c, c);
}
int new_node(int left, int right) {
    DL[size].left = left, DL[size].right = right;
    DL[left].right = DL[right].left = size;
    return size++;
}
int new_row(int n, int Row[], int rid) {
    int i, r, row = -1, k;
    for (i = 0; i < n; i++) {
        r = Row[i];
        DL[size].ch = r, DL[size].rid = rid;
        if (row == -1) {
            row = new_node(size, size);
        } else {
            k = new_node(DL[row].left, row);
        }
    }
    return row;
}
void init(int m) {
    size = 0;
    head = new_node(0, 0);
    col_remain = m;
    int i;
    for (i = 1; i <= m; i++) {
        new_node(DL[head].left, head);
        DL[i].ch = i;
    }
}


int degree[MAXN] = {}, A[MAXN], B[MAXN], G[MAXN], Gm;
int g[MAXN][MAXN] = {};
int cmp(const void *a, const void *b) {
	return degree[*(int *) b] - degree[*(int *) a];
}

void connect(int u, int n) {
	if (B[u] == 0)	
		return ;
	B[u] = 0, G[Gm++] = u;
	for (int i = 0; i < n; i++) {
		if (g[u][i] == 0)
			connect(i, n);
	}
}
void subgraph(int base, int n, int *now_clique) {
	Gm = 0;
	connect(base, n);
	if (Gm <= *now_clique)	return ;
	
	int C[MAXN] = {};
	for (int i = 0; i < Gm; i++)
		C[i] = G[i];
	qsort(C, Gm, sizeof(int), cmp);
	
	// build graph
	init(Gm);
	for (int i = 0; i < Gm; i++) {
		int R[MAXN], Rn = 0;
		int u, v;
		u = C[i];
		for (int j = 0; j < Gm; j++) {
			v = C[j];
			if (g[u][v])
				R[Rn++] = j+1;
		}
		row_head[i+1] = new_row(Rn, R, i+1);
	}
	Ans = 0;
	DFS(0);
	if (Ans > *now_clique)
		*now_clique = Ans;
}
int main() {
    int n;
    while (scanf("%d", &n) == 1 && n) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				scanf("%d", &g[i][j]);
				g[i][j] = 1 - g[i][j];
			}
		}
		
		// relabel
		for (int i = 0; i < n; i++) {
			degree[i] = 0;
			for (int j = 0; j < n; j++)
				degree[i] += g[i][j];
		}
		for (int i = 0; i < n; i++)
			A[i] = i, B[i] = 1;
		qsort(A, n, sizeof(int), cmp);
		
		int ret = 1, predict = degree[A[0]];
		for (int i = 0; i < n; i++) {
			if (B[A[i]])
				subgraph(A[i], n, &ret);
			if (ret == predict)
				break;
		}
		
		printf("%d\n", ret);
    }
    return 0;
}



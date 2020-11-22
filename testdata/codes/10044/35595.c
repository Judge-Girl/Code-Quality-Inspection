#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#define MAXNODE 10000
#define MAXCOL 128
#define MAXN 128
struct DancingLinks {
    int left, right;
    int ch, rid;
} DL[MAXNODE];
int s[MAXCOL], o[MAXCOL], used[MAXCOL] = {};
int row_head[MAXN], col_remain, who_erase[MAXN];
int head, size, Ans;
void Remove(int c, int x) {
	if (who_erase[c])
		return ;
	int i;
    who_erase[c] = x, col_remain--;
    DL[DL[c].right].left = DL[c].left;
    DL[DL[c].left].right = DL[c].right;
}
void Resume(int c, int x) {
	if (who_erase[c] != x)
		return ;
	int i;
    who_erase[c] = 0, col_remain++;
    DL[DL[c].right].left = c;
    DL[DL[c].left].right = c;
}
void DFS(int k) {
    if (k + col_remain <= Ans)
		return;
	if (DL[head].right == head) {
		if (k > Ans)	Ans = k;
		return ;
	}
	
    int c, i, j;
    c = DL[DL[head].right].ch;
    i = row_head[c];
        
    Remove(c, c);
    if (i >= 0)
    for (j = DL[i].right; j != i; j = DL[j].right)
		Remove(DL[j].ch, c);
    DFS(k+1);
    if (i >= 0)
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
        DL[size].ch = r, DL[size].rid = rid, s[r]++;
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
        DL[i].ch = i, s[i] = 0;
    }
}
int main() {
    int n;
    while (scanf("%d", &n) == 1 && n) {
		int g[MAXN][MAXN] = {};
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				scanf("%d", &g[i][j]);
				g[i][j] = 1 - g[i][j];
			}
		}
		
		init(n);
		for (int i = 0; i < n; i++) {
			int A[MAXN], An = 0;
			for (int j = 0; j < n; j++) {
				if (g[i][j])
					A[An++] = j+1;
			}
			row_head[i+1] = new_row(An, A, i+1);
		}
		Ans = 0;
		DFS(0);
		printf("%d\n", Ans);
    }
    return 0;
}


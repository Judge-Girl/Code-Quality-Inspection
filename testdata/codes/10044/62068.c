#include <cstdio>
#include <cstring>

int graph[100][4], ans;
int ones(int n) {
	int cnt = 0;
	while (n) n &= n-1, cnt++;
	return cnt;
}
void clique(int dep, int *state) {
	if (ones(state[0])+ones(state[1])+ones(state[2])+ones(state[3])+dep <= ans) return;
	bool done = true;
	for (int i = 0; i < 4; i++) {
		if (state[i] == 0) continue;
		for (int j = 0; j < 32; j++) {
			if (state[i] & (1<<j)) {
				int k = (i<<5)+j;
				int state_[4];
				memcpy(state_, state, 16);
				state_[0] &= graph[k][0];
				state_[1] &= graph[k][1];
				state_[2] &= graph[k][2];
				state_[3] &= graph[k][3];
				clique(dep+1, state_);
				state[i] ^= (1<<j);
			}
		}
		done = false;
	}
	if (done && ans < dep) ans = dep; 
}
int main() {
	int N, d, state[4];
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%d", &d);
			if (d == 1) graph[i][j>>5] |= 1<<(j&31);
		}
	}
	int M = ((N-1)>>5)+1;
	memset(state, -1, M*4);
	state[M-1] = (1<<(((N-1)&31)+1))-1;
	if (state[M-1] == 0) state[M-1] = -1;
	
	clique(0, state);
	printf("%d\n", ans);
}

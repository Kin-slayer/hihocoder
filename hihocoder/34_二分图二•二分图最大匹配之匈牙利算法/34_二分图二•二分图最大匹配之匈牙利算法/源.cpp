#include<stdio.h>
#include<memory.h>

typedef struct E {
	int to, nx;
};
E e[10004];
int N, M, u, v, cnt, res = 0;
int head[1003], matched[1003], visited[1003];

bool query(int k) {
	visited[k] = 1;
	int i = head[k];
	while (i) {
		if (matched[e[i].to] == -1 || (!visited[matched[e[i].to]] && query(matched[e[i].to]))) {
			matched[e[i].to] = k;
			matched[k] = e[i].to;
			return 1;
		}
		i = e[i].nx;
	}
	return 0;
}
int main() {
	scanf_s("%d%d", &N, &M);
	memset(matched, -1, sizeof(matched));
	while (M--) {
		scanf_s("%d%d", &u, &v);
		e[++cnt] = { v, head[u] };
		head[u] = cnt;
		e[++cnt] = { u, head[v] };
		head[v] = cnt;
	}
	for (int i = 1; i <= N; i++) {
		if (matched[i] == -1) {
			memset(visited, 0, sizeof(visited));
			res += query(i);
		}
	}
	printf("%d", res);
}
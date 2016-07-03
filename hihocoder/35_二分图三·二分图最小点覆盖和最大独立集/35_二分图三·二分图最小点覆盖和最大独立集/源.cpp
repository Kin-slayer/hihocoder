#include<stdio.h>
#include<memory.h>
typedef struct E {
	int to, nx;
};
E e[10004];
int N, M, u, v, cnt, res;
int head[1003], matched[1003], visited[1003];

bool f(int k) {
	visited[k] = 1;
	int i = head[k];
	while (i) {
		if (!matched[e[i].to] || (!visited[matched[e[i].to]] && f(matched[e[i].to]))) {
			matched[k] = e[i].to;
			matched[e[i].to] = k;
			return 1;
		}
		i = e[i].nx;
	}
	return 0;
}

int main() {
	scanf_s("%d%d", &N, &M);
	while (M--) {
		scanf_s("%d%d", &u, &v);
		e[++cnt] = { v, head[u] };
		head[u] = cnt;
		e[++cnt] = { u, head[v] };
		head[v] = cnt;
	}

	for (int i = 1; i <= N; i++) {
		memset(visited, 0, sizeof(visited));
		if (matched[i]) continue;
		res += f(i);
	}

	printf("%d\n", res);
	printf("%d\n", N - res);
}
#include<cstdio>
#include<memory.h>
int N, M, S, T, x, y, v, count, a;
int head[100005], q[100005], in[100005], dt[100005];
int min(int x, int y) {
	return x < y ? x : y;
}
typedef struct E {
	int v, to, n;
};
E e[1000006];
int main() {
	memset(dt, 0x3f, sizeof(dt));
	scanf_s("%d%d%d%d", &N, &M, &S, &T);
	while (M--) {
		scanf_s("%d%d%d", &x, &y, &v);
		e[++count] = { v, y, head[x] };
		head[x] = count;
		e[++count] = { v, x, head[y] };
		head[y] = count;
	}
	q[0] = S;
	in[S] = 1;
	count = dt[S] = 0;
	for (int l = 0; l <= count; l++) {
		a = head[q[l]];
		while (a) {
			if (dt[e[a].to] > dt[q[l]] + e[a].v) {
				if (!in[e[a].to]) {
					q[++count] = e[a].to;
					in[e[a].to] = 1;
				}
				dt[e[a].to] = dt[q[l]] + e[a].v;
			}
			a = e[a].n;
		}
		in[q[l]] = 0;
	}
	printf("%d ", dt[T]);
}
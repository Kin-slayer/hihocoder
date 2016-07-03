#include<stdio.h>
int a[1000000][5];
int N, M, aa, q, L, R, V;
#define l(i) i<<1
#define r(i) i<<1|1
void devide(int i) {
	if (a[i][4]) {
		a[l(i)][4] = a[r(i)][4] = a[i][4];
		a[l(i)][3] = a[r(i)][3] = 0;
		a[l(i)][0] = (a[l(i)][2] - a[l(i)][1] + 1)*a[i][4];
		a[r(i)][0] = (a[r(i)][2] - a[r(i)][1] + 1)*a[i][4];
		a[i][4] = 0;
	}
	if (a[i][3]) {
		a[l(i)][4] ? a[l(i)][4] += a[i][3] : a[l(i)][3] += a[i][3];
		a[l(i)][0] += a[i][3] * (a[l(i)][2] - a[l(i)][1] + 1);
		a[r(i)][4] ? a[r(i)][4] += a[i][3] : a[r(i)][3] += a[i][3];
		a[r(i)][0] += a[i][3] * (a[r(i)][2] - a[r(i)][1] + 1);
		a[i][3] = 0;
	}
}
int add(int i) {
	if (L <= a[i][1] && a[i][2] <= R) {
		a[i][0] += V * (a[i][2] - a[i][1] + 1);
		a[i][4] ? a[i][4] += V : a[i][3] += V;
	}
	else if (!(a[i][1] > R || a[i][2] < L)) {
		devide(i);
		a[i][0] = add(l(i)) + add(r(i));
	}
	return a[i][0];
}
int set(int i) {
	if (L <= a[i][1] && a[i][2] <= R) {
		a[i][0] = V * (a[i][2] - a[i][1] + 1);
		a[i][4] = V;
		a[i][3] = 0;
	}
	else if (!(a[i][1] > R || a[i][2] < L)) {
		devide(i);
		a[i][0] = set(l(i)) + set(r(i));
	}
	return a[i][0];
}
int main() {
	scanf("%d %d", &N, &M);
	for (aa = 1; aa < N+1; aa <<= 1);
	for (int i = aa; i <= aa + N; a[i][1] = a[i][2] = i++ - aa) scanf("%d", &a[i][0]);
	for (int i = aa + N + 1; i <= (aa << 1); i++) a[i][2] = N, a[i][1] = N + 1;
	for (int i = aa - 1; i > 0; i--) {
		a[i][0] = a[l(i)][0] + a[r(i)][0];
		a[i][1] = a[l(i)][1];
		a[i][2] = a[r(i)][2];
	}
	while (M--) {
		scanf("%d %d %d %d", &q, &L, &R, &V);
		printf("%d\n", q ? set(1) : add(1));
	}
}
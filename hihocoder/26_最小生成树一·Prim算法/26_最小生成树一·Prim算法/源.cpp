#include<cstdio>
#include<memory.h>
int N, v, count, min, res, m = 1;
int a[1003][1003], in[1003];
int main() {
	scanf_s("%d", &N);
	memset(a[0], 0x3f, sizeof(a[0]));
	memset(in, 0, sizeof(in));
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++) {
			scanf_s("%d", &v);
			a[i][j] = v;
		}
	a[0][1] = 0;
	while (++count < N) {
		min = 100000007;
		in[m] = 1;
		for (int i = 1; i <= N; i++)
			if (a[m][i] < a[0][i] && !in[i])
				a[0][i] = a[m][i];
		for (int i = 1; i <= N; i++)
			if (!in[i] && a[0][i] < min)
				min = a[0][m = i];
		res += a[0][m];
	}
	printf("%d", res);
}
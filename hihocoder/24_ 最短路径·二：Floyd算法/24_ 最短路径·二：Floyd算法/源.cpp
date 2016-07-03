#include<cstdio>
#include<memory.h>
using namespace std;
int N, M, x, y, t,value;
int a[103][103];
int main() {
	scanf_s("%d%d", &N, &M);
	memset(a, 0x3f, sizeof(a));
	while (M--) {
		scanf_s("%d%d%d", &x, &y, &t);
		if (a[x][y] > t)
			a[x][y] = a[y][x] = t;
	}
	for (int k = 1; k <= N; k++) {
		for (int j = 2; j <= N; j++) {
			for (int i = 0; i < j; i++) {
				value = a[i][k] + a[k][j];
				if (value < a[i][j]) {
					a[i][j] = a[j][i] = value;
				}
			}
		}
	}
	for (int i = 1; i <= N; i++) a[i][i] = 0;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			printf("%d ",a[i][j]);
		}
		printf("\n");
	}
}
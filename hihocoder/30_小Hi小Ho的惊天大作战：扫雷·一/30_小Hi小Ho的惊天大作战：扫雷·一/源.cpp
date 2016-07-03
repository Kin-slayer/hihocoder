#include<cstdio>

int T, N;
int a[100005], b[100005][2];

void f(int k) {
	int boom = b[1][k] = k;
    b[0][k] = 0;
	for (int i = 1; i <= N; i++) {
		b[i + 1][k] = a[i] - b[i][k] - b[i - 1][k];
		if (!(b[i + 1][k] == 0 || b[i + 1][k] == 1)) {
			b[0][k] = -1;
			return;
		}
		boom += b[i + 1][k];
	}
	b[0][k] = boom;
	if (b[N + 1][k]) b[0][k] = -1;
}

void p(int k) {
	printf("%d ", b[0][k]);
	for (int i = 1; i <= N; i++) 
		if (b[i][k]) printf("%d ", i);
	printf("\n%d ", N - b[0][k]);
	for (int i = 1; i <= N; i++) if (!b[i][k]) 
		printf("%d ", i);
	printf("\n");
}
int main() {
	scanf_s("%d", &T);
	while (T--) {
		scanf_s("%d", &N);
		for (int i = 1; i <= N; i++) {
			scanf_s("%d", &a[i]);
		}
		f(0); f(1);
		if (b[0][1] >= 0 && b[0][0] >= 0) {
			b[0][0] = 0;
			int notboom = 0;
			for (int i = 1; i <= N; i++) {
				b[i][0] = -(b[i][1] ^ b[i][0]);
				if (!b[i][0]) b[i][0] = b[i][1];
				if (b[i][0] == 1) b[0][0]++;
				if (!b[i][0]) notboom++;
			}
			printf("%d ", b[0][0]);
			for (int i = 1; i <= N; i++) 
				if (b[i][0] == 1) printf("%d ",i);
			printf("\n%d ", notboom);
			for (int i = 1; i <= N; i++)
				if (!b[i][0]) printf("%d ", i);
			printf("\n");
			continue;
		}
		b[0][0] > b[0][1] ? p(0) : p(1);
	}
}
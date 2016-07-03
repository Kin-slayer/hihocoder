#include<cstdio>

int a[100005], count, w, N;
char q;
void swap(int *x, int *y) {
	*x = *x^*y;
	*y = *x^*y;
	*x = *x^*y;
}
void add() {
	scanf_s("%d", &w);
	a[++count] = w;
	int i = count;
	while (true) {
		if (a[i] > a[i >> 1]) {
			swap(&a[i], &a[i >> 1]);
			i >>= 1;
		}
		else {
			break;
		}
	}
}

void eat() {
	printf("%d\n", a[1]);
	if (count == 1) {
		count--;
		return;
	}
	a[1] = a[count--];
	a[count+1] = 0;
	int i = 1;
	while (true) {
		if (a[i] > a[i << 1] && a[i] > a[i << 1 | 1]) break;
		if (a[i << 1] > a[i << 1 | 1]) {
			swap(&a[i << 1], &a[i]);
			i <<= 1;
		}
		else {
			swap(&a[i << 1 | 1], &a[i]);
			i = i << 1 | 1;
		}
	}
}
int main() {
	a[0] = 100005;
	scanf_s("%d", &N);
	while (N--) {
		while (q = getchar(), q != 'A' && q != 'T');
		if (q == 'A') {
			add();
		}
		else {
			eat();
		}
	}
}
#include<stdio.h>

int N, k;
long long a[1000006];

template<typename T> T mid_number(T a, T b, T c) {
	if (a > b && a <c) {
		return a;
	}
	if (b >a && b < c) {
		return b;
	}
	return c;
}

template<typename T> void swap(T *a, T *b) {
	*a = *a^*b;
	*b = *a^*b;
	*a = *a^*b;
}

long long query() {
	if (k>N || k < 1) return -1;
	int l = 0, r = N - 1, i, j;
	long long mid;
	while (r - l>0) {
		i = l, j = r;
		mid = mid_number(a[l], a[r], a[l + r >> 1]);
		while (1) {
			while (a[i] < mid) i++;
			while (a[j] > mid) j--;
			if (i < j) swap(&a[i], &a[j]);
			else break;
		}
		if (i + 1 == k) return a[i];
		if (i + 1 > k) r = i;
		else l = i;
	}
	return a[0];
}

int main() {
	scanf("%d%d", &N, &k);
	for (int i = 0; i < N; i++) scanf("%d", &a[i]);
	printf("%d\n", query());

}
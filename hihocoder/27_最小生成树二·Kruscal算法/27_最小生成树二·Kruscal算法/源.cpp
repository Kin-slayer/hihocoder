#include<cstdio>

int N, M, x, y, v, count, res;
int in[100005], represent[100005], la[100005];

typedef struct E {
	int x, y, v;
	bool operator< (const E& node)const {
		return (v < node.v);
	}
	bool operator>(const E& node)const {
		return (v > node.v);
	}
};
E e[1000006], temp;

int findpresent(int n) {
	return represent[n] == n ? n : represent[n] = findpresent(represent[n]);
}
void swap(E *x, E *y) {
	temp = *x;
	*x = *y;
	*y = temp;
}
void trim() {
	for (int i = count; i > 1; i >>= 1) {
		if (e[i] < e[i >> 1]) swap(&e[i], &e[i >> 1]);
		else return;
	}
}


E pop() {
	E min = e[1];
	e[1] = e[count];
	for (int i = 1; i << 1 < count; ) {
		if (e[i] < e[i << 1] && e[i] < e[i << 1 | 1]) break;
		if (e[i << 1] > e[i << 1 | 1]) {
			swap(&e[i], &e[i << 1 | 1]);
			i = i << 1 | 1;
		}
		else {
			swap(&e[i], &e[i << 1]);
			i = i << 1;
		}
	}
	count--;
	return min;
}
int main() {
	scanf_s("%d%d", &N, &M);
	int p = M;
	while (M--) {
		scanf_s("%d%d%d", &x, &y, &v);
		e[++count] = { x, y, v }; trim();
	}
	for (int i = 1; i <= N; i++) {
		represent[i] = i;
	}
	while (count) {
		temp = pop();
		int pre = findpresent(temp.x);
		if (pre == findpresent(temp.y)) continue;
		represent[pre] = temp.y;
		res += temp.v;
	}
	printf("%d", res);
}
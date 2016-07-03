#include<iostream>
int a[1000000][4];
int l, r, q, n, aa, res;

int geti() {
	int r = 0; char c = 0;  while (c<'0' || c>'9') c = getchar();
	while (c >= '0'&&c <= '9') { r = ((r << 3) + (r << 1)) + (c - '0'); c = getchar(); }
	return r;
}

void outi(int x) {
	int i; char buf[16];
	if (x == 0) { putchar('0'); putchar('\n'); return; }
	for (i = 0; x; i++) { buf[i] = x % 10 + '0'; x /= 10; }
	for (; i--;) putchar(buf[i]); putchar('\n');
}
void dp(int i) {
	if (l > a[i][2] || r < a[i][1]) {
		return;
	}
	if (l <= a[i][1] && r >= a[i][2]) {
		a[i][0] = (a[i][2] - a[i][1] + 1) * q;
		a[i][3] = q;
		return;
	}
	if (a[i][3]) {
		a[i << 1][3] = a[i][3];
		a[i << 1][0] = (a[i << 1][2] - a[i << 1][1] + 1)*a[i][3];
		a[i << 1 | 1][3] = a[i][3];
		a[i << 1 | 1][0] = (a[i << 1 | 1][2] - a[i << 1 | 1][1] + 1)*a[i][3];
		a[i][3] = 0;
	}
	dp(i << 1);
	dp(i << 1 | 1);
	a[i][0] = a[i << 1][0] + a[i << 1 | 1][0];
}

void md() {
	l = geti();
	r = geti();
	q = geti();
	dp(1);
}

void dp2(int i) {
	if (l <= a[i][1] && r >= a[i][2]) {
		res += a[i][0];
		return;
	}
	if (l > a[i][2] || r < a[i][1]) return;
	if (a[i][3]) {
		a[i << 1][3] = a[i][3];
		a[i << 1][0] = (a[i << 1][2] - a[i << 1][1] + 1)*a[i][3];
		a[i << 1 | 1][3] = a[i][3];
		a[i << 1 | 1][0] = (a[i << 1 | 1][2] - a[i << 1 | 1][1] + 1)*a[i][3];
		a[i][3] = 0;
	}
	dp2(i << 1);
	dp2(i << 1 | 1);

}

void qr() {
	l = geti();
	r = geti();
	dp2(1);
	outi(res);
	res = 0;
}

int main() {
	int  q;
	n = geti();

	for (aa = 1; aa < n; aa <<= 1);
	for (int i = 0; i < n; i++) {
		a[i + aa][0] = geti();
		a[i + aa][1] = a[i + aa][2] = i + 1;
	}
	for (int i = aa - 1; i > 0; i--) {
		a[i][0] = a[i << 1][0] + a[i << 1 | 1][0];
		a[i][1] = a[i << 1][1];
		a[i][2] = a[i << 1 | 1][2] ? a[i << 1 | 1][2] : a[i << 1][2];
	}

	q = geti();
	int u;
	while (q--) {
		u = geti();
		u ? md() : qr();
	}
}
#include <cstdio>
#include <cstring>
#include<map>
using namespace std;
int N, M, S, E, ss, s, count, x, y, v, ch, aa, left, d[1003], a[1003][1003];
int F() {
	while (ch = getchar(), ch<'0' || ch>'9'); aa = ch - 48;
	while (ch = getchar(), ch >= '0'&&ch <= '9')aa = aa * 10 + ch - 48; return aa;
}
struct E {
	int fr, to;
	int v;
	E* next = NULL;
	bool operator < (E const& A) const {
		return v < A.v;
	}
}e[1003][1003], last[1003];
map<struct E, int> q;
void add(int x, int y, int v) {
	if (!e[x][y].v) {
		e[x][y].v = e[y][x].v = v;
		e[x][y].fr = x;
		e[x][y].to = y;
		e[y][x].fr = y;
		e[y][x].to = x;
		e[x][y].next = &last[x];
		last[x] = e[x][y];
		e[y][x].next = &last[y];
		last[y] = e[y][x];
		return;
	}
	if (v < e[x][y].v) e[x][y].v = e[y][x].v = v;
}
int min(int x, int y) {
	return x < y ? x : y;
}
int main() {
	memset(d, 0x3f, sizeof(d));
	scanf("%d%d%d%d", &N, &M, &S, &E);
	while (M--) {
		x = F(); y = F(); v = F();
		add(x, y, v);
	}
	q[0] = last[S];
	while (!q.empty()) {
		struct E* i = q.begin()->first;
		do {
			
			i = i->next;
		} while (i != NULL);
	}
}
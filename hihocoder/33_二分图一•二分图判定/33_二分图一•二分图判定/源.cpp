#include<cstdio>
#include<memory.h>
int T, N, M, u, v, count, c;

typedef	struct E {
	int to, nx;
};

E e[40004];
int head[10004], painted[10004];

bool paint(int k) {
	int i = head[k];
	while (i) {
		if (painted[e[i].to] && painted[e[i].to] == painted[k]) return false;
		if (painted[e[i].to]) {
			i = e[i].nx;
			continue;
		}
		painted[e[i].to] = -painted[k];
		if (!paint(e[i].to)) return false;
		i = e[i].nx;
	}
	return true;
}

int main() {
	scanf_s("%d", &T);
	while (T--) {
		count = 0;
		memset(painted, 0, sizeof(painted));
		memset(head, 0, sizeof(head));
		memset(e, 0, sizeof(e));
		scanf_s("%d%d", &N, &M);
		while (M--) {
			scanf_s("%d%d", &u, &v);
			e[++count] = { v, head[u] };
			head[u] = count;
			e[++count] = { u, head[v] };
			head[v] = count;
		}
		bool ok = true;
		for (c = 1; c <= N; c++) {
			if (!painted[c]) {
				painted[c] = 1;
				if (!paint(c)) {
					ok = false;
					break;
				}
			}
		}
		if (ok) {
			printf("Correct\n");
		}
		else {
			printf("Wrong\n");
		}
	}
}

#include <iostream>
using namespace std;
int q, n, m, A, B, sum_Ax, sum_Ay, sum_Ax2, sum_Ay2, sum_Bx, sum_By;

struct  node {
	int left = 0;
	node* next = NULL;
};
int max(int x, int y) {
	return x > y ? x : y;
}
int min(int x, int y) {
	return x < y ? x : y;
}
void insert(int temp, node* head) {
	node* n = head;
	while (n->next != NULL) {
		if (n->next->left > temp)
			break;
		n = n->next;
	}
	node* a = new node;
	a->next = n->next;
	n->next = a;
	a->left = temp;
}
int f(int x, int plus, int c) {
	cout << A << " " << x << " " << sum_Ax << " " << B << " " << c << " " << sum_Ax2 << " " << plus << " " << sum_Bx << endl;
	cout << A*x*x - ((sum_Ax << 1) + B - (c << 1))*x + sum_Ax2 + sum_Bx - (plus << 1) << endl;
	return A*x*x - ((sum_Ax << 1) + B - (c << 1))*x + sum_Ax2 + sum_Bx - (plus << 1);
}
int getRankMin(int left, int right, int plus, int c) {
	int x = (sum_Ax + (B >> 1) - c) / A;
	if (x > left && x < right)return min(f(x + 1, plus, c), f(x, plus, c));
	return min(f(left, plus, c), f(right, plus, c));
}
int getMin(node* head) {
	int plus = 0, res = 65535, c = 0;
	while (head != NULL&&head->next != NULL) {
		res = min(res, getRankMin(head->left, head->next->left, plus, c));
		head = head->next;
		plus += head->left;
		c++;
	}
	sum_Ax = sum_Ay;
	sum_Ax2 = sum_Ay2;
	sum_Bx = sum_By;
	return res;
}
int main() {
	cin >> q;
	while (q--) {
		sum_Ax = sum_Ay = sum_Ax2 = sum_Ay2 = sum_Bx = sum_By = 0;
		node *head_x = new node, *head_y = new node;
		head_x->next = new node;
		head_y->next = new node;
		head_y->left = head_x->left = 100;
		int temp;
		cin >> n >> m >> A >> B;
		for (size_t i = 0; i < A; i++) {
			cin >> temp;
			sum_Ax += temp;
			sum_Ax2 += temp * temp;
			head_x->left = min(head_x->left, temp);
			head_x->next->left = max(head_x->next->left, temp);
			cin >> temp;
			sum_Ay += temp;
			sum_Ay2 += temp * temp;
			head_y->left = min(head_y->left, temp);
			head_y->next->left = max(head_y->next->left, temp);
		}

		for (int i = 0; i < B; i++) {
			cin >> temp;
			sum_Bx += temp;
			insert(temp, head_x);
			head_x->left = min(head_x->left, temp);
			head_x->next->left = max(head_x->next->left, temp);
			cin >> temp;
			sum_By += temp;
			insert(temp, head_y);
			head_y->left = min(head_y->left, temp);
			head_y->next->left = max(head_y->next->left, temp);
		}
		cout << getMin(head_x) + getMin(head_y) << endl;
	}
}
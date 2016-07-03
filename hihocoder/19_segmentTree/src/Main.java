import java.util.Scanner;

public class Main {
	static int MAX = 10000000;
	static int[] a = new int[1000000];

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int aa, bb;
		for (aa = 1; aa < n; aa <<= 1)
			;
		for (int i = aa; i < aa + n; i++)
			a[i] = sc.nextInt();
		for (int i = aa + n; i < aa << 1; i++)
			a[i] = MAX;
		for (int i = aa - 1; i > 0; i--) {
			a[i] = Math.min(a[i << 1], a[i << 1 | 1]);
		}
		int q = sc.nextInt();
		for (int i = 0; i < q; i++) {
			System.out.println(qre(sc.nextInt()-1+aa, sc.nextInt()-1+aa));
		}
	}

	public static int qre(int l, int r) {
		int res = MAX;
		while (true) {
			if (l>r) {
				break;
			}
			if (l == r) {
				res = Math.min(res, a[l]);
				break;
			}
			if ((l & 1) == 1) {
				res = Math.min(res, a[l]);
				l++;
			}
			if ((r & 1) == 0) {
				res = Math.min(res, a[r]);
				r--;
			}
			l >>= 1;
			r >>= 1;
		}
		return res;
	}

}

import java.util.Scanner;

public class Main {
	static int[][] a = new int[1000007][20];

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		for (int i = 1; i <= n; i++) {
			a[i][0] = sc.nextInt();
		}
		for (int i = 1; 1 << i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				a[j][i] = Math.min(a[j][i - 1], a[j + (1 << (i - 1))][i - 1]);
			}
		}

		int q = sc.nextInt();
		for (int i = 0; i < q; i++) {
			int t1 = sc.nextInt();
			int t2 = sc.nextInt();
			int mid = (int) (Math.log(t2 - t1) / Math.log(2));
			System.out.print(Math
					.min(a[t1][mid], a[t2 - (1 << mid) + 1][mid])+"\n");
		}
		System.out.flush();
		sc.close();
	}
}

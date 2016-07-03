import java.util.Scanner;
import java.util.Stack;

public class Main {
	static int MAX = 105;
	static int[][] dp = new int[MAX][MAX];
	static Stack<Integer> stack = new Stack<Integer>();

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		for (int i = 0; i < (1 + n) * n / 2; i++) {
			stack.add(sc.nextInt());
		}
		for (int i = n; i > 0; i--) {
			for (int j = 1; j <= i; j++) {
				dp[i][j] = (int) Math.max(dp[i + 1][j], dp[i + 1][j + 1])
						+ stack.pop();
			}
		}
		System.out.println(dp[1][1]);
		sc.close();
	}
}

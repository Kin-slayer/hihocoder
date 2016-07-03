import java.util.Scanner;

public class Main {

	static int n;
	static int m;

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		n = sc.nextInt();
		m = sc.nextInt();
		System.out.println(dp(0,0,0,0));
		sc.close();
	}

	public static int dp(int a, int b, int index,int count) {
		int res = 0;
		int thisIndex = index;
		int nextIndex = 1 << index + 1;
		index++;
		if (index == m) {
			if (++count == n) {
				for (int i = 0; i < m; i++) {
					
				}
			}
			index = 0;
			nextIndex = 1;
			while ((a & nextIndex) != 0) {
				nextIndex = nextIndex << 1;
				index++;
			}
			return dp(b, 0, index,count);
		}
		for (nextIndex = nextIndex << 1, index++; (a & nextIndex) != 0;) {
			nextIndex = nextIndex << 1;
			index++;
		}
		if ((a & nextIndex) == 0) {
			res = dp((a | (1 << thisIndex + 1)), b, index,count);
		}
		return res += dp(a, (b | (1 << thisIndex + 1)), index,count);

	}
}

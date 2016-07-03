import java.util.Scanner;

public class Main {
	static int[][] a = new int[1000000][2];
	static int[] left = new int[1000000];
	static int[] right = new int[1000000];

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int aa;
		for (aa = 1; aa < n; aa <<= 1)
			;
		for (int i = aa; i < n; i++) {
			a[i][0] = sc.nextInt();
			left[i] = i;
			right[i] = i;
		}
		for (int i = aa - 1; i > 0; i--) {
			a[i][0] = a[i << 1][0] + a[i << 1 | 1][0];
			left[i] = left[i<<1];
			right[i] = right[i<<1|1];
			if (right[i<<1|1] == 0) {
				right[i] = right[i<<1];
			}
		}
		
		int q = sc.nextInt();
		for (int i = 0; i < q; i++) {
			if (sc.nextInt() == 1) {
				m();
			} else {
				
			}
		}
		
	}
	
	public static void m() {
		
	}
	
	public static int q() {
		return 0 ;
	}
}

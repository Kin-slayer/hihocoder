import java.util.Scanner;


public class Main {
	static int N = 1005;
	static boolean map[][] = new boolean[N][N];
	static boolean usd[] = new boolean[N];
	static int match[] = new int[N];
	static int m,n;
	static int res = 0;
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		n = sc.nextInt();
		m = sc.nextInt();
		for (int i = 0 ;i < m ;i++) {
			map[sc.nextInt()][sc.nextInt()] = true;
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < usd.length; j++) {
				usd[j] = false;
			}
			if (find(i)) {
				res ++;
			}
		}
		System.out.println(res);
	}
	
	static boolean find(int i){
		for (int j = 0; j < n; j++) {
			if (map[i][j] && !usd[j]) {
				 usd[i] = true;
				 if(match[j] == -1 || find(match[j]))
				 {
					 match[j] = i;
					 return true;
				 }
			}
		}
		return false;
	}

}

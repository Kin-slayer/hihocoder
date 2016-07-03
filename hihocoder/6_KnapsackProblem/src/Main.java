import java.util.Scanner;


public class Main {
	static int[] need,value;
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int m = sc.nextInt();
		value = new int[n];
		need = new int[n];
		for (int i = 0; i < n; i++) {
			need[i] = sc.nextInt();
			value[i] = sc.nextInt();
		}
		
		dp(n,m);
		
	}
	int dp(int n,int m){
		if (condition) {
			
		}
	}
}

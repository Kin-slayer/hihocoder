import java.util.Scanner;
public class Main {
	public static void main (String args[]){
		int res = 0 ;
		boolean flag = false;
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int k = sc.nextInt();
		for (int i = 0; i < n; i++) {
			int temp = sc.nextInt();
			if (k >= temp) {
				res++;
			}
			if (k == temp) {
				flag = true;
			}
		}
		if (flag) {
			System.out.println(res);
		}
		else {
			System.out.println(-1);
		}
	}
}


import java.util.Iterator;
import java.util.Scanner;


public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int[] ans = new int[n];
		char[] cs1  = null,cs2 = null;
		for (int i = 0; i < n; i++) {
			cs1 = sc.next().toCharArray();
			cs2 = sc.next().toCharArray();
			int[] next = new int[cs1.length];
			getNext(cs1, next);
			int j = 0, k = 0;
			while (j < cs1.length && k < cs2.length) {
				if (cs1[j] == cs2[k]) {
					k++;j++;
				}
				
				
			}
		}
	}

	public static void getNext(char[] pattern ,int[] next){
		int k = -1;
		next[0] = -1;
		for (int i = 0; i < pattern.length; i++) {
			if (k != -1 && pattern[i] != pattern[k]) {
				k = next[k];
			}
			++i;++k;
			if (pattern[i] == pattern[k]) {
				 next[i] = next[k];
			}
			else {
				next[i] = k;
			}
		}
	}
}

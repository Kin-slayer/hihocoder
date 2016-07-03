import java.util.Arrays;
import java.util.Scanner;
import java.util.Stack;

public class Main {
	static Stack<String> stack = new Stack<String>();
	static char[] ad;
	static int count = 0;

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		ad = sc.next().toCharArray();
		stack.push(sc.next());
		while (!stack.isEmpty()) {
			tree();
		}
		System.out.println();
		sc.close();
	}

	public static void tree() {
		char[] chars = stack.pop().toCharArray();
		if (chars.length == 0) {
			return;
		}
		if (count == ad.length) {
			System.out.print(chars[0]);
			return;
		}
		for (int i = 0; i < chars.length; i++) {
			if (chars[i] == ad[count]) {
				if (i == 0) {
					System.out.print(chars[0]);
					count++;
					return;
				}
				stack.push(String.valueOf(chars[i]));
				stack.push(String.valueOf(Arrays.copyOfRange(chars, i + 1,
						chars.length)));
				stack.push(String.valueOf(Arrays.copyOfRange(chars, 0, i)));
				count++;
				return;
			}
		}
		if (chars.length == 1) {
			System.out.print(chars[0]);
		}
	}
}

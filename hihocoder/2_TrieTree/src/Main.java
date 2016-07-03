import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;


public class Main {
	
	static Map<Character, Node> nodes = new HashMap<Character, Node>();
	static char[] cs;
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		for (int i = 0; i < n; i++) {
			cs = sc.next().toCharArray();
			recursion1(nodes,0);
		}
		int m = sc.nextInt();
		int res[] = new int[m];
		for (int i = 0; i < m; i++) {
			cs = sc.next().toCharArray();
			res[i] = recursion2(nodes,0);
		}
		for (int i = 0; i < res.length; i++) {
			System.out.println(res[i]);
		}
		sc.close();
	}
	
	static void recursion1(Map<Character, Node> map ,int i){
		if (i == cs.length) {
			return;
		}
		if (map.containsKey(cs[i])) {
			map.get(cs[i]).sum++;
		}
		else {
			map.put(cs[i], new Node());
		}
		recursion1(map.get(cs[i]).nextNodes,i+1);
	}
	
	static int recursion2(Map<Character, Node> map ,int i){
		if (map.containsKey(cs[i])) {
			if (i == cs.length-1) {
				return map.get(cs[i]).sum;
			}
			return recursion2(map.get(cs[i]).nextNodes,i+1);
		}
		else {
			return 0;
		}
	}
}

class Node {
	Map<Character, Node> nextNodes = new HashMap<Character, Node>();
	int sum;
	public Node() {
		sum = 1;
	}
}
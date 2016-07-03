import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

import javax.rmi.CORBA.Tie;

public class Main {
	static Map<String, Integer> map = new HashMap<String, Integer>();
	static Node[] nodes = new Node[100000];
	static int[][] midTr = new int[1000000][20];
	static int count = 0;

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		map.put(sc.next(), 0);
		nodes[0] = new Node(0);
		map.put(sc.next(), 1);
		nodes[1] = new Node(1);
		nodes[0].head = new E(nodes[1], nodes[0].head);
		for (int i = 2; i <= n; i++) {
			Node preNode = nodes[map.get(sc.next()).intValue()];
			map.put(sc.next(), i);
			nodes[i] = new Node(preNode.height + 1);
			preNode.head = new E(nodes[i], preNode.head);
		}
		dp(nodes[0]);
		for (int j = 1; 1 << j < count; j++) {
			for (int i = 0; i < count; i++) {
				midTr[i][j] = Math.max(midTr[i][j - 1],
						midTr[i + (1 << j - 1)][j - 1]);
			}
		}
		int q = sc.nextInt();
		for (int i = 0; i < q; i++) {
			int t1 = nodes[map.get(sc.next()).intValue()].index;
			int t2 = nodes[map.get(sc.next()).intValue()].index;
			if (t1==t2) {
				System.out.println(-1);
				continue;
			}
			if (t1>t2) {
				t1 = t1^t2;
				t2 = t1^t2;
				t1 = t1^t2;
			}
			int m = (int) (Math.log(t2-t1)/Math.log(2));
			System.out.println(Math.max(midTr[t1][m], midTr[t2-(1<<m)][m]));
		}
	}

	public static void dp(Node n) {
		E e = n.head;
		while (e != null) {
			dp(e.to);
			e = e.next;
			n.index = count;
			midTr[count++][0] = n.height;
			if (e == null) {
				break;
			}
		}

		n.index = count;
		midTr[count++][0] = n.height;
	}

	static class Node {
		public Node(int hei) {
			this.height = hei;
		}

		int index;
		int height;
		E head;
	}

	static class E {
		public E(Node to, E nx) {
			this.to = to;
			this.next = nx;
		}

		Node to;
		E next;
	}
}

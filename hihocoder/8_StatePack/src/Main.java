import java.util.Arrays;
import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);

		int n = sc.nextInt();
		int m = sc.nextInt();
		int q = sc.nextInt();
		int bitNumber = 1 << m;
		int[][] quantity = new int[n + 1][bitNumber];
		for (int i = 1; i < quantity.length; i++) {
			int temp = sc.nextInt();
			for (int j = 0; j < quantity[i].length; j++) {
				if (Integer.bitCount(j) > q) {
					continue;
				}
				if ((j & bitNumber >> 1) > 0) {
					quantity[i][j] = Math.max(quantity[i - 1][(j << 1)
							- bitNumber + 1], quantity[i - 1][(j << 1)
							- bitNumber])
							+ temp;
				} else {
					quantity[i][j] = quantity[i - 1][(j << 1)];
				}
			}
		}
		
		
		/*
		 * 另外的一种写法
		 * 二维数组只开了两行
		 * 有与、异或操作来交替使用
		 * 66666
		 */ 
		/*
		cnt[0]=0;cnt[1]=1;
	    for (int i=2; i<b[m]; ++i) cnt[i]=cnt[i>>1]+cnt[i&1];
	    for (int i=1; i<=n; ++i)
	        for (int j=0; j<b[m]; ++j) if (cnt[j]<=q)
	            f[i&1][j]=max(f[(i&1)^1][j>>1], f[(i&1)^1][(j>>1)+b[m-1]])+(j&1)*w[i];
		*/
		
		for (int i = 0; i < quantity.length; i++) {
			for (int j = 0; j < quantity[i].length; j++) {
				System.out.print(quantity[i][j] + "   ");
			}
			System.out.println();
		}
		Arrays.sort(quantity[n]);
		System.out.println(quantity[n][bitNumber - 1]);
		sc.close();
	}
}
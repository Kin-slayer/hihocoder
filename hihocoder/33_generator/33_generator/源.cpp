
#include <stdio.h>
int main(int argc, char *argv[]) {
	freopen("c:\\in.txt", "r", stdin);
	scanf("");//输入将从c:\\in.txt输入
	//或者
	fscanf(stdin, "");//输入将从c:\\in.txt输入


	freopen("c:\\out.txt", "w", stdout);
	printf("the stream will go into out.txt");//输出流将向c:\\out.txt输出。
	//或者
	fprintf(stdout, "");//输出流将向c:\\out.txt输出。



	freopen("c:\\errout.txt", "w", stderr);
	fprintf(stderr, "the error stream will go into errout.txt");// 错误信息将向重c:\\errout.txt输出。
	//或者
	fprintf(stderr, "");// 错误信息将向重c:\\errout.txt输出。
}
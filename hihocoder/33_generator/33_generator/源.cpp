
#include <stdio.h>
int main(int argc, char *argv[]) {
	freopen("c:\\in.txt", "r", stdin);
	scanf("");//���뽫��c:\\in.txt����
	//����
	fscanf(stdin, "");//���뽫��c:\\in.txt����


	freopen("c:\\out.txt", "w", stdout);
	printf("the stream will go into out.txt");//���������c:\\out.txt�����
	//����
	fprintf(stdout, "");//���������c:\\out.txt�����



	freopen("c:\\errout.txt", "w", stderr);
	fprintf(stderr, "the error stream will go into errout.txt");// ������Ϣ������c:\\errout.txt�����
	//����
	fprintf(stderr, "");// ������Ϣ������c:\\errout.txt�����
}
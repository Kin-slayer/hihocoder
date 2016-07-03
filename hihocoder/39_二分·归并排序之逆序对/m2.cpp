#include<stdio.h>

int N;
int a[100],b[100];

int main(){
	scanf("%d",&N);
	for(int i = 0;i < N;i++) {
		scanf("%d",&a[i]);
		printf("a[%d] = %d",i,a[i]);
	}
}
	

#include<stdio.h>

float temp,accu,a[233][233],x[233];
int N,flag = 1;
#define abs(num) (num>0? num:-num)
float f(int k){
	float res = a[k][0];
	for(int i = 1;i <= N;i ++){
		res += a[k][i]*x[i];
	}
	return res;
}
int main(){
	scanf("%d%f",&N,&accu);
	for(int i = 1;i <= N;i++){
		for(int j =1;j <= N;j++){
			scanf("%f",&a[i][j]);
		}
		scanf("%f",&a[i][0]);
	}
	for(int i = 1;i <= N;i++)
		scanf("%f",&x[i]);
	while(flag){
		flag = 0;
		for(int i = 1;i <= N;i++){
			temp = f(i);
			if(abs(temp) - x[i] > accu) flag = 1;
			x[i] = temp;
		}
		for(int i = 1;i <= N;i++)
			printf("%f ",x[i]);
		printf("\n");
	}
	for(int i = 1;i <= N;i++)
		printf("%f",x[i]);
}

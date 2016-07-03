#include<stdio.h> 
#include<cstring>
#include<math.h>

#define MAX 100000000
#define abs(num) (num>0? num:-num)
#define max(n1,n2) (n1>n2? n1:n2)
float temp,w,accu,a[233][233],x[233];
int N,cnt,flag = 1; 

float g(int k){
	float res = a[k][0]; 
	for(int i = 1;i <= N;i++) 
		res += -a[k][i]*x[i]; 
	return (w/a[k][k])*res;
}

int main(){
	scanf("%d%f%f",&N,&w,&accu);	
	for(int i = 1;i <= N;i++){
		for(int j = 1;j <= N;j++)
			scanf("%f",&a[i][j]);
		scanf("%f",&a[i][0]);
	}
	for(int i = 1;i <= N;i++)
		scanf("%f",&x[i]);
	printf("迭代因子：%f\n",w);
	while(flag){
		cnt++;
		flag = 0;
		for(int i = 1;i <= N;i++){
			temp = g(i);
			if(abs(temp) > accu)flag = 1;
			x[i] += temp;
		}
		printf("第%d次迭代结果\n",cnt);
		for(int i = 1;i <= N;i++)
			printf("x[%d]=%3f ",i,x[i]);
		printf("\n");
	}
	printf("总迭代次数：%d\n最终结果:\n",cnt);
	for(int i = 1;i <= N; i++)
		printf("x[%d]=%3f ",i,x[i]);
}

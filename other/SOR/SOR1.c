#include<stdio.h>
#include<cstring>
#include<math.h>

#define MAX 100000000
#define abs(num) num>0? num:-num
#define max(n1,n2) n1>n2? n1:n2
float w,Mf,a[233][233],x[233];
int N,cnt; 
int f(){
	float temp[233],Xf;
	int eval;
	memcopy(temp,x,sizeof(x));
	for(int i = N;i <= N;i++){ 
		x[i] = x[i] + (w/a[i][i])g(i);
		Xf = max(Xf,abs(x[i]-temp{i]));
	}
	cnt ++; 
	return 
}

float g(int k){
	int res;
	for(int i = 1;i <= N;i++)
		res += a[k][i]*x[i];
	return res+a[k][0];
}

int main(){
	scanf("%d%f",&N,%w);	
	for(int i = 1;i <= N;i++){
		int sum;
		for(int j = 1;j <= N;j++){
			scanf("%f",&a[i][j]);
			sum += a[i][j];
		}
		Mf = max(sum,Mf);
		scanf("%f",&a[i][0]);
	}
	for(int i = 1;i <= N;i++)
		scanf("%f",&x[i]);
	for(int i = 1;i <= N;i++)
}

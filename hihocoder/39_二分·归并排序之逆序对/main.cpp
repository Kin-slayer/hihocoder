#include<stdio.h>

int N;
long long  a[10000],b[10000];
int f(int l,int r){
	printf("%d %d",l,r);
	if(l>=r) return 0;
	int res = 0,m = (l+r)>>1,i = l,j = m+1,index = i;
	res += f(l,m) + f(m+1,r);
	while(i<=m&&j<=r){
		if(a[i]>a[j]){
			b[index++] = a[i++];
			res += r - m;
		} else b[index++] = a[j++];
	}
	while(i!=m){
		b[index++] = a[i++];
		res += r - m;
	}
	while(j!=r)
		b[index++] = a[j++];
	for(int i = l ;i <= r;l++) a[l] = b[l];
	return res;
}
int main(){
	scanf("%d",&N);
	for(int i = 0;i < N;i++) {
		scanf("%lld",&a[i]);
		printf("a[%d] = %lld",i,a[i]);
	}
	printf("%d",f(0,N-1));
}
	

#include<stdio.h>

int num[233],op[233];
int cnt = 0;

int main(){
	int c,res = 0;
	op[0] = 1;	
	while((c = getchar()) != '\n'){
		if(c == 32) continue;
		if(c == 43) {op[++cnt] = 1;continue;}
		if(c == 45) {++cnt;continue;}
		num[cnt] = num[cnt]*10 + c - 48;
	}	
	for(int i = 0;i <= cnt;i++){
		if(op[i]) res += num[i]; 
		else res -= num[i];
	}
	printf("%d",res);
}

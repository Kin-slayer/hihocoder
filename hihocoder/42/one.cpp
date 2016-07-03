#include <iostream>
using namespace std;

const int mod = 12357;

int main()
{
	int num;
	cin >> num;
	if(num & 1){
		cout << 0 ;
		return 0;
	}
	if(num == 2){
		cout << 3 ;
		return 0;
	}
	num -= 2;
	int i = 3 ,j = 11,k = 11;
	while(num -= 2){
		k = (4*j - i) % mod;
		i = j;
		j = k;
	}

	cout << k ;
}


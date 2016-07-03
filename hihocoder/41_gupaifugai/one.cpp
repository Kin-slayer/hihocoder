#include <iostream>
using namespace std;

int main()
{
	int num;
	cin >> num;
	int i = 0,j = 1, k = 0;
	while (num--){
		k = (i + j)%19999997;	
		i = j;
		j = k;
	}
	cout << k << endl;
}


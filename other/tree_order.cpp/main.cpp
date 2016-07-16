#include <iostream>
#include <list>
#include <fstream>

using namespace std;
list<int> pre_order,mid_order;
list<int>::const_iterator target;

void f(list<int>::iterator b,list<int>::iterator e);

int main()
{
	ifstream is("input");
	int temp;
	while(true){
		is >> temp;
		if(temp == -1) break;
		pre_order.push_back(temp);
	}
	while(true){
		is >> temp;
		if(temp == -1) break;
		mid_order.push_back(temp);
	}

	target = pre_order.cbegin();
	f(mid_order.begin(),mid_order.end());

	for(auto val:mid_order)
		cout << val << " " ;

	cout << endl;

}

void f(list<int>::iterator b,list<int>::iterator e){
	list<int>::iterator iter = b ,flag = b;
	flag++;

	if(iter == e)
		return ;
	if(flag == e){
		target++;
		return;
	}

	while(iter != e){
		if(*iter == *target){
			e = mid_order.insert(e,*target);
			target++;
			if(iter == b)
				b++;
			iter = mid_order.erase(iter);

			f(b,iter);
			f(iter,e);
			break;
		}	
		iter++;
	}	
}


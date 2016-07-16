#include <iostream>
#include <list>
#include <fstream>
#include <stack>

using namespace std;

typedef struct iters_struct{
	list<int>::iterator b;
	list<int>::iterator e;
}Iters;

int main()
{
	list<int> pre_order,mid_order;
	ifstream is("input");
	int temp;
	list<int>::const_iterator target;
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

	stack<Iters> iters_stack;
	iters_stack.push({mid_order.begin(),mid_order.end()});

	while(!iters_stack.empty()){
		Iters iters = iters_stack.top();
		iters_stack.pop();

		list<int>::iterator iter = iters.b ,flag = iters.b;
		flag++;

		if(iter == iters.e)
			continue ;
		if(flag == iters.e){
			target++;
			continue ;
		}

		while(iter != iters.e){
			if(*iter == *target){
				iters.e = mid_order.insert(iters.e,*target);
				target++;
				if(iter == iters.b)
					iters.b++;
				iter = mid_order.erase(iter);

				iters_stack.push({iter,iters.e});
				iters_stack.push({iters.b,iter});
				break;
			}	
			iter++;
		}
	}

	for(auto val:mid_order)
		cout << val << " " ;

	cout << endl;

}

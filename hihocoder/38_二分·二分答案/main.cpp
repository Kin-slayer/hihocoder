#include<stdio.h>
#include<map>
#include<queue>
#include<memory.h>

using namespace std;

int N,M,K,T,u,v,w,cnt,l = 10000000,r;
int cost[10004],step[10004];
map<int,int> m[10004];
queue<int> que;

int max(int x,int y){return x>y?x:y;}
int min(int x,int y){return x<y?x:y;}

int query(int awnser){
	memset(cost,0,sizeof(cost));
	memset(step,0,sizeof(step));
	que.push(1);
	int now;
	while(!que.empty()){
		now = que.front();
		que.pop();
		if (step[now] + 1 > K) continue;
		for (map<int,int>::iterator it = m[now].begin();it!=m[now].end(); ++it){
			if (cost[it->first] && cost[it->first] <  cost[now]) continue;
			if (it->second > awnser) continue;
			cost[it->first] = max(cost[now],it->second);
			step[it->first] = step[now] + 1;
			que.push(it->first);
		}
	}
	if (cost[T]) return 1;
	return 0;
}

int main(){
	scanf("%d%d%d%d",&N,&M,&K,&T);
	while(M--){
		scanf("%d%d%d",&u,&v,&w);
		l = min(l,w);
		r = max(r,w);
		if( m[u][v]==0 || m[u][v] > w )
            m[u][v] = w;
        m[v][u] = m[u][v];
	}
	while(r != l){
		if (query(l+r>>1)) r = l+r>>1;
		else l = (l+r>>1)+1;
	}
	printf("%d\n",l);
}
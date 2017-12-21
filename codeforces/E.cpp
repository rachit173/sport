#include<bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define pb(x) push_back(x)
#define N 200006
#define cout2(x, y) cout << x << " " << y << endl
 
#define MAXLOG 18
 
using namespace std;
 
vector<int>L[N], W[N];
int des[N], fin[N], timer;
 
int P[N][MAXLOG], level[N];
long long AC[N];
 
void DFS(int u, int pd, int l, long long acum){
	
	if(des[u] != -1)return;
	des[u] = timer++;
	
	level[u] = l;
	AC[u] = acum;
	
	P[u][0] = pd;
	
	for(int i = 1; (1<<i) <= l; i++)
		P[u][i] = P[P[u][i - 1]][i - 1];
	
	for(int i = 0; i < L[u].size(); i++){
		
		int v = L[u][i];
		int w = W[u][i];
		
		if(v == pd)continue;
		DFS(v, u, l + 1, acum + w);
		
	}
	
	fin[u] = timer++;
}
 
int getLCA(int u, int v){
	
	if(u == v)return u;
	if(level[u] < level[v])swap(u, v);	
	
	if(level[u] != level[v]){
		
		for(int i = MAXLOG - 1; i >= 0; i--)
			if(level[P[u][i]] > level[v])u = P[u][i];
			
		u = P[u][0];
	}
	
	if(u == v)return u;
	
	for(int i = MAXLOG - 1; i >= 0; i--)
		if(P[u][i] != P[v][i])u = P[u][i], v = P[v][i];
			
	return P[u][0];
}
 
 
long long tree[2 * N];
long long query(int x){
		
	long long ans = 0;
	for(int i = x; i > 0; i -= i&-i)ans ^= tree[i];
	return ans;
}
 
void update(int x, int val){
	
	for(int i = x; i < 2 * N; i += i&-i)tree[i] ^= val;	
}
 
int E[N];
pair<int, int>par[N];
 
 
long long solve(int u, int v){
	
	//int lca = getLCA(u, v);
	
	/*cout2("lca: ", lca);
	cout2(query(u), query(v));
	cout2("query : ", query(lca));*/
	long long ans = AC[u]^AC[v];
 
	ans ^= query(des[u])^query(des[v]);
	return ans;
}
 
 
int main(){
 
	int n, m;
    int T;
    cin>>T;
	while(scanf("%d", &n) == 1){
 
		for(int i = 0; i < n; i++)L[i].clear(), W[i].clear();
		
		int u, v, w;
        int edge[n-1];
		for(int i = 0; i < n - 1; i++){
		
			scanf("%d%d%d", &u, &v, &w);
			u--, v--;
			edge[i]=w;
            L[u].pb(v);
			L[v].pb(u);
			
			W[u].pb(w);
			W[v].pb(w);
			
			E[i] = w;
			par[i] = make_pair(u, v);
		}
 
 
		memset(des, -1, sizeof des);
		timer = 0;
 
		DFS(0, 0, 0, 0);
 
		int m, x, y, op, add;
		scanf("%d", &m);
		
		for(int i = 0; i < m; i++){
			
			scanf("%d%d%d", &op, &x, &y);
			x--;
 
			if(op == 1){
				
				add = y ^ E[x];
				E[x] ^= add;
				
				u = par[x].first;
				v = par[x].second;
				
				if(level[u] < level[v])swap(u, v);
				
				update(des[u], add);
				update(fin[u] + 1, add);	
			}
			else{
				
				y--;
				printf("%lld\n", solve(x, y));	
			}
		}
		
	}	
}
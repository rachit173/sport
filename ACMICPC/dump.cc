bool mark[MAXN];
void dijkstra(int v){
	fill(d,d + n, inf);
	fill(mark, mark + n, false);
	d[v] = 0;
	int u;
	priority_queue<pair<int,int>,vector<pair<int,int> >, less<pair<int,int> > > pq;
	pq.push({d[v], v});
	while(!pq.empty()){
		u = pq.top().second;
		pq.pop();
		if(mark[u])
			continue;
		mark[u] = true;
		for(auto p : adj[u]) //adj[v][i] = pair(vertex, weight)
			if(d[p.first] > d[u] + p.second){
				d[p.first] = d[u] + p.second;
				pq.push({d[p.first], p.first});
			}
	}
}

/---------------------------------------------------------------------------------
finding euler tour
vector E
dfs (v):
        color[v] = gray
        for u in adj[v]:
                erase the edge v-u and dfs(u)
        color[v] = black
        push v at the end of e

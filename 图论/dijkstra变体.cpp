// hdoj3873
// 某些点只有经过其他点才能通过，一次可以同时往多个方向走，问到某点的最短时间
// 直接修改入队条件，类似拓扑排序，入度为0则可以入队
/*
void dijkstra(int s,int ed){
    int ans=0;
    memset(vis,0,sizeof(vis));
    memset(dis,0x3f,sizeof(dis));
    priority_queue<pii,vector<pii>,greater<pii> > que;
    dis[s]=0;
    que.push(make_pair(0,s));
    while(!que.empty()){
        int p=que.top().second;que.pop();
        if(vis[p]) continue;
        vis[p]=true;
        dis[p]=max(dis[p],ans);
        ans=dis[p];
        if(p==ed) return;
        for(auto x:vec[p]){
            ind[x]--;
            if(ind[x]==0) que.push(make_pair(dis[x],x));
        }
        for(int i=head[p];i;i=edges[i].next){
            if(!vis[edges[i].to]){
                dis[edges[i].to]=min(dis[p]+edges[i].w,dis[edges[i].to]);
                if(ind[edges[i].to]==0) que.push(make_pair(dis[edges[i].to],edges[i].to));
            }
        }
    }
}
void solve(){
    int n,m;cin>>n>>m;
    for(int i=1;i<=m;i++){
        int a,b,c;cin>>a>>b>>c;
        add(a,b,c);
    }
    for(int i=1;i<=n;i++){
        int k;cin>>k;
        ind[i]=k;
        for(int j=0;j<k;j++){
            int x;cin>>x;
            vec[x].push_back(i);
        }
    }
    dijkstra(1,n);
    cout<<dis[n]<<endl;
}
*/
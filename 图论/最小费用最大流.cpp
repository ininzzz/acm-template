/*


// n=5e3,m=5e4的随机数据洛谷上跑了600ms
// 人工构造的数据建议用dijkstra
// 算法本质是流量在每条增广路上处处相等，所以只需要跑一个费用的最短路然后乘起来就是这条增广路上的花费，然后把所有增广路上的花费加起来就是最小花费了



struct Edge{
    int to, flow,w,next;
}edges[2*MAXM];
int head[MAXN],cnt=1;
void add(int u,int v,int f,int w){
    edges[++cnt].w=w;
    edges[cnt].flow=f;
    edges[cnt].to=v;
    edges[cnt].next=head[u];
    head[u]=cnt;
}

int dis[MAXN],vis[MAXN],incf[MAXN];
int pre[MAXN];
bool SPFA(int s,int t){
    queue<int> que;
    memset(dis,0x3f,sizeof(dis));
    memset(vis,0,sizeof(vis));
    que.push(s);
    dis[s]=0;vis[s]=true;incf[s]=INF;
    while(!que.empty()){
        int u=que.front();
        vis[u]=false;
        que.pop();
        for(int i=head[u];i;i=edges[i].next){
            if(!edges[i].flow) continue;
            int v=edges[i].to;
            if(dis[v]>dis[u]+edges[i].w){
                dis[v]=dis[u]+edges[i].w;
                incf[v]=min(incf[u],edges[i].flow);
                pre[v]=i;
                if(!vis[v]) vis[v]=true,que.push(v);
            }
        }
    }
    if(dis[t]==INF) return 0;
    return 1;
}

pii MCMF(int s,int t){
    int maxflow=0,mincost=0;
    while(SPFA(s,t)){
        int x=t;
        maxflow+=incf[t];
        mincost+=dis[t]*incf[t];
        while(x!=s){
            int i=pre[x];
            edges[i].flow-=incf[t];
            edges[i^1].flow+=incf[t];
            x=edges[i^1].to;
        }
    }
    return make_pair(maxflow,mincost);
}

void solve(){
    int n=read(),m=read(),s=read(),t=read();
    for(int i=0;i<m;i++){
        int a=read(),b=read(),c=read(),d=read();
        add(a,b,c,d);
        add(b,a,0,-d);
    }
    pii ans=MCMF(s,t);
    cout<<ans.first<<" "<<ans.second<<endl;
}

*/
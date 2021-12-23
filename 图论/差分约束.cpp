/*

// SPFA判负环，如果存在负环，则说明无解
// 如果u+x>=v，那么add(u,v,x)
// 0作为超级源点，保证图的连通性(先跑SPFA(确保连通性))
// dis[n]即为a_n-a_m的最大值(跑SPFA(m))

struct Edge{
    int to,w,next;
}edges[MAXN];
int head[MAXN],cnt=0;
void add(int u,int v,int w){
    edges[++cnt].w=w;
    edges[cnt].to=v;
    edges[cnt].next=head[u];
    head[u]=cnt;
}

bool inqueue[MAXN];
int dis[MAXN],quecnt[MAXN];
int n,m;
bool SPFA(int s){
    memset(dis,0x3f,sizeof(dis));
    memset(inqueue,0,sizeof(inqueue));
    memset(quecnt,0,sizeof(quecnt));
    queue<int> que;
    dis[s]=0;
    que.push(s);
    while(!que.empty()){
        int p=que.front();que.pop();
        inqueue[p]=false;
        for(int i=head[p];i;i=edges[i].next){
            if(edges[i].w+dis[p]<dis[edges[i].to]){
                dis[edges[i].to]=edges[i].w+dis[p];
                quecnt[edges[i].to]=quecnt[p]+1;
                if(quecnt[edges[i].to]>n){
                    return false;
                }
                if(!inqueue[edges[i].to]){
                    que.push(edges[i].to);
                    inqueue[edges[i].to]=true;
                }
            }
        }
    }
    return true;
}

void solve(){
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int a,b,c;cin>>a>>b>>c;
        add(b,a,c);
    }
    for(int i=1;i<=n;i++){
        add(0,i,0);
    }
    if(!SPFA(0)){
        cout<<"NO\n";
        return;
    }
    else{
        for(int i=1;i<=n;i++){
            cout<<dis[i]<<" ";
        }
        cout<<endl;
    }
}

*/
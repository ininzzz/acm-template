/*
struct Edge{
    int u,v,w;
}edges[MAXN];
int cnt=0;
void add(int u,int v,int w){
    edges[++cnt].u=u;
    edges[cnt].v=v;
    edges[cnt].w=w;
}

int cmp(Edge a,Edge b){
    return a.w<b.w;
}

int kruskal(int n){
    sort(edges+1,edges+cnt+1,cmp);
    init(n);
    int res=0;
    for(int i=1;i<=cnt;i++){
        Edge e=edges[i];
        if(!same(e.u,e.v)){
            res+=e.w;
            unite(e.u,e.v);
        }
    }
    return res;
}
*/
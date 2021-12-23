/*

// scc[i]: 第i个点对应的强连通分量序号
// sz[i]: 第i个强连通分量的大小

经典问题：
1. 1个消息可以沿路径扩散到所有路径上的点，问至少多少个消息可以扩散全图
对所有的强连通分量缩点，然后找入度为0的点的个数

2. 最少添加多少条边可以使得原图变为一个强连通图
对所有的强连通分量缩点，然后找入读为0的点和出度为0的点个数的最大值
即ans=max(in_cnt,out_cnt);

stack<int> stk;
int dfsn[MAXN],low[MAXN],instk[MAXN],scc[MAXN];
int sz[MAXN];
int cdfs,cscc;

void tarjan(int u){
    low[u]=dfsn[u]=++cdfs;
    instk[u]=1;
    stk.push(u);
    for(int i=head[u];i;i=edges[i].next){
        int v=edges[i].to;
        if(!dfsn[v]){
            tarjan(v);
            low[u]=min(low[u],low[v]);
        }
        else if(instk[v]) low[u]=min(low[u],dfsn[v]);
    }
    if(low[u]==dfsn[u]){
        cscc++;
        while(true){
            int temp=stk.top();stk.pop();instk[temp]=0;
            scc[temp]=cscc;
            sz[cscc]++;
            if(temp==u) break;
        }
    }
}

*/
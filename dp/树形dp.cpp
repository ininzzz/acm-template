/*
// 给定一颗树，每个结点只有0或2个儿子，现在需要保留m个条边，其余边全部删去，每个边有一个权值，问保留的权值最大值？(注意删去某一条边后去后继的边全部会被删去)
// dfs后进行dp，dp[u][i]代表以u为子树保留m条边的最大收益
// 其实可以看成分组背包，每个分支作为一个组，每个组枚举选取个数作为重量

void dfs(int u,int fa){
    int ans=0;
    for(int i=head[u];i;i=edges[i].next){
        int v=edges[i].to;
        if(v==fa) continue;
        dfs(v,u);
    }
    for(int i=head[u];i;i=edges[i].next){
        int v=edges[i].to;
        if(v==fa) continue;
        for(int j=m;j>=1;j++){
            for(int k=0;k<sz[v];k++){
                dp[u][j]=max(dp[u][j],dp[u][j-wt[k]]+val[k])
            }
        }
    }
}

// 换根dp
// 自底向上dp
void dfs1(int u,int fa){
    for(int i=head[u];i;i=edges[i].next){
        int v=edges[i].to;
        if(v==fa) continue;
        dfs1(v,u);
        dp1[u]+=dp1[v]+edges[i].w;
    }
}

// 自顶向下dp
void dfs2(int u,int fa){
    for(int i=head[u];i;i=edges[i].next){
        int v=edges[i].to;
        if(v==fa) continue;
        dp1[v]=dp1[u]+(edges[i].w?-1:1);
        dfs2(v,u);
    }
}
*/
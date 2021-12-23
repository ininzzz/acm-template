/*


dsu on tree的本质就是暴力统计每个子树的所有结点对答案的贡献
同时保留重儿子对应的结点，然后拿轻儿子的贡献合并上去
这样可以减少统计重儿子的时间，体现在cal函数中v==son就continue上

int sz[MAXN],hson[MAXN];
int dep[MAXN];
void dfs1(int u,int fa){
    dep[u]=dep[fa]+1;sz[u]=1;
    int temp=0;
    for(int i=head[u];i;i=edges[i].next){
        int v=edges[i].to;
        if(v==fa) continue;
        dfs1(v,u);
        sz[u]+=sz[v];
        if(sz[v]>temp){
            temp=sz[v];
            hson[u]=v;
        }
    }
}

int nowans,son,mx;
int ans[MAXN];
int cntt[MAXN][26];
char ch[MAXN];
vector<pii> q[MAXN];
void cal(int u,int fa,int val){
    cntt[dep[u]][ch[u]-'a']+=val;
    for(int i=head[u];i;i=edges[i].next){
        int v=edges[i].to;
        if(v==fa||v==son) continue;
        cal(v,u,val);
    }
}

void dfs2(int u,int fa,bool keep){
    for(int i=head[u];i;i=edges[i].next){
        int v=edges[i].to;
        if(v==fa||v==hson[u]) continue;
        dfs2(v,u,false);
    }
    if(hson[u]){
        dfs2(hson[u],u,true);
        son=hson[u];
    }
    cal(u,fa,1);
    son=0;
    for(auto x:q[u]){
        int temp=0;
        for(int i=0;i<26;i++){
            if(cntt[x.first][i]&1) temp++;
        }
        if(temp<=1) ans[x.second]=1;
        else ans[x.second]=0;
    }
    if(!keep){
        cal(u,fa,-1);
    }
}

*/
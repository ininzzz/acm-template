/*
第一遍dfs确定f,dep,sz,hson
第二遍优先遍历重儿子，确定时间戳以及链顶点
int n,m,r,p;
int hson[MAXN],id[MAXN],sz[MAXN],dep[MAXN],f[MAXN];
int val[MAXN],top[MAXN];
int idcnt=0;

void dfs1(int u,int fa){
    f[u]=fa;
    dep[u]=dep[fa]+1;
    sz[u]=1;
    int temp=0;
    for(int i=head[u];i;i=edges[i].next){
        if(edges[i].to==fa) continue;
        dfs1(edges[i].to,u);
        sz[u]+=sz[edges[i].to];
        if(sz[edges[i].to]>temp){
            temp=sz[edges[i].to];
            hson[u]=edges[i].to;
        }
    }
}

void dfs2(int u,int tp,int fa){
    id[u]=++idcnt;
    number[idcnt]=val[u];
    top[u]=tp;
    if(!hson[u]) return;
    dfs2(hson[u],tp,u);
    for(int i=head[u];i;i=edges[i].next){
        if(edges[i].to==hson[u]||edges[i].to==fa) continue;
        dfs2(edges[i].to,edges[i].to,u);
    }
}

//O(logn^2)
void updpath(int x,int y,int z){
    //深度大的点向上跑，直到两个点在一条链
    while(top[x]!=top[y]){
        if(dep[top[x]]<dep[top[y]]) swap(x,y);
        update(1,id[top[x]],id[x],z);
        x=f[top[x]];
    }
    //同一条链区间搞一搞
    if(dep[x]<dep[y]) swap(x,y);
    update(1,id[y],id[x],z);
}

int qpath(int x,int y){
    int ans=0;
    while(top[x]!=top[y]){
        if(dep[top[x]]<dep[top[y]]) swap(x,y);
        ans+=query(1,id[top[x]],id[x]);
        x=f[top[x]];
    }
    if(dep[x]<dep[y]) swap(x,y);
    ans+=query(1,id[y],id[x]);
    return ans;
}

void updtree(int x,int y){
    update(1,id[x],id[x]+sz[x]-1,y);
}

int qtree(int x){
    return query(1,id[x],id[x]+sz[x]-1);
}

void solve(){
    cin>>n>>m>>r>>p;
    for(int i=1;i<=n;i++){//点权
        val[i]=read();
    }
    for(int i=1;i<n;i++){//连边
        int a,b;a=read();b=read();
        add(a,b,1);
        add(b,a,1);
    }
    //两遍dfs
    dfs1(r,0);
    dfs2(r,r,0);
    //开线段树
    build(1,1,n);
    for(int i=0;i<m;i++){
        int opt;opt=read();
        if(opt==1){
            int a,b,c;a=read();b=read();c=read();
            updpath(a,b,c);
        }
        else if(opt==2){
            int a,b;a=read();b=read();
            print(qpath(a,b)%p);
            putchar('\n');
        }
        else if(opt==3){
            int a,b;a=read();b=read();
            updtree(a,b);
        }
        else if(opt==4){
            int a;a=read();
            print(qtree(a)%p);
            putchar('\n');
        }
    }
}



*/
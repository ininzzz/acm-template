/*

int par[MAXN];
void init(int n){
    for(int i=0;i<=n;i++) par[i]=i;
}
int find(int n){
    if(par[n]==n) return n;
    return par[n]=find(par[n]);
}
bool same(int x,int y){
    return find(x)==find(y);
}
void unite(int x,int y){
    x=find(x);y=find(y);
    if(x==y) return;
    par[y]=x;
}

*/
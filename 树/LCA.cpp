/*
int depth[MAXN],fa[MAXN][22],lg[MAXN];
void init(int n){
	for(int i=1;i<=n;++i)
		lg[i]=lg[i-1]+(1<<lg[i-1]==i);
}
void dfs(int now,int fath) {
	fa[now][0]=fath;depth[now]=depth[fath]+1;
	for(int i=1;i<=lg[depth[now]];++i)
		fa[now][i]=fa[fa[now][i-1]][i-1];
	for(int i=head[now]; i; i=edges[i].next)
		if(edges[i].to!=fath) dfs(edges[i].to,now);
}
int LCA(int x,int y) {
	if(depth[x]<depth[y]) swap(x,y);
	while(depth[x]>depth[y])
		x=fa[x][lg[depth[x]-depth[y]]-1];
	if(x==y) return x;
	for(int k=lg[depth[x]]-1;k>=0;--k)
		if(fa[x][k]!=fa[y][k])
			x=fa[x][k],y=fa[y][k];
	return fa[x][0];
}
*/
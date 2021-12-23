/*

1. 树的直径(POJ1985)
做两遍DFS,第一趟找到一个叶节点，第二趟从叶节点找到一个最远的叶节点构成直径
int d[MAXN];
void dfs(int u,int fa){
    for(int i=head[u];i;i=edges[i].next){
        if(edges[i].to==fa) continue;
        d[edges[i].to]=d[u]+edges[i].w;
        dfs(edges[i].to,u);
    }
}
int TreeDiameter(int n){
    dfs(1,0);
    int ans=0,id=0;
    for(int i=1;i<=n;i++){
        if(d[i]>ans){
            id=i;ans=d[i];
        }
        d[i]=0;
    }
    dfs(id,0);
    for(int i=1;i<=n;i++) ans=max(ans,d[i]);
    return ans;
}


2. 树的重心(POJ1655)
考虑从dfs方向求得子树的和sum以及最大子树的大小
然后和dfs反方向的结点数(n-sum)比较，找一个最大值ans存到num中
最后遍历num找到对应的重心编号和重心对应的结点数

int num[MAXN];
int dfs(int u,int fa){
    int ans=0,sum=1;
    for(int i=head[u];i;i=edges[i].next){
        if(edges[i].to==fa) continue;
        int temp=dfs(edges[i].to,u);
        sum+=temp;
        ans=max(ans,temp);
    }
    num[u]=max(ans,n-sum);
    return sum;
}

// 将两棵树x和y合并后的直径最小是多少
// ans=max{ceil(d[x]/2)+ceil(d[y]/2)+1,d[x],d[y]}

*/
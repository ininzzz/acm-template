/*
int ind[MAXN];
int topo_ans[MAXN];
bool topo(int n){
    queue<int> que;
    for(int i=1;i<=n;i++){
        if(ind[i]==0){
            que.push(i);
        }
    }
    int cnt=0;
    while(!que.empty()){
        int x=que.front();que.pop();
        topo_ans[cnt++]=x;
        for(int i=head[x];i;i=edges[i].next){
            if(--ind[edges[i].to]==0){
                que.push(edges[i].to);
            }
        }
    }
    return cnt==n;
}
*/
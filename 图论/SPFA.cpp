// struct Edge{
//     int to,w,next;
// }edges[MAXN];
// int head[MAXN],cnt=0;
// void add(int u,int v,int w){
//     edges[++cnt].w=w;
//     edges[cnt].to=v;
//     edges[cnt].next=head[u];
//     head[u]=cnt;
// }

// bool inqueue[MAXN];
// int dis[MAXN];
// void SPFA(int s){
//     memset(dis,INF,sizeof(dis));
//     memset(inqueue,0,sizeof(inqueue));
//     queue<int> que;
//     dis[s]=0;
//     que.push(s);
//     while(!que.empty()){
//         int p=que.front();que.pop();
//         inqueue[p]=false;
//         for(int i=head[p];i;i=edges[i].next){
//             if(edges[i].w+dis[p]<dis[edges[i].to]){
//                 dis[edges[i].to]=edges[i].w+dis[p];
//                 if(!inqueue[edges[i].to]){
//                     que.push(edges[i].to);
//                     inqueue[edges[i].to]=true;
//                 }
//             }
//         }
//     }
// }
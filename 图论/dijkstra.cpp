#include<iostream>
#include<stdio.h>
#include<vector>
#include<iomanip>
#include<algorithm>
#include<cstring>
#include<set>
#include<sstream>
#include<map>
#include<queue>
#include<math.h>
using namespace std;

#define INF 0x3f3f3f3f
const int MAXN=1e5+10;
typedef pair<int,int> pii;

struct Edge{
    int to,w,next;
}edges[MAXN];
int head[MAXN],cnt=0;
void add(int u,int v,int w){
    edges[++cnt].w=w;
    edges[cnt].to=v;
    edges[cnt].next=head[u];
    head[u]=cnt;
}
bool vis[MAXN];
int dis[MAXN];
void dijkstra(int s){
    memset(vis,0,sizeof(vis));
    memset(dis,INF,sizeof(dis));
    priority_queue<pii,vector<pii>,greater<pii> > que;
    dis[s]=0;
    que.push(make_pair(0,s));
    while(!que.empty()){
        int p=que.top().second;que.pop();
        if(vis[p]) continue;
        vis[p]=true;
        for(int i=head[p];i;i=edges[i].next){
            int v=edges[i].to;
            if(!vis[v]){
                dis[v]=min(dis[p]+edges[i].w,dis[v]);
                que.push(make_pair(dis[v],v));
            }
        }
    }
}
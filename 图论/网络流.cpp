#include<iostream>
#include<stdio.h>
#include<vector>
#include<iomanip>
#include<algorithm>
#include<cstring>
#include<set>
#include<map>
#include<queue>
#include<math.h>
#include<stack>
#include<bitset>
using namespace std;

#define INF 0x3f3f3f3f3f3f3f3f
#define IO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define debug(x) cout<<#x<<": "<<x<<endl
#define gcd __gcd
#define double long double
#define int long long
#define endl '\n'

const int MAXN = 200+10;
const int MOD = 998244353;
const int MAXnum = 2e5;
const double eps = 1e-8;
const double inf = 1e20;
const double PI = acos(-1);
typedef pair<int, int> pii;

inline int read(){
   int s=0,w=1;
   char ch=getchar();
   while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
   while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
   return s*w;
}
inline void print(int x){
    if(x < 0) putchar('-'), x = x;
    if(x > 9) print(x / 10);
    putchar(x % 10 + '0');
}

struct Edge{
    int to,w,next;
}edges[10010];
int head[MAXN],cnt=1;
void add(int u,int v,int w){
    edges[++cnt].w=w;
    edges[cnt].to=v;
    edges[cnt].next=head[u];
    head[u]=cnt;
}

int dis[MAXN],now[MAXN];
int s,t;
int bfs() {
	memset(dis,0x3f,sizeof(dis));
	queue<int> q;
	q.push(s);
	dis[s]=0;
	now[s]=head[s];
	while(!q.empty()) {
		int x=q.front();
		q.pop();
		for(int i=head[x];i;i=edges[i].next) {
			int v=edges[i].to;
			if(edges[i].w>0&&dis[v]==INF) {
				q.push(v);
				now[v]=head[v];
				dis[v]=dis[x]+1;
				if(v==t) return 1;
			}
		}
	}
	return 0;
}

int dfs(int x,int sum) {
	if(x==t) return sum;
	int k,res=0;
	for(int i=now[x];i&&sum;i=edges[i].next) {
		now[x]=i;
		int v=edges[i].to;
		if(edges[i].w>0&&(dis[v]==dis[x]+1)) {
			k=dfs(v,min(sum,edges[i].w));
			if(k==0) dis[v]=INF;
			edges[i].w-=k;
			edges[i^1].w+=k;
			res+=k;
			sum-=k;
		}
	}
	return res;
}

void solve(){
    int n,m;cin>>n>>m>>s>>t;
    for(int i=0;i<m;i++){
        int a,b,c;cin>>a>>b>>c;
        add(a,b,c);
        add(b,a,0);
    }
    int ans=0;
    while(bfs()){
        ans+=dfs(s,INF);
    }
    cout<<ans<<endl;
}

signed main(){
    IO;
    // freopen("1.in","r",stdin);
    // freopen("1.out","w",stdout);
    int t=1;
    // cin>>t;
    while(t--){
        solve();
    }
    return 0;
}
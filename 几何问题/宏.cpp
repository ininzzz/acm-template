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
#include<ctime>
#include<list>
using namespace std;

#define INF 0x3f3f3f3f
#define IO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define debug(x) cout<<#x<<": "<<x<<endl
#define sf(x) scanf("%d",&(x))
#define gcd __gcd
#define random(a,b) (rand()%(b-a)+a)
#define isrun cout<<"ok\n"
#define double long double
#define int long long

const int MAXN = 4e5+10;
const int TestN = 1e5;
const int MOD = 998244353;
const int MAXnum = 1e9;
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
inline void print(int x) {
    if(x < 0) putchar('-'), x = -x;
    if(x > 9) print(x / 10);
    putchar(x % 10 + '0');
}

void solve(){
    
}

signed main(){
    int t=1;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}
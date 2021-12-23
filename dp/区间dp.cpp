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
#include<stack>
#include<fstream>
#include<list>
using namespace std;

#define MAXN 100 + 10
#define MAXNN 2000+5
#define INF 0x3f3f3f3f
#define MOD 1000000007
#define IO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define ll long long
#define debug(x) cout<<"debug: "<<(x)<<endl
#define sf(x) scanf("%d",&(x))
const int MAXint = 2147483647;
const double eps = 1e-6;
const double inf = 1e20;
typedef pair<int, int> P;


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

int number[MAXN];
int sum[MAXN];
int dp[MAXN][MAXN];
int n;
int dfs(int i,int j){
    if(i==j) return 0;
    if(dp[i][j]!=0) return dp[i][j];
    int ans=INF;
    for(int k=i;k<=j-1;k++){
        int temp=dfs(i,k)+dfs(k+1,j)+sum[j]-sum[i-1];       
        ans=min(ans,temp);
    }
    return dp[i][j]=ans;
}

int main()
{
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>number[i];
        number[i+n]=number[i];
    }
    for(int i=1;i<=n;i++){
        sum[i]=number[i]+sum[i-1];
    }
    cout<<dfs(1,n)<<endl;
    return 0;
}
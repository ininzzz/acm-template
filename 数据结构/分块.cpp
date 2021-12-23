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
using namespace std;

#define MAXN 2000000+5
#define MAXNN 2000+5
#define INF 0x3f3f3f3f
#define MOD 10000007
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


int st[MAXNN];
int ed[MAXNN];
int bel[MAXN];
int number[MAXN];
int mark[MAXNN];

void init(int n){
    int num=sqrt(n);
    for(int i=1;i<=num;i++){
        st[i]=n/num*(i-1)+1;
        ed[i]=n/num*i;
    }
    ed[num]=n;
    for(int i=1;i<=num;i++){
        for(int j=st[i];j<=ed[i];j++){
            bel[j]=i;
        }
        sort(number+st[i],number+ed[i]+1);
    }
}

void add(int l,int r,int k){
    int a=bel[l];
    int b=bel[r];
    if(a==b){
        for(int i=l;i<=r;i++){
            number[i]+=k;
        }
    }
    else{
        for(int i=l;i<=ed[a];i++){
            number[i]+=k;
        }
        sort(number+st[a],number+ed[a]+1);
        for(int i=st[b];i<=r;i++){
            number[i]+=k;
        }
        sort(number+st[b],number+ed[b]+1);
        for(int i=a+1;i<=b-1;i++){
            mark[i]+=k;
        }
    }
}


int query(int l,int r,int k){
    int a=bel[l];
    int b=bel[r];
    int cnt=0;
    if(a==b){
        for(int i=l;i<=r;i++){
            if(number[i]+mark[a]>=k){
                cnt++;
            }
        }
        return cnt;
    }
    else{
        for(int i=l;i<=ed[a];i++){
            if(number[i]+mark[a]>=k){
                cnt++;
            }
        }
        for(int i=st[b];i<=r;i++){
            if(number[i]+mark[b]>=k){
                cnt++;
            }
        }
        for(int i=a+1;i<=b-1;i++){
            cnt+=(number+ed[i]+1-lower_bound(number+st[i],number+ed[i]+1,k-mark[i]));
        }
    }
    return cnt;
}


int main(){
    int n,m;
    n=read();m=read();
    for(int i=1;i<=n;i++){
        number[i]=read();
    }
    init(n);
    for(int i=1;i<=m;i++){
        char x;int a,b,c;
        scanf(" %c",&x);a=read();b=read();c=read();
        if(x=='M'){
            add(a,b,c);
        }
        else{
            printf("%d\n",query(a,b,c));
        }
    }
    system("pause");
    return 0;
}
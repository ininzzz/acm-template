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

#define MAXN 100000 + 5
#define INF 0x3f3f3f3f
#define MOD 10000000 + 7
#define IO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
const int MAXint = 2147483647;
const double eps = 1e-6;
const double inf = 1e20;
typedef pair<int, int> P;

int number[20];
int ans[20][2];


int dfs(int p,bool limit,int pre,int sta){
    if(p<0) return 1;
    if(!limit&&ans[p][sta]!=-1) return ans[p][sta];
    int up=limit?number[p]:9;
    int anss=0;
    for(int i=0;i<=up;i++){
        if(i==4) continue;
        if(pre==6&&i==2) continue;
        anss+=dfs(p-1,limit&&i==up,i,i==6);
    }
    if(!limit) ans[p][sta]=anss;
    return anss;
}

int solve(int n){
    memset(ans,-1,sizeof(ans));
    memset(number,0,sizeof(number));
    int cnt=0;
    int x=n;
    while(n){
        number[cnt++]=n%10;
        n/=10;
    }
    return dfs(cnt-1,true,0,0);
}

int main(){
    IO;
    int n,m;
    while(cin>>n>>m){
        if(n==0&&m==0) break;
        cout<<solve(m)-solve(n-1)<<endl;
    }
    system("pause");
    return 0;
}
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
#define MAXN 56000 + 5
#define INF 0x3f3f3f3f
const int MAXint=2147483647;
typedef pair<int,int> P;

int n;
int num[MAXN];
struct ST{
    int dp[MAXN][25];
    void init(){
        for(int i=0;i<n;i++){
            dp[i][0]=num[i];
        }
        for(int j=1;j<=__lg(n);j++){
            for(int i=0;i+(1<<j)-1<n;i++){
                dp[i][j]=max(dp[i][j-1],dp[i+(1<<j-1)][j-1]);
            }
        }
    }
    int query(int l,int r){
        int j=__lg(r-l+1);
        return max(dp[l][j],dp[r-(1<<j)+1][j]);
    }
}st;
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

#define MAXN 100000010
#define INF 0x3f3f3f3f
#define MOD 10000000 + 7
#define ll long long
#define INF2 0x3f3f3f3f
const int MAXint = 2147483647;
const int SMint = 130;
const double eps = 1e-6;
const double inf = 1e20;
typedef pair<int, int> P;

//n=(p1^k1)*(p2^k2)*···
//phi(n)=n*((p1-1)/p1)*((p2-1)/p2)*···


int n;
int phi(int n){
    int ans=n;
    for(int i=2;i*i<=n;i++){
        if(n%i==0)
            ans=ans/i*(i-1);
        while(n%i==0)
            n/=i;
    }
    if(n>1)
        ans=ans/n*(n-1);
    return ans;
}

int main(){
    //ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    while(scanf("%d",&n)!=EOF){
        if(n==0) break;
        printf("%d\n",phi(n));
    }
    system("pause");
    return 0;
}




/*

线性筛的同时求欧拉函数

int prime[MAXN];
bool isnp[MAXN];
int phi[MAXN];
int euler(int n){
    int cnt=0;phi[1]=1;
    for(int i=2;i<=n;i++){
        if(!isnp[i]){
            prime[cnt++]=i;
            phi[i]=i-1;
        }  
        for(int j=0;j<cnt;j++){
            if(prime[j]*i>n)
                break;
            isnp[prime[j]*i]=true;
            if(i%prime[j]==0){
                phi[prime[j]*i]=phi[i]*prime[j];
                break;
            }
            else{
                phi[prime[j]*i]=phi[prime[j]]*phi[i];
            }
                
        }
    }
    return cnt;
}
*/
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


//相对于埃氏筛，通过规定最小素因子的方法避免重复筛素数
//对于一个合数x=pr来说，一定存在一个最小素因子，所以从之前筛得的素数开始遍历，并依次筛去
//如果prime[j]|i，说明i存在大小为prime[j]的素因子，所以对于之后的素因子都不是最小的，应该brea
//euler()返回筛完后的素数个数，即prime[]的大小
//模板题洛谷P3383
vector<int> prime;
bool isnp[MAXN];
void euler(int n){
    isnp[1]=isnp[0]=true;
    for(int i=2;i<=n;i++){
        if(!isnp[i])
            prime.push_back(i);
        for(int j=0;j<prime.size();j++){
            if(prime[j]*i>n) break;
            isnp[prime[j]*i]=true;
            if(i%prime[j]==0) break;
        }
    }
    return;
}

int main(){
    //ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n,q;cin>>n>>q;
    euler(n);
    for(int i=0;i<q;i++){
        int x;cin>>x;
        cout<<prime[x-1]<<'\n';
    }
    system("pause");
    return 0;
}
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

#define MAXN 500000
#define INF 0x3f3f3f3f
#define MOD 10000000 + 7
#define ll long long
#define INF2 0x3f3f3f3f
const int MAXint = 2147483647;
const int SMint = 130;
const double eps = 1e-6;
const double inf = 1e20;
typedef pair<int, int> P;


//k门课，学分为ai的学科有bi个,求学分为n的组合数
//模板题hdu2079
//第一次for循环存第一个括号的系数
//第二次的第一层for循环代表第i个括号，第二层枚举第i-1个括号的系数，第三层把第i个括号和第i-1个括号的多项式乘起来
//j+k*a[i]是乘积的系数，+=c1[j]是增加的系数，因为第i个括号的系数一般都为1，实际上是c1[j]*1

int t,n,k;
int c1[MAXN],c2[MAXN];
int a[10],b[10];

int mufunc(){
    memset(c1,0,sizeof(c1));
    memset(c2,0,sizeof(c2));
    for(int i=0;i<=b[0];i++){
        c1[i*a[0]]=1;
    }
    for(int i=1;i<k;i++){
        for(int j=0;j<=n;j++){
            if(c1[j]){
                for(int k=0;k<=b[i]&&j+k*a[i]<=n;k++){
                    c2[j+k*a[i]]+=c1[j];
                }
            }
        }
        for(int i=0;i<=n;i++){
            c1[i]=c2[i];
            c2[i]=0;
            //cout<<c2[i]<<" ";
        }
        //cout<<endl;
    }
}

int main(){
    //ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>t;
    while(t--){
        cin>>n>>k;
        for(int i=0;i<k;i++){
            cin>>a[i]>>b[i];
        }
        mufunc();
        cout<<c1[n]<<'\n';
    }
    system("pause");
    return 0;
}


//如果要求多重集合的重数无穷大，则每个括号的系数枚举到n即可

// int mufunc(){
//     memset(c1,0,sizeof(c1));
//     memset(c2,0,sizeof(c2));
//     for(int i=0;i<=n;i++){
//         c1[i]=1;
//     }
//     for(int i=2;i<=n;i++){
//         for(int j=0;j<=n;j++){
//             if(c1[j]){
//                 for(int k=0;k+j<=n;k+=i){
//                     c2[j+k]+=c1[j];
//                 }
//             }
            
//         }
//         for(int j=0;j<=n;j++){
//             c1[j]=c2[j];
//             c2[j]=0;
//         }
//     }
// }
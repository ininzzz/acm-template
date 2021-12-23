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


//k�ſΣ�ѧ��Ϊai��ѧ����bi��,��ѧ��Ϊn�������
//ģ����hdu2079
//��һ��forѭ�����һ�����ŵ�ϵ��
//�ڶ��εĵ�һ��forѭ�������i�����ţ��ڶ���ö�ٵ�i-1�����ŵ�ϵ����������ѵ�i�����ź͵�i-1�����ŵĶ���ʽ������
//j+k*a[i]�ǳ˻���ϵ����+=c1[j]�����ӵ�ϵ������Ϊ��i�����ŵ�ϵ��һ�㶼Ϊ1��ʵ������c1[j]*1

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


//���Ҫ����ؼ��ϵ������������ÿ�����ŵ�ϵ��ö�ٵ�n����

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
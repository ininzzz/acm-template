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

struct tree{
    int l,r;
    int sum,mark;
}arr[4*MAXN];

int number[MAXN];

void build(int i,int l,int r){
    arr[i].l=l;arr[i].r=r;
    if(l==r){
        arr[i].sum=number[l];
        return;
    }
    int mid=(l+r)/2;
    build(2*i,l,mid);
    build(2*i+1,mid+1,r);
    arr[i].sum=arr[2*i].sum+arr[2*i+1].sum;
}

void pushdown(int i){
    if(arr[i].mark){
        arr[2*i].mark+=arr[i].mark;
        arr[2*i+1].mark+=arr[i].mark;
        arr[2*i].sum+=(arr[2*i].r-arr[2*i].l+1)*arr[i].mark;
        arr[2*i+1].sum+=(arr[2*i+1].r-arr[2*i+1].l+1)*arr[i].mark;
        arr[i].mark=0;
    }
}

int query(int i,int l,int r){
    if(arr[i].l>r||arr[i].r<l) return 0;
    if(arr[i].l>=l&&arr[i].r<=r) return arr[i].sum;
    pushdown(i);
    int sum=0;
    sum+=query(2*i,l,r);
    sum+=query(2*i+1,l,r);
    return sum;
}

void add(int i,int l,int r,int k){
    if(arr[i].l>r||arr[i].r<l) return;
    if(arr[i].l>=l&&arr[i].r<=r){
        arr[i].sum+=(arr[i].r-arr[i].l+1)*k;
        if(arr[i].r!=arr[i].l) arr[i].mark+=k;
        return;
    }
    pushdown(i);
    add(2*i,l,r,k);
    add(2*i+1,l,r,k);
    arr[i].sum=arr[2*i].sum+arr[2*i+1].sum;
}



int main(){
    //ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n,q;
    scanf("%d%d",&n,&q);
    for(int i=1;i<=n;i++){
        scanf("%intd",&number[i]);
    }
    build(1,1,n);
    for(int i=0;i<q;i++){
        char x;
        cin>>x;
        if(x=='Q'){
            int a,b;scanf("%d%d",&a,&b);
            printf("%intd\n",query(1,a,b));
        }
        else{
            int a,b;
            int c;
            scanf("%d%d%intd",&a,&b,&c);
            add(1,a,b,c);
        }
    }
    system("pause");
    return 0;
}
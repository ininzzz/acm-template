#include<vector>
#include<iostream>
#include<algorithm>
const int MAXN=4e5+10;

#define ls(x) tree[x].ls
#define rs(x) tree[x].rs
#define val(x) tree[x].val

struct node{
    int val,ls,rs;
}tree[20*MAXN];
int root[MAXN];
int node_cnt;
std::vector<int> a,b;
void build(int &t,int l,int r){
    t=++node_cnt;
    if(l==r) return;
    int mid=(l+r)/2;
    build(ls(t),l,mid);
    build(rs(t),mid+1,r);
}

void update(int pos,int x,int p,int q,int l,int r){
    if(l==r){
        val(q)=val(p)+1;
        return;
    }
    int mid=(l+r)/2;
    ls(q)=ls(p);rs(q)=rs(p);
    if(pos<=mid){
        ls(q)=++node_cnt;
        update(pos,x,ls(p),ls(q),l,mid);
    }
    else{
        rs(q)=++node_cnt;
        update(pos,x,rs(p),rs(q),mid+1,r);
    }
    val(q)=val(ls(q))+val(rs(q));
}


int query(int k,int p,int q,int cl,int cr){
    if(cl==cr) return b[cl-1];
    int mid=(cl+cr)/2;
    if(val(ls(q))-val(ls(p))>=k){
        return query(k,ls(p),ls(q),cl,mid);
    }
    else{
        return query(k-(val(ls(q))-val(ls(p))),rs(p),rs(q),mid+1,cr);
    }
}

void solve(){
    int n,m;std::cin>>n>>m;
    for(int i=0;i<n;i++){
        int x;std::cin>>x;
        a.push_back(x);
        b.push_back(x);
    }
    sort(b.begin(),b.end());
    int len=unique(b.begin(),b.end())-b.begin();
    for(int i=0;i<n;i++){
        a[i]=lower_bound(b.begin(),b.begin()+len,a[i])-b.begin()+1;
    }
    build(root[0],1,len);
    for(int i=1;i<=n;i++){
        root[i]=++node_cnt;
        update(a[i-1],1,root[i-1],root[i],1,len);
        // root[i]=modify(root[i-1],1,len,a[i-1]);
    }
    for(int i=0;i<m;i++){
        int l,r,k;std::cin>>l>>r>>k;
        std::cout<<query(k,root[l-1],root[r],1,len)<<std::endl;
    }
}
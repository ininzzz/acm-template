/*
int tree[MAXN];
int n;

int lowbit(int x) {return x&(-x);}

int sum(int x){
    int ans=0;
    while(x>0){
        ans+=tree[x];
        x-=lowbit(x);
    }
    return ans;
}

void update(int x,int k){
    while(x<=n){
        tree[x]+=k;
        x+=lowbit(x);
    }
}
*/




/*
二维树状数组

int query(int x,int y){
    int sum=0;
    for(int i=x;i>0;i-=lowbit(i)){
        for(int j=y;j>0;j-=lowbit(j)){
            sum+=mp[i][j];
        }
    }
    return sum;
}

void update(int x,int y,int k){
    for(int i=x;i<=n;i+=lowbit(i)){
        for(int j=y;j<=n;j+=lowbit(j)){
            mp[i][j]+=k;
        }
    }
}

*/

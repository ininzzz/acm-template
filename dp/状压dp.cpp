/*
int dp[10][1<<9][100];
int ok[1<<9][2];
int cnt;
int getone(int n){
    int ans=0;
    while(n){
        if(n&1) ans++;
        n>>=1;
    }
    return ans;
}

int dfs(int row,int sta,int num,int cur){
    if(row==0) return num==0&&sta==0;
    if(dp[row][sta][num]!=-1) return dp[row][sta][num];
    int ans=0;
    for(int i=0;i<cnt;i++){
        int temp=ok[i][0];
        if(((temp|(temp<<1)|(temp>>1))&sta)==0){
            if(num-ok[i][1]>=0){
                ans+=dfs(row-1,temp,num-ok[cur][1],i);
            }
        }
    }
    return dp[row][sta][num]=ans;
}

void solve(){
    cnt=0;
    memset(dp,-1,sizeof(dp));
    int n,k;cin>>n>>k;
    for(int i=0;i<(1<<n);i++){
        if((((i<<1)|(i>>1))&i)==0){
            ok[cnt][0]=i;
            ok[cnt++][1]=getone(i);
        }
    }
    int ans=0;
    for(int i=0;i<cnt;i++){
        ans+=dfs(n,ok[i][0],k,i);
    }
    cout<<ans<<endl;
}
*/
/*

一维 线性子段和 O(n)
int subsum(int a[],int n){
    int temp=0,ans=-INF;
    for(int i=1;i<=n;i++){
        ans=max(ans,temp+a[i]);
        temp=max(temp+a[i],0ll);
    }
    return ans;
}

二维 加权子矩阵和 O(n^3)
void solve(){
    int n,m;cin>>n>>m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>mp[i][j];
            // if(mp[i][j]==0) mp[i][j]=-INF;
        }
    }
    //列前缀和
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            sum[j][i]=sum[j-1][i]+mp[j][i];
        }
    }
    int ans=-INF;
    //枚举矩阵下边界
    for(int i=1;i<=n;i++){
        //枚举矩阵上边界
        for(int j=1;j<=i;j++){
            for(int k=1;k<=m;k++){
                temp[k]=sum[i][k]-sum[j-1][k];
            }
            ans=max(ans,subsum(temp,m));
        }
    }
    cout<<ans<<endl;
}

*/
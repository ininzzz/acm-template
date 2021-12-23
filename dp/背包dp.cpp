
/*

01背包的循环过程是从大到小，保证不会利用到自身的选择
完全背包从小到大，因为在循环的过程中会利用到之前的选择
多重背包如果数量足够大就可以当作完全背包做，降低时间复杂度
将多重背包展开可以当作01背包做，但是时间复杂度会更大，可以考虑二进制优化或单调队列优化
如果是背包做min的话，一般把背包的值全部刷成INF，令dp[0]=0，然后跑背包就行了
如果dp[i]是背包容量至少为i的最小花费，要把重量小于i的做一个min，然后跑一个整除的背包即可，注意完全背包和01背包的顺序

01背包
for(int i=0;i<n;i++){
    for(int j=sum;j>=value[i];j--){
        dp[j]=min(dp[j],dp[j-weight[i]]+value[i]);
    }
}

完全背包
for(int i=0;i<n;i++){
    for(int j=value[i];j<=sum;j++){
        dp[j]=max(dp[j],dp[j-weight[i]]+value[i]);
    }
}

多重背包(展开)
for(int i=0;i<n;i++){
    for(int j=0;j<num[i];j++){
        for(int k=m;k>=weight[i];k--){
            dp[k]=max(dp[k-weight[i]]+value[i],dp[k]);
        }
    }
}

多重背包(二进制优化)
二进制优化的本质是将多个物品拆分为二进制的大背包
例如当前有当前物品有17个可以选择，那么可以拆分为1+2+4+8+2，即5个大背包
对这5个做01背包可以保证遍历0-17的所有取值
时间复杂度(n*m*log(num))
for(int i=0;i<n;i++){
    int temp=num[i];
    for(int j=1;j<=temp;j<<=1){
        for(int k=sum;k>=value[i];k--){
            dp[k]=max(dp[k],dp[k-weight[i]]+value[i]);
        }
        temp-=j;
    }
}

二维背包
for(int i=0;i<n;i++){
    for(int j=1;j<=s;j++){
        for(int k=c[i];k<=m;k++){
            dp[j][k]=max(dp[j-1][k-c[i]]+a[i],dp[j][k]);
        }
    }
}

分组背包
int dp[MAXN];
vector<pii> vec[1005];
void solve(){
    int cntt=0;
    int m,n;cin>>m>>n;
    for(int i=1;i<=n;i++){
        int w,v,c;cin>>w>>v>>c;
        vec[c].push_back(make_pair(w,v));
        cntt=max(cntt,c);
    }
    //按组枚举，对每个容量跑一遍组内所有物品，可以保证当前选择不受同组干扰
    //从大到小枚举保证原先dp的内容为上一组的最优解
    for(int i=1;i<=cntt;i++){
        for(int k=m;k>=0;k--){
            for(int j=0;j<vec[i].size();j++){
                if(k-vec[i][j].first>=0){
                    dp[k]=max(dp[k],dp[k-vec[i][j].first]+vec[i][j].second);
                }
            }            
        }
    }
    cout<<dp[m]<<endl;
}
*/



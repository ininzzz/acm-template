#include<bits/stdc++.h>
int mp[200][200],f[200][200];
int mincycle(int n){
    int ans=1e9;
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(i==j||i==k||j==k) continue;
                ans=std::min(ans,f[i][j]+mp[i][k]+mp[k][j]);
            }
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                f[i][j]=std::min(f[i][j],f[i][k]+f[k][j]);
            }
        }
    }
    return ans;
}

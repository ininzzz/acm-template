/*

//求 k/1 + k/2 + k/3 + ... + k/n
int getsum(int n,int k){
    int ans=0;
    for(int l=1,r;l<=n;l=r+1){
        if((k/l)==0) r=n;
        else r=min(n,k/(k/l));
        ans+=(k/l)*(r-l+1);
    }
    return ans;
}

*/


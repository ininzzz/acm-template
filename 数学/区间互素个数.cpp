/*
给定[l,r]，求[l,r]中有多少个和m互素的数
先func(m)，然后答案就是r-l+1-(cal(r)-cal(l-1))

vector<int> vec;
void func(int n){
    for(int i=2;i*i<=n;i++){
        if(n%i==0){
            vec.push_back(i);
            while(n%i==0) n/=i;
        }
    }
    if(n>1) vec.push_back(n);
}
int cal(int n){
    int ans=0;
    int len=vec.size();
    for(int i=1;i<(1<<len);i++){
        int sum=1,cnt=0;
        for(int j=0;j<len;j++){
            int a=(i>>j)&1;
            if(a==1){
                sum*=vec[j];
                cnt++;
            }
        }
        if(cnt%2==1){
            ans+=n/sum;
        }
        else{
            ans-=n/sum;
        }
    }
    return ans;
}


*/
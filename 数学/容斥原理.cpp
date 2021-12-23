/*
vector<int> vec;
int func(int n){
    for(int i=2;i*i<=n;i++){
        if(n%i==0){
            vec.push_back(i);
            while(n%i==0){
                n/=i;
            }
        }
    }
    if(n>1) vec.push_back(n);
}

int rc(int n){
    int ans=0;
    int len=vec.size();
    for(int i=1;i<(1<<len);i++){
        int popcnt=0,temp=1;
        for(int j=0;j<len;j++){
            int x=(i>>j)&1;
            if(x==1){
                popcnt++;
                temp*=vec[j];
            }   
        }
        if(popcnt%2==1){
            ans+=(n/temp);
        }
        else{
            ans-=(n/temp);
        }
    }
    return ans;
}
*/
/*

//a^x=b(mod p) 求x的最小值 O(sqrt(p))
//map会T的话就用unordered_map

map<int,int> mp;
int BSGS(int a,int b,int p){
    mp.clear();
    int t=sqrt(p)+1,temp=1;
    for(int i=1;i<=t;i++){
        temp*=a;temp%=p;
        mp[b*temp%p]=i;
    }
    int now=temp;
    for(int i=1;i<=t;i++){
        if(mp[now]) return i*t-mp[now];
        now*=temp;now%=p;
    }
    return -1;
}

*/
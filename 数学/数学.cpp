#define MOD 10000007
int qpow(int base,int n,int mod=MOD){
    int ans=1;
    while(n){
        if(n&1) ans=ans*base%mod;
        base=base*base%mod;
        n>>=1;
    }
    return ans%mod;
}

int inv(int a,int p){
    return qpow(a,p-2,p);
}


int gcd(int a,int b){
    if(b==0){
        return a;
    }
    else{
        return gcd(b,a%b);
    }
}

int exgcd(int a,int b,int& x,int& y){
    if(b==0){
        x=1;
        y=0;
        return a;
    }
    int d=exgcd(b,a%b,y,x);
    y-=(a/b)*x;
    return d;
}

bool isprime(int n){
    if(n==1) return false;
    for(int i=2;i*i<=n;i++){
        if(n%i==0) return false;
    }
    return true;
}
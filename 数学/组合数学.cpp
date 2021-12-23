/*
//拓展欧几里得
int exgcd(int a,int b,int &x,int &y){
	if(b==0){
		x=1,y=0;
		return a;
	}
	int xx,yy;
	int g=exgcd(b,a%b,xx,yy);
	x=yy,y=xx-(a/b)*yy;
	return g;
}
//逆元
int inverse(int a,int b){
	int x,y;
	exgcd(a,b,x,y);
	return (x%b+b)%b;
}
//组合数递推(m固定)
int comb[MAXN];
void init(int n,int m){
    comb[m]=1;
    for(int i=m+1;i<=n;i++){
        comb[i]=((i*comb[i-1])%MOD*inverse(i-m,MOD))%MOD;
    }
}
//直接求组合数
int solve_c(int n,int m){
	int t1=1,t2=1,t3=1;
	for(int i=2;i<=n;i++) t1=(t1*i)%MOD;
	for(int i=2;i<=m;i++) t2=(t2*i)%MOD;
	for(int i=2;i<=n-m;i++) t3=(t3*i)%MOD;
	return (((t1*inverse(t2,MOD))%MOD)*inverse(t3,MOD))%MOD;
}


//阶乘预处理，O(logn)求组合数(逆元也预处理就是O(1))
void prework(){
    fac[0]=1;
    for(int i=1;i<MAXN;i++){
        fac[i]=fac[i-1]*i%mod;
    }
}
int C(int n,int m){
    int temp=fac[m]*fac[n-m]%MOD;
    return fac[n]*qpow(temp,MOD-2)%MOD;
}

//错位全排列 D(n)=(n-1)*(D(n-1)+D(n-2))
void pre_d(int n){
	d[0]=1;d[1]=0;d[2]=1;
	for(int i=3;i<n;i++){
		d[i]=(i-1)*(d[i-1]+d[i-2])%MOD;
	}
}
	
*/
/*

int C(int n,int m,int p=MOD){
    if(m>n) return 0;
    return fac[n]%p*qpow(fac[m],p-2,p)%p*qpow(fac[n-m],p-2,p)%p;
}

int Lucas(int n,int m,int p=MOD) {
  if(m==0) return 1;
  return (C(n%p,m%p,p)*Lucas(n/p,m/p,p))%p;
}

*/
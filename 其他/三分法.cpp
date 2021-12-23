/*
double l=0,r=inf;
while(r-l>eps){
    double mid=(l+r)/2;
    double fl=f(mid-eps),fr=f(mid+eps);
    if(fl>fr){
        r=mid;
    }
    else{
        l=mid;

    }
}

int lo=0,hi=l;
while(lo+1<hi){
    int mid=(lo+hi)/2;
    int fl=f(mid-1),fr=f(mid+1);
    if(fl<fr){
        hi=mid;
    }
    else{
        lo=mid;
    }
}
*/
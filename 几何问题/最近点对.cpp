#include<iostream>
#include<iomanip>
#include<cmath>
#include<algorithm>
using namespace std;
struct point{
    double x,y;
};
point p[100005],px[100005],py[100005];
bool cmpx(point a,point b){
    return a.x<b.x;
}
bool cmpy(point a,point b){
    return a.y<b.y;
}
double distance(point a,point b){
    return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}
double func(int f,int l){
    if(f+1==l){
        return distance(px[f],px[l]);
    }
    if(f+2==l){
        return min(distance(px[f],px[l]),min(distance(px[f+1],px[l]),distance(px[f],px[f+1])));
    }
    int mid=(f+l)/2,cnt=0;
    double ans=min(func(f,mid),func(mid+1,l));
    for(int i=f;i<=l;i++){
        if(px[i].x>=px[mid].x-ans&&px[i].x<=px[mid].x+ans){
            py[cnt++]=px[i];
        }
    }
    sort(py,py+cnt,cmpy);
    for(int i=0;i<cnt;i++){
        for(int j=i+1;j<cnt;j++){
            if(py[j].y-py[i].y>=ans){
                break;
            }
            ans=min(ans,distance(py[i],py[j]));
        }
    }
    return ans;
}

int main(){
    int n;
    while(true)
    {
        cin>>n;
        if(n==0){
            break;
        }
        for(int i=0;i<n;i++)
        {
            scanf("%lf%lf",&p[i].x,&p[i].y);
            px[i]=p[i];
        }
        sort(px,px+n,cmpx);
        double distance=func(0,n-1);
        printf("%.2lf\n",distance/2);
    }
    return 0;
}
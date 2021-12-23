/*

struct line{
    int x,lo,hi,f;
}lines[MAXN];
bool cmp(line a,line b){
    return a.x<b.x;
}

struct node{
    int l,r,cnt,len;
}nodes[4*MAXN];
vector<int> vec;
void build(int i,int l,int r){
    nodes[i].l=l;nodes[i].r=r;
    if(l+1==r) return;
    int mid=(l+r)/2;
    build(2*i,l,mid);
    build(2*i+1,mid,r);
}

void pushup(int i){
    if(nodes[i].cnt){
        nodes[i].len=vec[nodes[i].r-1]-vec[nodes[i].l-1];
    }
    else{
        nodes[i].len=nodes[2*i].len+nodes[2*i+1].len;
    }
}

void update(int i,int l,int r,int k){
    if(nodes[i].l>r||nodes[i].r<l) return;
    if(nodes[i].l>=l&&nodes[i].r<=r){
        nodes[i].cnt+=k;
        pushup(i);
        return;
    }
    update(2*i,l,r,k);
    update(2*i+1,l,r,k);
    pushup(i);
}

void solve(){
    int n=read();
    int len=1;
    for(int i=1;i<=n;i++){
        int x1=read(),y1=read(),x2=read(),y2=read();
        lines[len++]={x1,y1,y2,1};
        lines[len++]={x2,y1,y2,-1};
        vec.push_back(y1);
        vec.push_back(y2);
    }
    sort(vec.begin(),vec.end());
    unique(vec.begin(),vec.end());
    for(int i=1;i<len;i++){
        lines[i].lo=lower_bound(vec.begin(),vec.end(),lines[i].lo)-vec.begin()+1;
        lines[i].hi=lower_bound(vec.begin(),vec.end(),lines[i].hi)-vec.begin()+1;
    }
    sort(lines+1,lines+len,cmp);
    build(1,1,len-1);
    int ans=0;
    for(int i=1;i<len-1;i++){
        update(1,lines[i].lo,lines[i].hi,lines[i].f);
        ans+=(lines[i+1].x-lines[i].x)*nodes[1].len;
    }
    write(ans);
    putchar('\n');
}

*/
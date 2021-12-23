/*
string a,b;
int nxt[MAXN];
void getnxt(string &b){
    for(int i=1;i<b.size();i++){
        int j=nxt[i-1];
        while(j&&b[i]!=b[j]) j=nxt[j-1];
        if(b[j]==b[i]) j++;
        nxt[i]=j;
    }
}
void kmp(string &a,string &b){
    for(int i=0,j=0;i<a.size();i++){
        while(j&&a[i]!=b[j]) j=nxt[j-1];
        if(a[i]==b[j]) j++;
        if(j==b.size()){
            cout<<i-b.size()+2<<endl;
            j=nxt[j-1];
        }
    }
}

// tricks: 

// 给定一个字符串，求其最小循环节长度：n-nxt[n-1] (下标0开始)

// 求最短公共前后缀
void solve(){
    getnxt(s);
    for(int i=0;i<n;i++){
        int j=i;
        while(nxt[j]) j=nxt[j]-1;
        if(nxt[i]) nxt[i]=j+1; //记忆化
    }
}

// 给定一个字符串做匹配，匹配完把这个串删去，求能删完后的串(删去后新拼接的串可能会产生新的模式串)
void kmp(string &a,string &b){
    int ans=0;
    for(int i=0,j=0;i<a.size();i++){
        while(j&&a[i]!=b[j]) j=nxt[j-1];
        if(a[i]==b[j]) j++;
        sv[i]=j;
        stk.push(i);
        if(j==b.size()){
            ans++;
            int m=b.size();
            while(m--) stk.pop();
            if(stk.empty()) j=0; 
            else j=sv[stk.top()]; //核心操作
        }
    }
    //stk中剩下的下标就是剩下的串，注意反转一下
}

*/
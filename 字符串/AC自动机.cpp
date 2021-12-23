#include<iostream>
#include<stdio.h>
#include<vector>
#include<iomanip>
#include<algorithm>
#include<cstring>
#include<set>
#include<sstream>
#include<map>
#include<queue>
#include<math.h>
using namespace std;
#define MAXN 500000 + 5
#define INF 0x3f3f3f3f
const int MAXint=2147483647;
typedef pair<int,int> P;


struct trie{
    struct node{
        int num;
        int next[26];
    }nodes[MAXN];
    int fail[MAXN];
    int cnt;
    void insert(string& s){
        int p=0,len=s.length();
        for(int i=0;i<len;i++){
            int c=s[i]-'a';
            if(!nodes[p].next[c]){
                nodes[p].next[c]=++cnt;
            }
            p=nodes[p].next[c];
        }
        nodes[p].num++;
    }
    void insert(char* s){
        int p=0,len=strlen(s);
        for(int i=0;i<len;i++){
            int c=s[i]-'a';
            if(!nodes[p].next[c]){
                nodes[p].next[c]=++cnt;
            }
            p=nodes[p].next[c];
        }
        nodes[p].num++;
    }
    bool find(string& s){
        int p=0,len=s.length();
        for(int i=0;i<len;i++){
            int c=s[i]-'a';
            if(!nodes[p].next[c]){
                return false;
            }
            p=nodes[p].next[c];
        }
        return nodes[p].num;
    }
    bool find(char* s){
        int p=0,len=strlen(s);
        for(int i=0;i<len;i++){
            int c=s[i]-'a';
            if(!nodes[p].next[c]){
                return false;
            }
            p=nodes[p].next[c];
        }
        return nodes[p].num;
    }
    void build(){
        queue<int> que;
        for(int i=0;i<26;i++){
            if(nodes[0].next[i]){
                que.push(nodes[0].next[i]);
            }
        }
        while(!que.empty()){
            int temp=que.front();
            que.pop();
            for(int i=0;i<26;i++){
                if(nodes[temp].next[i]){
                    fail[nodes[temp].next[i]]=nodes[fail[temp]].next[i];
                    que.push(nodes[temp].next[i]);
                }
                else{
                    nodes[temp].next[i]=nodes[fail[temp]].next[i];
                }
            }
        }
    }
    int query(string &s){
        int now=0,res=0;
        int len=s.length();
        for(int i=0;i<len;i++){
            now=nodes[now].next[s[i]-'a'];
            for(int j=now;j&&nodes[j].num!=-1;j=fail[j]){
                res+=nodes[j].num;
                nodes[j].num=-1;
            }
        }
        return res;
    }
}tree;
int main(){
    int n;cin>>n;
    for(int i=0;i<n;i++){
        string s;cin>>s;
        tree.insert(s);
    }
    tree.build();
    string t;cin>>t;
    cout<<tree.query(t)<<endl;
    system("pause");
    return 0;
}
/*
struct trie{
    struct node{
        int num;
        int next[2];
    }nodes[MAXN];
    int cnt;
    void init(){
        memset(nodes,0,sizeof(nodes));
        cnt=0;
    }
    void insert(int n){
        int p=0;
        for(int i=31;i>=0;i--){
            int val=(n>>i)&1;
            if(!nodes[p].next[val]){
                nodes[p].next[val]=++cnt;
            }
            p=nodes[p].next[val];
        }
        nodes[p].num=n;
    }
    int find(int n){
        int p=0;
        for(int i=31;i>=0;i--){
            int val=(n>>i)&1;
            if(!nodes[p].next[val^1]) p=nodes[p].next[val];
            else p=nodes[p].next[val^1];
        }
        return nodes[p].num;
    }
}tree;
*/
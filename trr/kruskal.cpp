#include <iostream>
#include <algorithm>
using namespace std;

struct task{
    int u;
    int v;
    int l;
};
int n,m;
int pr[1000];
task a[1000];
bool cmp(task x,task y)
{
    return (x.l<y.l);
}

int find(int u){
    while (pr[u]>0) u=pr[u];
    return u;
}

void Union(int u, int v){
    if (pr[u]>=pr[v]){
        pr[v]+=pr[u];
        pr[u]=v;
    }
    else Union(v,u);
}

int kruskal(){
    for (int i=0; i<=n; i++) pr[i]=-1;
    sort(a,a+m,cmp);
    int res=0,count=0; 
    for (int i=0; i<m; i++){
        int u=find(a[i].u);
        int v=find(a[i].v);
        if (u!=v){
            Union(u,v);
            res=res+a[i].l;
            count++;
            if (count==n-1) break;
        }
    }
    return res;
}

int main(){
    int t;
    cin >> t;
    while (t--){
        cin >> n >> m;
        for (int i=0; i<m; i++) cin >> a[i].u >> a[i].v >> a[i].l;
        cout << kruskal() << endl;
    }
}
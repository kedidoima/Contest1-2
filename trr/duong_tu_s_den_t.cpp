#include <iostream>
using namespace std;
int n,s,t,a[20][20],fr[20],qu[20],tr[20];

void dfs(int u)
{
    fr[u]=0;
    for (int v=1; v<=n; v++)
        if (a[u][v] && fr[v]) {
            tr[v]=u;                   // gán trước v là u
            dfs(v);
        }
}

void bfs(int u)
{
    int l=0,r=0;                       // khởi tạo queue rỗng
    r++; qu[r]=u;                      // push đỉnh u vào queue
    tr[u]=0;                           // khởi tạo không có đỉnh nào trước u
    fr[u]=0;                           // đánh dấu đỉnh u đã được thăm
    while (l<r) {                      // while (queue chưa rỗng) thì
        l++;  u=qu[l];                 // pop đỉnh ra khỏi queue vào gán vào u
        for (int v=1; v<=n; v++)       // duyệt tất cả các đỉnh
            if (a[u][v] && fr[v]) {    // nếu có đường đi và chưa thăm thì
                r++; qu[r]=v;          // push v vào queue
                tr[v]=u;               // gán trước v là u
                fr[v]=0;               // đánh dấu đã gán
            }
    }
}

void duong_s_den_t (){
    int m=0,b[20];
    m++; b[m]=t;                       // gán t vào đường đi
    if (tr[t]==0) {                    // nếu trước v không có đỉnh nào
        cout << "Khong co duong di";
        return;
    }
    
    int u=tr[t];
    while (tr[u]!=0)                   // khi trước u vẫn còn đỉnh
    {
        m++; b[m]=u;
        u=tr[u];                       // gán u bằng đỉnh trước u
    }

    m++; b[m]=s;                       // gán s vào đường đi
    for (int i=m; i>0; i--) cout << b[i] << " " ; // in đường đi
}

int main()
{
    // đọc ma trận nxn, đỉnh s và t
    cin >> n >> s >> t;
    for (int i=1; i<=n; i++)
        for (int j=1; j<=n; j++) cin >> a[i][j];
    for (int j=1; j<=n; j++) fr[j]=1;
    tr[s]=0; // trước s không có đỉnh nào
    dfs(s);
    duong_s_den_t();
}
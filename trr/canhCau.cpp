#include <bits/stdc++.h>

using namespace std;
#define ll long long //%li
#define ull unsigned long long //%lli
#define uint unsigned int //%u
#define MAX 1e6
#define MIN -1e6

int n, m;
vector <vector <int> > a;
vector<vector<int> > edge;
vector  <bool> key;

void init() {
    cin >> n >> m;
    a.assign(n+1, vector <int> (n+1, 0));
    edge.assign(2, vector<int> (m+1, 0));
    key.assign(n+1, false);
    for(int i = 1; i <= m; ++i){
        cin >> edge[0][i] >> edge[1][i];
        int x = edge[0][i], y = edge[1][i];
        a[x][y] = 1;
        a[y][x] = 1;
    }
}

void BFS(int &dem, int u, bool in) {
    queue <int> q;
    q.push(u);
    key[u] = true;
    while(!q.empty()){
        u = q.front();
        if(in) cout << u << " ";
        dem++;
        q.pop();
        for(int i = 1; i <= n; ++i){
            if(a[u][i] == 1 && key[i] == false){
                q.push(i);
                key[i] = true;
            }
        }
    }
    if(in) cout <<endl;
}

int demTpLienThong(){
    int dem = 0, emptyy=0;
    for(int i = 1; i <= n; ++i){
        if(key[i] == 0){
            dem++;
            BFS(emptyy, i, false);
        }
    }
    return dem;
}

int main(){
    // CẠNH CẦU: là khi xóa NÓ đi thì số thành phần liên thông tăng lên
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    init();
    // số thành phần liên thông ban đầu
    int tplt = demTpLienThong();
    cout << tplt << endl;
    for(int i = 1; i <= m; ++i){
        int x = edge[0][i], y = edge[1][i];
        key.assign(n+1, false);
        // xóa cạnh
        cout << x << " " << y << " ";
        a[x][y] = 0;
        a[y][x] = 0;
        // đếm số thành phần liên thông
        int tmp = demTpLienThong();
        // so sánh với số thành phần liên thông ban đầu => kết luận
        if(tmp > tplt) cout <<"YES" << endl;
        else cout << "NO" << endl;
        //trả lại cạnh bị xóa
        a[x][y] = 1;
        a[y][x] = 1;
    }
    return 0;
}
/*
7 8
1 3
1 7
2 3
2 7
3 5
5 6
6 2
2 4
 */

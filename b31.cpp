#include <iostream>
#include <string>
using namespace std;
int n,k,fr[11][11],tr[11][11],a[10],b[10];
int m,trs[100],count;
string s[101],ff[10][10],ss[1000];
char f[10][10];

void init()
{
    a[1]=-1; a[2]=-1; a[3]=-1; a[4]=0; a[5]=0; a[6]=1; a[7]=1; a[8]=1;
    b[1]=-1; b[2]=0; b[3]=1; b[4]=-1; b[5]=1; b[6]=-1; b[7]=0; b[8]=1;
    for (int i=0; i<=10; i++)
        for (int j=0; j<=10; j++) fr[i][j]=1;
}

bool check(int x,int y)
{
    return (x>0 && x<=m && y>0 && y<=n);
}

void xuat()
{
}

void loang(int x, int y)
{
    fr[x][y]=0;
    for (int i=1; i<=8; i++)
    {
        int xx=x+a[i];
        int yy=y+b[i];
        if (check(xx,yy) )
            if (fr[xx][yy]) {
                ff[xx][yy]=ff[x][y]+f[xx][yy];
                count++;
                ss[count]=ff[xx][yy];
                cout << ss[count] << endl;
                loang(xx,yy);
            }
    }
    fr[x][y]=1;
}

int main()
{   
    init();
    int t;
    cin >> t;
    while (t--)
    {
        cin >> k >> m >> n;
        for (int i=1; i<=k; i++) cin >> s[i];
        for (int i=1; i<=m; i++)
            for (int j=1; j<=n; j++) cin >> f[i][j];
        
        count=0;
        for (int i=1; i<=m; i++)
            for (int j=1; j<=n; j++)
            {
                ff[i][j]=f[i][j];
                loang(i,j);
            }
        for (int i=1; i<=count; i++) cout << ss[i] << endl;
    }
}
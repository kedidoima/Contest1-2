#include <iostream>
using namespace std;
int n,f[12][12],fr[12][12],tr[12][12],a[5],b[5];
int m,trs[102],dem;
void init()
{
    a[1]=1; a[2]=0;
    b[1]=0; b[2]=1;
}

bool check(int x)
{
    return (x>0 && x<=n);
}

void xuat()
{
    int  x=n,y=n,xx,yy;
    m=0; dem++;
    while (tr[x][y]>0)
    {
        m++; trs[m]=tr[x][y];
        xx=x-a[tr[x][y]];
        yy=y-b[tr[x][y]];
        x=xx; y=yy;
    } 
    for (int i=m; i>0; i--) 
        if (trs[i]==1) cout << "D";
        else cout << "R";
    cout << " ";
}

void loang(int x, int y)
{
    //cout << x << " " << y << endl;
    fr[x][y]=0;
    for (int i=1; i<=2; i++)
    {
        int xx=x+a[i];
        int yy=y+b[i];
        if (check(xx) && check(yy) )
            if (f[xx][yy]==1 && fr[xx][yy]) 
            {
                tr[xx][yy]=i;
                if (xx==n && yy==n) xuat();
                else loang(xx,yy);
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
        cin >> n;
        for (int i=1; i<=n; i++)
            for (int j=1; j<=n; j++) 
            {
                cin >> f[i][j];
                fr[i][j]=1;
            }
        dem=0;
        if (f[1][1]!=1)
        {
            cout << -1 << endl;
            continue;
        }
        loang(1,1);
        if (dem==0) cout << -1;
        cout << endl;
    }
}
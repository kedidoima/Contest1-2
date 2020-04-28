#include <iostream>
using namespace std;
int n,f[11][11],fr[11][11],tr[11][11],a[5],b[5];
int m,trs[100],dem;
void init()
{
    a[1]=1; a[2]=0; a[3]=0; a[4]=-1;
    b[1]=0; b[2]=-1; b[3]=1; b[4]=0;
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
    {
        if (trs[i]==1) cout << "D";
        if (trs[i]==2) cout << "L";
        if (trs[i]==3) cout << "R";
        if (trs[i]==4) cout << "U";
    }
    cout << " ";
}

void loang(int x, int y)
{
    //cout << x << " " << y << endl;
    fr[x][y]=0;
    for (int i=1; i<=4; i++)
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
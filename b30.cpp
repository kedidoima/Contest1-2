#include <iostream>
using namespace std;
int n,m,p,s,res,mm,snt[200],tr[10000][11],a[50],b[11];

bool nt(int x)
{
    for (int i=2; i<x; i++) 
        if (x % i==0) return false;
    return true;
}

void init()
{
    m=0;
    for (int i=2; i<=200; i++)
        if (nt(i)) 
        {
            m++; snt[m]=i;
        }
}

void xuat()
{
    int sum=0;
    for (int i=1; i<=n; i++)
    {
        sum+=a[b[i]];
    }
    if (sum==s) 
    {
        res++;
        for (int i=1; i<=n; i++) tr[res][i]=a[b[i]];
    }
}

void Try(int x)
{
    for (int i=b[x-1]+1; i<=mm-n+x; i++){
        b[x]=i;
        if (x==n) xuat();
        else Try(x+1);
    }
}

int main()
{
    init();
    int t;
    cin >> t;
    while (t--)
    {
        cin >> n >> p >> s;
        mm=0;
        for (int i=1; i<=m; i++)
            if (snt[i]>=p)
            {
                mm++;
                a[mm]=snt[i];
                if (snt[i]>s) 
                {
                    mm--;
                    break;
                }
            }
        res=0; b[0]=0;
        Try(1);
        cout << res << endl;
        for(int i=1; i<=res; i++) 
        {
            for (int j=1; j<=n; j++) cout << tr[i][j] << " ";
            cout << endl;
        }
    }
    
}
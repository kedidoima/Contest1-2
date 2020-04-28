#include <iostream>
#include <algorithm>
using namespace std;
int n,k,a[100],b[100];
bool ok=true;
void xuat(int x)
{
    cout << "[" << a[b[0]];
    for (int i=1; i<=x; i++) cout << " " << a[b[i]] ;
    cout << "] ";
    ok=false;
}

void Try(int x,int y)
{
    for (int i=y; i<n; i++)
        if (a[i]<=k)
        {
            b[x]=i;
            k=k-a[i];
            if (k==0) xuat(x);
            else Try(x+1,i);
            k=k+a[i];
        }
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        cin >> n >> k;
        for (int i=0; i<n; i++) cin >> a[i];
        Try(0,0);
        if (ok) cout << -1;
        cout << endl;
    }
}
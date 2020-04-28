#include <iostream>
using namespace std;
int n,k,a[100],dem;
int b[50000][20];

void xuat()
{
    int count=0;
    for (int i=0; i<=n-k; i++)
        if (a[i]==0)
        {
            int ok=1;
            for (int j=i; j<i+k; j++)
                if (a[j]==1) ok=0;
            count+=ok;
        }
    if (count==1)
    {
        dem++;
        for (int i=0; i<n; i++)
            b[dem][i]=a[i];
    }
}

void back_track(int x)
{
    for (int i=0; i<=1; i++){
        a[x]=i;
        if (x==n-1) xuat();
        else back_track(x+1);
    }
}

int main()
{
        cin >> n >> k;
        dem=0;
        back_track(0);
    cout << dem << endl;
    for (int i=1; i<=dem; i++)
    {
        for (int j=0; j<n; j++) 
            if (b[i][j]==0) cout << "A";
            else cout << "B";
        cout << endl;
    }
}
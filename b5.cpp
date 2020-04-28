#include <iostream>
using namespace std;
int n,k,a[100];

void xuat()
{
    for (int i=1; i<=k; i++) cout << a[i];
    cout << " ";
}

void back_track(int x)
{
    for (int i=a[x-1]+1; i<=n-k+x; i++){
        a[x]=i;
        if (x==k) xuat();
        else back_track(x+1);
    }
}

int main()
{
    int t;
    cin >> t;
    a[0]=0;
    while (t--)
    {
        cin >> n >> k;
        back_track(1);
        cout << endl;
    }
}
#include <iostream>
using namespace std;
int n,k,a[100];

void xuat()
{
    int count=0;
    for (int i=0; i<n; i++)
        if (a[i]==1) count++;
    if (count==k) 
    {
        for (int i=0; i<n; i++) cout << a[i];
        cout << endl;
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
    int t;
    cin >> t;
    while (t--)
    {
        cin >> n >> k;
        back_track(0);
    }
}
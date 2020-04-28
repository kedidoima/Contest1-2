#include <iostream>
using namespace std;
int n,a[100];

void xuat()
{
    for (int i=0; i<n; i++) 
        if (a[i]==0) cout << "A";
        else cout << "B";
    cout << " ";
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
        cin >> n;
        back_track(0);
        cout << endl;
    }
}
#include <iostream>
using namespace std;
int n,k,a[100];
bool b[100];

void xuat()
{
    for (int i=1; i<=n; i++) cout << a[i];
    cout << " ";
}

void back_track(int x)
{
    for (int i=n; i>0; i--)
        if (b[i]) {
            a[x]=i;
            b[i]=false;
            if (x==n) xuat();
            else back_track(x+1);
            b[i]=true;
        }
}

int main()
{
    int t;
    cin >> t;
    a[0]=0;
    for (int i=0; i<20; i++) b[i]=true;
    while (t--)
    {
        cin >> n ;
        back_track(1);
        cout << endl;
    }
}
#include <iostream>
using namespace std;
int n,k,a[100];
bool b[100];

void xuat(int x)
{
    cout << "(" << a[1];
    for (int i=2; i<=x; i++) cout << " " << a[i] ;
    cout << ") ";
}

void back_track(int x)
{
    for (int i=a[x-1]; i>0; i--)
    {
        a[x]=i;
        n=n-i;
        //cout << i << " " << x << " " << n << endl;
        if (n<0) 
        {
            n=n+i;
            continue;
        }
        if (n==0) xuat(x);
        else back_track(x+1);
        n=n+i;
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
        a[0]=n;
        back_track(1);
        cout << endl;
    }
}
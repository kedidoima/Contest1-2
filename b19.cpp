#include <iostream>
using namespace std;
int main()
{
    int t,n,a[10000];
    cin >> t;
    while (t--)
    {
        cin >> n;
        for (int i=0; i<n; i++) cin >> a[i];
        cout << "[";
        for (int i=0; i<n-1; i++) cout << a[i] << " "; 
        cout << a[n-1] << "]" << endl;
        while (n>1)
        {
            for (int i=0; i<n-1; i++) a[i]+=a[i+1];
            n--;
            cout << "[";
            for (int i=0; i<n-1; i++) cout << a[i] << " "; 
            cout << a[n-1] << "]" << endl;
        }
    }
}
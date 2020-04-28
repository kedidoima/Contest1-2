#include <iostream>
#include <string.h>
using namespace std;

int main()
{
    int t,a[1000],n,k;
    cin >> t;
    while (t--)
    {
        cin >> n >> k;
        bool ok=true;
        for (int i=1; i<=k; i++) 
        {
            cin >> a[i];
            if (a[i]<n-k+i) ok=false;
        }
        if (ok) {
            for (int i=1; i<=k; i++) cout << i << " ";
        }   
        else {
            for (int i=k; i>0; i--)
                if (a[i]<n-k+i) {
                    a[i]++;
                    for (int j=i+1; j<=k; j++) a[j]=a[j-1]+1;
                    for (int j=1; j<=k; j++) cout << a[j] << " ";
                    break;
                }
        }
        cout << endl;
    }
}
#include <iostream>
#include <string.h>
using namespace std;

int main()
{
    int t,a[1000],b[1000],n,k;
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
            cout << k ;
        }   
        else {
            for (int i=k; i>0; i--)
                if (a[i]<n-k+i) {
                    /*a[i]++;
                    for (int j=i+1; j<=k; j++) a[j]=a[j-1]+1;
                    for (int j=1; j<=k; j++) cout << a[j] << " ";*/
                    b[i]=a[i]+1;
                    for (int j=i+1; j<=k; j++)  b[j]=b[j-1]+1;
                    int count=0;
                    for (int j=i; j<=k; j++)
                    {
                        int ok=1;
                        for (int ii=i; ii<=k; ii++)
                            if (b[j]==a[ii]) ok=0;
                        count += ok;
                    }
                    cout << count;
                    break;
                }
        }
        cout << endl;
    }
}
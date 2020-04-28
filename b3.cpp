#include <iostream>
#include <string.h>
using namespace std;

int main()
{
    int t,a[1002],n,k;
    cin >> t;
    while (t--)
    {
        cin >> n ;
        bool ok=true;
        a[0]=100000;
        for (int i=1; i<=n; i++) 
        {
            cin >> a[i];
            if (a[i]>a[i-1]) ok=false;
        }
        if (ok) {
            for (int i=1; i<=n; i++) cout << i << " ";
        }   
        else {
            //cout << " cac";
            int pos;
            for (int i=n-1; i>0; i--)
                if (a[i]<a[i+1]) {
                    pos=i;
                    //cout << pos << " " ;
                    for (int j=n; j>i; j--)
                        if (a[j]>a[i]) {
                            int emt=a[i];
                            a[i]=a[j];
                            a[j]=emt;
                            break;
                        }
                    int l=i+1, r=n;
                    while (l<r){
                        int emt=a[l];
                        a[l]=a[r];
                        a[r]=emt;
                        l++; r--;
                    } 
                    break;
                }
            for (int i=1; i<=n; i++) cout << a[i] << " ";

        }
        cout << endl;
    }
}
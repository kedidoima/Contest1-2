#include <iostream>
#include <string.h>
using namespace std;

int main()
{
    int t,n,k;
    string a;
    cin >> t;
    while (t--)
    {
        cin >> k >> a ;
        bool ok=true;
        n=a.length();
        a='9'+a;
        for (int i=1; i<=n; i++)
            if (a[i]>a[i-1]) ok=false;
        
        if (ok) {
            cout << k << " BIGGEST";
        }   
        else {
            int pos;
            for (int i=n-1; i>0; i--)
                if (a[i]<a[i+1]) {
                    pos=i;
                    for (int j=n; j>i; j--)
                        if (a[j]>a[i]) {
                            char emt=a[i];
                            a[i]=a[j];
                            a[j]=emt;
                            break;
                        }
                    int l=i+1, r=n;
                    while (l<r){
                        char emt=a[l];
                        a[l]=a[r];
                        a[r]=emt;
                        l++; r--;
                    } 
                    break;
                }
            a.erase(0,1);
            cout << k << " " << a;

        }
        cout << endl;
    }
}
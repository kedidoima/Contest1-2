#include <iostream>
using namespace std;
int main()
{
    int t,n,m,nn,a[10000],b[10000],count;
    cin >> t;
    while (t--)
    {
        cin >> n;
        m=n; nn=n;
        for (int i=0; i<n; i++) 
        {
            cin >> a[i];
            b[m-i-1]=a[i];
        }
        while (n>1)
        {
            for (int i=0; i<n-1; i++) a[i]+=a[i+1];
            n--;
            for (int i=n-1; i>=0; i--)
            {
                b[m]=a[i];
                m++;
            }
        }
        count=1;
        while (count <= nn)
        {
            cout << "[";
            for (int i=0; i<count-1; i++)
            {
                cout << b[m-1] << " ";
                m--;
            }
            cout << b[m-1] <<  "] ";
            m--;
            count++;
        }
        cout << endl;
    }
}
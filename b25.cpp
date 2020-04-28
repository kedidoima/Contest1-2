#include <iostream>
using namespace std;
int main(){
    int t,n,a[101],f[10001],s;
    cin >> t;
    while (t--)
    {
        cin >> n;
        s=0;
        for (int i=0; i<n; i++)
        {
            cin >> a[i];
            s+=a[i];
        }
        if (s % 2 ==1) 
        {
            cout << "NO" << endl;
            continue;
        }
        s=s/2;
        for (int i=0; i<=s; i++) f[i]=0;
        f[0]=1;
        for (int i=0; i<n; i++) 
            for (int j=s; j>=a[i]; j--)
                if (f[i]==0 && f[j-a[i]==1]) f[j]=1;
        if (f[s]==1) cout << "YES"  ;
        else cout << "NO";
        cout << endl;
    }
}
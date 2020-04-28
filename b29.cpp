#include <iostream>
using namespace std;
int main()
{
    int t,a[101][101],n,m;
    cin >> t;
    while (t--)
    {
        cin >> m >> n;
        for (int i=0; i<m; i++) 
            for (int j=0; j<n; j++) cin >> a[i][j];
        for (int i=0; i<100; i++)
        {
            a[0][i]=1;
            a[i][0]=1;
        }
        for (int i=1; i<m; i++)
            for (int j=1; j<n; j++)
                a[i][j]=a[i-1][j]+a[i][j-1];
        cout << a[m-1][n-1] << endl;
    }
}
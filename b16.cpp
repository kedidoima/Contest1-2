#include <iostream>
using namespace std;
int n,k,count,a[20][20],b[20],c[20],res[20000][20];

void check()
{
    int sum=0;
    for (int i=0; i<n; i++)
        sum+=a[i][c[i]];
    if (sum==k)
    {
        count++;
        for (int j=0; j<n; j++) res[count][j]=c[j]+1;
    }
}

void TRY(int x)
{
    for (int i=0; i<n; i++)
        if (b[i]) {
            c[x]=i;
            b[i]=0;
            if (x==n-1) check();
            else TRY(x+1);
            b[i]=1;
        }
}

int main()
{
    cin >> n >> k;
    for (int i=0; i<n; i++)
        for (int j=0; j<n; j++) cin >> a[i][j];
    for (int i=0; i<n; i++) b[i]=1;
    TRY(0);
    cout << count << endl;
    for (int i=1; i<=count; i++) 
    {
        for (int j=0; j<n; j++) cout << res[i][j] << " ";
        cout << endl;
    }
}
#include <iostream>
using namespace std;
int t,n,k,a[101],b[21],fr[101],s,sum;

void check()
{
    sum=0;
    for (int i=0; i<n; i++) sum+=a[i]*b[i];
    if (sum==s) 
        for (int i=0; i<n; i++) 
            if (b[i]) fr[i]=1;
}

void Try(int x)
{
    if (fr[x]) 
    {
        b[x]=0;
        if (x==n-1) check();
        else Try(x+1);
    }
    else
        for (int i=0; i<=1; i++)
        {
            b[x]=i;
            if (x==n-1) check();
            else Try(x+1);
        }
}

int main(){
    cin >> t;
    while (t--)
    {
        cin >> n >> k;
        s=0;
        for (int i=0; i<n; i++)
        {
            cin >> a[i];
            s+=a[i];
        }
        if (s % k !=0) 
        {
            cout << 0 << endl;
            continue;
        }
        s=s/k;
        for (int i=0; i<n; i++) fr[i]=0;
        Try(0);
        int ok=1;
        for (int i=0; i<n; i++)
            if (fr[i]==0){
                ok=0;
                break;
            }
        cout << ok << endl;
    }
}
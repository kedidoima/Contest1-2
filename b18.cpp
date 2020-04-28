#include <iostream>
#include <algorithm>
using namespace std;
int n,minn=100,s,a[100],b[100];
int64_t sum,res=0;

void check();
void TRY(int x);

void init()
{
    sort(a,a+n);
    for (int i=n-1; i>=0; i--)
    {
        if (s>=a[i])
        {
            s=s-a[i];
            res++;
        }
    }
    cout << res;
}

int main()
{
    cin >> n >> s;
    for (int i=0; i<n; i++) cin >> a[i];
    init();
}

void check()
{
    sum=0; 
    int count=0;
    for (int i=0; i<n; i++) 
        if (b[i]==1) 
        {
            sum+=a[i];
            count++;
        }
    if (sum==s && count<minn) minn=count; 
}

void TRY(int x)
{
    for (int i=0; i<=1; i++)
    {
        b[x]=i;
        if (x==n-1) check();
        else TRY(x+1);
    }
}
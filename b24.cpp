#include <iostream>
#include <algorithm>
using namespace std;
int n,minn=100,s,a[20],b[20],c[20],d[10000];
int64_t sum,res=0,dem,m;

void check();
void TRY(int x);
void init()
{
    sort(a,a+n);
    dem=0; m=0;
    TRY(0);
    if (dem==0) 
    {
        cout << -1 << endl;
        return;
        
    }
    for (int i=dem; i>0; i--)
    {
        cout << "[";
        while (c[i]>1) {
            cout << d[m] << " ";
            c[i]--;
            m--;
        }
        cout << d[m] << "] ";
        m--;
    }
    cout << endl;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        cin >> n >> s;
        for (int i=0; i<n; i++) cin >> a[i];
        init();
    }

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
    if (sum==s) 
    {
        dem++;
        c[dem]=0;
        for (int i=n-1; i>=0; i--)
            if (b[i]) 
            {
                m++;
                d[m]=a[i];
                c[dem]++;
            }
    }
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
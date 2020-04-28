#include <iostream>
using namespace std;
int n,k,dem;
int64_t a[500],b[12000];
void xuat()
{
    k++;
    for (int i=0; i<13; i++) 
    {
        b[k]=b[k]*10+a[i]*9;
    }
    if (b[k]==0) k--;
}

void TRY(int x)
{
    for (int i=0; i<=1; i++){
        a[x]=i;
        if (x==12) xuat();
        else TRY(x+1);
    }
}

void init()
{
    k=0;
    TRY(0);
    for (int i=1; i<=500; i++)
    {
        for (int j=1; j<=k; j++)
            if (b[j] % i == 0) 
            {
                a[i]=b[j];
                break;
            }
        //if (a[i]==0) cout << i << endl;
    }
}

int main()
{

    init();    
    int t;
    cin >> t;
    while (t--)
    {
        cin >> n;
        cout << a[n] << endl;
    }
    
}
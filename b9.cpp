#include <iostream>
#include <string>
using namespace std;
int n,m;
string a;
int64_t b[5000],c[5000];

char xor_c(char x, char y)
{
    return (x==y)? '0' : '1'; 
}
void xuat()
{
    /*m++;
    b[m]=0;
    for (int i=0; i<n; i++) 
    {
        b[m]=b[m]*10+a[i];
    }*/
    a="";
    for (int i=0; i<n; i++)
        if (b[i]==0) a+='0';
        else a+='1';
    string g="";
    g+=a[0];
    for (int i=1; i<a.length(); i++) 
        g+=xor_c(a[i-1],a[i]);
    cout << g  << " ";
}

void back_track(int x)
{
    /*if (y==0) 
    {
        for (int i=0; i<=1; i++){
            a[x]=i;
            if (x==n-1) xuat();
            else back_track(x+1,i);
        }
    }
    else 
    {
        for (int i=1; i>=0; i--)
        {
            a[x]=i;
            if (x==n-1) xuat();
            else back_track(x+1,i);
        }
    }*/
    for (int i=0; i<=1; i++)
    {
        b[x]=i;
        if (x==n-1) xuat();
        else back_track(x+1);
    }
}

void xuatc()
{
    for (int i=1; i<m; i++)
    {
        int64_t tg=c[i],count=0;
        while (tg>0) 
        {
            count++;
            tg=tg/10;
        }
        while (count<n) 
        {
            cout << 0;
            count++;
        }
        cout << c[i] << endl;
    }
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        cin >> n;
        m=0;
        back_track(0);
        cout << endl;
    }
}
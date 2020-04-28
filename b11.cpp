#include <iostream>
#include <string>
using namespace std;
int n,m;
string a;
int64_t b[5000],c[5000];

char flip(char x)
{
    return (x=='0')? '1' : '0'; 
}
void xuat()
{
    /*m++;
    b[m]=0;
    for (int i=0; i<n; i++) 
    {
        b[m]=b[m]*10+a[i];
    }*/
    string g="";
    g+=a[0];
    for (int i=1; i<a.length(); i++) 
        if (a[i]=='0')
            g+=g[i-1];
        else g+=flip(g[i-1]);
    cout << g  << endl;
}

int main()
{
    int t;
    cin >> t;
    cin.ignore();
    while (t--)
    {
        getline(cin,a);
        xuat();
    }
}
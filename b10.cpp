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
    string g="";
    g+=a[0];
    for (int i=1; i<a.length(); i++) 
        g+=xor_c(a[i-1],a[i]);
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
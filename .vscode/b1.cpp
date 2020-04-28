#include <iostream>

#include <string.h>
using namespace std;

int main()
{
    int t;
    string s;
    cin >> t;
    cin.ignore();
    while (t--)
    {
        getline(cin,s);
        bool ok=true;
        int n=s.length();
        for (int i=0; i<n; i++)
            if (s[i]=='0') ok=false;
        if (ok) {
            
            for (int i=0; i<n; i++) cout << 0;
        }
        else {

            for (int i=n-1; i>=0; i--)
                if (s[i]=='0') {
                    s[i]='1';
                    for (int j=i+1; j<n; j++) s[j]='0';
                    break;
                }
            cout << s;
        }
        cout << endl;
    }
}
#include <iostream>
#include <string>
using namespace std;
int main()
{
    int t,k,l,r;
    string s;
    cin >> t;
    while (t--)
    {
        cin >> k;
        cin >> s;
        l=0; r=s.length()-1;
        while (l<r && k>0)
        {
            char tg=s[l];
            int pos=-1;
            for (int i=r; i>l; i--) 
                if (s[i]>tg)
                {
                    pos=i;
                    tg=s[i];
                }
            if (pos>0) 
            {
                tg=s[l];
                s[l]=s[pos];
                s[pos]=tg;
                k--;
            }
            l++;
        }
        cout << s << endl;
    }
}
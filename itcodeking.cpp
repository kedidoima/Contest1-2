#include <iostream>
#include <fstream>
#include <math.h>
#include <string>
#define p 1000000007
int gcd(int x, int y) {
    if (y==0) return x;
    return gcd(y,x%y);
}

using namespace std;
int main(){
    int n,a[100002],st[100005],pos[100005],top,tr,l,r;
    int64_t b[100002],maxx=0;
    cin >> n;
    for (int i=1; i<=n; i++) cin >> a[i];
    for (int i=1; i<=n; i++) cin >> b[i];
    for (int i=2; i<=n; i++) b[i]=b[i-1]+b[i];
    st[1]=a[1]; pos[1]=1; top=1; l=1; r=1; maxx=b[1]; b[0]=0;
    for (int i=2; i<=n; i++){
        tr=i;
        while (top>0 && a[i]>=st[top]){
            top--;
        }
        if (top==0) tr=1;
        else tr=pos[top]+1;
        top++;
        st[top]=a[i]; pos[top]=i;
        if (b[i]-b[tr-1]>maxx){
            maxx=b[i]-b[tr-1];
            l=tr; r=i;
        }
    }
    cout << l-1 << " " << r-1;
}
#include <iostream>
using namespace std;
 
int n,k,s;
int a[100],dem = 0;
 
void tinh(){
	int tong = 0;
	for(int i=1;i<=k;i++){
		tong += a[i];
	}
	if(tong == s) dem++;
}
 
void quaylui(int i){
	for(int j=a[i-1]+1; j<=n-k+i;j++){
		a[i] = j;
		if(i == k) tinh();
		else quaylui(i+1);
	}
}
 
main(){
	while(true){
		cin>>n>>k>>s;
		if(n==0 && k==0 && s==0){
			break;
		}
		quaylui(1);
		cout<<dem<<endl;
		dem=0;
	}
}
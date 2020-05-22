#include<iostream>
#include<math.h>
#include<vector>
using namespace std;

int n,s,a[1000],b[1000],stop=0,outp=0;

void sinh(int k){
	int i=k;
	while(b[i]==n-k+i) i--;
	if(i==0) stop=1;
	else {
		b[i]++;
		for (int j=i+1;j<=n;j++) b[j]=b[j-1]+1;
	}
}

void duyet(int k){
	int tong=0,dem=0;
	for (int i=1;i<=k;i++){
			dem++;
			tong+=a[b[i]];
			if(tong>s) break;
	}
	if(tong==s) outp = dem;
}

int main(){
	cin>>n>>s;
	for (int i=1;i<=n;i++) cin>>a[i];
	int i=1;
	while(true){
		for (int j=1;j<=i;j++) b[j]=j;
		while(!stop){
			duyet(i);
			sinh(i);
			if(outp!=0) break;
		}
		if(outp!=0){
			cout<<outp<<endl;
			break;
		}
		i++;
		stop=0;
	}
return 0;
}

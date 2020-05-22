#include<iostream>
#include<math.h>
#include<vector>
using namespace std;
int x[100],xuoi[100],nguoc[100],cot[100],dem=0,n=8,a[100][100],kq=0;

void init(){
	for (int i=1;i<=n;i++)
		for (int j=1;j<=n;j++) cin>>a[i][j];
	
	for (int i=1;i<=n;i++) cot[i]=0;
	for (int i=1;i<=n*2-1;i++){
		xuoi[i]=0;
		nguoc[i]=0;
	}
}

void in(){
	int tong=0;
	for (int i=1;i<=n;i++) tong+=a[i][x[i]];
	if(tong>kq) kq=tong;
}

void Try(int i){
	for (int j=1;j<=n;j++){
		if(!cot[j] && !xuoi[i+j-n] && !nguoc[i-j+1]){
			x[i]=j;
			cot[j]=1;
			xuoi[i+j-n]=1;
			nguoc[i-j+1]=1;
			if(i==n){
				in();
			}
			else Try(i+1);
			cot[j]=0;
			xuoi[i+j-n]=0;
			nguoc[i-j+1]=0;
			
		}
	}
}

int main(){
	int t;
	cin>>t;
	while(t--){
		init();
		Try(1);
		cout<<kq<<endl;
		kq=0;
	}

return 0;
}
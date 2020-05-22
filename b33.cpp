#include<iostream>
#include<math.h>
#include<vector>
using namespace std;
int x[100],xuoi[100],nguoc[100],cot[100],dem=0,n;

void init(){
	cin>>n;
	for (int i=1;i<=n;i++) cot[i]=0;
	for (int i=1;i<=n*2-1;i++){
		xuoi[i]=0;
		nguoc[i]=0;
	}
}

void Try(int i){
	for (int j=1;j<=n;j++){
		if(!cot[j] && !xuoi[i+j-n] && !nguoc[i-j+1]){
			x[i]=j;
			cot[j]=1;
			xuoi[i+j-n]=1;
			nguoc[i-j+1]=1;
			if(i==n) dem++;
			else Try(i+1);
			cot[j]=0;
			xuoi[i+j-n]=0;
			nguoc[i-j+1]=0;
			
		}
	}
}

int main(){
	init();
	Try(1);
	cout<<dem<<endl;
return 0;
}

#include<iostream>
#include<math.h>
#include<vector>
using namespace std;

//bai 36

int a[10],x[10],b[10],n=5,isDone=0;
bool check[10]={false};

void in(){
	int tong=x[b[1]];
	for (int i=1;i<n;i++) {
		if(a[i]==1) tong+=x[b[i+1]];
		else if(a[i]==2) tong-=x[b[i+1]];
		else tong*=x[b[i+1]];
	}
	if(tong==23) isDone=1;
}

void TryDau(int i){ //quay lui hoan vi 3 dau(+ * -) cho 4 vi tri 
	if(!isDone)
		for (int j=1;j<=3;j++){
			if(isDone) break;
			a[i]=j;
			if(i==n-1) in(); 
			else TryDau(i+1);
		}
}

void TryHV(int i){ //hoan vi 5 vi tri cua 5 so
	if(!isDone)
		for (int j=1;j<=n;j++){ 
			if(isDone) break;
			if(!check[j]){
				b[i]=j;
				check[j]=true;
				if(i==n) TryDau(1);
				else TryHV(i+1);
				check[j]=false;
			}
		}
}

int main(){
	int t;
	cin>>t;
	while(t--){
		for (int i=1;i<=n;i++) {
			cin>>x[i];
			check[i]=false;
		}
		TryHV(1);
		if(isDone) cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
		isDone=0;
	}

return 0;
}
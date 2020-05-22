#include<iostream>
#include<math.h>
#include<vector>
using namespace std;

//bai 40: bai toan nguoi du lich
int n, c[100][100], fopt = 32000, can = 0, b[100]={0} , a[100], cMin=0;

//b[] kiem tra xem thanh pho nao da duoc chon
//a[] luu diem den cua thanh pho theo hang

int findMinMatrix(){
	int min = c[1][2];
	for(int i=1;i<=n;i++)
		for (int j=1;j<=n;j++) 
			if(c[i][j] < min && j!=i ) min=c[i][j];
	return min; 
}

void updateKyLuc(){
	int sum;
	sum = can + c[a[n]][a[1]];
	if(sum<fopt) fopt = sum;
}


void Try(int i){
	for (int j=2;j<=n;j++){
		if(!b[j]){
			a[i]=j;
			b[j]=1; // check la da den thanh pho 
			can+=c[a[i-1]][a[i]];
			if(i==n) updateKyLuc();
			else if(can + (n-i+1) * cMin <fopt){ //cap nhat dieu kien g
				Try(i+1);
			}
			b[j]=0;
			can-= c[a[i-1]][a[i]];
		}
	}
}

int main(){
	cin>>n;
	a[1] = 1;
	cMin = findMinMatrix();
	for (int i=1;i<=n;i++)
		for (int j=1;j<=n;j++) cin>>c[i][j];
	Try(2);
	cout<<fopt<<endl;
	
return 0;
}
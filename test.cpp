#include <bits/stdc++.h>
using namespace std;

int main(){
 ios_base::sync_with_stdio(0);
 cin.tie(0);
 
 int t; cin>>t;
 while(t--){
 	int n,m;
 	cin>>n>>m;
 	long long a[n+5],b[m+5];
 	for (int i=0;i<n;i++) cin>>a[i];
 	for (int i=0;i<m;i++) cin>>b[i];
 	sort(a,a+n); sort(b,b+m);
 	int i=0,j=0;
	a[n]=100000000; b[m]=10000000;
	while(i<n || j<m){
		if(a[i]<=b[j] && i<n){
			cout<<a[i]<<' ';
			i++;
			continue;
		}
		if(a[i]>b[j] && j<n){
			cout<<b[j]<<' ';
			j++;
			continue;
		}
	}
	cout<<endl;
 }
return 0;
}



/*#include <bits/stdc++.h>
using namespace std;

void quickSort(int16_t *a, int left, int right){
	int i = left, j = right;
	int mid = (left+right)/2;
	while(i<=j){
		while(a[i] < a[mid] && i<=j) i++; 
		while(a[j] > a[mid] && i<=j) j--; 
		if(i<=j){
			swap(a[i],a[j]);
			i++,j--; 
		}
	}
	if(i<right) quickSort(a,i,right);
	if(j>left) quickSort(a,left,j);
}

int main(){
 ios_base::sync_with_stdio(0);
 cin.tie(0);
 
 int t; cin>>t;
 while(t--){
 	int n;
 	cin>>n;
 	int16_t *a = new int16_t(n);
 	for (int i=0;i<n;i++) cin>>a[i];
 	quickSort(a,0,n-1);
 	for (int i=0;i<n;i++) cout<<a[i]<<' ';
 	cout<<endl;
 }
return 0;
}/*/
#include <bits/stdc++.h>
using namespace std;
int main (){
	string s;
	long long n;
	cin>>s>>n;
	long long check=s.size();
	while(n>check){
		check*=2;
	}
	int len=s.size();
	while(n>len){
		if(n>check/2){
			n-=check/2;
			n--;
			if(n==0) n=check/2;
		}
		check/=2;
	}
	cout<<s[n-1];
	return 0;
}
#include <iostream>
#include <fstream>
#include <math.h>
#include <string>
using namespace std;
int main(){
	ifstream fi("password.txt");;

	//fi.ignore();
	string s,res;
	int maxx=0;
	while (!fi.eof()) {
		getline(fi,s);
		bool ok=false;
		string s1;
		for (int i=0; i<s.length(); i++){
			for (int j=s.length()-1; j>i; j--)
			{
				s1="";
				for (int ii=i; ii<=j; ii++) s1=s1+s[ii];
				string ss="";
				for (int ii=0; ii<s1.length(); ii++) ss=s1[ii]+ss;
				if (s1.compare(ss)==0) {
					cout << s1 << endl;
					if (s1.length()>maxx) {
						res=s1;
						maxx=s1.length();
					}
					ok=true;
					break;
				}
				if (ok) break;
			}
			if (ok) break;
		}
	}
	cout << res;
}
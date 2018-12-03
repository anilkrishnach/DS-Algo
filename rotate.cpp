#include<iostream>
using namespace std;
int main(){
	int n=1;
	int len;
	cin>>len;
	while(n*(n+1)/2!=len*n){
		n++;
	}
	cout<<n;
}

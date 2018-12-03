#include<iostream>
using namespace std;
int a[100];
int count;
int fib(int n){
	count++;
	if(n==0)
		return 0;
	if(n==1)
		return 1;
	if(a[n])
		return a[n];
	else
	{
		a[n]=fib(n-1)+fib(n-2);
		return a[n];
	}
}
int fact(int n){
	count++;
	if(n<=1)
		return 1;
	if(a[n])
		return a[n];
	else{
		a[n] = n*fact(n-1);
		return a[n];
	}
}
int main(){
	int n;
	cin>>n;
	int r;
	cin>>r;
	cout<<fact(n)/(fact(n-r)*fact(r))<<"\n";
}

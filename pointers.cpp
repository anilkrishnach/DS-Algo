#include<iostream>
using namespace std;
int main(){
	int a[3][3];
	int *p;
	p=a[0];
	for(int i=0;i<9;i++){
		*p=i+1;
		p++;
	}
	for(int i=0;i<3;i++)
	for(int j=0;j<3;j++)
		cout<<a[i][j]<<"\n";
}

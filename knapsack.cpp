#include<iostream>
using namespace std;
int main(){
	int c;
	cin>>c;
	while(c--){
		int n;
		cin>>n;
		int max;
		cin>>max;
		int w[n], val[n];
		for(int i=0;i<n;i++)
			cin>>val[i];
		for(int i=0;i<n;i++)
			cin>>w[i];
		int a[n+1][max+1];
		for(int i=0;i<n+1;i++){
			for(int j=0;j<max+1;j++){
				if(i==0 || j==0)
					a[i][j]=0;
				else{
					int include= w[i-1]<=j ? val[i-1]+a[i-1][j-w[i-1]]: 0;
					int exclude=a[i-1][j];
					include>exclude?a[i][j]=include:a[i][j]=exclude;
				}
			}
		}
		cout<<a[n][max]<<"\n";
	}
}

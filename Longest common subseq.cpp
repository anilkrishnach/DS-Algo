#include<iostream>
#include<stack>
#include<algorithm>
using namespace std;
int main(){
	int c;
	cin>>c;
	while(c--){
		int n;
		cin>>n;
		int a[n];
		for(int i=0;i<n;i++)	
			cin>>a[i];
		int count[n];
		fill(count,count+n,1);
		count[0]=1;
		for(int i=1;i<n;i++){
			for(int j=0;j<i;j++){
				if(a[i]>a[j]){
					cout<<"YES ";
					count[i] = max(count[j]+1, count[i]);
				}
				cout<<a[i]<<" "<<a[j]<<" "<<count[i]<<"\n";
			}
		}
		int max=0;
		for(int i=0;i<n;i++)
			cout<<count[i]<<" ";
//			if(count[i]>max)
//				max=count[i];
//		cout<<max<<"\n";
	}
}

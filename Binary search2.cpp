#include<iostream>
using namespace std;

int main(){
	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++)
		cin>>a[i];
	int temp=6;
	while(temp--)
	{
		int key;
		int l=0, r=n;
		cin>>key;
		int mid;
		while(l<=r){
			mid=(l+r)/2;
			if(a[mid]==key){
				cout<<"Found at mid: "<<mid<<"\n";
				break;
			}
			else if(a[mid]<key)
				l=mid+1;
			else
				r=mid-1;
		}
		if(l>r)
			cout<<"Coudln't find\n";
	}
}

#include<iostream>
using namespace std;
int search(int a[], int key, int left, int right){
	while(left<=right){
		int mid = (right-left)/2+left;
		if(a[mid]==key)
			return mid;
		else if(a[mid]>key)
			right = mid-1;
		else
			left = mid+1;
	}
	return -1;
}
int floor(int a[], int key, int left, int right){
	
	while(left<right){
		int mid = (left+right)/2;
//		cout<<mid<<"\n";
		if(a[mid]<=key){
			if(a[mid+1]>key)
				return a[mid];
			else
				left = mid;
		}
		else 
			right = mid;
	}
}

int main(){	
	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++)	
		cin>>a[i];
	int c;
	cin>>c;
	while(c--){
		int key;
		cin>>key;
		cout<< floor(a, key, 0 , n-1)<<"\n";
	}
}

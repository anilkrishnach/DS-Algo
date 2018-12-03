#include<iostream>
using namespace std;
int main(){
	int c;
	cin>>c;
	while(c--){
		string a,b;
		cin>>a>>b;
		int n=a.length(), m=b.length();
		int mat[n+1][m+1];
		for(int i=0;i<n+1;i++){
			for(int j=0;j<m+1;j++){
				if(i==0||j==0){
					mat[i][j]=i>j?i:j;
				}
				else{
					if(a[i-1]==b[j-1]){
						mat[i][j]=mat[i-1][j-1];
					}
					else{
						mat[i][j]=min(min(mat[i-1][j-1],mat[i][j-1]), mat[i-1][j])+1;
					}
				}
			}
		}
		cout<<mat[n][m]<<"\n";
	}
}

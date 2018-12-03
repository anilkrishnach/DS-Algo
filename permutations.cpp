#include<iostream> 
#include<algorithm>
using namespace std;
int co=0;
void perm(int count[], string res){
	bool flag=false;
	for(int i=0;i<26;i++){
		if(count[i])
		{
			count[i]--;
			flag=true;
			perm(count, res+(char)(i+97));
			count[i]++;
		}
	}
	if(!flag)
	{
		cout<<res<<"\n";
		return;
	}
}
int main(){
	string c;
	cin>>c;
	int l=c.length();
	int a[26];
	fill(a,a+26,0);
	for(int i=0;i<l;i++)
		a[c[i]-97]++;
	perm(a,"");
}

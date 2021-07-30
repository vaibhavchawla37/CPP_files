#include<iostream>
#include<algorithm>
using namespace std;
bool compare(int a , int b){
	cout << "compare "<<a<<" , "<<b<<endl;
	return a>b;
}
int main(){
	int n ,key;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++)
		cin>>a[i];
	
	sort(a,a+n,compare);
	 
	for(int i=0;i<n;i++)
		cout<<a[i]<<" ";
	return 0;
}

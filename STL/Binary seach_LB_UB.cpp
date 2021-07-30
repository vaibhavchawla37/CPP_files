#include<iostream>
#include<algorithm>
using namespace std;

int main(){
	int a[]={20,30,40,40,40,50,1100};
	int n=sizeof(a)/sizeof(int);
	int key=40;
	bool present = binary_search(a,a+n,key);
	cout<<boolalpha<<present<<endl;
	
	int* lb=lower_bound(a,a+n,key);
	cout<<lb-a<<endl;
	
	int* ub =upper_bound(a,a+n,key);
	cout<<ub-a;
	
	
}

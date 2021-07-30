#include<iostream>
using namespace std;
float sqrt_bs(int n){
	int s=0;
	int l=n;
	float ans;
	int p=3;
	
	while(s<=l){
		int m=(s+l)/2;
		if(m*m==n){
			ans=m;
			return m;
		}
		else if(m*m<n){
			ans=m;
			s=m+1;
			}
		else{
			l=m-1;
		//	ans=m;
			}
	}	
	
	float i=0.1;
	for(int t=0;t<p;t++){
		while(ans*ans<=n){
			ans=ans+i;
		}
		ans=ans-i;
		i=i/10;
	}
	
	return ans ;	
}

int main(){
	int n;
	cin>>n;
cout<<	sqrt_bs(n);

	return 0;
}

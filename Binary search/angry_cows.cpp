#include<iostream>
using namespace std;

bool cow_place(int stalls[],int n,int c,int min_step){
	int last_pos=stalls[0];
	int cnt=1;
	
	for(int i=1;i<n;i++){
		if((stalls[i]-last_pos)>=min_step){
			last_pos=stalls[i];
			cnt++;
			if(cnt==c)
				return true;
		}
	}
	return false;
}

int main(){
	int stalls[] = {1,2,4,8,9};
	int n=5;
	int c=3;  
	
	int s=0;
	int l=stalls[n-1]-stalls[0];
	int ans=0;
	while(s<=l){
		int m=(s+l)/2;
		bool condition = cow_place(stalls,n,c,m);
		//cout<<boolalpha<<m<<" : "<<condition<<endl;
		if(condition){
		//	cout<<m<<endl;
			ans = m;
			s=m+1;
		}
		else{
			l=m-1;
		}
	}
	cout<<ans;
	
	return 0;	
}

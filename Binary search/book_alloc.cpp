#include<iostream>
using namespace std;

bool can_alloc(int p[],int n,int s,int min_pages){
	int stu=1;
	int page_alloc=p[0];
	for(int i=1;i<n;i++){
		if(page_alloc+p[i]<=min_pages){
			page_alloc+=p[i];
		}
		else {
			stu++;
			page_alloc=p[i];
			if(stu>s)
				return false;
		}
	}
	return true;
}

int main(){
	int pages[] = {10,20,30,40};
	int N=4;
	int S=2;  
	
	int s=pages[N-1];
	int l=0;
	int sum=0;
	for(int i=0;i<N;i++)
		l=l+pages[i];
	sum=l;
	int ans=10000000;
	while(s<=l){
		int m=(s+l)/2;
		bool condition = can_alloc(pages,N,S,m);
		cout<<boolalpha<<m<<" : "<<condition<<endl;
		if(condition){
			cout<<m<<endl;
			ans = min(m,ans);
			l=m-1;
			
		}
		else{
			s=m+1;
		}
	}
	cout<<ans;
	
	return 0;	
}

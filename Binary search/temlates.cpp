#include<iostream>

#include<vector>
using namespace std;

template<class foreward_iterator,class T> 
foreward_iterator search(foreward_iterator start,foreward_iterator end,T key){
	while(*start!=key){
		if (start==end){
			return start;
		}
		start++;
	}
	return start;
}

int main(){
	vector<int> l;
	l.push_back(3);
	l.push_back(4);
		l.push_back(8);
	l.push_back(7);
	l.push_back(9);
	vector<int>::iterator it;
	it =search(l.begin(),l.end(),3);
	if (it ==l.end())
		cout<<"Not found";
	else
		cout<<"element "<<*it<<" found at : "<<(it-l.begin());
	
}

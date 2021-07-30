#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>
using namespace std;

class Car{
    public:
    string car_name;
    int x,y;
    Car(){

    }
    Car(string n,int x,int y){
        this->x=x;
        this->y=y;
        this->car_name=n;
    }
    int dist(){
        return x*x + y*y;
    }

};


bool compare(Car A,Car B){
    
    int da = A.dist();
    int db = B.dist();
    if (da==db){
        if(A.car_name.length()<B.car_name.length())
            return true;
        else return false;
        }
    else if(da<db)
        return true;    
    return false;
}

int main(){
    int n ;
    cin>>n;
    vector<Car> v;
    for (int i = 0; i < n; i++)
    {
        int x,y;
        string name;
        cin>>name;
        cin>>x>>y;
        Car temp(name,x,y);
        v.push_back(temp);
    }
    sort(v.begin(),v.end(),compare);
    for (auto x:v){
        cout<<x.x<<" ";
        cout<<x.y<<" ";
        cout<<" : "<<x.dist()<<" ";
        cout<<x.car_name<<endl;
    }

    
    return 0;
}

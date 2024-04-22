#include<iostream>
using namespace std;

int main(){
    enum Day {sun=7,mon=1,tue,wed,thu,fri,sat};
    Day d1,d2;
    d1=sun;
    d2=(Day)1;
    cout<<d1<<endl;
    cout<<d2;
    return 0;
}
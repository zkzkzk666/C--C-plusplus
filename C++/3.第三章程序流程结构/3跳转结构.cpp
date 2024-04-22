#include<iostream>
using namespace std;

int main(){
    //break
    for (int i = 0; i < 5; i++)
    {
        for (size_t j = 0; j < 5; j++)
        {
            if (j==2)
            {
                break;
            }
            cout<<i<<"and"<<j<<endl;
        }
    }
    //continue
    for (int i = 0; i < 5; i++)
    {
        for (size_t j = 0; j < 5; j++)
        {
            if (j==2)
            {
                continue;
            }
            cout<<i<<"and"<<j<<endl;
        }
    }
    //goto
    goto FLAG;
    cout<<"111"<<endl;
    FLAG:
    cout<<"666"<<endl;
    return 0;
}
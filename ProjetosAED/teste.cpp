#include <iostream>
#include <string>

using namespace std;

int main(){

    string oi,oi2;

    getline(cin,oi);
    getline(cin,oi2);

    cout<<oi<<" a "<<oi2;
    if(oi == oi2)
        cout<<"\nopa";
}
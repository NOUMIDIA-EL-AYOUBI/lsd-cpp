#include <iostream>
#include <cmath>
using namespace std;

template<typename type>



type multiply(int n,type m)
{
    cout<<"\n result of multiplication ="<<n*m<<endl;
    return n*m;
}





int main()
{
    int n;
    float m;
    cout<<"\n Enter un entier ";
    cin>>n;
    cout<<"\n Enter un reel: ";
    cin>>m;
    multiply(n,m);  
    
}




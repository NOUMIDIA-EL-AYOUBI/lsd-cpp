#include <iostream>
#include <cmath>
using namespace std;

template<typename type>


type powiter(type a , int p)
{
    type pow = 1;
    while(p>0)
    {
        if(p&1)
            pow=pow*a;
        a=a*a;
        p=p>>1;
    }
    return pow;
}


template<typename type>
type powrec(type a , int p)
{
    if(p==0)
        return 1;
    if(p%2==0)
        return powrec(pow(a,2),p/2);
    else
        return powrec(pow(a,2),(p-1)/2)*a;
}


int main()
{
    int n;
    float m;
    cout<<"\n Enter un entier ";
    cin>>n;
    cout<<"\n Enter un reel: ";
    cin>>m; 
    cout<<"\n power ="<<powiter(m,n)<<endl; 
    cout<<"\n power ="<<powrec(m,n)<<endl;
}


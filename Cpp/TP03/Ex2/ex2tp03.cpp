#include<iostream>

using namespace std;

class shape{

    protected:
    float width;
    float height;
    public:
    shape(float x, float y):width{x},height{y}{}
    virtual float area( ) = 0;  
};

class rectangle : public shape{

    public:
    rectangle(float x, float y):shape(x, y) {}  
    float area()
    {
        return width*height;
    }
};

class triangle : public shape{
    
    public :
    triangle(float x, float y):shape(x, y) {}  
    float area()
    {
        return width*height*0.5;
    }
};

int main()
{
    float w=5;
    float h=6;
    rectangle A(w,h);  
    triangle B(w,h);  
    cout<<"Area of rectangle :"<<endl;
    float sr= A.area();
    cout<<sr<<endl;
    cout<<"Area of triangle"<<endl;
    float st =B.area();
    cout<< st <<endl;
}


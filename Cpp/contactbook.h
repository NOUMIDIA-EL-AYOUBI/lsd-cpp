#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

class contact
{
    public:
    string first_name;
    string second_name;
    string nickname ;
    int number;
    void display( int i);
    void display_all( int i);
};

class phonebook
{
    public:
    contact* C{new contact [8]{}}; //C[8]{};
    int size=0;
    void add();
    void search (int);
    void exit ();
};


void afficher(string s)
{
    int len = s.size();
    if (len < 10) {
        if((len-10)%2==0){
                int pad_len = (10 - len) / 2;
                cout << string(pad_len, ' ') + s+ string(pad_len, ' ') << '|'; 
                         }

        else             {
                int pad_len = (10 - len) / 2;
                cout << string(pad_len, ' ') + s+ string(pad_len+1, ' ') << '|';

                         }

                  }
    else{
           string s2=s.substr(0,9);
           cout<<s2<<'.'<<'|';
        }
    

}
void contact::display( int i)
{
    cout.width(10);
	cout << ( to_string(i)) +"    "<<'|';
    afficher(first_name);
    afficher(second_name);
    afficher(nickname);
    cout<<endl;
    
}



void contact::display_all(int i)
{
	printf("index:%d \nfirst name: %s \nlast name: %s \nnickname: %s \n",i,first_name.c_str(),second_name.c_str(),nickname.c_str());
	
}


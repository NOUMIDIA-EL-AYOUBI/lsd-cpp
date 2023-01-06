
#include"contactbook.h"

void phonebook :: add()
{
   if (size>=8) size =0;

   cout << "Saisir votre nom : ";
   cin >> C[size].first_name ;
   cout << "Saisir votre prenom : ";
   cin >> C[size].second_name ;
   cout << "Saisir votre surnom : ";
   cin >> C[size].nickname ;
   cout << "Saisir votre numero de telephone : ";
   cin >> C[size].number ;
   size+=1;
      
}

void phonebook :: search(int i)
{
    //les colonnes 
    cout << '\n';
    cout<< "   index  " << '|';
    cout<< "firstname " << '|';
    cout<< "secondname" << '|';
    cout<< " nickname " << '|';
    cout<<endl;
    //saved contacts
    for (int j=0;j<size;j++)
    {
       contact s_contact = C[j];
       s_contact.display(j);
    }
    cout<<'\n';
    //wrong index
    if (i<0 or i>size) cout<<"you can only choose numbers from 0 to "<<to_string(size-1)<<endl;
    else
    {
    //data of index i
    cout<<"searched contact : "<<endl;
    contact s_contact = C[i];
    cout<<endl;
    s_contact.display_all(i);
    cout<<'\n';
    }
}
void phonebook::exit()
{
	delete [] C;
    size=0;
    C= new contact[8];
	cout<<"the phonebook is empty"<<endl;
}

int main()
{
    
   phonebook A ;
   int j=0;
    while(j<3)
    {
   cout<<"choisir une des commandes suivantes en tapant le numero de la commande : Add(1),Search(2),Exit(3); if you choose 3 (exit) you will delete contacts and quit"<<'\n';
    cin>>j;
    if (j==1) A.add(); 
    if(j==2)
    {
        int k=0 ;
        cout<<"entrer l'indice du contact"<<endl;
        cin>>k;
        A.search(k);
    } 
    if(j==3) A.exit();
    }
 } 

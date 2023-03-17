#include <iostream>
#include <fstream>
#include <string>
using namespace std;

bool login()
{
    string username, password, un, pw;

    cout<<"Enter username: ";
    cin>> username;
    cout<<"Enter password: ";
    cin>> password;

    ifstream read ("manager.txt");
    getline(read, un);
    getline(read, pw);
    if(un == username && pw == password)
    {
        return true;
    }
    else
    {
        return false;
    }

}

int main ()
{
    int choice;
    cout<< "1.sign up "<<endl<<"2. login"<<endl;
    cin>>choice;
    if(choice == 1 )
    {
        string username, password;
        cout<< "Select a userName: ";
        cin>>username;
        cout<<"Select a password: ";
        cin>>password;
        ofstream file;
        file.open("manager.txt", ios::out|ios::app);
        file<<username<<endl<<password;
        file.close();
        main();

    }
    else if(choice ==2)
    {
        bool status = login();
        if(!status)
        {
            cout<<" False login!"<<endl<<"1. Try again"<<endl<<"2. Pause this"<<endl;
            int ch;
            cin>>ch;
            if(ch == 1)
            {
                main();
            }
            else{
               return 0;
            }

        }
        else{

            cout<<"Successfully logged in"<<endl;
            return 1;
        }
    }
}







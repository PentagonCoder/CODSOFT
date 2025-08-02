#include<iostream>
using namespace std;
int main(){
    //Calculator program
    cout << "Welcome to the calculator program!" << endl;
    //Input Two number 
    cout<<"enter first number :";
    int n;
    cin>>n;
    //input second number
    cout <<"enter second number :";
    int m;
    cin>>m;
    //slect opration 
    cout<<"1. sum"<<endl;
    cout<<"2. subtraction"<<endl;
    cout<<"3. multiplication"<<endl;
    cout<<"4. division"<<endl;     
    int choice;
    cout<<"enter your choice :";
    cin>>choice; 
    switch (choice)
    {
    case (1):
        cout<<"sum is :"<<n+m<<endl;
        break;
    case (2):
        cout<<"subtraction is :"<<n-m<<endl;
        break;
    case (3):
        cout<<"multiplication is :"<<n*m<<endl;
        break;
    case (4):
        if (m != 0) {  
            cout<<"division is :"<<n/m<<endl;
        }   
        else {
            cout<<"division by zero is not allowed"<<endl;
        }   
        break;
    default:
        break;
    }
    cout<<"thank you for using this calculator"<<endl;
    cout << "Press Enter to exit...";
    cin.ignore();
    cin.get(); // Waits for user input before closing
    return 0;
}

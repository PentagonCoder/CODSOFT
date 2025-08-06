// task2.cpp
#include <iostream>
#include <string>
#include <vector>
using namespace std;
int toperformtask(){

}
int toaddtask(){
    string task;
    cout << "Enter the task to add: ";
    cin.ignore();   
    getline(cin, task);
    cout << "Task added: " << task << endl;
    return 0;
}
int toviewtask(){
    cout << "Viewing tasks..." << endl;
    // Here you would typically display the tasks stored in a vector or list.
    return 0;
}
int tocompletetask(){
}
int todeletetask(){
}
int toexitprogram(){
}

int main() {
    vector<char>task;
    int id;
    cin>>id;
    while (id >0 && id <6)
    {
        /* code */
    }
    
    if (id <=0) {
        cout << "Invalid task ID" << endl;
        return 1;
    }
    task.push_back(id);

    cout << "wellcome to our To do list" << endl;
    
    return 0;
}

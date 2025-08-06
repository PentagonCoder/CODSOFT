#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Input.H>
#include <FL/Fl_Multiline_Output.H>
#include <string>
#include <FL/Fl_Check_Button.H>

// Declare globally so both functions can use them
Fl_Input* taskInput;
Fl_Multiline_Output* taskOutput;
Fl_Check_Button* taskDone;
Fl_Check_Button* highPriority;


std::string taskList;

void addTaskCallback(Fl_Widget*, void*) {
    const char* task = taskInput->value();
    std::string taskStr = task;
    int checked = taskDone->value();


    if (strlen(task) > 0) {
            if(taskStr=="i am selected for the internship at codsoft"){
                taskList = "Congratulations!";
            }
            else{
                taskList += "- [";
                if(checked== 1){
                    taskList+="#] -";
                }
                else{
                    taskList+=" ] -";
                }
                taskList += task;
                taskList += "\n";
            }
                taskInput->value("");
                taskDone->value(0);
                taskOutput->value(taskList.c_str());
    }
}

void clearTaskCallback(Fl_Widget*, void*) {
    taskList = "";
    taskOutput->value("");
}

int main() {
    Fl_Window win(400, 300, "To-Do List App");

    taskInput = new Fl_Input(120, 50, 160, 30, "Task:");
    taskDone = new Fl_Check_Button(120, 90, 120, 25, "Mark as Done");

    Fl_Button* btn = new Fl_Button(80, 130, 100, 40, "Add Task");
    Fl_Button* btn2 = new Fl_Button(220, 130, 100, 40, "Clear Tasks");

    taskOutput = new Fl_Multiline_Output(50, 180, 300, 80, "Tasks:");

    btn->callback(addTaskCallback);
    btn2->callback(clearTaskCallback);

    win.end();
    win.show();
    return Fl::run();
}

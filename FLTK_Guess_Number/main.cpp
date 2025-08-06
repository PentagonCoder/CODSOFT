#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Input.H>
#include <FL/Fl_Multiline_Output.H>
#include <string>
#include <cstdlib>
#include <ctime>

Fl_Input* taskInput;
Fl_Multiline_Output* taskOutput;
int secretNumber;
std::string taskList;

void addTaskCallback(Fl_Widget*, void*) {
    const char* task = taskInput->value();
    double num = atof(task);  // Convert input to number

    if (secretNumber > num) {
        taskList += "Too low! You guessed: ";
    } else if (secretNumber < num) {
        taskList += "Too high! You guessed: ";
    } else {
        taskList += "🎉 Congratulations! You guessed it: ";
    }

    taskList += std::to_string((int)num) + "\n";
    taskInput->value("");  // Clear input box
    taskOutput->value(taskList.c_str());  // Update output
}

void clearTaskCallback(Fl_Widget*, void*) {
    taskList = "";
    taskOutput->value("");
    secretNumber = rand() % 100 + 1;  // New secret number
}

int main() {
    srand(time(0));  // Seed random
    secretNumber = rand() % 100 + 1;

    Fl_Window win(400, 300, "Guess the Number Game");
    taskInput = new Fl_Input(120, 50, 160, 30, "Enter Number:");
    Fl_Button* btn = new Fl_Button(80, 130, 100, 40, "Check");
    Fl_Button* btn2 = new Fl_Button(220, 130, 100, 40, "Clear");

    taskOutput = new Fl_Multiline_Output(50, 180, 300, 80, "Output:");

    btn->callback(addTaskCallback);
    btn2->callback(clearTaskCallback);

    win.end();
    win.show();
    return Fl::run();
}

#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Input.H>
#include <FL/Fl_Output.H>
#include <string>

// Global widgets
Fl_Input *num1_input, *num2_input;
Fl_Output *result_output;

void addCalculator(Fl_Widget*, void*) {
    const char* num1_str = num1_input->value();
    const char* num2_str = num2_input->value();
    double num1 = atof(num1_str);
    double num2 = atof(num2_str);
    double result = num1 + num2;

    char buffer[32];
    sprintf(buffer, "%.2f", result);
    result_output->value(buffer);

    num1_input->value("");
    num2_input->value("");
}

void subCalculator(Fl_Widget*, void*) {
    const char* num1_str = num1_input->value();
    const char* num2_str = num2_input->value();
    double num1 = atof(num1_str);
    double num2 = atof(num2_str);
    double result = num1 - num2;

    char buffer[32];
    sprintf(buffer, "%.2f", result);
    result_output->value(buffer);

    num1_input->value("");
    num2_input->value("");
}

void mulCalculator(Fl_Widget*, void*) {
    const char* num1_str = num1_input->value();
    const char* num2_str = num2_input->value();
    double num1 = atof(num1_str);
    double num2 = atof(num2_str);
    double result = num1 * num2;

    char buffer[32];
    sprintf(buffer, "%.2f", result);
    result_output->value(buffer);

    num1_input->value("");
    num2_input->value("");
}

void divCalculator(Fl_Widget*, void*) {
    const char* num1_str = num1_input->value();
    const char* num2_str = num2_input->value();
    double num1 = atof(num1_str);
    double num2 = atof(num2_str);
    double result = (num2 != 0) ? num1 / num2 : 0;

    char buffer[32];
    sprintf(buffer, "%.2f", result);
    result_output->value(buffer);

    num1_input->value("");
    num2_input->value("");
}

void clearCallback(Fl_Widget*, void*) {
    num1_input->value("");
    num2_input->value("");
    result_output->value("");
}

int main() {
    Fl_Window win(400, 350, "Simple FLTK Calculator");

    num1_input = new Fl_Input(130, 50, 200, 30, "Number 1:");
    num2_input = new Fl_Input(130, 100, 200, 30, "Number 2:");

    // Button row centered and equally spaced
    Fl_Button* add_btn = new Fl_Button(40, 160, 70, 30, "+");
    Fl_Button* sub_btn = new Fl_Button(120, 160, 70, 30, "-");
    Fl_Button* mul_btn = new Fl_Button(200, 160, 70, 30, "*");
    Fl_Button* div_btn = new Fl_Button(280, 160, 70, 30, "/");

    result_output = new Fl_Output(130, 210, 200, 30, "Result:");

    Fl_Button* clear_btn = new Fl_Button(150, 270, 100, 30, "Clear");

    // Button callbacks
    add_btn->callback(addCalculator);
    sub_btn->callback(subCalculator);
    mul_btn->callback(mulCalculator);
    div_btn->callback(divCalculator);
    clear_btn->callback(clearCallback);

    win.end();
    win.show();
    return Fl::run();
}

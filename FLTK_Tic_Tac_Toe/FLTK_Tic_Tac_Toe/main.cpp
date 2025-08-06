#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Output.H>
#include <string>
#include <cstring>

const int CELL_SIZE = 90;
const int GRID_SIZE = 3;

Fl_Button* cells[GRID_SIZE][GRID_SIZE];
Fl_Output* statusOutput;
Fl_Button* resetButton;

char currentPlayer = 'X';
bool gameOver = false;

void checkWinner() {
    const char* winner = nullptr;

    // Check rows and columns
    for (int i = 0; i < GRID_SIZE; ++i) {
        // Row
        if (strcmp(cells[i][0]->label(), cells[i][1]->label()) == 0 &&
            strcmp(cells[i][1]->label(), cells[i][2]->label()) == 0 &&
            strcmp(cells[i][0]->label(), "") != 0) {
            winner = cells[i][0]->label();
        }

        // Column
        if (strcmp(cells[0][i]->label(), cells[1][i]->label()) == 0 &&
            strcmp(cells[1][i]->label(), cells[2][i]->label()) == 0 &&
            strcmp(cells[0][i]->label(), "") != 0) {
            winner = cells[0][i]->label();
        }
    }

    // Diagonals
    if (strcmp(cells[0][0]->label(), cells[1][1]->label()) == 0 &&
        strcmp(cells[1][1]->label(), cells[2][2]->label()) == 0 &&
        strcmp(cells[0][0]->label(), "") != 0) {
        winner = cells[0][0]->label();
    }

    if (strcmp(cells[0][2]->label(), cells[1][1]->label()) == 0 &&
        strcmp(cells[1][1]->label(), cells[2][0]->label()) == 0 &&
        strcmp(cells[0][2]->label(), "") != 0) {
        winner = cells[0][2]->label();
    }

    if (winner) {
        std::string msg = "Player ";
        msg += winner;
        msg += " wins!";
        statusOutput->value(msg.c_str());
        gameOver = true;
        return;
    }

    // Check for draw
    bool draw = true;
    for (int r = 0; r < GRID_SIZE; ++r) {
        for (int c = 0; c < GRID_SIZE; ++c) {
            if (strcmp(cells[r][c]->label(), "") == 0) {
                draw = false;
                break;
            }
        }
    }

    if (draw) {
        statusOutput->value("It's a draw!");
        gameOver = true;
    }
}

void cellClicked(Fl_Widget* w, void*) {
    if (gameOver) return;

    Fl_Button* btn = (Fl_Button*)w;

    if (strcmp(btn->label(), "") == 0) {
        btn->label(currentPlayer == 'X' ? "X" : "O");
        checkWinner();

        if (!gameOver) {
            currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
            std::string msg = "Turn: ";
            msg += currentPlayer;
            statusOutput->value(msg.c_str());
        }
    }
}

void resetGame(Fl_Widget*, void*) {
    for (int r = 0; r < GRID_SIZE; ++r) {
        for (int c = 0; c < GRID_SIZE; ++c) {
            cells[r][c]->label("");
        }
    }
    currentPlayer = 'X';
    gameOver = false;
    statusOutput->value("Turn: X");
}

int main() {
    Fl_Window* win = new Fl_Window(CELL_SIZE * 3 + 40, CELL_SIZE * 3 + 100, "Tic-Tac-Toe");

    for (int row = 0; row < GRID_SIZE; ++row) {
        for (int col = 0; col < GRID_SIZE; ++col) {
            cells[row][col] = new Fl_Button(30 + col * CELL_SIZE, 30 + row * CELL_SIZE, CELL_SIZE-15, CELL_SIZE-15, "");
            cells[row][col]->callback(cellClicked);
            cells[row][col]->labelsize(26);
        }
    }

    statusOutput = new Fl_Output(20, CELL_SIZE * 3 + 30, 200, 30, "Status:");
    statusOutput->value("Turn: X");

    resetButton = new Fl_Button(CELL_SIZE * 3 - 60, CELL_SIZE * 3 + 30, 80, 30, "Reset");
    resetButton->callback(resetGame);

    win->end();
    win->show();
    return Fl::run();
}

#include <iostream>
#include "SudukoGame.h"

using namespace std;

bool SudukoGame::inputGameState() {
    bool validInput = false;

    cout << "Please input data:" << endl;

    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            cin >> gameBoard[i][j].value;
            if (cin.fail()) {
                cout << "Input contains a non-number." << endl << endl;
                cin.clear();
                cin.ignore(256, '\n');
                return false;
            }
            for (int k = 0; k < 10; k++){
                if (gameBoard[i][j].value == k){
                    validInput = true;
                }
            }
            if (!validInput){
                cout << "Input contains a number not from 0 to 9." << endl << endl;
                return false;
            }
            validInput = false;
            if (gameBoard[i][j].value !=  0){
                gameBoard[i][j].enteredValue = true;
            }
        }
    }
    return true;
}
bool SudukoGame::simulateBacktrackingDriver() {
    if (!simulateBacktracking(0,0)){
        return false;
    }
    return true;
}
void SudukoGame::outputGameState() {
    for (int i = 0; i < 9; i++) {
        if (i % 3 == 0){
            cout << "-------------------" << endl;
        }
        for (int j = 0; j < 9; j++) {
            if (j % 3 == 0){
                cout << '|';
            }
            else {
                cout << ' ';
            }
            if (gameBoard[i][j].value == 0){
                cout << " ";
            }
            else {
                cout << gameBoard[i][j].value;
            }
        }
        cout << '|' << endl;
    }
    cout << "-------------------" << endl;
}
bool SudukoGame::simulateBacktracking(int i, int j) {
    if (gameBoard[i][j].enteredValue) {
        if (i + 1 == 9){
            if (j + 1 == 9) {
                return true;
            }
            else {
                return simulateBacktracking(0, j + 1);
            }
        }
        return simulateBacktracking(i + 1, j);
    }
    else {
        gameBoard[i][j].value = 1;
        while (true){
            outputGameState();
            if (validateBox(i, j)){
                if ((i + 1) == 9){
                    if ((j + 1) == 9) {
                        return true;
                    }
                    else if (simulateBacktracking(0, j + 1)){
                        return true;
                    }
                }
                else if (simulateBacktracking(i + 1, j)) {
                    return true;
                }
            }
            gameBoard[i][j].value++;
            if (gameBoard[i][j].value > 9) {
                gameBoard[i][j].value = 0;
                return false;
            }
        }
    }
    return false;
}
bool SudukoGame::validateBox(int i, int j) {
    bool valid = true;
    if (!validateVertical(i,j)) valid = false;
    if (!validateHorizontal(i,j)) valid = false;
    if (!validateGrouping(i,j)) valid = false;
    return valid;
}
bool SudukoGame::validateVertical(int i, int j) {
    for (int k = 0; k < 9; k++){
        if (gameBoard[i][k].value == gameBoard[i][j].value){
            if (k != j){
                return false;
            }
        }
    }
    return true;
}
bool SudukoGame::validateHorizontal(int i, int j) {
    for (int k = 0; k < 9; k++){
        if (gameBoard[k][j].value == gameBoard[i][j].value){
            if (k != i){
                return false;
            }
        }
    }
    return true;
}
bool SudukoGame::validateGrouping(int i, int j) {
    int xBegin, xEnd, yBegin, yEnd;

    if ((i == 0) || (i == 1) || (i == 2)) {
        xBegin = 0;
        xEnd = 3;
    }
    else if ((i == 3) || (i == 4) || (i == 5)) {
        xBegin = 3;
        xEnd =  6;
    }
    else {
        xBegin = 6;
        xEnd = 9;
    }

    if ((j == 0) || (j == 1) || (j == 2)) {
        yBegin = 0;
        yEnd = 3;
    }
    else if ((j == 3) || (j == 4) || (j == 5)) {
        yBegin = 3;
        yEnd = 6;
    }
    else {
        yBegin = 6;
        yEnd = 9;
    }

    for (int m = xBegin; m < xEnd; m++){
        for (int n = yBegin; n < yEnd; n++){
            if (gameBoard[m][n].value == gameBoard[i][j].value){
                if (m != i && n != j){
                    return false;
                }
            }
        }
    }
    return true;
}

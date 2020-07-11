#include "EnhancedSudukoGame.h"
#include <vector>
#include <iostream>
bool EnhancedSudukoGame::simulateBacktrackingDriver(){
    generatePossibleValues();
    confirmSingleValues();
    if (!simulateBacktracking(0,0)){
        return false;
    }
    return true;
}
bool EnhancedSudukoGame::simulateBacktracking(int i, int j){
    int index = 0;
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
        gameBoard[i][j].value = possibleValues[i][j][0];
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
            index ++;
            if (index >= possibleValues[i][j].size()) {
                gameBoard[i][j].value = 0;
                return false;
            }
            else {
                gameBoard[i][j].value = possibleValues[i][j][index];
            }
        }
    }
    return false;
}
void EnhancedSudukoGame::generatePossibleValues(){
    for (int i = 0; i < 9; i++){
        for (int j = 0; j < 9; j++) {
            if (!gameBoard[i][j].enteredValue) {
                for (int k = 1; k < 10; k++) {
                    gameBoard[i][j].value = k;
                    if (validateBox(i,j)){
                        possibleValues[i][j].push_back(k);
                    }
                }
                gameBoard[i][j].value = 0;
            }
        }
    }
}
void EnhancedSudukoGame::confirmSingleValues(){
    for (int i = 0; i < 9; i++){
        for (int j = 0; j < 9; j++) {
            if (!gameBoard[i][j].enteredValue) {
                    if (possibleValues[i][j].size() == 1){
                        gameBoard[i][j].value = possibleValues[i][j][0];
                        gameBoard[i][j].enteredValue = true;
                    }
            }
        }
    }
}

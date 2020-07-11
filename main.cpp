#include <iostream>
#include "SudukoGame.h"
#include "EnhancedSudukoGame.h"

using namespace std;
void displayIntroMessage(){
    cout << "This program uses two backtracking approaches to solve a 9 x 9   \n"
         << "Sudoku puzzle. Both methods use a depth-first / recursive        \n"
         << "approach that will explore each possible branch of the solution  \n"
         << "set. The original method works by testing for valid inputs by    \n"
         << "setting a box value from 1 to 9 and incrementing until a valid   \n"
         << "input is found. If no valid input is found then the program will \n"
         << "backtrack to the last solved input and continue incrementing.    \n"
         << "This solution concept will guarantee a solution, but is slower   \n"
         << "than a more deterministic approach would be. The secondary       \n"
         << "method is an enhanced version of the algorithm that will find    \n"
         << "all possible numbers the box could be before attempting to       \n"
         << "solve. This can significantly decrease algorithm complexity as   \n"
         << "the program will only increment in the range of possible values  \n"
         << "instead of through the entirety of 1 to 9. In cases where only   \n"
         << "one possible value can be in a box, this possible is additionally\n"
         << "treated as if it was entered data to decrease complexity further.\n"
        << endl;

        cout << "Press Enter to Continue";
        cin.ignore();

        cout << endl;
}
void displayInputMessage(){
    cout << "Enter the puzzle as a 9x9 grid in which known inputs\n"
         << "are set as 1-9 and unknown inputs are set as 0. Leave a\n"
         << "space between every input block in the puzzle. \n\n"
         << "Example:\n"
         << "1 0 0 0 0 0 0 0 0\n"
         << "0 2 0 0 0 0 0 0 0\n"
         << "0 0 3 0 0 0 0 0 0\n"
         << "0 0 0 4 0 0 0 0 0\n"
         << "0 0 0 0 5 0 0 0 0\n"
         << "0 0 0 0 0 6 0 0 0\n"
         << "0 0 0 0 0 0 7 0 0\n"
         << "0 0 0 0 0 0 0 8 0\n"
         << "0 0 0 0 0 0 0 0 9\n" << endl;

        cout << "Press Enter to Continue";
        cin.ignore();

        cout << endl;
}
bool getAlgorithmType(){

}
bool getShowOutput(){

}
int main() {
    bool validInput = false;
    EnhancedSudukoGame playThrough;
    displayIntroMessage();
    displayInputMessage();
    do {
        validInput = playThrough.inputGameState();
    }while(!validInput);
    cout << endl << "Pre-Simulated Game Board: " << endl;
    playThrough.outputGameState();
    if (!playThrough.simulateBacktrackingDriver()){
        cout << "!Game in unsolvable configuration!" << endl;
        return 0;
    }
    cout << "Post-Simulated Game Board: " << endl;
    playThrough.outputGameState();
    return 0;
}

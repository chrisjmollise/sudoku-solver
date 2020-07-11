#ifndef SUDUKOGAME_H
#define SUDUKOGAME_H


class SudukoGame {
    public:
        /** Public Methods */
        bool inputGameState();
        virtual bool simulateBacktrackingDriver();
        void outputGameState();
    protected:
        /** Protected Variables**/
        int totalSolveAttempts = 1;
        struct Box //Simulates individual state of a box
        {
            int value; //Value within a box
            bool enteredValue = false; // Checks if value was entered/simulated
        };
        Box gameBoard[9][9]; //Simulates a 9x9 board of boxes
        /** Protected Methods**/
        virtual bool simulateBacktracking(int i, int j);
        bool validateBox(int i, int j);
        bool validateVertical(int i, int j);
        bool validateHorizontal(int i, int j);
        bool validateGrouping(int i, int j);
};

#endif // SUDUKOGAME_H

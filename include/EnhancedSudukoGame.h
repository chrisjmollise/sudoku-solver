#ifndef ENHANCEDSUDUKOGAME_H
#define ENHANCEDSUDUKOGAME_H

#include "SudukoGame.h"
#include <vector>

using namespace std;

class EnhancedSudukoGame: public SudukoGame {
    public:
        bool simulateBacktrackingDriver();
    private:
        /** Private Variables **/
        vector<int> possibleValues[9][9];
        bool simulateBacktracking(int i, int j);
        void generatePossibleValues();
        void confirmSingleValues();
};

#endif // ENHANCEDSUDUKOGAME_H

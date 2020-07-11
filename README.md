# sudoku-solver
This program uses two backtracking approaches to solve a 9 x 9
Sudoku puzzle. Both methods use a depth-first / recursive        
approach that will explore each possible branch of the solution  
set. The original method works by testing for valid inputs by    
setting a box value from 1 to 9 and incrementing until a valid   
input is found. If no valid input is found then the program will 
backtrack to the last solved input and continue incrementing.    
This solution concept will guarantee a solution, but is slower   
than a more deterministic approach would be. The secondary       
method is an enhanced version of the algorithm that will find    
all possible numbers the box could be before attempting to       
solve. This can significantly decrease algorithm complexity as   
the program will only increment in the range of possible values  
instead of through the entirety of 1 to 9. In cases where only   
one possible value can be in a box, this possible is additionally
treated as if it was entered data to decrease complexity further.

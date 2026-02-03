#include <iostream>
#include <cstdlib>
#include <ctime>

using  namespace std;

//TODO: 
// 
bool isValidMove(int userMove, int stones) {
    if (userMove < 1 || userMove > 3 || userMove > stones) {
        return false;
    }
    return true;
}
// Create a function named isValidMove(). It needs to have boolean return type
//      and it needs to take two parameters: int userMove and int stones.
//      This function is to determine if the move is valid or not. If the user move
//      is less than 1, greater than 3, or if their move is greater than the number
//      of available stones, then return false. Else return true.

int getUserMove(int stones) {
    int userMove;
    while (true) {
        cout << "How many stones would you like to take (1-3)? ";
        cin >> userMove;
        if (isValidMove(userMove, stones)) {
            return userMove;
        } else {
            cout << "Invalid amount." << endl;
        }
    }
}

//TODO: Create a function named getUserMove(). It needs to have a int return type and
//      it needs to take one parameter: int stones.
//      The purpose of the function is to get the users move. You will need to
//      do the following steps in the function:
//      1) create a a loop that will only break when a valid move is made
//      2) inside the loop ask the user how many stones they would like to take and
//         then have them input their answer
//      3) if the move is valid, return the user's move. Else print "Invalid amount."
//         (hint: use the isValidMove function to test if the move is valid)

int computerMove(int stones) {
    if (stones == 1 || stones == 2) {
        return 1;
    } else if (stones == 3) {
        return 2;
    } else if (stones == 4) {
        return 3;
    } else {
        return rand() % 3 + 1; // random number between 1 and 3
    }
}

//TODO: Create a function named computerMove() that has a return type of int. It needs
//      to take one parameter: int stones.
//      The purpose of this function is to program how many stones the computer will
//      take on their move.
//      If the number of stones = 1 or 2 then return 1. If stones = 3 then return 2.
//      If stones = 4 then return 3. Else return a random number between 1 and 3.

bool checkWin(int stones) {
    if (stones <= 0) {
        return true;
    }
    return false;
}


//TODO: Create a function of type bool named checkWin(). It will take one parameter: int stones
//      This one should be very simple, if there are no stones left then return true else 
//      return false.


int main() {
    //TODO: Start the stone count at 16 and tell the user how many stones are in the 
    //      pile

	int stones = 16;
	cout << "There are " << stones << " stones in the pile." << endl;

    //TODO: Create a loop that will only break when the game is over.
    //      Within the loop, have the user take their move then subtract
    //      the result of the user's move with the total number of stones.

    while (true) {
        int userMove = getUserMove(stones);
        stones -= userMove;
        cout << "There are " << stones << " stones remaining." << endl;
        if (checkWin(stones)) {
            cout << "You win!" << endl;
            break;
        }
        int compMove = computerMove(stones);
        cout << "The computer takes " << compMove << " stones." << endl;
        stones -= compMove;
        cout << "There are " << stones << " stones remaining." << endl;
        if (checkWin(stones)) {
            cout << "The computer wins!" << endl;
            break;
        }
	}

    //TODO: Once again print how many stones are remaining and then check the
    //      the win condition.


    //TODO: Now have the computer take its turn. Subtract the computer's move
    //      from the total number of stones.

    //TODO: Print the total number of stones and then check the win condition

    return 0;
}
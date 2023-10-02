#include <cstdlib>
#include <string>

#include "Gameboard.h"

using namespace std;

class TicTacToeGame {

    public:

        GameBoard gameboard;

        TicTacToeGame() {
            moves_left = 9;
        }

        void start_game() {

            int turn_number = 0;
            int player_move;
            int computer_move;
            

            printGameInstructions();

            while(moves_left > 0){


                cout << string("\n\n\nTurn ") + to_string(turn_number) + string(":");
                cout << "\n\n";


                // Player Moves
                player_move = get_players_move();
                if(gameboard.isMoveAvailable(player_move)){
                    gameboard.AddMoveToBoard("x",player_move);
                }
                --moves_left;


                
                // Computer Moves
                computer_move = get_computers_move();
                gameboard.AddMoveToBoard("o",computer_move);
                --moves_left;
                

                // Check row victories 
                if(gameboard.allElementsInRowContainSameValue(1)) {
                    cout << "\n\nRow 1 Victory\n";
                    displayWinnerMessage(gameboard.getGameBoardPosition(0));
                    gameboard.printGameBoard(true);
                    return;
                }else if(gameboard.allElementsInRowContainSameValue(2)) {
                    cout << "\n\nRow 2 Victory\n";
                    displayWinnerMessage(gameboard.getGameBoardPosition(3));
                    gameboard.printGameBoard(true);
                    return;
                }else if(gameboard.allElementsInRowContainSameValue(3)) {
                    cout << "\n\nRow 3 Victory\n";
                    displayWinnerMessage(gameboard.getGameBoardPosition(6));
                    gameboard.printGameBoard(true);
                    return;
                }


                // Check column victories 
                if(gameboard.allElementsInColumnContainSameValue(1)) {
                    cout << "\n\nColumn 1 Victory\n";
                    displayWinnerMessage(gameboard.getGameBoardPosition(0));
                    gameboard.printGameBoard(true);
                    return;
                }else if(gameboard.allElementsInColumnContainSameValue(2)) {
                    cout << "\n\nColumn 2 Victory\n";
                    displayWinnerMessage(gameboard.getGameBoardPosition(1));
                    gameboard.printGameBoard(true);
                    return;
                }else if(gameboard.allElementsInColumnContainSameValue(3)) {
                    cout << "\n\nColumn 3 Victory\n";
                    displayWinnerMessage(gameboard.getGameBoardPosition(2));
                    gameboard.printGameBoard(true);
                    return;
                }

                // Check diagonal victories
                if(gameboard.allElementsInDiagonalContainSameValue(1)) {
                    cout << "\n\nDiagonal 1 Victory\n";
                    displayWinnerMessage(gameboard.getGameBoardPosition(0));
                    gameboard.printGameBoard(true);
                    return;
                }else if(gameboard.allElementsInDiagonalContainSameValue(2)){
                    cout << "\n\nDiagonal 2 Victory\n";
                    displayWinnerMessage(gameboard.getGameBoardPosition(2));
                    gameboard.printGameBoard(true);
                    return;
                }

                ++turn_number;
            }

            cout << "\n\nPlayer tied with computer\n";
            gameboard.printGameBoard(true);

        }



    private:

        int moves_left;

        void printGameInstructions(){
            cout << "\n\t\t\t\tGame Instructions\n\n";
            cout << string("Tic-Tac-Toe is a two-player game played on a 3x3 grid. Players take turns placing their\n") +
                    string("symbols (traditionally \"X\" for one player and \"O\" for the other) in empty cells. The objective is\n") +
                    string("to form a line of three of your symbols horizontally, vertically, or diagonally, before your\n") +
                    string("opponent does. The game ends when one player achieves this goal, resulting in a win for that\n") +
                    string("player, or when all cells on the grid are filled without a winner, resulting in a draw or tie game.\n") +
                    string("Players take turns until there is a winner or a draw, and the player who forms a winning line or\n") +
                    string("forces a draw is declared the winner.\n\n");

            cout << endl;




            cout << "\n\t\t\t\t   How to Play\n\n";
            cout << "\t\t\t\t    1 | 2 | 3  \n";
            cout << "\t\t\t\t   =========== \n";
            cout << "\t\t\t\t    4 | 5 | 6  \n";
            cout << "\t\t\t\t   =========== \n";
            cout << "\t\t\t\t    7 | 8 | 9  \n\n";

            cout << endl;


            cout << string("As the player, you begin at the start of the game by entering a number that corresponds with the location\n") +
                    string("you want to put your \"X\" token in. The computer then takes its turn and places its \"O\" token in a random\n") +
                    string("location on the board. This repeats until all spots on the board are filled, or either the player or\n") +
                    string("computer wins. Good luck and have fun! :)\n\n");

            cout << "=========================================================================================================";
           
        } 

        void displayWinnerMessage(string winner_token){
            
            if(winner_token == "x"){
                cout << "Player Wins!\n";
            }else if(winner_token == "o"){
                cout << "Computer Wins!\n";
            }

        }
    
        int getMovesLeft(){
            return moves_left;
        }

        int get_players_move() {

            gameboard.printGameBoard();

            int player_move;
            cout << "\nPlease enter the slot # of your move: ";
            cin >> player_move;
            return player_move-1;
        }

        int get_computers_move() {
            int computer_move = rand() % 9;

            do {
                computer_move = rand() % 9;
            } while(!gameboard.isMoveAvailable(computer_move));

            return computer_move;
        }

    
};
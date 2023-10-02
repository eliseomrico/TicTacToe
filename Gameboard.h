#include <cstdlib>
#include <string>
#include <iostream>

using namespace std;

class GameBoard {

    public:

        GameBoard(){

            // Fill gameboard with empty space.
            for(int i=0; i<9; i++){
                gameboard[i] = "";
            }
        }

        void AddMoveToBoard(string token, int move){
            if(gameboard[move] == "")
                gameboard[move] = token;
        }
        void printGameBoard(bool uppercase=false){

            cout << "\n\n";

            for(int i=0; i<9; i++){

                
                // For the first element in each row place a space before it
                if( i % 3 == 0){
                    cout << "\t\t\t\t    ";
                }

                // If x or o print it other wise insert a space
                if(gameboard[i] == "x" || gameboard[i] == "o"){
                        cout << gameboard[i];
                }else{
                    cout << " ";
                }

                if(i != 2 && i != 5 && i != 8){
                    cout << " | ";
                } else{
                    if(i != 8){
                        cout << endl;
                        cout << "\t\t\t\t   ===========";
                        cout << endl;
                    }
                }
            }


            cout << "\n\n\n";
        }
        bool isMoveAvailable(int move){
            return ( gameboard[move] == "" );
        }

        bool allElementsInRowContainSameValue(int row_number){

            switch(row_number){
                case 1:
                    if(gameboard[0] != "") {
                        return ((gameboard[0]== gameboard[1]) && (gameboard[0] == gameboard[2]));
                    }
                    break;
                case 2:
                    if(gameboard[3] != "") {
                        return ((gameboard[3]== gameboard[4]) && (gameboard[3] == gameboard[5]));
                    }
                    break;
                case 3:
                    if(gameboard[6] != "") {
                        return ((gameboard[6]== gameboard[7]) && (gameboard[6] == gameboard[8]));
                    }
                    break;
                default:
                    return false;
            }
            return false;
        }

        bool allElementsInColumnContainSameValue(int column_number){

            switch(column_number){
                case 1:
                    if(gameboard[0] != "") {
                        return ((gameboard[0]== gameboard[3]) && (gameboard[0] == gameboard[6]));
                    }
                    break;
                case 2:
                    if(gameboard[1] != "") {
                        return ((gameboard[1]== gameboard[4]) && (gameboard[1] == gameboard[7]));
                    }
                    break;
                case 3:
                    if(gameboard[2] !="") {
                        return ((gameboard[2]== gameboard[5]) && (gameboard[2] == gameboard[8]));
                    }
                    break;
                default:
                    return false;
            }
            return false;
        }

        bool allElementsInDiagonalContainSameValue(int diagonal_number){

            switch(diagonal_number){
                case 1:
                    if(gameboard[0] != "") {
                        return ((gameboard[0] == gameboard[4]) && (gameboard[0] == gameboard[8]));
                    }
                    break;
                case 2:
                    if(gameboard[2] != ""){
                        return ((gameboard[2] == gameboard[4]) && (gameboard[2] == gameboard[6]));
                    }
                    break;
                default:
                    return false;
            }

            return false;
        }

        string getGameBoardPosition(int element){
            return gameboard[element];
        }

    private:
        string gameboard[9];

};
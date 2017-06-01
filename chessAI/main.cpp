#include <iostream>
#include <stdio.h>
#include <vector>
#include "moveFunctions.h"
#include "interface.h"
#include "generationFunctions.h"

using namespace std;

int main()
{

    char fullBoard[12][12] = {
                    {'x','x','x','x','x','x','x','x','x','x','x','x'},
                    {'x','x','x','x','x','x','x','x','x','x','x','x'},
                    {'x','x','r','n','b','q','a','b','n','r','x','x'},
                    {'x','x','p','p','p','p','p','p','p','p','x','x'},
                    {'x','x','o','o','o','o','o','o','o','o','x','x'},
                    {'x','x','o','o','o','o','o','o','o','o','x','x'},
                    {'x','x','o','o','o','o','o','o','o','o','x','x'},
                    {'x','x','o','o','o','o','o','o','o','o','x','x'},
                    {'x','x','P','P','P','P','P','P','P','P','x','x'},
                    {'x','x','R','N','B','Q','A','B','N','R','x','x'},
                    {'x','x','x','x','x','x','x','x','x','x','x','x'},
                    {'x','x','x','x','x','x','x','x','x','x','x','x'}
                    };

    //Initializing array to store generated moves
    //vector< vector<int> > moveList(1000, vector<int>(6));
    int moveList[1000][6];

    moveList[0][0] = 0;

    generateMoves(fullBoard,moveList);

    for(int i = 0; i < 144; i++){
        printf("%i",moveList[i][0]);
        printf("%i",moveList[i][1]);
        printf("%i",moveList[i][2]);
        printf("%i",moveList[i][3]);
        printf("%i",moveList[i][4]);
        printf("\n");
    }

    printBoard(fullBoard);

    int game = true;

    while(game)
    {
        int x, y;

        printf("Enter the x position of the piece you would like to move: ");
        scanf("%i",&x);
        printf("Enter the y position of the piece you would like to move: ");
        scanf("%i",&y);

        int current[2] = {y + 1,x + 1};

        printf("Enter the x position of the position you would like to move to: ");
        scanf("%i",&x);
        printf("Enter the y position of the position you would like to move to: ");
        scanf("%i",&y);

        int next[2] = {y + 1,x + 1};

        movePiece(current,next,fullBoard);

        generateMoves(fullBoard,moveList);

        printBoard(fullBoard);
    }
    return 0;
}

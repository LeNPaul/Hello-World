#include <iostream>
#include <stdio.h>

using namespace std;

int printBoard(char board[12][12])
{
    //Print out the board array for visualization
    for(int i = 0; i < 12; i++)
    {

        for(int j = 0; j < 12; j++)
        {
            printf("%c",board[i][j]);
        };

        printf("\n");

    };
}

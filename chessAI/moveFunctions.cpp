#include <iostream>
#include <stdio.h>
#include "generationFunctions.h"

int movePiece(int currentPosition[2], int nextPosition[2], char board[12][12])
{
    int rowMove;
    int columnMove;

    rowMove = nextPosition[0] - currentPosition[0];
    columnMove = nextPosition[1] - currentPosition[1];

    char pieceID = board[currentPosition[0]][currentPosition[1]];

    board[currentPosition[0]][currentPosition[1]] = 'o';

    board[currentPosition[0] + rowMove][currentPosition[1] + columnMove] = pieceID;

    return 0;

}

int movePawn(int currentPosition[2],char board[12][12], int moveList[1000][6])
{
    int top = true;
    int top_left = true;
    int top_right = true;

    while(top || top_left || top_right)
    {
        if(top)
        {
            if(board[currentPosition[0] + 1][currentPosition[1]] == 'o')
            {
                printf("This is possible (t) \n");
                int test = true;
                int i = 0;
                while(test){
                    if(moveList[i][3] == 0 && moveList[i][4] == 0){
                        moveList[i][0] = 'p';
                        moveList[i][1] = currentPosition[1];
                        moveList[i][2] = currentPosition[0];
                        moveList[i][3] = currentPosition[1];
                        moveList[i][4] = currentPosition[0] + 1;
                        test = false;
                    }
                    else
                    {
                        i++;
                    }
                }
                top = false;
            }
            else
            {
                char square = board[currentPosition[0] + 1][currentPosition[1]];
                checkPiece(square);

                top = false;
            }
        }
        if(top_left)
        {
            if(board[currentPosition[0] + 1][currentPosition[1] - 1] == 'o')
            {
                printf("This is possible (tl) \n");
                int test = true;
                int i = 0;
                while(test){
                    if(moveList[i][3] == 0 && moveList[i][4] == 0){
                        moveList[i][0] = 'p';
                        moveList[i][1] = currentPosition[1];
                        moveList[i][2] = currentPosition[0];
                        moveList[i][3] = currentPosition[1] - 1;
                        moveList[i][4] = currentPosition[0] + 1;
                        test = false;
                    }
                    else
                    {
                        i++;
                    }
                }
                top_left = false;
            }
            else
            {
                char square = board[currentPosition[0] + 1][currentPosition[1] - 1];
                checkPiece(square);

                top_left = false;
            }
        }
        if(top_right)
        {
            if(board[currentPosition[0] + 1][currentPosition[1]] == 'o')
            {
                printf("This is possible (tr) \n");
                int test = true;
                int i = 0;
                while(test){
                    if(moveList[i][3] == 0 && moveList[i][4] == 0){
                        moveList[i][0] = 'p';
                        moveList[i][1] = currentPosition[1];
                        moveList[i][2] = currentPosition[0];
                        moveList[i][3] = currentPosition[1];
                        moveList[i][4] = currentPosition[0] + 1;
                        test = false;
                    }
                    else
                    {
                        i++;
                    }
                }
                top_right = false;
            }
            else
            {
                char square = board[currentPosition[0] + 1][currentPosition[1] + 1];
                checkPiece(square);

                top_right = false;
            }
        }
    }
    return 0;
}

int moveRook(int currentPosition[2],char board[12][12],int moveList[1000][6])
{
    int top = true;
    int bottom = true;
    int left = true;
    int right = true;
    int n = 1;

    while(top || bottom || left || right)
    {
        if(top)
        {
            if(board[currentPosition[0] + n][currentPosition[1]] == 'o')
            {
                printf("This is possible (t) \n");
                int okay = true;
                int i = 0;
                while(okay){
                    if(moveList[i][1] = 0 && moveList[i][2] == 0){
                        moveList[i][0] = 'r';
                        moveList[i][1] = currentPosition[1];
                        moveList[i][2] = currentPosition[0];
                        moveList[i][3] = currentPosition[1];
                        moveList[i][4] = currentPosition[0] + n;
                        okay = false;
                    }
                    else
                    {
                        i++;
                    }
                }
            }
            else
            {
                char square = board[currentPosition[0] + n][currentPosition[1]];
                checkPiece(square);

                top = false;
            }
        }

        if(bottom)
        {
            if(board[currentPosition[0] - n][currentPosition[1]] == 'o')
            {
                printf("This is possible (b) \n");
            }
            else
            {
                char square = board[currentPosition[0] - n][currentPosition[1]];
                checkPiece(square);

                bottom = false;
            }
        }

        if(left)
        {
            if(board[currentPosition[0]][currentPosition[1] - n] == 'o')
            {
                printf("This is possible (l) \n");
            }
            else
            {
                char square = board[currentPosition[0]][currentPosition[1] - n];
                checkPiece(square);

                left = false;
            }
        }

        if(right)
        {
            if(board[currentPosition[0]][currentPosition[1] + n] == 'o')
            {
                printf("This is possible (r) \n");
            }
            else
            {
                char square = board[currentPosition[0]][currentPosition[1] + n];
                checkPiece(square);

                right = false;
            }
        }

    n = n + 1;

    }
    return 0;
}

int moveBishop(int currentPosition[2],char board[12][12],int moveList[1000][6])
{
    int top_right = true;
    int top_left = true;
    int bottom_right = true;
    int bottom_left = true;
    int n = 1;

    while(top_right || bottom_left || top_left || bottom_right)
    {
        if(top_right)
        {
            if(board[currentPosition[0] + n][currentPosition[1] + n] == 'o')
            {
                printf("This is possible (tr) \n");
                int okay = true;
                int i = 0;
                while(okay){
                    if(moveList[i][1] = 0 && moveList[i][2] == 0){
                        moveList[i][0] = 'b';
                        moveList[i][1] = currentPosition[1];
                        moveList[i][2] = currentPosition[0];
                        moveList[i][3] = currentPosition[1] + n;
                        moveList[i][4] = currentPosition[0] + n;
                        okay = false;
                    }
                    else
                    {
                        i++;
                    }
                }
            }
            else
            {
                char square = board[currentPosition[0] + n][currentPosition[1] + n];
                checkPiece(square);

                top_right = false;
            }
        }

        if(bottom_right)
        {
            if(board[currentPosition[0] - n][currentPosition[1] + n] == 'o')
            {
                printf("This is possible (br) \n");
            }
            else
            {
                char square = board[currentPosition[0] - n][currentPosition[1] + n];
                checkPiece(square);

                bottom_right = false;
            }
        }

        if(top_left)
        {
            if(board[currentPosition[0] + n][currentPosition[1] - n] == 'o')
            {
                printf("This is possible (tl) \n");
            }
            else
            {
                char square = board[currentPosition[0] + n][currentPosition[1] - n];
                checkPiece(square);

                top_left = false;
            }
        }

        if(bottom_left)
        {
            if(board[currentPosition[0] - n][currentPosition[1] - n] == 'o')
            {
                printf("This is possible (bl) \n");
            }
            else
            {
                char square = board[currentPosition[0] - n][currentPosition[1] - n];
                checkPiece(square);

                bottom_left = false;
            }
        }

        n = n + 1;

    }
    return 0;
}

int moveQueen(int currentPosition[2],char board[12][12])
{
    int top = true;
    int bottom = true;
    int left = true;
    int right = true;
    int top_right = true;
    int top_left = true;
    int bottom_right = true;
    int bottom_left = true;
    int n = 1;

    while(top_right || bottom_left || top_left || bottom_right || top || bottom || left || right)
    {
        if(top)
        {
            if(board[currentPosition[0] + n][currentPosition[1]] == 'o')
            {
                printf("This is possible (t) \n");
            }
            else
            {
                char square = board[currentPosition[0] + n][currentPosition[1]];
                checkPiece(square);

                top = false;
            }
        }

        if(bottom)
        {
            if(board[currentPosition[0] - n][currentPosition[1]] == 'o')
            {
                printf("This is possible (b) \n");
            }
            else
            {
                char square = board[currentPosition[0] - n][currentPosition[1]];
                checkPiece(square);

                bottom = false;
            }
        }

        if(left)
        {
            if(board[currentPosition[0]][currentPosition[1] - n] == 'o')
            {
                printf("This is possible (l) \n");
            }
            else
            {
                char square = board[currentPosition[0]][currentPosition[1] - n];
                checkPiece(square);

                left = false;
            }
        }

        if(right)
        {
            if(board[currentPosition[0]][currentPosition[1] + n] == 'o')
            {
                printf("This is possible (r) \n");
            }
            else
            {
                char square = board[currentPosition[0]][currentPosition[1] + n];
                checkPiece(square);

                right = false;
            }
        }
        if(top_right)
        {
            if(board[currentPosition[0] + n][currentPosition[1] + n] == 'o')
            {
                printf("This is possible (tr) \n");
            }
            else
            {
                char square = board[currentPosition[0] + n][currentPosition[1] + n];
                checkPiece(square);

                top_right = false;
            }
        }

        if(bottom_right)
        {
            if(board[currentPosition[0] - n][currentPosition[1] + n] == 'o')
            {
                printf("This is possible (br) \n");
            }
            else
            {
                char square = board[currentPosition[0] - n][currentPosition[1] + n];
                checkPiece(square);

                bottom_right = false;
            }
        }

        if(top_left)
        {
            if(board[currentPosition[0] + n][currentPosition[1] - n] == 'o')
            {
                printf("This is possible (tl) \n");
            }
            else
            {
                char square = board[currentPosition[0] + n][currentPosition[1] - n];
                checkPiece(square);

                top_left = false;
            }
        }

        if(bottom_left)
        {
            if(board[currentPosition[0] - n][currentPosition[1] - n] == 'o')
            {
                printf("This is possible (bl) \n");
            }
            else
            {
                char square = board[currentPosition[0] - n][currentPosition[1] - n];
                checkPiece(square);

                bottom_left = false;
            }
        }
        n = n + 1;
    }
    return 0;
}

int moveKing(int currentPosition[2],char board[12][12])
{
    int top = true;
    int bottom = true;
    int left = true;
    int right = true;
    int top_right = true;
    int top_left = true;
    int bottom_right = true;
    int bottom_left = true;

    while(top_right || bottom_left || top_left || bottom_right || top || bottom || left || right)
    {
        if(top)
        {
            if(board[currentPosition[0] + 1][currentPosition[1]] == 'o')
            {
                printf("This is possible (t) \n");
                top = false;
            }
            else
            {
                char square = board[currentPosition[0] + 1][currentPosition[1]];
                checkPiece(square);

                top = false;
            }
        }

        if(bottom)
        {
            if(board[currentPosition[0] - 1][currentPosition[1]] == 'o')
            {
                printf("This is possible (b) \n");
                bottom = false;
            }
            else
            {
                char square = board[currentPosition[0] - 1][currentPosition[1]];
                checkPiece(square);

                bottom = false;
            }
        }

        if(left)
        {
            if(board[currentPosition[0]][currentPosition[1] - 1] == 'o')
            {
                printf("This is possible (l) \n");
                left = false;
            }
            else
            {
                char square = board[currentPosition[0]][currentPosition[1] - 1];
                checkPiece(square);

                left = false;
            }
        }

        if(right)
        {
            if(board[currentPosition[0]][currentPosition[1] + 1] == 'o')
            {
                printf("This is possible (r) \n");
                right = false;
            }
            else
            {
                char square = board[currentPosition[0]][currentPosition[1] + 1];
                checkPiece(square);

                right = false;
            }
        }
        if(top_right)
        {
            if(board[currentPosition[0] + 1][currentPosition[1] + 1] == 'o')
            {
                printf("This is possible (tr) \n");
                top_right = false;
            }
            else
            {
                char square = board[currentPosition[0] + 1][currentPosition[1] + 1];
                checkPiece(square);

                top_right = false;
            }
        }

        if(bottom_right)
        {
            if(board[currentPosition[0] - 1][currentPosition[1] + 1] == 'o')
            {
                printf("This is possible (br) \n");
                bottom_right = false;
            }
            else
            {
                char square = board[currentPosition[0] - 1][currentPosition[1] + 1];
                checkPiece(square);

                bottom_right = false;
            }
        }

        if(top_left)
        {
            if(board[currentPosition[0] + 1][currentPosition[1] - 1] == 'o')
            {
                printf("This is possible (tl) \n");
                top_left = false;
            }
            else
            {
                char square = board[currentPosition[0] + 1][currentPosition[1] - 1];
                checkPiece(square);

                top_left = false;
            }
        }

        if(bottom_left)
        {
            if(board[currentPosition[0] - 1][currentPosition[1] - 1] == 'o')
            {
                printf("This is possible (bl) \n");
                bottom_left = false;
            }
            else
            {
                char square = board[currentPosition[0] - 1][currentPosition[1] - 1];
                checkPiece(square);

                bottom_left = false;
            }
        }
    }
    return 0;
}

int moveKnight(int currentPosition[2],char board[12][12])
{
    int top_right = true;
    int top_left = true;
    int left_top = true;
    int left_bottom = true;
    int right_top = true;
    int right_bottom = true;
    int bottom_right = true;
    int bottom_left = true;

    while(top_right || top_left || left_top || left_bottom || bottom_right || bottom_left || right_top || right_bottom)
    {
        if(top_right)
        {
            if(board[currentPosition[0] + 2][currentPosition[1] + 1] == 'o')
            {
                printf("This is possible (tr) \n");
                top_right = false;
            }
            else
            {
                char square = board[currentPosition[0] + 2][currentPosition[1] + 1];
                checkPiece(square);

                top_right = false;
            }
        }

        if(top_left)
        {
            if(board[currentPosition[0] + 2][currentPosition[1] - 1] == 'o')
            {
                printf("This is possible (tl) \n");
                top_left = false;
            }
            else
            {
                char square = board[currentPosition[0] + 2][currentPosition[1] - 1];
                checkPiece(square);

                top_left = false;
            }
        }

        if(right_top)
        {
            if(board[currentPosition[0] + 1][currentPosition[1] + 2] == 'o')
            {
                printf("This is possible (rt) \n");
                right_top = false;
            }
            else
            {
                char square = board[currentPosition[0] + 1][currentPosition[1] + 2];
                checkPiece(square);

                right_top = false;
            }
        }

        if(right_bottom)
        {
            if(board[currentPosition[0]  - 1][currentPosition[1] + 2] == 'o')
            {
                printf("This is possible (br) \n");
                right_bottom = false;
            }
            else
            {
                char square = board[currentPosition[0] - 1][currentPosition[1] + 2];
                checkPiece(square);

                right_bottom = false;
            }
        }

        if(bottom_right)
        {
            if(board[currentPosition[0] - 2][currentPosition[1] + 1] == 'o')
            {
                printf("This is possible (br) \n");
                bottom_right = false;
            }
            else
            {
                char square = board[currentPosition[0] - 2][currentPosition[1] + 1];
                checkPiece(square);

                bottom_right = false;
            }
        }

        if(bottom_left)
        {
            if(board[currentPosition[0] - 2][currentPosition[1] - 1] == 'o')
            {
                printf("This is possible (bl) \n");
                bottom_left = false;
            }
            else
            {
                char square = board[currentPosition[0] - 2][currentPosition[1] - 1];
                checkPiece(square);

                bottom_left = false;
            }
        }

        if(left_top)
        {
            if(board[currentPosition[0] + 1][currentPosition[1] - 2] == 'o')
            {
                printf("This is possible (lt) \n");
                left_top = false;
            }
            else
            {
                char square = board[currentPosition[0] + 1][currentPosition[1] - 1];
                checkPiece(square);

                left_top = false;
            }
        }

        if(left_bottom)
        {
            if(board[currentPosition[0] - 1][currentPosition[1] - 2] == 'o')
            {
                printf("This is possible (lb) \n");
                left_bottom = false;
            }
            else
            {
                char square = board[currentPosition[0] - 1][currentPosition[1] - 2];
                checkPiece(square);

                left_bottom = false;
            }
        }
    }
    return 0;
}

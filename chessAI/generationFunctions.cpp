#include <iostream>
#include <stdio.h>
#include <vector>
#include "moveFunctions.h"

int checkPiece(char pieceID)
{
    //When checking for the possible moves of a given piece, this function returns which piece is under attack

    switch(pieceID)
    {
    case 'x':
        printf("Move not possible \n");
        break;
    case 'P':
        printf("Attacking a white pawn \n");
        break;
    case 'p':
        printf("Attacking a black pawn \n");
        break;
    case 'R':
        printf("Attacking a white rook \n");
        break;
    case 'r':
        printf("Attacking a black rook \n");
        break;
    case 'N':
        printf("Attacking a white knight \n");
        break;
    case 'n':
        printf("Attacking a black knight \n");
        break;
    case 'B':
        printf("Attacking a white bishop \n");
        break;
    case 'b':
        printf("Attacking a black bishop \n");
        break;
    case 'Q':
        printf("Attacking a white queen \n");
        break;
    case 'q':
        printf("Attacking a black queen \n");
        break;
    case 'A':
        printf("Attacking a white king \n");
        break;
    case 'a':
        printf("Attacking a black king \n");
        break;
    }
    return pieceID;
}

int findMoves(char pieceID,int currentPosition[2],char board[12][12],int moveList[1000][6])
{
    //Returns which piece is occupying a given square and all the possible moves for that piece

    switch(pieceID)
    {
    case 'o':
        break;
    case 'x':
        break;
    case 'P':
        printf("This is a white pawn, and these are it's possible moves: \n");
        movePawn(currentPosition,board,moveList);
        break;
    case 'p':
        printf("This is a black pawn and these are it's possible moves: \n");
        movePawn(currentPosition,board,moveList);
        break;
    case 'R':
        printf("This is a white rook and these are it's possible moves: \n");
        moveRook(currentPosition,board,moveList);
        break;
    case 'r':
        printf("This is a black rook and these are it's possible moves: \n");
        moveRook(currentPosition,board,moveList);
        break;
    case 'N':
        printf("This is a white knight and these are it's possible moves: \n");
        moveKnight(currentPosition,board);
        break;
    case 'n':
        printf("This is a black knight and these are it's possible moves: \n");
        moveKnight(currentPosition,board);
        break;
    case 'B':
        printf("This is a white bishop and these are it's possible moves: \n");
        moveBishop(currentPosition,board,moveList);
        break;
    case 'b':
        printf("This is a black bishop and these are it's possible moves: \n");
        moveBishop(currentPosition,board,moveList);
        break;
    case 'Q':
        printf("This is a white queen and these are it's possible moves: \n");
        moveQueen(currentPosition,board);
        break;
    case 'q':
        printf("This is a black queen and these are it's possible moves: \n");
        moveQueen(currentPosition,board);
        break;
    case 'A':
        printf("This is a white king and these are it's possible moves: \n");
        moveKing(currentPosition,board);
        break;
    case 'a':
        printf("This is a black king and these are it's possible moves: \n");
        moveKing(currentPosition,board);
        break;
    }
    return pieceID;
}

int generateMoves(char board[12][12], int moveList[1000][6])
{
    int n = 0;
    //Check each square for a piece
    for(int i = 2; i < 10; i++)
    {

        for(int j = 2; j < 10; j++)
        {
            char selfPiece = board[i][j];
            int current[2] = {i,j};

            findMoves(selfPiece,current,board,moveList);

        };
        printf("\n");
    };

    return 0;
}

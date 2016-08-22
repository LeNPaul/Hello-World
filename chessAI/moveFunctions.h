#ifndef MOVEFUNCTIONS_H_INCLUDED
#define MOVEFUNCTIONS_H_INCLUDED

int movePiece(int currentPosition[2], int nextPosition[2], char board[12][12]);

int movePawn(int currentPosition[2],char board[12][12],int moveList[1000][6]);

int moveKing(int currentPosition[2],char board[12][12]);

int moveKnight(int currentPosition[2],char board[12][12]);

int moveRook(int currentPosition[2],char board[12][12],int moveList[1000][6]);

int moveBishop(int currentPosition[2],char board[12][12],int moveList[1000][6]);

int moveQueen(int currentPosition[2],char board[12][12]);

#endif // MOVEFUNCTIONS_H_INCLUDED

#ifndef GENERATIONFUNCTIONS_H_INCLUDED
#define GENERATIONFUNCTIONS_H_INCLUDED

int generateMoves(char board[12][12], int moveList[1000][6]);

int findMoves(char pieceID,int currentPosition[2],char board[12][12],int moveList[1000][6]);

int checkPiece(char pieceID);

#endif // GENERATIONFUNCTIONS_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define BOARD_SIZE 8

typedef struct {
    int row;
    int col;
} Position;

typedef struct {
    char type;
    char color;
} Piece;

typedef struct {
    Position start;
    Position end;
} Move;

void printBoard(Piece board[BOARD_SIZE][BOARD_SIZE]) {
    int i, j;

    printf("\n   A B C D E F G H\n");
    printf("  -----------------\n");
    
    for (i = 0; i < BOARD_SIZE; i++) {
        printf("%d| ", i + 1);
        for (j = 0; j < BOARD_SIZE; j++) {
            printf("%c ", board[i][j].type);
        }
        printf("|%d\n", i + 1);
    }
    
    printf("  -----------------\n");
    printf("   A B C D E F G H\n");
}

bool isValidMove(Position start, Position end, Piece board[BOARD_SIZE][BOARD_SIZE]) {
    // Implemente as regras de movimento aqui
    // Retorne true se o movimento for válido, caso contrário, retorne false
}

bool isInsideBoard(Position position) {
    return position.row >= 0 && position.row < BOARD_SIZE &&
           position.col >= 0 && position.col < BOARD_SIZE;
}

bool isOccupied(Position position, Piece board[BOARD_SIZE][BOARD_SIZE]) {
    return board[position.row][position.col].type != ' ';
}

bool isSameColor(Position position, char color, Piece board[BOARD_SIZE][BOARD_SIZE]) {
    return board[position.row][position.col].color == color;
}

bool isDifferentColor(Position position, char color, Piece board[BOARD_SIZE][BOARD_SIZE]) {
    return board[position.row][position.col].color != color;
}

bool isPawnMoveValid(Move move, Piece board[BOARD_SIZE][BOARD_SIZE]) {
  
}

bool isRookMoveValid(Move move, Piece board[BOARD_SIZE][BOARD_SIZE]) {
  
}

bool isBishopMoveValid(Move move, Piece board[BOARD_SIZE][BOARD_SIZE]) {
   
}

bool isKnightMoveValid(Move move, Piece board[BOARD_SIZE][BOARD_SIZE]) {
  
}

bool isQueenMoveValid(Move move, Piece board[BOARD_SIZE][BOARD_SIZE]) {
   
}

bool isKingMoveValid(Move move, Piece board[BOARD_SIZE][BOARD_SIZE]) {
   
}

bool isMoveValid(Move move, Piece board[BOARD_SIZE][BOARD_SIZE]) {
    char pieceType = board[move.start.row][move.start.col].type;

    if (pieceType == 'P') {
        return isPawnMoveValid(move, board);
    } else if (pieceType == 'R') {
        return isRookMoveValid(move, board);
    } else if (pieceType == 'B') {
        return isBishopMoveValid(move, board);
    } else if (pieceType == 'N') {
        return isKnightMoveValid(move, board);
    } else if (pieceType == 'Q') {
        return isQueenMoveValid(move, board);
    } else if (pieceType == 'K') {
        return isKingMoveValid(move, board);
    } else {
        return false; 
}

bool makeMove(Move move, Piece board[BOARD_SIZE][BOARD_SIZE]) {
    if (isMoveValid(move, board)) {
        board[move.end.row][move.end.col] = board[move.start.row][move.start.col];
        board[move.start.row][move.start.col].type = ' ';
        return true;
    } else {
        return false;
    }
}

Position parsePosition(char* input) {
    Position position;
    position.col = input[0] - 'A';
    position.row = input[1] - '1';
    return position;
}

Move parseMove(char* input) {
    Move move;
    move.start = parsePosition(input);
    move.end = parsePosition(input + 2);
    return move;
}

int main() {
    Piece board[BOARD_SIZE][BOARD_SIZE] = {
        {'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R'},
        {'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P'},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p'},
        {'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r'}
    };

    printBoard(board);

    while (true) {
        char input[5];

        printf("Digite seu movimento (exemplo: 'E2 E4'): ");
        scanf("%s", input);

        Move move = parseMove(input);

        if (makeMove(move, board)) {
            printBoard(board);
        } else {
            printf("Movimento inválido! Tente novamente.\n");
        }
    }

    return 0;
}

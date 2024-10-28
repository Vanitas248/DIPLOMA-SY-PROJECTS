----------------------------------------------------------------------------TIC TAC TOE----------------------------------------------------------------------------------------
#include <conio.h> 
#include <graphics.h>
#include <stdlib.h>

void drawBoard();
void drawMove(int row, int col, char player);
char checkWin(char board[3][3]);
void playerMove(char board[3][3], int player);

void drawBoard() {
    int offsetX = 300;
    setcolor(WHITE);
    line(200 + offsetX, 100, 200 + offsetX, 400);
    line(300 + offsetX, 100, 300 + offsetX, 400);
    line(100 + offsetX, 200, 400 + offsetX, 200);
    line(100 + offsetX, 300, 400 + offsetX, 300);
}

void drawMove(int row, int col, char player) {
    int offsetX = 300;
    int x = 150 + col * 100 + offsetX;
    int y = 150 + row * 100;

    setcolor(player == 'X' ? RED : GREEN);
    if (player == 'X') {
        line(x - 30, y - 30, x + 30, y + 30);
        line(x - 30, y + 30, x + 30, y - 30);
    } else {
        circle(x, y, 30);
    }
}

char checkWin(char board[3][3]) {
    int i;
    i = 0;
    if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != ' ')
        return board[i][0];
    i = 1;
    if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != ' ')
        return board[i][0];
    i = 2;
    if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != ' ')
        return board[i][0];
    i = 0;
    if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != ' ')
        return board[0][i];
    i = 1;
    if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != ' ')
        return board[0][i];
    i = 2;
    if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != ' ')
        return board[0][i];
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != ' ')
        return board[0][0];
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != ' ')
        return board[0][2];
    for (i = 0; i < 9; i++) {
        if (board[i / 3][i % 3] == ' ')
            return 0;
    }
    return 'D';
}

void playerMove(char board[3][3], int player) {
    int row, col;
    do {
        printf("Player %d, enter row and column (1-3): ", player);
        scanf("%d%d", &row, &col);
        row--; col--;
    } while (row < 0 || row > 2 || col < 0 || col > 2 || board[row][col] != ' ');
    board[row][col] = (player == 1) ? 'X' : 'O';
    drawMove(row, col, board[row][col]);
}

int main() {
    int gd = DETECT, gm;
    char board[3][3] = {{' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '}};
    int player = 1;
    char result = 0;

    initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");
    drawBoard();

    while (!result) {
        playerMove(board, player);
        result = checkWin(board);
        player = 3 - player;
    }

    setcolor(WHITE);
    outtextxy(450, 50, result == 'D' ? "It's a Draw!" : result == 'X' ? "Player 1 (X) Wins!" : "Player 2 (O) Wins!");

    getch();
    closegraph();
    return 0;
}

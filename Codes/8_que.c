#include<stdio.h>
#include<conio.h>

int board[8];

int safe(int col, int row){
    int i;
    for(i=0; i<col; i++){
        if(board[i] == row || i - col == board[i] - row || i - col == row - board[i]){
            return 0;
        }
    }
    return 1;
}

int solve(int col){
    int row;
    if(col == 8)
        return 1;
    for(row=0; row<8; row++){
        if(safe(col, row)){
            board[col] = row;
            if(solve(col + 1))
                return 1;
        }
    }
    return 0;
}

void print(){
    int i,j;
    for(i=0; i<8; i++){
        for(j=0; j<8; j++){
            printf("%c ", board[i] == j ? 'Q': '.');
        }
        printf("\n");
    }
}

int main(){
    clrscr();

    if(solve(0))
        print();
    else
        printf("No");
    
    getch();
    return 0;
}
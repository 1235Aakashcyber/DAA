#include<stdio.h>
#include<conio.h>
#include<string.h>

int max(int a, int b){
return (a>b) ? a : b;
}

int main(){
char X[100];
char Y[100];
char L[100][100];
int i,j,m,n;
clrscr();

printf("Enter the string 1: ");
scanf("%s",&X);
printf("Enter the string 2: ");
scanf("%s",&Y);

m = strlen(X);
n = strlen(Y);

for(i=0; i<=m; i++){
for(j=0; j<=n; j++){
if(i==0 || j==0){
L[i][j] = 0;
}
else if(X[i-1] == Y[j-1]){
L[i][j] = L[i-1][j-1] + 1;
}
else{
L[i][j] = max(L[i][j-1], L[i-1][j]);
}
}
}

printf("The longest common subsequence is %d ",L[m][n]);

getch();
return 0;
}
#include<stdio.h>
#include<conio.h>
#include<string.h>

void naive(char pattern[100], char text[100]){
int n,m;
int i,j;
m =  strlen(pattern);
n = strlen(text);

for(i=0; i<=n-m; i++){
for(j=0; j<m; j++){
if(text[i+j] != pattern[j]){
break;
}
}
if(j == m){
printf("Pattern found at index %d",i);
}
}

}

int main(){
char pattern[100];
char text[100];
clrscr();

printf("Enter text: ");
scanf("%s",&text);

printf("Enter pattern: ");
scanf("%s",&pattern);

naive(pattern, text);

getch();
return 0;
}
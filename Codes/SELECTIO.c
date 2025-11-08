#include<stdio.h>
#include<conio.h>
int main(){
clrscr();
int i,j;
int its,temp;
int min;
int A[5] = {4, 1, 2, 7, 5};

for(i=0; i<5; i++){
min = A[i];
its = i;
for(j=i+1; j<5; j++){
if(A[j] < min){
its = j;
min = A[j];
}
}
if(its != i){
temp = A[its];
A[its] = A[i];
A[i] = temp;
}
}

for(i=0; i<5; i++){
printf("%d ",A[i]);
}
getch();
return 0;
}
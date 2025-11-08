#
include<stdio.h>
#include<conio.h>
int main(){
clrscr();
int high = 5;
int low = 0;
int A[5] = {2, 6, 9, 11, 15};
int mid,i,value;
int ret = -1;

printf("Enter the value to search: ");
scanf("%d",&value);

while(low<= high){
mid = (low + high)/2;
if(A[mid] == value){
ret = mid;
break;
}
else if(A[mid] > value){
high = mid - 1;
}
else{
low = mid + 1;
}
}
if(ret != -1){
printf("Element found at index %d",ret);
}
else{
printf("Not found!");
}
getch();
return 0;
}
#include<stdio.h>
#include<conio.h>
int A[5] = {45, 89, 12, 65, 10};
void merge(int st, int mid, int end){
int temp[5];
int i=st;
int j = mid +1;
int t=0;
int idx;

while(i<=mid && j<=end){
if(A[i] < A[j]){
temp[t] = A[i];
i++;
t++;
}
else{
temp[t] = A[j];
j++;
t++;
}
}
while(i<=mid){
temp[t] = A[i];
i++;
t++;
}
while(j<=end){
temp[t] = A[j];
t++;
j++;
}

for(idx = 0; idx<t; idx++){
A[idx + st] = temp[idx];
}
}

void merge_sort(int st, int end){
if(st<end){
int mid = (st + end)/2;
merge_sort(st, mid);
merge_sort(mid+1, end);
merge(st, mid, end);
}
}

int main(){
int i;
clrscr();

merge_sort(0, 4);
for(i=0; i<5; i++){
printf("%d ",A[i]);
}
getch();
return 0;
}
#include<stdio.h>
#include<conio.h>
int main(){
int mw = 50;
float pro[3] = {60, 100, 120};
float wei[3] = {10, 20, 30};
int rem = mw;
float value = 0.0;
float ratio[3];
int i;
clrscr();

for(i=0; i<3; i++){
ratio[i] = pro[i]/wei[i];
}

for(i=0; i<3; i++){
if(rem >= wei[i]){
value = value + pro[i];
rem = rem - wei[i];
}
else{
value = value + (ratio[i] * rem);
rem = 0;
break;
}
}

printf("Value is: %f",value);

getch();
return 0;
}
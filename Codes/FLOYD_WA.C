#include<stdio.h>
#include<conio.h>
#define INF 999
#define V 4

int main(){
int graph[V][V]= {
{0, 8, INF, 1},
{INF, 0, 1, INF},
{4, INF, 0, INF},
{INF, 2, 9, 0}
};
int i,j,k;
int dist[V][V];
clrscr();

for(i=0; i<V; i++){
for(j=0; j<V; j++){
dist[i][j] = graph[i][j];
}
}

for(k=0; k<V; k++){
for(i=0; i<V; i++){
for(j=0; j<V; j++){
if(dist[i][j] > dist[i][k] + dist[k][j]){
dist[i][j] = dist[i][k] + dist[k][j];
}
}
}
}
for(i=0; i<V; i++){
for(j=0; j<V; j++){
if(dist[i][j] == INF){
printf("%7s", "INF");
}
else{
printf("%7d",dist[i][j]);
}
}
printf("\n");
}

getch();
return 0;
}
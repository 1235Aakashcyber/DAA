#include<stdio.h>
#include<conio.h>
#include<limits.h>

struct edge{
int src;
int dest;
int wt;
};

int main(){
int i,j;
int V = 6;
int E = 9;
int dist[6];
struct edge edges[] = {
{0, 1, 6},
{0, 2, 4},
{0, 3, 5},
{1, 4 -1},
{2, 1 -2},
{2, 4, 3},
{3, 2, -2},
{3, 5, -1},
{4, 5, 3}
};
int src = 0;
int u,v,w;
clrscr();

for(i=0; i<V; i++){
dist[i] = INT_MAX;
}
dist[src] = 0;

for(i=1; i<V; i++){
for(j=0; j<E; j++){
u = edges[j].src;
v = edges[j].dest;
w = edges[j].wt;
if(dist[u] != INT_MAX && dist[u] + w < dist[v]){
dist[v] = dist[u] + w;
}
}
}

printf("Nodes\t\tDistance from source\n");
for(i=0; i<V; i++){
printf("%d\t\t%d\n",i,dist[i]);
}
getch();
return 0;
}
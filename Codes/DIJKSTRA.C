#include<stdio.h>
#include<conio.h>
#include<limits.h>
#define V 5

int min_dist(int dist[V], int visited[V]){
int min = INT_MAX;
int min_idx;
int v;
for(v=0; v<V; v++){
if(!visited[v] && dist[v] <= min){
min = dist[v];
min_idx = v;
}
}
return min_idx;
}

void print_sol(int dist[V]){
int i;
printf("Node\t\t Distance from source\n");
for(i=0; i<V; i++){
printf("%d\t\t%d\n",i,dist[i]);
}
}

void diji(int graph[V][V], int src){
int dist[V];
int visited[V];
int i,u,v;

for(i=0; i<V; i++){
dist[i] = INT_MAX;
visited[i] = 0;
}
dist[src] = 0;

for(i=0; i<V-1; i++){
u = min_dist(dist, visited);
visited[u] = 1;

for(v=0; v<V; v++){
if(!visited[v] && graph[u][v] && dist[u] != INT_MAX && graph[u][v] + dist[u] < dist[v]){
dist[v] = graph[u][v] + dist[u];
}
}
}
print_sol(dist);
}

int main(){
int graph[V][V] = {
{0, 10, 0, 5, 0},
{0, 0, 1, 2, 0},
{0, 0, 0, 0, 4},
{0, 0, 9, 0, 2},
{0, 0, 0, 0, 0}
};
clrscr();
diji(graph, 0);

getch();
return 0;
}
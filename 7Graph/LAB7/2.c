// 66070501043 Phoorin Chinphuad
// Dijkstra's Algorithm
#include <stdio.h>

#define INF 999

// V for total number of vertex
// u for initial vertex
// v for terminal vertex
void Initialize(int dist[], int isVisited[] , int V);
void Dijkstra(int *graph[], int srcV, int V);
void display(int dist[], int V);

int main(){
  int V, source;
  scanf(" %d %d", &V, &source);

  int graph[V][V];
  for(int i = 0; i < V; i++){
    for(int j = 0; j < V; j++){
      scanf(" %d", &graph[i][j]);
    }
  }

  int *graphPtr[V];
  for(int i = 0; i< V; i++){
    graphPtr[i] = graph[i];
  }

  Dijkstra(graphPtr, source, V);
  return 0;
}

void Initialize(int dist[], int isVisited[] , int V){
  for(int i = 0; i < V; i++){
    dist[i] = INF;
    isVisited[i] = 0;
  }
  return ;
}

int minDistance(int dist[], int isVisited[], int V){
  int min = INF;
  int min_idx;
  
  for(int v = 0; v<V; v++){
    if(isVisited[v] == 0 && dist[v] <= min){
      min = dist[v];
      min_idx = v;
    }
  }

  return min_idx;
}

void display(int dist[], int V){
    for(int v = 0; v < V; v++){
      printf("%d %d\n", v, dist[v]);
    }

    return;
}

void Dijkstra(int *graph[], int srcV, int V){
  int dist[V];
  int isVisited[V];

  Initialize(dist, isVisited, V);
  dist[srcV] = 0;

  for(int i = 0; i < V-1; i++){
    int u = minDistance(dist, isVisited, V);
    isVisited[u] = 1;

    for(int v = 0; v<V; v++){
      if(!isVisited[v] && graph[u][v] &&dist[u] != INF && dist[v] > dist[u] + graph[u][v]){
        dist[v] = dist[u] + graph[u][v];
      }
    }
  }

  display(dist, V);
  return;
}

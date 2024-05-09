// Bellman Ford Algorithm in C

#include <stdio.h>
#include <stdlib.h>

#define INFINITY 99999

//struct for the edges of the graph
struct Edge {
  int u;  //start vertex of the edge
  int v;  //end vertex of the edge
  int weight;  //weight of the edge (u,v)
};

//Graph - it consists of edges
struct Graph {
  int V;        //total number of vertices in the graph
  int E;        //total number of edges in the graph
  struct Edge *edge;  //array of edges
};

void bellmanford(struct Graph *g, int source);
void display(int dst[], int pre[], int size, int initial);
void displaygph(struct Graph *graph);
struct Graph *sortEdges(struct Graph *graph);

int main(void) {
  //create graph
  struct Graph *graph = (struct Graph*)malloc(sizeof(struct Graph));
  printf("Enter graph vertex and graph edges in order : ");
  scanf(" %d %d", &graph->V, &graph->E); // input total number of graph

  //array of edges for graph
  graph->edge = (struct Edge*)malloc(sizeof(struct Edge) * graph->E);

  //------- adding the edges of the graph
  /*
		edge(u, v)
		where 	u = start vertex of the edge (u,v)
				v = end vertex of the edge (u,v)
		
		w is the weight of the edge (u,v)
	*/  
  for(int i = 0; i < graph->E; i++){
      scanf(" %d %d %d", &graph->edge[i].u, &graph->edge[i].v, &graph->edge[i].weight);
  }

  graph = sortEdges(graph);

  displaygph(graph);

  bellmanford(graph, 0);  //0 is the source vertex

  return 0;
}

void bellmanford(struct Graph *g, int source) {
  //variables
  int i, j, u, v, w;

  //total vertex in the graph g
  int tV = g->V;

  //total edge in the graph g
  int tE = g->E;

  //distance array
  //size equal to the number of vertices of the graph g
  int d[tV];

  //predecessor array
  //size equal to the number of vertices of the graph g
  int p[tV];

  //step 1: fill the distance array and predecessor array
  for (i = 0; i < tV; i++) {
    d[i] = INFINITY;
    p[i] = 0;
  }

  //mark the source vertex
  d[source] = 0;

  //step 2: relax edges |V| - 1 times
  for (i = 1; i <= tV - 1; i++) {
    for (j = 0; j < tE; j++) {
      //get the edge data
      u = g->edge[j].u;
      v = g->edge[j].v;
      w = g->edge[j].weight;

      if (d[u] != INFINITY && d[v] > d[u] + w) {
        d[v] = d[u] + w;
        p[v] = u;
      }
    }
  }

  //step 3: detect negative cycle
  //if value changes then we have a negative cycle in the graph
  //and we cannot find the shortest distances
  for (i = 0; i < tE; i++) {
    u = g->edge[i].u;
    v = g->edge[i].v;
    w = g->edge[i].weight;
    if (d[u] != INFINITY && d[v] > d[u] + w) {
      printf("Negative weight cycle detected!\n");
      return;
    }
  }

  //No negative weight cycle found!
  //print the distance and predecessor array
  printf("All shortest path from source: \n");
  display(d, p, tV, source);
}

void display(int dst[], int pre[], int size, int initial) {
  int i;
  for (i = 0; i < size; i++) {
    if(i==initial || dst[i] == INFINITY){
      continue;
    }
    printf("source to %d distance = %d and pre vertex is %d\n", i, dst[i], pre[i]);
  }
  printf("\n");
}

struct Graph *sortEdges(struct Graph *graph){
    int i, j, min_idx;
    for (i = 0; i < graph->E-1; i++) {
        min_idx = i;
        for (j = i+1; j < graph->E; j++){
            if (graph->edge[j].u < graph->edge[min_idx].u){
                min_idx = j;
            }
            else if (graph->edge[j].u == graph->edge[min_idx].u){
                if(graph->edge[j].v < graph->edge[min_idx].v){
                    min_idx = j;
                }
                else if (graph->edge[j].v == graph->edge[min_idx].v){
                    if(graph->edge[j].weight < graph->edge[min_idx].weight){
                        min_idx = j;
                    }
                }
            }
        }
        struct Edge temp = graph->edge[min_idx];
        graph->edge[min_idx] = graph->edge[i];
        graph->edge[i] = temp;
    }

    return graph;
}

void displaygph(struct Graph *graph){
    for(int i = 0; i< graph->E; i++){
        printf("%d -> %d (%d)\n",graph->edge[i].u, graph->edge[i].v, graph->edge[i].weight);
    }

    return;
}

/*test case
1. no negative cycle
5 7
0 1 2
0 2 -3
1 2 4
1 3 -2
2 3 -1
2 4 -4
3 4 5

2. negative cycle
5 6
0 1 2
1 2 -1
2 3 3
2 4 4
3 1 -3
3 4 2
*/
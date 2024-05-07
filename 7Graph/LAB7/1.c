//Weighted Directed Graph Implementation

#include <stdio.h>
#include <stdlib.h>

struct Edge{
    int u;  //start vertex of the edge
    int v;  //end vertex of the edge
    int weight;
};

struct Graph{
    int V; //total number of vertex
    int E; //total number of graph
    struct Edge *edge;
};

void display(struct Graph *graph);
struct Graph *sortEdges(struct Graph *graph);

int main(){
    struct Graph *graph = (struct Graph*)malloc(sizeof(struct Graph));
    scanf(" %d", &graph->E); // input total number of graph
    graph->V = graph->E + 1; // vertex = edge + 1

    graph->edge = (struct Edge*)malloc(sizeof(struct Edge) * graph->E);
    
    for(int i = 0; i < graph->E; i++){
        scanf(" %d %d %d", &graph->edge[i].u, &graph->edge[i].v, &graph->edge[i].weight);
    }

    graph = sortEdges(graph);

    display(graph);

    return;
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

void display(struct Graph *graph){
    for(int i = 0; i< graph->E; i++){
        printf("%d -> %d (%d)\n",graph->edge[i].u, graph->edge[i].v, graph->edge[i].weight);
    }

    return;
}
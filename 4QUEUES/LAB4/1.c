//Phoorin Chinphuad 66070501043
//Lab 5.1: Spotify

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct MSnode
{
    char name[50];
    char artist[50];
    int time;
    struct MSnode *next;
};

struct Queue
{
    struct MSnode *front;
    struct MSnode *rear;
};

void addTo(struct Queue **playlist);
void play(struct Queue **playlist);
void sum(struct Queue **playlist);
void freeQ(struct Queue **playlist);

int main(){
    char mode[5];
    struct Queue *playlist = (struct Queue*)malloc(sizeof(struct Queue));
    playlist->front = NULL;
    playlist->rear = NULL;

    while(1)
    {
        scanf(" %s", mode);
        if(!strcmp(mode, "sum"))
        {
            sum(&playlist);
            break; 
        }
        else if(!strcmp(mode, "add")){ addTo(&playlist); }
        else if(!strcmp(mode, "play")){ play(&playlist); }
        else { printf("Invalid Choice"); }
    }

    freeQ(&playlist);
    return 0;
}

void addTo(struct Queue **playlist){

    struct MSnode *newsong;
    newsong = (struct MSnode*)malloc(sizeof(struct MSnode));
    scanf(" %[^\n]s", newsong->name);
    scanf(" %[^\n]s", newsong->artist);
    scanf(" %d", &newsong->time);
    newsong->next = NULL;

    if ((*playlist)->front == NULL)
    {
        (*playlist)->front = newsong;
        (*playlist)->rear = newsong;
        (*playlist)->front->next = (*playlist)->rear->next = NULL;
        return ;
    }
    else
    {
        (*playlist)->rear->next = newsong;
        (*playlist)->rear = newsong;
        (*playlist)->rear->next = NULL;
    }

}

void play(struct Queue **playlist){

    struct MSnode *ptr;
    ptr = (*playlist)->front;
    if(ptr == NULL)
    {
        printf("No songs in the playlist\n");
        return ;
    }
    else
    {
        (*playlist)->front = (*playlist)->front->next;
        printf("Now playing: %s by %s\n", ptr->name, ptr->artist);
        free(ptr);
    }

    return ;
}

void sum(struct Queue **playlist){
    
    int TotalTime = 0;
    struct MSnode *ptr;
    ptr = (*playlist)->front;
    if(ptr == NULL)
    {
        printf("No songs in the playlist\n");
        return ;
    }
    else
    {
        printf("Songs in the playlist:\n");
        while(ptr != (*playlist)->rear->next)
        {
            printf("%s by %s %d\n", ptr->name, ptr->artist, ptr->time);
            TotalTime += ptr->time;
            ptr = ptr->next;
        }
        printf("Remaining Time: %d\n", TotalTime);
    }
}

void freeQ(struct Queue **playlist){

    struct MSnode *ptr , *temp;
    ptr = (*playlist)->front;
    if(ptr == NULL)
    {
        printf("No songs in the playlist\n");
        return ;
    }
    else
    {
        while(ptr != (*playlist)->rear->next)
        {
            temp = ptr;
            ptr = ptr->next;
            free(temp);
        }
    }
    free(*playlist);
}
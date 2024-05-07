//Phoorin Chinphuad 66070501043
#include <stdio.h>

void universal_get(int *universal, int init_number, int final_number);
void subset_get(int* set_elements, int* set_length, int universal[], int length_universal);
void Union(int setA[], int setB[], int length_setA, int length_setB, int universal[], int length_universal);
void Intersection(int setA[], int setB[], int length_setA, int length_setB, int universal[], int length_universal);
void Difference(int set1[], int set2[], int length_set1, int length_set2, int universal[], int length_universal);
void Complement(int set_elements[], int set_length, int universal[], int length_universal);
void selectionSort(int *elements, int length);
void swap(int *x, int *y);
void print_elements(int elements[], int length);

int main(){
    int init_universal, final_universal, length_setA, length_setB;
    scanf(" %d %d",&init_universal , &final_universal);

    scanf(" %d" , &length_setA);
    int setA[length_setA];
    for(int i=0; i<length_setA; i++){
        scanf(" %d", &setA[i]);
    }

    scanf(" %d", &length_setB);
    int setB[length_setB];
    for(int i=0; i<length_setB; i++){
        scanf(" %d", &setB[i]);
    }

    int length_universal = final_universal-init_universal+1;
    int universal[length_universal];
    universal_get(universal ,init_universal, final_universal);
    subset_get(setA, &length_setA, universal, length_universal);
    subset_get(setB, &length_setB, universal, length_universal);
    // debug
    
    Union(setA, setB, length_setA, length_setB, universal, length_universal);
    Intersection(setA, setB, length_setA, length_setB, universal, length_universal);
    Difference(setA, setB, length_setA, length_setB, universal, length_universal);
    Difference(setB, setA, length_setB, length_setA, universal, length_universal);
    Complement(setA, length_setA, universal, length_universal);
    Complement(setB, length_setB, universal, length_universal);
}

void universal_get(int *universal , int init_number, int final_number){
    int i = 0;
    while(init_number <= final_number){
        //printf("init_number = %d\n" , init_number);
        universal[i] = init_number;
        i++;
        init_number++;
    }
}

void subset_get(int* set_elements, int* set_length, int universal[], int length_universal){
    int count = 0;

    for(int i = 0; i<*set_length; i++){
        int check = 0;
        for(int j=0; j<count; j++){
            if(set_elements[i]==set_elements[j]){
                check += 1;
            }
        }
        if(check == 0){
            set_elements[count] = set_elements[i];
            count += 1;
        }
    }

    *set_length = count;
    count = 0;
    for(int i=0; i<*set_length; i++){
        int check = 0;
        for(int j=0; j<length_universal; j++){
            if(set_elements[i] == universal[j]){
                check += 1;
            }
        }
        if(check > 0){
            set_elements[count] = set_elements[i];
            count += 1;
        }
    }
    *set_length = count;

    // printf("%d\n", *length);
    
    print_elements(set_elements, *set_length);
}

void Union(int setA[], int setB[], int length_setA, int length_setB, int universal[], int length_universal){
    int i;
    int union_length=length_setA+length_setB;
    int union_elements[length_setA+length_setB];

    for(i=0; i<length_setA; i++){
        union_elements[i] = setA[i];
    }
    union_length = i;
    for(i=0; i<length_setB; i++){
        union_elements[union_length] = setB[i];
        union_length++;
    }
    selectionSort(union_elements, union_length);
    subset_get(union_elements, &union_length, universal, length_universal);
}

void selectionSort(int *elements, int length){
    int i, j, minPos;
    for (i = 0; i < length - 1; i++) {
        minPos = i;
        for (j = i + 1; j < length; j++) {
            if (elements[j] < elements[minPos]) {
                minPos = j;
            }
        }
        swap(&elements[i], &elements[minPos]);
    }
}

void swap(int *x, int *y){
    int tmp;
    tmp = *x;
    *x = *y;
    *y = tmp;
}

void Intersection(int setA[], int setB[], int length_setA, int length_setB, int universal[], int length_universal){
    int count=0;
    int intersection_length=length_setA;
    int intersection_elements[intersection_length];

    for(int i=0; i<length_setA; i++){
        for(int j=0; j<length_setB; j++){
            if(setA[i] == setB[j]){
                intersection_elements[count] = setA[i];
                count += 1;
            }
        }
    }
    intersection_length = count;
    print_elements(intersection_elements, intersection_length);
}

void Difference(int set1[], int set2[], int length_set1, int length_set2, int universal[], int length_universal){
    int count = 0;
    int difference_length = length_set1+length_set2;
    int difference_elements[difference_length];

    for(int i=0; i<length_set1; i++){
        int check = 0;
        for(int j=0; j<length_set2; j++){
            if(set1[i] == set2[j]){
                check = 1;
                break;
            }
        }
        if(check == 0){
            difference_elements[count] = set1[i];
            count += 1;
        }
    }
    difference_length = count;
    print_elements(difference_elements, difference_length);
}

void Complement(int set_elements[], int set_length, int universal[], int length_universal){
    int count = 0;
    int complement_length = length_universal;
    int complement_elements[complement_length];
    for(int i=0; i<length_universal; i++){
        int check = 0;
        for(int j=0; j<set_length; j++){
            if(set_elements[j] == universal[i]){
                check = 1;
                break;
                // printf("element >%d", set1[i], set2[j]);
            }
        }
        if(check == 0){
            complement_elements[count] = universal[i];
            count += 1;
        }
    }
    complement_length = count;
    print_elements(complement_elements, complement_length);
}

void print_elements(int elements[], int length){
    if (length == 0){
        printf("empty");
        }
    for(int i = 0; i<length; i++){
            printf("%d ", elements[i]);
    }
    printf("\n");
}
//Phoorin Chinphuad 66070501043
//Grading
#include <stdio.h>
#include <math.h>

struct student
{
    char name[100];
    float score;
};

float find_MEAN(struct student *student_info, int amount);
float find_SD(struct student *student_info, int amount, float Mean);
void MAXIMUM_student(struct student *student_info, int amount);
void MINIMUM_student(struct student *student_info, int amount);

int main(){
    int amount;
    float MEAN, SD;
    scanf(" %d", &amount);

    struct student studentINFO[amount];
    for(int i=0; i<amount; i++){
        scanf(" %s %f", studentINFO[i].name, &studentINFO[i].score);
    }

    MEAN = find_MEAN(studentINFO, amount);
    SD = find_SD(studentINFO, amount, MEAN);

    printf("%.2f", MEAN);
    printf(" %.2f",SD);

    MAXIMUM_student(studentINFO, amount);
    MINIMUM_student(studentINFO, amount);

    return 0;
}

float find_MEAN(struct student *student_info, int amount){
    float sum=0.00, Mean;

    for(int i=0; i<amount; i++){
        sum += student_info[i].score;
    }

    Mean = sum / (float)amount;
    return Mean;
}

float find_SD(struct student *student_info, int amount, float Mean){
    float sum=0.00, SD;
    
    for(int i=0; i<amount; i++){
        sum += pow((student_info[i].score - Mean), 2);
    }

    SD = sqrt(sum/amount);
    return SD;
}

void MAXIMUM_student(struct student *student_info, int amount){
    int pos_MaxScore = 0;

    for(int i=0; i<amount; i++){
        if(student_info[i].score > student_info[pos_MaxScore].score){
            pos_MaxScore = i;
        }
    }
    printf(" %s", student_info[pos_MaxScore].name);
    return;
}

void MINIMUM_student(struct student *student_info, int amount){
    int pos_MinScore = 0;

    for(int i=0; i<amount; i++){
        if(student_info[i].score < student_info[pos_MinScore].score){
            pos_MinScore = i;
        }
    }
    printf(" %s", student_info[pos_MinScore].name);
    return;
}
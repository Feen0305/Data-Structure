//Phoorin Chinphuad 66070501043
#include<stdio.h>
#include<string.h>

struct dict{
	char value[100];
	char key[100];
};

void inputdict(struct dict *dic, int size);
void editdict(struct dict *dic, int size);
void printdict(struct dict *dic, int size);

int main(){
	int size;
	scanf("%d",&size);
	struct dict dic[size];

    inputdict(dic, size);
    editdict(dic, size);
    printdict(dic, size);

    return 0;
}

void inputdict(struct dict *dic, int size){
    for(int i=0; i<size; i++){
        scanf(" %s %s", dic[i].key, dic[i].value);
    }
    //debug
    // for(int i=0; i<size; i++){
    //     printf("%s %s\n", dic[i].key, dic[i].value);
    // }
}

void editdict(struct dict *dic, int size){ //for editing the dictionary
	char EditKey[100], EditValue[100];
    scanf(" %s %s", EditKey, EditValue);
    
    for(int i=0; i<size; i++){
        if(strcmp(dic[i].key , EditKey)==0){
            strcpy(dic[i].value, EditValue);
            return;
        }
    }

    printf("No change\n");
    return;
}

void printdict(struct dict *dic, int size){ //for printing the output
	for(int i=0; i<size ; i++){
		printf("%s : %s\n", dic[i].key, dic[i].value);
	}
}
//Phoorin Chinphuad 66070501043
#include <stdio.h>
#include <stdlib.h>

int* twoSum(int* nums, int numsSize, int target, int* returnSize, int* isSuccess){
    int* result = malloc(2*sizeof(int));
    *returnSize = 2;
    for(int i = 0; i< numsSize - 1; i++){
        for(int j=i; j< numsSize; j++){
            if((nums[i]+ nums[j]) == target){     
                result[0] = i;
                result[1] = j;
                *isSuccess = 1;
                return result;
            }
        }
    }
    *isSuccess = 0;
    return result;
}

int main(){
    int nums[10] = {1,2,3,4,5};
    int target = 6;
    int numsSize = sizeof(nums)/sizeof(nums[0]);
    int returnSize, isSuccess;
    int *result = twoSum(nums, numsSize, target, &returnSize, &isSuccess);

    int i;
    if(isSuccess == 1){
        printf("Indices: ");
        for(i=0; i<returnSize; i++){
            printf("%d ", result[i]);
            free(result[i]);
        }
    }
    else{
        printf("No two numbers add up to the target");
    }

    return 0;
}

/*โปรแกรมต้นแบบมีการประกาศตัวแปรแบบ Dynamic และจัดการตัวแปรได้ไม่เหมาะสม เนื่องจาก
การประกาศตัวแปรแบบ Dynamic มักจะใช้เมื่อไม่ทราบค่าขอบเขตของข้อมูลที่แน่ชัด แต่ในข้อนี้เราทราบชัดว่ามีข้อมูลทั้งหมดแค่2จำนวน
และที่สำคัญหากเรามีการประกาศตัวแปรแบบ Dynamic ในทุกครั้งเราควรที่จะ free ข้อมูลนั้นๆ 
เมื่อใช้งานเสร็จ เพื่อป้องกันการ memory leak ดังบรรทัดที่ 34*/
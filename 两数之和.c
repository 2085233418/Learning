#include<stdio.h>
#include<stdlib.h>
#include<string.h>
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

typedef struct HashNode{
    int key;
    int value;
    struct HashNode*next; 
}HashNode;

HashNode* CreateNode(int value,int key){
    HashNode* node=(HashNode*)malloc(sizeof(HashNode));
    node->value=value;
    node->key=key;
    node->next=NULL;
    return node;
}
unsigned int hash(int key,int size){
    return (unsigned int)((key%size+size)%size);
}
void insert(HashNode* *table,int size, int key,int value){
    unsigned int index=hash(key,size);
    HashNode* node=CreateNode(value,key);
    node->next=table[index];
    table[index]=node;
}
int search(HashNode* *table,int size,int key){
    unsigned int index = hash(key,size);
    HashNode* current =table[index];
    while(current!=NULL){
        if(current->key==key){
            return current->value;
        }
        current=current->next;
    }
    return -1;
}

void freeHashTable(HashNode* *table,int size){
    int index=0;
    for(;index<size;index++){
        HashNode* current=table[index];
        while(current!=NULL){
            HashNode* temp=current;
            current=current->next;
            free(temp);
        } 
    }
    free(table);
}
int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    int hashSize=2*numsSize;
    *returnSize=2;
    HashNode**hashTable=(HashNode**)calloc(hashSize,sizeof(HashNode*));
    int* result=(int*)malloc(*returnSize*sizeof(int));

    for(int i=0;i<numsSize;i++){
        int complement=target-nums[i];

        int complementindex=search(hashTable,hashSize,complement);
        if(complementindex!=-1){
            result[0]=complementindex;
            result[1]=i;
            freeHashTable(hashTable,hashSize);
            return result;
        }
        insert(hashTable,hashSize,nums[i],i);
    }
    freeHashTable(hashTable,hashSize);
    *returnSize=0;
    return NULL;
}

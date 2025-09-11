

 
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct ListNode {
     int val;
     struct ListNode *next;
 }ListNode;

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    ListNode*l3=(ListNode*)malloc(sizeof(ListNode));
    int l1v,l2v;
    int co=0;
    while(l1!=NULL||l2!=NULL){
        if(l1==NULL){
            l1v=0;
        }
        else{
            l1v=l1->val;
        }
        if(l2==NULL){
            l2v=0;
        }
        else{
            l2v=l2->val;
        }
        int current=(l1v+l2v)%10;
        co=(l1v+l2v)/10;
        InsertNode(current,l3);
        
        
    }
}

ListNode* CreateNode(int val){
    ListNode*node=(ListNode*)malloc(sizeof(ListNode));
    node->val=val;
    node->next=NULL;
}
void InsertNode(int val,ListNode**L){
    ListNode*node=CreateNode(val);
    node->next=L;
    L=node;
}
int countlength(struct ListNode*L){
    int count=0;
    struct ListNode *temp =L;
    while(temp!=NULL){
        count++;
        temp=temp->next;
    } 
    return count;
}
int main(void){

}

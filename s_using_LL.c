#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int info;
    struct node *nl;
    
} node;

typedef struct stack{
    node *top;
    
}stack ;



void pop(stack *s){
    if(s->top==NULL){
        printf("Stack under flow!!!\n");
        printf("Cannot POP!! :( \n");
        return;
    }
    node *ptr=s->top;
    s->top=s->top->nl;
    free(ptr);
    
    
}

void push(stack *s,int data){
    node *n_node = (node *)malloc(sizeof(node));
    n_node->info=data;
    n_node->nl=s->top;
    s->top=n_node;
}
void print(stack *s1){
    node *ptr=s1->top;
    while(ptr!=NULL){
    	printf("%d ",ptr->info);
    	ptr=ptr->nl;
    }
}
void main(){
    stack *s1=(stack*)malloc(sizeof(stack));
    s1->top=NULL;
    
    while(1){
        int ch;
        printf("\n1.Push\n2.Pop\n3.Print Stack\n4.Exit\n");
        printf("Enter Your Choice: ");
        scanf("%d",&ch);
        if(ch==1){
        int data;
        printf("Enter DATA: ");
        scanf("%d",&data);
            push(s1,data);
        }
        else if(ch==2){
            pop(s1);
        }
        else if(ch==3){
            print(s1);
        }
        else if(ch==4){
        printf("DONE :)\n");
            break;
        }
        else{
            printf("Enter Correct Choice !!\n");
        }
    }
}

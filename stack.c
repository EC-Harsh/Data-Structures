# include <stdio.h>
# include <stdlib.h>

typedef struct stack{
    int size;
    int top;
    int *arr;
} stack;

int isempty(stack * s){
    if(s->top==-1){
        return 1;
    }
    else
    return 0;
}
int isfull(stack *s){
    if(s->top == s->size-1){
        return 1;
    }
    else
    return 0;
}

void push(stack * s){
    if(isfull(s))
    printf("Cannot Push\n The stack is full.\n");
    else{
        
        s->top=s->top+1;
        printf("TOP Val: %d",s->top);
        printf("Enter DATA: ");
        scanf("%d",&s->arr[s->top]);
    }
}

int pop(stack * s){
    if(isempty(s)){
        printf("Cannot Pop\nThe stack is empty.\n");
    }
    else{
        int data=s->arr[s->top];
        s->top=s->top-1; // this will make top -1 and the value will be overwrite in the next push.
        printf("TOP Val: %d",s->top); 
        return data;
    }
}

void print(stack * s){
    if(s->top!=-1){
    for(int i=0;i <= s->top;i++){
        printf("Element %d: %d\n",i+1,s->arr[i]);}
    }
else{
    printf("Empty Stack \n.");
}
}
int main() {
    stack *s=(stack *)malloc(sizeof(stack));
    printf("Enter Size of the stack: ");
    scanf("%d",&s->size);
    s->top=-1;
    s->arr=(int*)malloc(s->size*sizeof(int));
    int ch;

    while(1){

    
    printf("\nEnter Your choice:\n1.Push\n2.Pop\n3.Print Stack\n4.Exit\nChoice: ");
    scanf("%d",&ch);
    if(ch==1){
        push(s);
    }
    else if(ch==2){
        pop(s);
    }
    else if(ch==3){
        print(s);
    }
    else if(ch==4){
        break;
    }
    else{
        printf("Incorrect Choice\nNothing Happens!!!! \n");
    }
}
return 0 ;
}
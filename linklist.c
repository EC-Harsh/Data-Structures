#include<stdio.h>
#include <stdlib.h>
typedef struct node{
    int info;
    struct node *link;
} node ;
// void enter(node *n,int val){
    
//     n->info=val;
//     n->link=NULL; //this will make tail's link = NULL
// }
void print(node*n){ //accessing data using recursion

    if(n->link==NULL)
    {printf("%d\n",n->info); 
    return;} //base condition for tail node.
       
    
    printf("%d\n",n->info);
    print(n->link);

    }

void main(){
    //we have to create at least a head which is denoted by n here.
    node *n;
    n=(node*)malloc(sizeof(node));
    node *t; // a temp pointer is created
        
    int data ;
    printf("Enter Data %d: ",1);
    scanf("%d",&data);
    n->info=data;
    t=(node*)malloc(sizeof(node));
    n->link=t;
    //above a head is created and it's next node(t) is also been created

    for(int i=1;i<5;i++){
        
        printf("Enter Data %d: ",i+1);
        scanf("%d",&data);
        t->info=data;
        
        t->link=i!=4?(node*)malloc(sizeof(node)):NULL;  //temporary nodes are been created 
        t=t->link;
        }

        

    //As the data structure tells by accessing only head we can track/access any value that's why only pointer to head is passed in the print function
    print(n);


}
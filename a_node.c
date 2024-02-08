#include<stdio.h>
#include <stdlib.h>
typedef struct node{
    int info;
    struct node *link;
}node;
void enter(node *n,int val){
    
    n->info=val;
    n->link=NULL; //this will make tail's link = NULL
}
void print(node*n){ //accessing data using recursion

    if(n->link==NULL)
    {printf("%d\n",n->info); 
    return;} //base condition for tail node.
       
    
    printf("%d\n",n->info);
    print(n->link);

    }

node* add(node*head,node*t_ptr,int ch){
    node*ptr=head;
    
    if(ch==2){
        while(ptr->link!=NULL){
            ptr=ptr->link;
            }// going at end
            
        ptr->link=t_ptr;//changing last node link value to new node pointer
        
        return head;
        
    }

    else if(ch==1){
        t_ptr->link=head;// changing new node link value to previous head.
        head=t_ptr;// head pointer is updated
        return head ;
        }

    else if(ch==3){
        int pos;
        printf("Enter position : ");
        scanf("%d",&pos);
        int c=0;
        while(ptr->link!=NULL){
            c++;
            if(c==(pos-1)){
                break;
            }
            ptr=ptr->link;
            }
        t_ptr->link=ptr->link;// changing new node link to that node where new node is added. or (pos-1)th node->link.
        ptr->link=t_ptr;//changing link of pos-1th node to new node;
        return head;

    }
    else{
        printf("Enter correct choice !!!\nNo node was added.\n");
        return head;
        
    }

}

void main(){
    //we have to create at least a head which is denoted by n here.
    node *n;
    n=(node*)malloc(sizeof(node));
    node *t; // a temp pointer is created
        
    int data ;
    printf("Enter Data %d: ",1);
    scanf("%d",&data);
    enter(n,data);
    t=(node*)malloc(sizeof(node));
    n->link=t;
    
    for(int i=1;i<5;i++){
        
        printf("Enter Data %d: ",i+1);
        scanf("%d",&data);
        enter(t,data);
        
        t->link=i!=4?(node*)malloc(sizeof(node)):NULL;
        t=t->link;
        }
        int ch;
    printf("ADD Node in: \n1.Starting \n2.Ending\n3.At any position\n");
    printf("Enter choice: ");
    scanf("%d",&ch);
    node*ptr1=(node*)malloc(sizeof(node)); //this is the pointer which will store the values that being added
    
    printf("Enter Data : ");
    scanf("%d",&data);
    ptr1->info=data;
    n=add(n,ptr1,ch);
        

    
    print(n);
}
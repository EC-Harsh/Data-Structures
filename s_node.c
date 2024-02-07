#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int info;
    struct node *link;
} node;
void enter(node *n, int val)
{

    n->info = val;
    n->link = NULL; // this will make tail's link = NULL
}
node *sub(node *head,node *v_ptr,int ch){
    node *ptr=head;
    if(ch==1){
        head=head->link;
        return head ;
    }
    else if(ch==2){
        while(ptr->link->link!=NULL){
            ptr=ptr->link;
        }
        ptr->link=NULL;
        return head;
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
        ptr->link=ptr->link->link;
        return head;
    }
    else{
        printf("Enter correct choice !!!\nNo node was deleted.\n");
        return head;
        
    }
}
void print(node*n){ //accessing data using recursion

    if(n->link==NULL)
    {printf("%d\n",n->info); 
    return;} //base condition for tail node.
       
    
    printf("%d\n",n->info);
    print(n->link);

    }

void main()
{
    // we have to create at least a head which is denoted by n here.
    node *n;
    n = (node *)malloc(sizeof(node));
    node *t; // a temp pointer is created

    int data,ch;
    printf("Enter Data %d: ", 1);
    scanf("%d", &data);
    enter(n, data);
    t = (node *)malloc(sizeof(node));
    n->link = t;
    // above a head is created and it's next node(t) is also been created

    for (int i = 1; i < 5; i++)
    {

        printf("Enter Data %d: ", i + 1);
        scanf("%d", &data);
        enter(t, data);

        t->link=i!=4?(node*)malloc(sizeof(node)):NULL; // temporary nodes are been created
        t = t->link;
    }
    printf("Delete Node From:\n");
    printf("1.Starting \n2.Ending \n3.At any position\nENTER YOUR CHOICE: ");
    scanf("%d",&ch);
    node *ptr1=(node *)malloc(sizeof(node));
    n=sub(n,ptr1,ch);

    // As the data structure tells by accessing only head we can track/access any value that's why only pointer to head is passed in the print function
    print(n);
}
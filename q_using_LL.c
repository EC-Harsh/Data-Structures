# include <stdio.h>
# include <stdlib.h>

typedef struct node{
    int info;
    struct node* nl;
} node ;

typedef struct queue{
    int size;
    node * r; //rear
    node *f; // front
} queue;


void enqueue(queue *q){
    q->r->nl=(node*)malloc(sizeof(node)); // create a new node
    q->r=q->r->nl; // change rear to that node
    printf("Enter Data : ");
    scanf("%d",&q->r->info); // take user input that node
    
}
void dequeue(queue *q){
    if(q->f==NULL){
        printf("Queue is empty can't Delete\n"); // if f==NULL the queue is empty we cant delete anything from it
        
        return ;
    }
    node *ptr=q->f;
    q->f=q->f->nl;
    free(ptr);
}
void print(queue* q){
    node *ptr=q->f;
    if(ptr==NULL){
    printf("Empty Set!! \n");
    	return ;}
    
    while(ptr!=NULL){
        printf("%d ",ptr->info);
        ptr=ptr->nl;
    }
    return ;

}

void main(void){
        
    queue *q1=(queue*)malloc(sizeof(queue));
    
    q1->r=(node *)malloc(sizeof(node));
    
    q1->f=q1->r; // for first time both front and rear are same.
    
    
    printf("Enter Data For First value: ");
    scanf("%d",&q1->r->info); // user input for first element .
    
    
    while(1){
        int ch;
        printf("\n1.Enqueue.\n2.Dequeue\n3.Print Queue\n4.Exit\n");
        printf("Enter YOur choice: ");
        scanf("%d",&ch);

        if(ch==1){
            enqueue(q1);
        }
        else if(ch==2){
            dequeue(q1);
        }
        else if (ch==3){
            print(q1);
        }
        else if(ch==4){
            printf("\nDONE :)\n");
            break;
        }
        else{
            printf("Enter Correct choice !!\n");
        }
    }

}

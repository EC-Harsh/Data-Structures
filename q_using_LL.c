# include <stdio.h>
# include <stdlib.h>

typedef struct node{
    int info;
    struct node* nl;
} node ;

typedef struct queue{
    int size;
    node * r;
    node *f;
} queue;
node * c_queue(int n){
    node *head=(node*)malloc(sizeof(node));
    node *ptr=head;    
    int i=1;
    while(n!=0){
        if(i==1){
            head->nl=NULL;
        }
        else{
            ptr->nl=(node*)malloc(sizeof(node));
            ptr=ptr->nl;
        }
        i++;
        n--;
        
    }
    ptr->nl=NULL;
    return head;
}

void enqueue(queue *q){
    if(q->r!=NULL){
        printf("Enter Element: ");
        scanf("%d",&q->r->info);
        q->r=q->r->nl;
        return ;
    }
    printf("Queue Is FULL Can't ADD !!\n");
}
void dequeue(queue *q){
    if(q->r==q->f){
        printf("Queue is empty can't Delete");
        return ;
    }
    q->f=q->f->nl;
}
void print(queue* q){
    node *ptr=q->f;
    while(ptr!=NULL){
        printf("%d ",ptr->info);
        ptr=ptr->nl;
    }
    return ;

}

void main(void){
    int size;
    printf("Enter Size of the Queue you want to create: ");
    scanf("%d",&size);
    queue *q1=(queue*)malloc(sizeof(queue));
    q1->r=q1->f=c_queue(size);
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
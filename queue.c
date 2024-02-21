# include <stdio.h>
# include <stdlib.h>

typedef struct queue {
    int r;
    int size;
    int f;
    int *arr;
} queue;

void enq(queue *q){
    if(q->r>=0 && q->r < q->size){
        printf("Enter Element: ");
        scanf("%d",&q->arr[q->r]);
        q->r++;
        return ;
    }
    else{
        printf("Queue FULL !\n");
        return ;
    }
}
void deq(queue *q){
    if(q->r==0 || q->f==q->r){
        printf("Empty QUEUE Cannot Remove!!\n");
        return ;
    }
    printf("Deleted element : %d\n",q->arr[q->f]);
    q->f++;
}

void printq(queue *q){
    if(q->r==0){
        printf("Empty QUEUE !!\n");
        return ;
    }
    for(int i=q->f;i<=q->r-1;i++){
        printf("%d ",q->arr[i]);
    }
    printf("\n");
    return ;
}
int main() {
    queue *q=(queue *)malloc(sizeof(queue));
    printf("Enter Size of the queue : ");
    scanf("%d",&q->size);
    q->arr=(int *)malloc(q->size*sizeof(int));
    q->f=0;
    q->r=0;
    int ch;
    while(1){
        printf("\n1.Enqueue\n2.Dequeue\n3.Print Queue\n4.Exit\n");
        printf("Enter choice: ");
        scanf("%d",&ch);
        if(ch==1){
            enq(q);
            printf("The queue is: \n");
            printq(q);
        }
        else if(ch==2){
            deq(q);
             printf("The queue is: \n");
            printq(q);

        }
        else if(ch==3){
             printf("The queue is: \n");
            printq(q);
        }
        else if(ch==4){
            printf("DONE :)\n");
            break;
        }
        else{
            printf("Enter Correct Choice !! \n");
        }
    }
return 0 ;
}
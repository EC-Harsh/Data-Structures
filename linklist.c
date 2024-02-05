#include<stdio.h>
#include <stdlib.h>
typedef struct node{
    int info;
    struct node *link;
} node ;
void main(){
    node *n1=(node*)malloc(sizeof(node));
    scanf("%d",&n1->info);

}
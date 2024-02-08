#include <stdio.h>
#include <stdlib.h>

typedef struct node // doubly linklist node contains:
{
    struct node *pl; // previous node's address
    int info;        // node's own data;
    struct node *nl; // next node's address
} node;
node *c_list(int n)
{
    node *head = (node *)malloc(sizeof(node)); // head node
    node *t_ptr = head;                        // create a pointer that iterates till last node
    node *prev_node;                           // create a node pointer that stores previous node address
    int i = 1;
    while (n != 0)
    {

        if (i == 1) // for head/first node both previous and next node's address will be null
        {
            t_ptr->pl = NULL;
            t_ptr->nl = NULL;
            prev_node = t_ptr;
        }
        else
        {
            t_ptr->nl = (node *)malloc(sizeof(node)); // node's next link value updated to new address
            t_ptr->pl = prev_node;                    // node's previous link is updated
            prev_node = t_ptr;                        // previous node's adresss is updated before changing to the next node
            t_ptr = t_ptr->nl;                        // temp ptr changes to next node;
        }
        printf("Enter Data %d: ", i++);
        scanf("%d", &t_ptr->info); // node's data updated.
        n--;
    }
    return head;
}

void print(node *ptr) // accessing data using recursion
{
    if (ptr->nl == NULL) // base condition for tail node.
    {
        printf("%d\n", ptr->info);
        return;
    }
    printf("%d->", ptr->info);
    print(ptr->nl);
}

void rprint(node *ptr) // using recurssion we are going till end
{
    if (ptr->nl == NULL) // ending condition.
    {
        printf("%d", ptr->info);
        return;
    }
    rprint(ptr->nl);
    printf("<-%d", ptr->info);
}

node *del(node *head, int n, int m)
{
    node *tptr = head;
    int c = 0;
    if (n == 1) // when user wants to delete 1st node.
    {
        head = tptr->nl; // changing head pointer value
        head->pl = NULL; // chnaging it's previous link to null
        return head;
    }

    while (tptr->nl != NULL)
    {
        c++;
        if (c == (n - 1)) // going till (n-1)th node if user want to delete nth node
        {
            break;
        }
        tptr = tptr->nl;
    }
    // user wants to delete nth node;
    if (n != m)
    {
        tptr->nl->nl->pl = tptr; // changing (n+1)th node's previous link value to (n-1)th node's address
        tptr->nl = tptr->nl->nl; // changing (n-1)th node's next link to (n+1)th node's address
        return head;
    }
    else // when user wants to delete last node
    {
        tptr->nl == NULL; // we just have to change (n-1)th node's next link to NULL
        return head;
    }

    // returning head because we can acess any value using head;
}

int main()
{
    int n;
    char ch;
    printf("Enter list length: "); // asking list's length
    scanf("%d", &n);
    node *h = c_list(n);

    print(h);
    printf("Reverse of the list: \n"); // printing reverse of the list.
    rprint(h);

    printf("\nIf you want to delete any node enter[y/n]: ");
    scanf("%s", &ch);
    if (ch == 'y' || ch == 'Y')
    {
        int pos;
        printf("Enter Position: ");
        scanf("%d", &pos);
        h = del(h, pos, n);
        print(h);
        printf("Reverse of the list: \n");
        rprint(h);
    }

    printf("\nDONE! \n");

    return 0;
}
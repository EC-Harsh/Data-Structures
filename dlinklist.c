#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int info;
    struct node *pl;
    struct node *nl;
} node;

node *c_list(int n)
{
    node *head = (node *)malloc(sizeof(node));
    int i = 1;
    node *prev_node, *tptr = head;
    ;
    while (n != 0)
    {
        if (i == 1)
        {

            head->pl = NULL;
            head->nl = NULL;
            prev_node = head;
        }
        else
        {
            tptr->nl = (node *)malloc(sizeof(node *));
            tptr->pl = prev_node;
            prev_node = tptr;
            tptr = tptr->nl;
        }
        printf("Enter Data For node %d: ", i);
        scanf("%d", &tptr->info);
        n--;
        i++;
        tptr->nl = NULL;
    }

    return head;
}
void print(node *ptr)
{
    if (ptr->nl == NULL)
    {
        printf("%d\n", ptr->info);
        return;
    }
    printf("%d->", ptr->info);
    print(ptr->nl);
}
void rprint(node *ptr)
{
    if (ptr->nl == NULL)
    {
        printf("%d", ptr->info);
        return;
    }
    rprint(ptr->nl);
    printf("<-%d", ptr->info);
}
node *d_list(node *head, int n)
{
    if (head == NULL)
    {
        printf("List is empty.\n");
        return head;
    }
    if (n < 0)
    {
        printf("Invalid choice \n");
        return head;
    }

    if (n == 1)
    {

        head = head->nl;
        head->pl = NULL;
        return head;
    }

    else if (n == 2)
    {
        node *ptr = head;
        while (ptr->nl->nl != NULL)
        {
            ptr = ptr->nl;
        }
        ptr->nl = NULL;
        return head;
    }
    else if (n != 2)
    {
        int pos;
        printf("Enter Position: ");
        scanf("%d", &pos);
        if (pos == 1)
        {

            head = head->nl;
            head->pl = NULL;
            return head;
        }
        int i = 1;
        node *ptr = head;
        while (1)
        {
            if (ptr->nl == NULL && (i <= (pos - 1)))
            {
                printf("Incorrect Position !!\n");
                return head;
            }

            if ((ptr->nl->nl == NULL) && (i == (pos - 1)))
            {

                printf("last node deleted.\n");
                ptr->nl = NULL;
                return head;
                break;
            }
            else if (i == pos)
            {
                ptr->pl->nl = ptr->nl;
                ptr->nl->pl = ptr->pl;
                return head;
                break;
            }

            else
            {
                i++;
                ptr = ptr->nl;
            }
        }
        return head;
    }
}

node *a_list(node *head, int n)
{
    if (head == NULL)
    {
        printf("List is empty.\n");
        return head;
    }
    if (n < 0||n>3)
    {
        printf("Invalid choice \n");
        return head;
    }

    if (n == 1)
    {
       
        node*t_ptr=(node*)malloc(sizeof(node));
        printf("Enter Data: ");
        scanf("%d",&t_ptr->info);
        t_ptr->nl=head;
        t_ptr->pl=NULL;
        head->pl=t_ptr;
        head=t_ptr;
        return head;
    }

    else if (n == 2)
    {
        node *ptr = head;
        while (ptr->nl!= NULL)
        {
            ptr = ptr->nl;
        }
        ptr->nl =(node*)malloc(sizeof(node)) ;
        printf("Enter Data: ");
        scanf("%d",&ptr->nl->info);
        ptr->nl->pl=ptr;
        ptr->nl->nl=NULL;
        
        return head;
    }
    else if (n != 2)
    {
        int pos;
        printf("Enter Position: ");
        scanf("%d", &pos);
        node*t_ptr=(node*)malloc(sizeof(node));
        printf("Enter Data: ");
        scanf("%d",&t_ptr->info);

        if (pos == 1)
        {
           t_ptr->nl=head;
            t_ptr->pl=NULL;
            head->pl=t_ptr;
            head=t_ptr;
            return head;
        }

                
        int i = 1;
        node *ptr = head;
        while (1)
        {
            if (ptr->nl == NULL && (i <= (pos - 1)))
            {
                printf("Incorrect Position !!\n");
                return head;
            }

            if ((ptr->nl->nl == NULL) && (i == (pos - 1)))
            {

                t_ptr->nl= ptr->nl;
                t_ptr->pl=ptr;
                t_ptr->nl->pl=t_ptr;
                ptr->nl=t_ptr;
                return head;
                break;
            }
            else if (i == pos)
            {
                t_ptr->nl=ptr;
                t_ptr->pl=ptr->pl;
                ptr->pl=t_ptr;
                t_ptr->pl->nl=t_ptr;
                return head;
                break;
            }

            else
            {
                i++;
                ptr = ptr->nl;
            }
        }
        return head;
    }
}

void main()
{
    int size;
    printf("Enter Size of the list : ");
    scanf("%d", &size);
    if (size > 0)
    {
        char ch;
        node *l1 = c_list(size);
        printf("Size %d\n", size);
        printf("The List is: \n");
        print(l1);
        printf("\nThe reverse of the list will be: \n");
        rprint(l1);
        printf("\n");
        printf("Size %d\n", size);

        printf("If you want to delete and node enter [y/n]: ");
        scanf("%s", &ch);
        int s = size;
        if (ch == 'y' || ch == 'Y')
        {
            int ch;
            printf("Enter choice :\n1.Starting\n2.Ending\n3.At any particular position \nChoice: ");

            scanf("%d", &ch);
            l1 = d_list(l1, ch);

            printf("The List is: \n");
            print(l1);
            printf("\nThe reverse of the list will be: \n");
            rprint(l1);
            printf("\nDONE :) \n");
            
        }

        printf("If you want to insert a node enter [y/n]: ");
        scanf("%s", &ch);
        if (ch == 'y' || ch == 'Y')
        {
            int ch;
            printf("Enter choice :\n1.Starting\n2.Ending\n3.At any particular position \nChoice: ");

            scanf("%d", &ch);
            
                l1 = a_list(l1, ch);
                printf("The List is: \n");
                print(l1);
                printf("\nThe reverse of the list will be: \n");
                rprint(l1);
                printf("\nDONE :) \n");
            
            
        }
    }
    else
        printf("Enter a valid size greater than 0\n");
}
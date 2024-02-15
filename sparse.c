#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int r;
    int c;
    int v;
    struct node *nl;
} node;

void print(node *ptr)
{
    if (ptr->nl == NULL)
    {
        printf("|%d|%d|%d| \n", ptr->r, ptr->c, ptr->v);
        return;
    }
    printf("|%d|%d|%d| -> ", ptr->r, ptr->c, ptr->v);
    print(ptr->nl);
}
int main()
{
    int ra, ca;
    printf("Enter Rows and column of the matrix: ");
    scanf("%d%d", &ra, &ca);
    int a[ra][ca], x = 0;
    for (int i = 0; i < ra; i++)
    {
        for (int j = 0; j < ca; j++)
        {
            printf("Enter Element for (%d,%d): ", i + 1, j + 1);
            scanf("%d", &a[i][j]);
            if (a[i][j] == 0)
                x++;
        }
    }
    // A sparse matrix is that matrix in which the number
    // of  zeroes is greater than the non zero elements
    // approximately greater than 2/3 of the total elements.
    if ((float)x >= (ra * ca) * (2 / 3.0))
    {
        printf("The Matrix is a sparse matrix.\n");
        node *head = NULL;
        node *ptr = NULL;
        for (int i = 0; i < ra; i++)
        {
            for (int j = 0; j < ca; j++)
            {
                if (a[i][j] != 0)
                {
                    node *block = (node *)malloc(sizeof(node));
                    block->r = i;
                    block->c = j;
                    block->v = a[i][j];
                    block->nl = NULL;

                    if (head == NULL)
                    {
                        head = block;
                        ptr = head;
                    }
                    else
                    {
                        ptr->nl = block;
                        ptr = ptr->nl;
                    }
                }
            }
        }

        printf("The Link List representation of the given sparse matrix in given form |Row|Column|Value| is:\n");
        print(head);
    }
    else
    {
        printf("The Given Marix is not a sparse matrix.");
    }

    return 0;
}
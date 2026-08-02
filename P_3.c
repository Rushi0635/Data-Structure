#include <stdio.h>

int main()
{
    int a[20], n, i, pos, item, ch, found;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter array elements:\n");
    for(i = 0; i < n; i++)
        scanf("%d", &a[i]);

    do
    {
        printf("\n\n----- MENU -----");
        printf("\n1. Traversal");
        printf("\n2. Insertion");
        printf("\n3. Deletion");
        printf("\n4. Search");
        printf("\n5. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &ch);

        switch(ch)
        {
            case 1:
                printf("Array: ");
                for(i = 0; i < n; i++)
                    printf("%d ", a[i]);
                break;

            case 2:
                if(n == 20)
                {
                    printf("Array is full.");
                }
                else
                {
                    printf("Enter position and value: ");
                    scanf("%d%d", &pos, &item);

                    if(pos < 1 || pos > n + 1)
                    {
                        printf("Invalid position.");
                    }
                    else
                    {
                        for(i = n; i >= pos; i--)
                            a[i] = a[i - 1];

                        a[pos - 1] = item;
                        n++;

                        printf("Element inserted.");
                    }
                }
                break;

            case 3:
                if(n == 0)
                {
                    printf("Array is empty.");
                }
                else
                {
                    printf("Enter position to delete: ");
                    scanf("%d", &pos);

                    if(pos < 1 || pos > n)
                    {
                        printf("Invalid position.");
                    }
                    else
                    {
                        for(i = pos - 1; i < n - 1; i++)
                            a[i] = a[i + 1];

                        n--;

                        printf("Element deleted.");
                    }
                }
                break;

            case 4:
                    printf("Enter element to search: ");
                    scanf("%d", &item);

                    for(i = 0; i < n; i++)
                    {
                        if(a[i] == item)
                        {
                            printf("Element found at position %d", i + 1);
                            break;
                        }
                    }

                    if(i == n)
                    {
                        printf("Element not found.");
                    }
                break;

            case 5:
                printf("Program Ended.");
                break;

            default:
                printf("Invalid Choice.");
        }

    } while(ch != 5);

    return 0;
}
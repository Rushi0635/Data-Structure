#include <stdio.h>

int main()
{
    int a[20], size, i, pos, elem, ch;

    printf("Enter number of elements: ");
    scanf("%d", &size);

    printf("Enter array elements:\n");
    for(i = 0; i < size; i++)
        scanf("%d", &a[i]);

    do
    {
        printf("\n\n----- Array Operations -----");
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
                for(i = 0; i < size; i++)
                    printf("%d ", a[i]);
                break;

            case 2:
                if(size == 20)
                {
                    printf("Array is full.");
                }
                else
                {
                    printf("Enter position to insert: ");
                    scanf("%d", &pos);

                    printf("Enter element to insert: ");
                    scanf("%d", &elem);

                    if(pos < 1 || pos > size + 1)
                    {
                        printf("Invalid position.");
                    }
                    else
                    {
                        for(i = size; i >= pos; i--)
                            a[i] = a[i - 1];

                        a[pos - 1] = elem;
                        size++;

                        printf("Element inserted.");
                    }
                }
                break;

            case 3:
                if(size == 0)
                {
                    printf("Array is empty.");
                }
                else
                {
                    printf("Enter position to delete: ");
                    scanf("%d", &pos);

                    if(pos < 1 || pos > size)
                    {
                        printf("Invalid position.");
                    }
                    else
                    {
                        for(i = pos - 1; i < size - 1; i++)
                            a[i] = a[i + 1];

                        size--;

                        printf("Element deleted.");
                    }
                }
                break;

            case 4:
                    printf("Enter element to search: ");
                    scanf("%d", &elem);

                    for(i = 0; i < size; i++)
                    {
                        if(a[i] == elem)
                        {
                            printf("Element found at position %d", i + 1);
                            break;
                        }
                    }

                    if(i == size)
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
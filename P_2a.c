#include <stdio.h>

int main()
{
    int arr[10], n, i;
    int *ptr;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter array elements:\n");
    for(i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    
    ptr = arr + n - 1;

    printf("Array elements in reverse order are:\n");
    for(i = 0; i < n; i++)
    {
        printf("%d ", *ptr);
        ptr--;
    }

    return 0;
}
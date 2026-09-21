#include <stdio.h>

// Call by Value
void value(int x)
{
    x = x + 10;
    printf("Inside Call by Value: %d\n", x);
}

// Call by Reference
void reference(int *x)
{
    *x = *x + 10;
    printf("Inside Call by Reference: %d\n", *x);
}

int main()
{
    int a = 10;
    int b = 10;

    printf("Before Call by Value: %d\n", a);
    value(a);
    printf("After Call by Value: %d\n\n", a);

    printf("Before Call by Reference: %d\n", b);
    reference(&b);
    printf("After Call by Reference: %d\n", b);

    return 0;
}

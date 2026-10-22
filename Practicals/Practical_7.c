#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *last = NULL;

void insertBeginning(int value)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));

    newNode->data = value;

    if (last == NULL)
    {
        last = newNode;
        newNode->next = last;
    }
    else
    {
        newNode->next = last->next;
        last->next = newNode;
    }
}

void insertEnd(int value)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));

    newNode->data = value;

    if (last == NULL)
    {
        last = newNode;
        newNode->next = last;
    }
    else
    {
        newNode->next = last->next;
        last->next = newNode;
        last = newNode;
    }
}

void insertAfter(int key, int value)
{
    if (last == NULL)
    {
        printf("List is empty\n");
        return;
    }

    struct Node *temp = last->next;

    do
    {
        if (temp->data == key)
        {
            struct Node *newNode =
                (struct Node *)malloc(sizeof(struct Node));

            newNode->data = value;
            newNode->next = temp->next;
            temp->next = newNode;

            if (temp == last)
                last = newNode;

            return;
        }

        temp = temp->next;

    } while (temp != last->next);

    printf("Node not found\n");
}

void deleteFirst()
{
    if (last == NULL)
    {
        printf("List is empty\n");
        return;
    }

    struct Node *temp = last->next;

    if (temp == last)
    {
        last = NULL;
    }
    else
    {
        last->next = temp->next;
    }

    free(temp);
}

void deleteLast()
{
    if (last == NULL)
    {
        printf("List is empty\n");
        return;
    }

    struct Node *temp = last->next;

    if (temp == last)
    {
        free(last);
        last = NULL;
        return;
    }

    while (temp->next != last)
    {
        temp = temp->next;
    }

    temp->next = last->next;
    free(last);
    last = temp;
}

void deleteAfter(int key)
{
    if (last == NULL)
    {
        printf("List is empty\n");
        return;
    }

    struct Node *temp = last->next;

    do
    {
        if (temp->data == key)
        {
            struct Node *del = temp->next;

            
            if (del == temp)
            {
                last = NULL;
            }
            else
            {
                temp->next = del->next;

                if (del == last)
                    last = temp;
            }

            free(del);
            return;
        }

        temp = temp->next;

    } while (temp != last->next);

    printf("Node not found\n");
}

void display()
{
    if (last == NULL)
    {
        printf("List is empty\n");
        return;
    }

    struct Node *temp = last->next;

    printf("Circular Linked List: ");

    do
    {
        printf("%d ", temp->data);
        temp = temp->next;

    } while (temp != last->next);

    printf("\n");
}


int main()
{
    int choice, value, key;

    while (1)
    {
        printf("\n--- Singly Circular Linked List ---\n");
        printf("1. Insert at Beginning\n");
        printf("2. Insert at End\n");
        printf("3. Insert After Given Node\n");
        printf("4. Delete First Node\n");
        printf("5. Delete Last Node\n");
        printf("6. Delete Node After Given Node\n");
        printf("7. Display\n");
        printf("8. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                insertBeginning(value);
                break;

            case 2:
                printf("Enter value: ");
                scanf("%d", &value);
                insertEnd(value);
                break;

            case 3:
                printf("Enter node after which to insert: ");
                scanf("%d", &key);

                printf("Enter value: ");
                scanf("%d", &value);

                insertAfter(key, value);
                break;

            case 4:
                deleteFirst();
                break;

            case 5:
                deleteLast();
                break;

            case 6:
                printf("Enter node after which to delete: ");
                scanf("%d", &key);

                deleteAfter(key);
                break;

            case 7:
                display();
                break;

            case 8:
                exit(0);

            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}
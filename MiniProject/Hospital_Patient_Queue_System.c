
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Patient
{
    int id;
    char name[50];
    int age;
    char problem[100];
    int priority;
    struct Patient *next;
};

struct Patient *head = NULL;

struct Patient* createNode()
{
    struct Patient *newNode;

    newNode = (struct Patient*)malloc(sizeof(struct Patient));

    if (newNode == NULL)
    {
        printf("\nMemory allocation failed!\n");
        return NULL;
    }

    printf("\nEnter Patient ID: ");
    scanf("%d", &newNode->id);

    printf("Enter Patient Name: ");
    scanf(" %49[^\n]", newNode->name);

    printf("Enter Age: ");
    scanf("%d", &newNode->age);

    printf("Enter Medical Problem: ");
    scanf(" %99[^\n]", newNode->problem);

    printf("\nPriority Levels:\n");
    printf("4 - Emergency (Highest)\n");
    printf("3 - Serious\n");
    printf("2 - Normal\n");
    printf("1 - Minor (Lowest)\n");

    printf("Enter Priority: ");
    scanf("%d", &newNode->priority);

    if (newNode->priority < 1 || newNode->priority > 4)
    {
        printf("\nInvalid priority!\n");
        free(newNode);
        return NULL;
    }

    newNode->next = NULL;

    return newNode;
}

void addPatient()
{
    struct Patient *newNode;
    struct Patient *temp;

    newNode = createNode();

    if (newNode == NULL)
    {
        return;
    }

    if (head == NULL ||
        newNode->priority > head->priority)
    {
        newNode->next = head;
        head = newNode;
    }
    else
    {
        temp = head;

        while (temp->next != NULL &&
               temp->next->priority >= newNode->priority)
        {
            temp = temp->next;
        }

        newNode->next = temp->next;
        temp->next = newNode;
    }

    printf("\nPatient added successfully!\n");
}

void displayPatients()
{
    struct Patient *temp = head;

    if (head == NULL)
    {
        printf("\nNo patients in queue.\n");
        return;
    }

    printf("\n---------- Patient Queue ----------\n");
    printf("ID\tName\t\tAge\tPriority\tProblem\n");

    while (temp != NULL)
    {
        printf("%d\t%-15s\t%d\t%d\t\t%s\n",
               temp->id,
               temp->name,
               temp->age,
               temp->priority,
               temp->problem);

        temp = temp->next;
    }
}

void nextPatient()
{
    if (head == NULL)
    {
        printf("\nNo patients in queue.\n");
        return;
    }

    printf("\n------- Next Patient -------\n");
    printf("Patient ID : %d\n", head->id);
    printf("Name       : %s\n", head->name);
    printf("Age        : %d\n", head->age);
    printf("Problem    : %s\n", head->problem);
    printf("Priority   : %d\n", head->priority);
}

void treatPatient()
{
    struct Patient *temp;

    if (head == NULL)
    {
        printf("\nNo patients in queue.\n");
        return;
    }

    temp = head;

    printf("\nPatient treated successfully!\n");
    printf("Patient ID : %d\n", temp->id);
    printf("Name       : %s\n", temp->name);
    printf("Priority   : %d\n", temp->priority);

    head = head->next;

    free(temp);
}


void searchPatient()
{
    struct Patient *temp = head;
    int id;

    printf("\nEnter Patient ID to search: ");
    scanf("%d", &id);

    while (temp != NULL)
    {
        if (temp->id == id)
        {
            printf("\nPatient Found!\n");
            printf("Patient ID : %d\n", temp->id);
            printf("Name       : %s\n", temp->name);
            printf("Age        : %d\n", temp->age);
            printf("Problem    : %s\n", temp->problem);
            printf("Priority   : %d\n", temp->priority);

            return;
        }

        temp = temp->next;
    }

    printf("\nPatient not found.\n");
}

void freeQueue()
{
    struct Patient *temp;

    while (head != NULL)
    {
        temp = head;
        head = head->next;
        free(temp);
    }
}

int main()
{
    int choice;

    do
    {
        printf("\n====================================\n");
        printf("   HOSPITAL PATIENT QUEUE SYSTEM\n");
        printf("====================================\n");
        printf("1. Add Patient\n");
        printf("2. Display Patient Queue\n");
        printf("3. View Next Patient\n");
        printf("4. Treat Patient\n");
        printf("5. Search Patient\n");
        printf("6. Exit\n");

        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                addPatient();
                break;

            case 2:
                displayPatients();
                break;

            case 3:
                nextPatient();
                break;

            case 4:
                treatPatient();
                break;

            case 5:
                searchPatient();
                break;

            case 6:
                freeQueue();
                printf("\nThank you for using the system!\n");
                break;

            default:
                printf("\nInvalid choice!\n");
        }

    } while (choice != 6);

    return 0;
}

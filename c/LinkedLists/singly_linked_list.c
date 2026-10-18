#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *createNode(int data) {
    struct Node *newNode = malloc(sizeof(struct Node));

    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        return NULL;
    }

    newNode->data = data;
    newNode->next = NULL;

    return newNode;
}

int readInt(const char *message, int *value) {
    char buffer[100];
    char extra;
    int result;

    printf("%s", message);

    if (fgets(buffer, sizeof(buffer), stdin) == NULL) {
        return 0;
    }

    result = sscanf(buffer, " %d %c", value, &extra);

    if (result != 1) {
        printf("Invalid input. Please enter an integer.\n");
        return -1;
    }

    return 1;
}

void insertBeginning(struct Node **head, int data) {
    struct Node *newNode = createNode(data);

    if (newNode == NULL) {
        return;
    }

    newNode->next = *head;
    *head = newNode;

    printf("Node inserted successfully.\n");
}

void insertEnd(struct Node **head, int data) {
    struct Node *newNode = createNode(data);
    struct Node *temp;

    if (newNode == NULL) {
        return;
    }

    if (*head == NULL) {
        *head = newNode;
        printf("Node inserted successfully.\n");
        return;
    }

    temp = *head;

    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = newNode;

    printf("Node inserted successfully.\n");
}

void insertAtPosition(struct Node **head, int data, int position) {
    struct Node *newNode;
    struct Node *temp;
    int i;

    if (position < 1) {
        printf("Invalid position.\n");
        return;
    }

    if (position == 1) {
        insertBeginning(head, data);
        return;
    }

    temp = *head;

    for (i = 1; i < position - 1 && temp != NULL; i++) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Invalid position.\n");
        return;
    }

    newNode = createNode(data);

    if (newNode == NULL) {
        return;
    }

    newNode->next = temp->next;
    temp->next = newNode;

    printf("Node inserted successfully.\n");
}

void deleteBeginning(struct Node **head) {
    struct Node *temp;

    if (*head == NULL) {
        printf("The list is empty.\n");
        return;
    }

    temp = *head;
    *head = (*head)->next;

    printf("Deleted element: %d\n", temp->data);

    free(temp);
}

void deleteEnd(struct Node **head) {
    struct Node *temp;
    struct Node *previous = NULL;

    if (*head == NULL) {
        printf("The list is empty.\n");
        return;
    }

    temp = *head;

    if (temp->next == NULL) {
        printf("Deleted element: %d\n", temp->data);
        free(temp);
        *head = NULL;
        return;
    }

    while (temp->next != NULL) {
        previous = temp;
        temp = temp->next;
    }

    previous->next = NULL;

    printf("Deleted element: %d\n", temp->data);

    free(temp);
}

void deleteAtPosition(struct Node **head, int position) {
    struct Node *temp;
    struct Node *toDelete;
    int i;

    if (position < 1 || *head == NULL) {
        printf(*head == NULL ? "The list is empty.\n" : "Invalid position.\n");
        return;
    }

    if (position == 1) {
        deleteBeginning(head);
        return;
    }

    temp = *head;

    for (i = 1; i < position - 1 && temp != NULL; i++) {
        temp = temp->next;
    }

    if (temp == NULL || temp->next == NULL) {
        printf("Invalid position.\n");
        return;
    }

    toDelete = temp->next;
    temp->next = toDelete->next;

    printf("Deleted element: %d\n", toDelete->data);

    free(toDelete);
}

void displayList(struct Node *head) {
    struct Node *temp = head;

    if (head == NULL) {
        printf("The list is empty.\n");
        return;
    }

    printf("Linked list: ");

    while (temp != NULL) {
        printf("%d", temp->data);

        if (temp->next != NULL) {
            printf(" -> ");
        }

        temp = temp->next;
    }

    printf(" -> NULL\n");
}

void searchElement(struct Node *head, int key) {
    struct Node *temp = head;
    int position = 1;
    int found = 0;

    while (temp != NULL) {
        if (temp->data == key) {
            printf("Element %d found at position %d.\n", key, position);
            found = 1;
        }

        temp = temp->next;
        position++;
    }

    if (!found) {
        printf("Element not found.\n");
    }
}

int countNodes(struct Node *head) {
    int count = 0;
    struct Node *temp = head;

    while (temp != NULL) {
        count++;
        temp = temp->next;
    }

    return count;
}

void reverseList(struct Node **head) {
    struct Node *previous = NULL;
    struct Node *current = *head;
    struct Node *nextNode;

    while (current != NULL) {
        nextNode = current->next;
        current->next = previous;
        previous = current;
        current = nextNode;
    }

    *head = previous;

    printf("Linked list reversed successfully.\n");
}

void sortList(struct Node *head) {
    struct Node *current;
    struct Node *nextNode;
    int temp;

    if (head == NULL || head->next == NULL) {
        printf("List sorted successfully.\n");
        return;
    }

    for (current = head; current->next != NULL; current = current->next) {
        for (nextNode = current->next; nextNode != NULL;
             nextNode = nextNode->next) {
            if (current->data > nextNode->data) {
                temp = current->data;
                current->data = nextNode->data;
                nextNode->data = temp;
            }
        }
    }

    printf("Linked list sorted in ascending order.\n");
}

void deleteByValue(struct Node **head, int value) {
    struct Node *temp = *head;
    struct Node *previous = NULL;

    while (temp != NULL && temp->data != value) {
        previous = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Element not found.\n");
        return;
    }

    if (previous == NULL) {
        *head = temp->next;
    } else {
        previous->next = temp->next;
    }

    printf("Deleted element: %d\n", temp->data);

    free(temp);
}

void freeList(struct Node **head) {
    struct Node *temp;

    while (*head != NULL) {
        temp = *head;
        *head = (*head)->next;
        free(temp);
    }
}

int main(void) {
    struct Node *head = NULL;
    int choice;
    int data;
    int position;
    int result;

    while (1) {
        printf("\n===== SINGLY LINKED LIST MENU =====\n");
        printf("1. Insert at the beginning\n");
        printf("2. Insert at the end\n");
        printf("3. Insert at a specific position\n");
        printf("4. Delete from the beginning\n");
        printf("5. Delete from the end\n");
        printf("6. Delete from a specific position\n");
        printf("7. Display all nodes\n");
        printf("8. Search for an element\n");
        printf("9. Count total nodes\n");
        printf("10. Reverse the linked list\n");
        printf("11. Sort in ascending order\n");
        printf("12. Delete a node by value\n");
        printf("13. Exit\n");

        result = readInt("Enter your choice: ", &choice);

        if (result == 0) {
            break;
        }

        if (result == -1) {
            continue;
        }

        switch (choice) {
            case 1:
                result = readInt("Enter the value: ", &data);
                if (result == 0) {
                    goto exit_program;
                }
                if (result == 1) {
                    insertBeginning(&head, data);
                }
                break;

            case 2:
                result = readInt("Enter the value: ", &data);
                if (result == 0) {
                    goto exit_program;
                }
                if (result == 1) {
                    insertEnd(&head, data);
                }
                break;

            case 3:
                result = readInt("Enter the value: ", &data);
                if (result == 0) {
                    goto exit_program;
                }
                if (result == -1) {
                    break;
                }

                result = readInt("Enter the position (starting from 1): ",
                                 &position);
                if (result == 0) {
                    goto exit_program;
                }
                if (result == 1) {
                    insertAtPosition(&head, data, position);
                }
                break;

            case 4:
                deleteBeginning(&head);
                break;

            case 5:
                deleteEnd(&head);
                break;

            case 6:
                result = readInt("Enter the position to delete: ", &position);
                if (result == 0) {
                    goto exit_program;
                }
                if (result == 1) {
                    deleteAtPosition(&head, position);
                }
                break;

            case 7:
                displayList(head);
                break;

            case 8:
                result = readInt("Enter the value to search: ", &data);
                if (result == 0) {
                    goto exit_program;
                }
                if (result == 1) {
                    searchElement(head, data);
                }
                break;

            case 9:
                printf("Total number of nodes: %d\n", countNodes(head));
                break;

            case 10:
                reverseList(&head);
                break;

            case 11:
                sortList(head);
                break;

            case 12:
                result = readInt("Enter the value to delete: ", &data);
                if (result == 0) {
                    goto exit_program;
                }
                if (result == 1) {
                    deleteByValue(&head, data);
                }
                break;

            case 13:
                goto exit_program;

            default:
                printf("Invalid choice. Please select 1 to 13.\n");
        }
    }

exit_program:
    freeList(&head);
    printf("All allocated memory freed. Program terminated.\n");

    return 0;
}


#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int readInt(const char *prompt, int *value)
{
    int result;
    int ch;

    printf("%s", prompt);
    result = scanf("%d", value);

    if (result != 1)
    {
        if (result != EOF)
        {
            while ((ch = getchar()) != '\n' && ch != EOF)
            {
            }
        }

        return 0;
    }

    while ((ch = getchar()) != '\n' && ch != EOF)
    {
        if (ch != ' ' && ch != '\t' && ch != '\r')
        {
            while (ch != '\n' && ch != EOF)
            {
                ch = getchar();
            }

            return 0;
        }
    }

    return 1;
}

void displayArray(const int arr[], int n)
{
    if (n == 0)
    {
        printf("Array is empty.\n");
        return;
    }

    printf("Array elements: ");

    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    printf("\n");
}

void insertBeginning(int arr[], int *n)
{
    int value;

    if (*n == MAX)
    {
        printf("Array is full.\n");
        return;
    }

    if (!readInt("Enter value: ", &value))
    {
        printf("Invalid input.\n");
        return;
    }

    for (int i = *n; i > 0; i--)
    {
        arr[i] = arr[i - 1];
    }

    arr[0] = value;
    (*n)++;

    printf("Element inserted successfully.\n");
}

void insertEnd(int arr[], int *n)
{
    int value;

    if (*n == MAX)
    {
        printf("Array is full.\n");
        return;
    }

    if (!readInt("Enter value: ", &value))
    {
        printf("Invalid input.\n");
        return;
    }

    arr[*n] = value;
    (*n)++;

    printf("Element inserted successfully.\n");
}

void insertPosition(int arr[], int *n)
{
    int value;
    int position;

    if (*n == MAX)
    {
        printf("Array is full.\n");
        return;
    }

    if (!readInt("Enter position: ", &position))
    {
        printf("Invalid input.\n");
        return;
    }

    if (position < 1 || position > *n + 1)
    {
        printf("Invalid position.\n");
        return;
    }

    if (!readInt("Enter value: ", &value))
    {
        printf("Invalid input.\n");
        return;
    }

    for (int i = *n; i >= position; i--)
    {
        arr[i] = arr[i - 1];
    }

    arr[position - 1] = value;
    (*n)++;

    printf("Element inserted successfully.\n");
}

void deleteBeginning(int arr[], int *n)
{
    if (*n == 0)
    {
        printf("Array is empty.\n");
        return;
    }

    for (int i = 0; i < *n - 1; i++)
    {
        arr[i] = arr[i + 1];
    }

    (*n)--;

    printf("First element deleted successfully.\n");
}

void deleteEnd(int *n)
{
    if (*n == 0)
    {
        printf("Array is empty.\n");
        return;
    }

    (*n)--;

    printf("Last element deleted successfully.\n");
}

void deletePosition(int arr[], int *n)
{
    int position;

    if (*n == 0)
    {
        printf("Array is empty.\n");
        return;
    }

    if (!readInt("Enter position to delete: ", &position))
    {
        printf("Invalid input.\n");
        return;
    }

    if (position < 1 || position > *n)
    {
        printf("Invalid position.\n");
        return;
    }

    for (int i = position - 1; i < *n - 1; i++)
    {
        arr[i] = arr[i + 1];
    }

    (*n)--;

    printf("Element deleted successfully.\n");
}

void searchArray(const int arr[], int n)
{
    int value;
    int found = 0;

    if (n == 0)
    {
        printf("Array is empty.\n");
        return;
    }

    if (!readInt("Enter value to search: ", &value))
    {
        printf("Invalid input.\n");
        return;
    }

    for (int i = 0; i < n; i++)
    {
        if (arr[i] == value)
        {
            printf("Value found at position %d.\n", i + 1);
            found = 1;
        }
    }

    if (!found)
    {
        printf("Value not found.\n");
    }
}

void countElements(int n)
{
    printf("Number of elements: %d\n", n);
}

void reverseArray(int arr[], int n)
{
    int left = 0;
    int right = n - 1;
    int temp;

    while (left < right)
    {
        temp = arr[left];
        arr[left] = arr[right];
        arr[right] = temp;

        left++;
        right--;
    }

    printf("Array reversed successfully.\n");
}

void sortArray(int arr[], int n)
{
    int temp;

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    printf("Array sorted in ascending order.\n");
}

void deleteByValue(int arr[], int *n)
{
    int value;
    int position = -1;

    if (*n == 0)
    {
        printf("Array is empty.\n");
        return;
    }

    if (!readInt("Enter value to delete: ", &value))
    {
        printf("Invalid input.\n");
        return;
    }

    for (int i = 0; i < *n; i++)
    {
        if (arr[i] == value)
        {
            position = i;
            break;
        }
    }

    if (position == -1)
    {
        printf("Value not found.\n");
        return;
    }

    for (int i = position; i < *n - 1; i++)
    {
        arr[i] = arr[i + 1];
    }

    (*n)--;

    printf("First matching value deleted successfully.\n");
}

void findMinMax(const int arr[], int n)
{
    int min;
    int max;

    if (n == 0)
    {
        printf("Array is empty.\n");
        return;
    }

    min = arr[0];
    max = arr[0];

    for (int i = 1; i < n; i++)
    {
        if (arr[i] < min)
        {
            min = arr[i];
        }

        if (arr[i] > max)
        {
            max = arr[i];
        }
    }

    printf("Minimum value: %d\n", min);
    printf("Maximum value: %d\n", max);
}

void rotateLeft(int arr[], int n)
{
    int first;

    if (n < 2)
    {
        printf("At least two elements are required.\n");
        return;
    }

    first = arr[0];

    for (int i = 0; i < n - 1; i++)
    {
        arr[i] = arr[i + 1];
    }

    arr[n - 1] = first;

    printf("Array rotated left by one position.\n");
}

void rotateRight(int arr[], int n)
{
    int last;

    if (n < 2)
    {
        printf("At least two elements are required.\n");
        return;
    }

    last = arr[n - 1];

    for (int i = n - 1; i > 0; i--)
    {
        arr[i] = arr[i - 1];
    }

    arr[0] = last;

    printf("Array rotated right by one position.\n");
}

void mergeArray(int arr[], int *n)
{
    int count;
    int value;

    if (*n == MAX)
    {
        printf("Array is full.\n");
        return;
    }

    if (!readInt("Enter number of elements to append: ", &count))
    {
        printf("Invalid input.\n");
        return;
    }

    if (count < 1 || count > MAX - *n)
    {
        printf("Invalid count. Available space: %d\n", MAX - *n);
        return;
    }

    for (int i = 0; i < count; i++)
    {
        if (!readInt("Enter element: ", &value))
        {
            printf("Invalid input. Merging stopped.\n");
            return;
        }

        arr[*n] = value;
        (*n)++;
    }

    printf("Elements appended successfully.\n");
}

void showMenu(void)
{
    printf("\n========== ARRAY OPERATIONS ==========\n");
    printf("1.  Insert at beginning\n");
    printf("2.  Insert at end\n");
    printf("3.  Insert at position\n");
    printf("4.  Delete from beginning\n");
    printf("5.  Delete from end\n");
    printf("6.  Delete from position\n");
    printf("7.  Display array\n");
    printf("8.  Search element\n");
    printf("9.  Count elements\n");
    printf("10. Reverse array\n");
    printf("11. Sort array ascending\n");
    printf("12. Delete by value\n");
    printf("13. Find minimum and maximum\n");
    printf("14. Rotate left\n");
    printf("15. Rotate right\n");
    printf("16. Append elements\n");
    printf("17. Exit\n");
    printf("======================================\n");
}

int main(void)
{
    int arr[MAX];
    int n = 0;
    int choice;

    while (1)
    {
        showMenu();

        if (!readInt("Enter your choice: ", &choice))
        {
            printf("Invalid input or end of input.\n");
            continue;
        }

        switch (choice)
        {
            case 1:
                insertBeginning(arr, &n);
                break;

            case 2:
                insertEnd(arr, &n);
                break;

            case 3:
                insertPosition(arr, &n);
                break;

            case 4:
                deleteBeginning(arr, &n);
                break;

            case 5:
                deleteEnd(&n);
                break;

            case 6:
                deletePosition(arr, &n);
                break;

            case 7:
                displayArray(arr, n);
                break;

            case 8:
                searchArray(arr, n);
                break;

            case 9:
                countElements(n);
                break;

            case 10:
                reverseArray(arr, n);
                break;

            case 11:
                sortArray(arr, n);
                break;

            case 12:
                deleteByValue(arr, &n);
                break;

            case 13:
                findMinMax(arr, n);
                break;

            case 14:
                rotateLeft(arr, n);
                break;

            case 15:
                rotateRight(arr, n);
                break;

            case 16:
                mergeArray(arr, &n);
                break;

            case 17:
                printf("Program terminated.\n");
                return 0;

            default:
                printf("Invalid choice. Select 1 to 17.\n");
        }
    }
}

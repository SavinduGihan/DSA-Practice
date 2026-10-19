
def display(arr):
    if not arr:
        print("Array is empty.")
    else:
        print("Array:", arr)


def insert(arr):
    value = int(input("Enter value: "))
    index = int(input("Enter index: "))

    if index < 0 or index > len(arr):
        print("Invalid index.")
        return

    arr.insert(index, value)
    print("Value inserted successfully.")


def delete(arr):
    if not arr:
        print("Array is empty.")
        return

    index = int(input("Enter index to delete: "))

    if index < 0 or index >= len(arr):
        print("Invalid index.")
        return

    removed = arr.pop(index)
    print("Deleted value:", removed)


def search(arr):
    value = int(input("Enter value to search: "))

    for i in range(len(arr)):
        if arr[i] == value:
            print("Value found at index:", i)
            return

    print("Value not found.")


def update(arr):
    if not arr:
        print("Array is empty.")
        return

    index = int(input("Enter index to update: "))

    if index < 0 or index >= len(arr):
        print("Invalid index.")
        return

    value = int(input("Enter new value: "))
    arr[index] = value

    print("Value updated successfully.")


def main():
    arr = []

    while True:
        print("\n--- ARRAY OPERATIONS ---")
        print("1. Display")
        print("2. Insert")
        print("3. Delete")
        print("4. Search")
        print("5. Update")
        print("6. Exit")

        choice = input("Enter your choice: ")

        if choice == "1":
            display(arr)
        elif choice == "2":
            insert(arr)
        elif choice == "3":
            delete(arr)
        elif choice == "4":
            search(arr)
        elif choice == "5":
            update(arr)
        elif choice == "6":
            print("Program terminated.")
            break
        else:
            print("Invalid choice.")


if __name__ == "__main__":
    main()

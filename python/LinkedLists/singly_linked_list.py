
class Node:
    def __init__(self, data):
        self.data = data
        self.next = None


class SinglyLinkedList:
    def __init__(self):
        self.head = None

    def insert_front(self, data):
        new_node = Node(data)
        new_node.next = self.head
        self.head = new_node
        print("Node inserted at the beginning.")

    def insert_end(self, data):
        new_node = Node(data)

        if self.head is None:
            self.head = new_node
            print("Node inserted at the end.")
            return

        current = self.head

        while current.next is not None:
            current = current.next

        current.next = new_node
        print("Node inserted at the end.")

    def delete(self, data):
        if self.head is None:
            print("List is empty.")
            return

        if self.head.data == data:
            self.head = self.head.next
            print("Node deleted successfully.")
            return

        current = self.head

        while current.next is not None:
            if current.next.data == data:
                current.next = current.next.next
                print("Node deleted successfully.")
                return

            current = current.next

        print("Value not found.")

    def search(self, data):
        current = self.head
        position = 0

        while current is not None:
            if current.data == data:
                print(f"Value found at position {position}.")
                return

            current = current.next
            position += 1

        print("Value not found.")

    def display(self):
        if self.head is None:
            print("List is empty.")
            return

        current = self.head
        print("HEAD", end=" -> ")

        while current is not None:
            print(current.data, end=" -> ")
            current = current.next

        print("NULL")


def main():
    linked_list = SinglyLinkedList()

    while True:
        print("\n--- SINGLY LINKED LIST ---")
        print("1. Insert at beginning")
        print("2. Insert at end")
        print("3. Delete a value")
        print("4. Search for a value")
        print("5. Display list")
        print("6. Exit")

        choice = input("Enter your choice: ")

        if choice == "1":
            data = int(input("Enter value: "))
            linked_list.insert_front(data)

        elif choice == "2":
            data = int(input("Enter value: "))
            linked_list.insert_end(data)

        elif choice == "3":
            data = int(input("Enter value to delete: "))
            linked_list.delete(data)

        elif choice == "4":
            data = int(input("Enter value to search: "))
            linked_list.search(data)

        elif choice == "5":
            linked_list.display()

        elif choice == "6":
            print("Program terminated.")
            break

        else:
            print("Invalid choice. Try again.")


if __name__ == "__main__":
    main()

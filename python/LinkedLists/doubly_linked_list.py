
class Node:
    def __init__(self, data):
        self.data = data
        self.prev = None
        self.next = None


class DoublyLinkedList:
    def __init__(self):
        self.head = None
        self.tail = None

    def insert_front(self, data):
        new_node = Node(data)

        if self.head is None:
            self.head = new_node
            self.tail = new_node
        else:
            new_node.next = self.head
            self.head.prev = new_node
            self.head = new_node

        print("Node inserted at the beginning.")

    def insert_end(self, data):
        new_node = Node(data)

        if self.tail is None:
            self.head = new_node
            self.tail = new_node
        else:
            new_node.prev = self.tail
            self.tail.next = new_node
            self.tail = new_node

        print("Node inserted at the end.")

    def delete(self, data):
        current = self.head

        while current is not None:
            if current.data == data:
                if current.prev is not None:
                    current.prev.next = current.next
                else:
                    self.head = current.next

                if current.next is not None:
                    current.next.prev = current.prev
                else:
                    self.tail = current.prev

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

    def display_forward(self):
        if self.head is None:
            print("List is empty.")
            return

        current = self.head
        print("NULL", end=" <-> ")

        while current is not None:
            print(current.data, end=" <-> ")
            current = current.next

        print("NULL")

    def display_backward(self):
        if self.tail is None:
            print("List is empty.")
            return

        current = self.tail
        print("NULL", end=" <-> ")

        while current is not None:
            print(current.data, end=" <-> ")
            current = current.prev

        print("NULL")


def main():
    linked_list = DoublyLinkedList()

    while True:
        print("\n--- DOUBLY LINKED LIST ---")
        print("1. Insert at beginning")
        print("2. Insert at end")
        print("3. Delete a value")
        print("4. Search for a value")
        print("5. Display forward")
        print("6. Display backward")
        print("7. Exit")

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
            linked_list.display_forward()

        elif choice == "6":
            linked_list.display_backward()

        elif choice == "7":
            print("Program terminated.")
            break

        else:
            print("Invalid choice. Try again.")


if __name__ == "__main__":
    main()

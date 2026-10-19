
def insertion_sort(arr):
    for i in range(1, len(arr)):
        key = arr[i]
        j = i - 1

        while j >= 0 and arr[j] > key:
            arr[j + 1] = arr[j]
            j -= 1

        arr[j + 1] = key

    return arr


def main():
    arr = list(map(int, input("Enter numbers separated by spaces: ").split()))

    print("Original array:", arr)
    insertion_sort(arr)
    print("Sorted array:  ", arr)


if __name__ == "__main__":
    main()

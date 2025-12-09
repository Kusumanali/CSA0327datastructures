#include <iostream>
using namespace std;

#define MAX 100

// Function to display array elements
void display(int arr[], int n) {
    if (n == 0) {
        cout << "Array is empty.\n";
        return;
    }
    cout << "Array elements: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

// Function to insert element at a position
void insertElement(int arr[], int &n, int pos, int value) {
    if (n == MAX) {
        cout << "Array Overflow! Cannot insert.\n";
        return;
    }
    if (pos < 0 || pos > n) {
        cout << "Invalid Position!\n";
        return;
    }

    // Shift elements to the right
    for (int i = n; i > pos; i--) {
        arr[i] = arr[i - 1];
    }

    arr[pos] = value;
    n++;
    cout << "Inserted " << value << " at position " << pos << endl;
}

// Function to delete element from a position
void deleteElement(int arr[], int &n, int pos) {
    if (n == 0) {
        cout << "Array Underflow! Cannot delete.\n";
        return;
    }
    if (pos < 0 || pos >= n) {
        cout << "Invalid Position!\n";
        return;
    }

    cout << "Deleted " << arr[pos] << " from position " << pos << endl;

    // Shift elements to the left
    for (int i = pos; i < n - 1; i++) {
        arr[i] = arr[i + 1];
    }

    n--;
}

int main() {
    int arr[MAX], n, choice, pos, value;

    cout << "Enter number of elements: ";
    cin >> n;

    cout << "Enter array elements: ";
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    while (true) {
        cout << "\n--- Array Operations Menu ---\n";
        cout << "1. Insert\n2. Delete\n3. Display\n4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter position to insert (0 to " << n << "): ";
                cin >> pos;
                cout << "Enter value: ";
                cin >> value;
                insertElement(arr, n, pos, value);
                break;

            case 2:
                cout << "Enter position to delete (0 to " << n-1 << "): ";
                cin >> pos;
                deleteElement(arr, n, pos);
                break;

            case 3:
                display(arr, n);
                break;

            case 4:
                cout << "Exiting...\n";
                return 0;

            default:
                cout << "Invalid choice!\n";
        }
    }
}

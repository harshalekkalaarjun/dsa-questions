#include <stdio.h>
#include <stdlib.h>

// Node structure: contains data and a pointer to the next node
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node with given data
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Insert a node at the beginning of the list
void insertAtBeginning(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    newNode->next = *head;
    *head = newNode;
}

// Insert a node at the end of the list
void insertAtEnd(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    struct Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

// Insert a node at a specific index (0-based)
void insertAtIndex(struct Node** head, int index, int data) {
    if (index == 0) {
        insertAtBeginning(head, data);
        return;
    }
    struct Node* temp = *head;
    int count = 0;
    while (temp != NULL && count < index - 1) {
        temp = temp->next;
        count++;
    }
    if (temp == NULL) {
        printf("Index %d out of bounds. Cannot insert.\n", index);
        return;
    }
    struct Node* newNode = createNode(data);
    newNode->next = temp->next;
    temp->next = newNode;
}

// Delete the first node with a given value
void deleteNode(struct Node** head, int key) {
    struct Node* temp = *head;
    struct Node* prev = NULL;
    while (temp != NULL && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL) return; // Key not found
    if (prev == NULL) {
        *head = temp->next; // Delete head
    } else {
        prev->next = temp->next;
    }
    free(temp);
}

// Delete a node at a specific index (0-based)
void deleteAtIndex(struct Node** head, int index) {
    if (*head == NULL) {
        printf("List is empty. Cannot delete.\n");
        return;
    }
    struct Node* temp = *head;
    if (index == 0) {
        *head = temp->next;
        free(temp);
        return;
    }
    int count = 0;
    struct Node* prev = NULL;
    while (temp != NULL && count < index) {
        prev = temp;
        temp = temp->next;
        count++;
    }
    if (temp == NULL) {
        printf("Index %d out of bounds. Cannot delete.\n", index);
        return;
    }
    prev->next = temp->next;
    free(temp);
}

// Get value at a specific index (0-based)
int getValueAtIndex(struct Node* head, int index) {
    int count = 0;
    struct Node* temp = head;
    while (temp != NULL) {
        if (count == index)
            return temp->data;
        temp = temp->next;
        count++;
    }
    // Index out of bounds
    printf("Index %d out of bounds.\n", index);
    return -1;
}

// Find index of a specific value (returns -1 if not found)
int getIndexOfValue(struct Node* head, int value) {
    int index = 0;
    struct Node* temp = head;
    while (temp != NULL) {
        if (temp->data == value)
            return index;
        temp = temp->next;
        index++;
    }
    // Value not found
    return -1;
}

// Traverse and print the linked list
void printList(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Free all nodes in the list
void freeList(struct Node* head) {
    while (head != NULL) {
        struct Node* temp = head;
        head = head->next;
        free(temp);
    }
}

// Main function with user menu
int main() {
    struct Node* head = NULL;
    int choice, value, index;

    while (1) {
        printf("\n--- Linked List Menu ---\n");
        printf("1. Insert at Beginning\n");
        printf("2. Insert at End\n");
        printf("3. Delete by Value\n");
        printf("4. Print List\n");
        printf("5. Exit\n");
        printf("6. Get Value at Index\n");
        printf("7. Get Index of Value\n");
        printf("8. Insert at Index\n");
        printf("9. Delete by Index\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert at beginning: ");
                scanf("%d", &value);
                insertAtBeginning(&head, value);
                break;
            case 2:
                printf("Enter value to insert at end: ");
                scanf("%d", &value);
                insertAtEnd(&head, value);
                break;
            case 3:
                printf("Enter value to delete: ");
                scanf("%d", &value);
                deleteNode(&head, value);
                break;
            case 4:
                printf("Linked List: ");
                printList(head);
                break;
            case 5:
                freeList(head);
                printf("Exiting...\n");
                return 0;
            case 6:
                printf("Enter index to get value: ");
                scanf("%d", &value);
                {
                    int result = getValueAtIndex(head, value);
                    if (result != -1) {
                        printf("Value at index %d: %d\n", value, result);
                    }
                }
                break;
            case 7:
                printf("Enter value to find index: ");
                scanf("%d", &value);
                {
                    int idx = getIndexOfValue(head, value);
                    if (idx != -1) {
                        printf("Index of value %d: %d\n", value, idx);
                    } else {
                        printf("Value %d not found in the list.\n", value);
                    }
                }
                break;
            case 8:
                printf("Enter index to insert at: ");
                scanf("%d", &index);
                printf("Enter value to insert: ");
                scanf("%d", &value);
                insertAtIndex(&head, index, value);
                break;
            case 9:
                printf("Enter index to delete: ");
                scanf("%d", &index);
                deleteAtIndex(&head, index);
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
}
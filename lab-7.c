#include<stdio.h>
#include<stdlib.h>

struct Node {
    int val;
    struct Node* prev;
    struct Node* next;
};

typedef struct Node* NODE;

NODE getNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->val = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

NODE insert_end(NODE head, int val) {
    NODE newNode = getNode(val);
    NODE current = head;
    if (head == NULL) {
        return newNode;
    }
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = newNode;
    newNode->prev = current;
    return head;
}

NODE insert_left(NODE head, int val, int key) {
    NODE newNode = getNode(val);
    NODE current = head;
    if (head == NULL) {
        return newNode;
    }
    while (current != NULL && current->val != key) {
        current = current->next;
    }
    if (current != NULL && current->val == key) {
        current->prev->next=newNode;
        newNode->prev=current->prev;
        newNode->next=current;
        current->prev=newNode;
        return head;
    } else {
        printf("Value not found\n");
        return head;
    }
}

NODE delete_val(NODE head, int key) {
    NODE current = head;
    if (head == NULL) {
        printf("Empty Linked List\n");
        return NULL;
    }
    while (current != NULL && current->val != key) {
        current = current->next;
    }
    if (current != NULL && current->val == key) {
        if (current->prev != NULL) {
            current->prev->next = current->next;
        } else {
            head = current->next;
        }
        if (current->next != NULL) {
            current->next->prev = current->prev;
        }
        free(current);
        return head;
    } else {
        printf("Value not found\n");
        return head;
    }
}

void display(NODE head) {
    printf("NULL <-");
    NODE current = head;
    if (current == NULL) {
        printf("Empty Linked List\n");
        return;
    }
    while (current != NULL) {
        printf("%d", current->val);
        if (current->next != NULL) {
            printf(" <-> ");
        }
        else{
            printf(" ->NULL");
        }
        current = current->next;
    }
    printf("\n");
}

int main() {
    NODE head = NULL;
    int val, key, choice;
    printf("\nMenu:\n");
    printf("1. Insert at End\n");
    printf("2. Insert at left\n");
    printf("3. Delete value\n");
    printf("4. Display\n");
    printf("5. Exit\n");

    while (1) {
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to insert at end: ");
                scanf("%d", &val);
                head = insert_end(head, val);
                break;
            case 2:
                printf("Enter key and value: ");
                scanf("%d %d", &key, &val);
                head = insert_left(head, val, key);
                break;
            case 3:
                printf("Enter key: ");
                scanf("%d", &key);
                head = delete_val(head, key);
                break;
            case 4:
                display(head);
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}

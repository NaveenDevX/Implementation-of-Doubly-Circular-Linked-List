#include <stdio.h>
#include <stdlib.h>

struct node {
    struct node *prev;
    int data;
    struct node *next;
};

struct node *start = NULL;

struct node *create_linked_list(struct node *);
struct node *display(struct node *);
struct node *insert_beg(struct node *);
struct node *insert_end(struct node *);
struct node *delete_beg(struct node *);
struct node *delete_end(struct node *);
struct node *delete_node(struct node *, int);
struct node *delete_list(struct node *);

int main() {
    int option, value;
    do {
        printf("\n\nMain Menu");
        printf("\n1: Create");
        printf("\n2: Display");
        printf("\n3: Add at Beginning");
        printf("\n4: Add at End");
        printf("\n5: Delete from Beginning");
        printf("\n6: Delete from End");
        printf("\n7: Delete Specific Node");
        printf("\n8: Delete Entire List");
        printf("\n9: Exit");
        printf("\nEnter option: ");
        scanf("%d", &option);
        
        switch (option) {
            case 1:
                start = create_linked_list(start);
                break;
            case 2:
                start = display(start);
                break;
            case 3:
                start = insert_beg(start);
                break;
            case 4:
                start = insert_end(start);
                break;
            case 5:
                start = delete_beg(start);
                break;
            case 6:
                start = delete_end(start);
                break;
            case 7:
                printf("Enter value to delete: ");
                scanf("%d", &value);
                start = delete_node(start, value);
                break;
            case 8:
                start = delete_list(start);
                break;
        }
    } while (option != 9);

    return 0;
}

struct node *create_linked_list(struct node *start) {
    struct node *new_node, *ptr;
    int num;
    printf("Enter data (-1 to stop): ");
    scanf("%d", &num);
    
    while (num != -1) {
        new_node = (struct node *)malloc(sizeof(struct node));
        new_node->data = num;
        if (start == NULL) {
            start = new_node;
            new_node->prev = new_node;
            new_node->next = new_node;
        } else {
            ptr = start;
            while (ptr->next != start)
                ptr = ptr->next;
            ptr->next = new_node;
            new_node->prev = ptr;
            new_node->next = start;
            start->prev = new_node;
        }
        printf("Enter data (-1 to stop): ");
        scanf("%d", &num);
    }
    return start;
}

struct node *display(struct node *start) {
    struct node *ptr;
    if (start == NULL) {
        printf("\nList is empty.");
        return start;
    }
    ptr = start;
    printf("\nList: ");
    do {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    } while (ptr != start);
    return start;
}

struct node *insert_beg(struct node *start) {
    struct node *new_node, *ptr;
    int num;
    printf("\nEnter data: ");
    scanf("%d", &num);
    
    new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = num;
    if (start == NULL) {
        new_node->prev = new_node;
        new_node->next = new_node;
        start = new_node;
    } else {
        ptr = start;
        while (ptr->next != start)
            ptr = ptr->next;
        new_node->next = start;
        new_node->prev = ptr;
        ptr->next = new_node;
        start->prev = new_node;
        start = new_node;
    }
    return start;
}

struct node *insert_end(struct node *start) {
    struct node *new_node, *ptr;
    int num;
    printf("\nEnter data: ");
    scanf("%d", &num);
    
    new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = num;
    if (start == NULL) {
        new_node->prev = new_node;
        new_node->next = new_node;
        start = new_node;
    } else {
        ptr = start;
        while (ptr->next != start)
            ptr = ptr->next;
        ptr->next = new_node;
        new_node->prev = ptr;
        new_node->next = start;
        start->prev = new_node;
    }
    return start;
}

struct node *delete_beg(struct node *start) {
    struct node *ptr;
    if (start == NULL) {
        printf("\nList is empty.");
        return start;
    }
    if (start->next == start) {
        free(start);
        return NULL;
    }
    
    ptr = start;
    while (ptr->next != start)
        ptr = ptr->next;
    ptr->next = start->next;
    start->next->prev = ptr;
    struct node *temp = start;
    start = start->next;
    free(temp);
    return start;
}

struct node *delete_end(struct node *start) {
    struct node *ptr;
    if (start == NULL) {
        printf("\nList is empty.");
        return start;
    }
    if (start->next == start) {
        free(start);
        return NULL;
    }
    
    ptr = start;
    while (ptr->next->next != start)
        ptr = ptr->next;
    struct node *temp = ptr->next;
    ptr->next = start;
    start->prev = ptr;
    free(temp);
    return start;
}

struct node *delete_node(struct node *start, int value) {
    struct node *ptr = start, *temp;
    if (start == NULL) {
        printf("\nList is empty.");
        return start;
    }
    do {
        if (ptr->data == value) {
            if (ptr == start)
                return delete_beg(start);
            ptr->prev->next = ptr->next;
            ptr->next->prev = ptr->prev;
            free(ptr);
            return start;
        }
        ptr = ptr->next;
    } while (ptr != start);
    
    printf("\nValue not found.");
    return start;
}

struct node *delete_list(struct node *start) {
    struct node *ptr = start, *temp;
    if (start == NULL) {
        printf("\nList is empty.");
        return start;
    }
    while (start->next != start) {
        temp = start;
        start = start->next;
        free(temp);
    }
    free(start);
    return NULL;
}


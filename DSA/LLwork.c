#include <stdio.h>
#include <stdlib.h>

// Node ka structure
struct node {
    int data;
    struct node *add;
};

// Global pointers
struct node *start, *temp, *new1;
struct node *dot;         // for display
struct node *prev, *next; // for insert middle & delete last
struct node *temp1;       // for delete last (not used here but reserved)

// 🔧 Creation
void create() {
    int n;
    char ch;
    printf("Enter Element: ");
    scanf("%d", &n);

    start = (struct node *)malloc(sizeof(struct node));
    start->data = n;
    start->add = NULL;
    temp = start;

    printf("Want to add more? (y/n): ");
    ch = getchar(); // to clear buffer
    ch = getchar();

    while (ch == 'y' || ch == 'Y') {
        printf("\nEnter Element: ");
        scanf("%d", &n);

        new1 = (struct node *)malloc(sizeof(struct node));
        new1->data = n;
        new1->add = NULL;

        temp->add = new1;
    
        temp = temp->add;

        printf("Want to add more? (y/n): ");
        ch = getchar();
        ch = getchar();
    }
}

// 🔍 Display
void display() {
    dot = start;
    printf("\nLinked List: ");
    while (dot != NULL) {
        printf("%d -> ", dot->data);
        dot = dot->add;
    }
    printf("NULL\n");
}

// ➕ Insert at First
void insertFst() {
    int n;
    if (start == NULL) {
        printf("LIST EMPTY\n");
    } else {
        printf("\nEnter element to insert at first: ");
        scanf("%d", &n);

        new1 = (struct node *)malloc(sizeof(struct node));
        new1->data = n;
        new1->add = start;

        start = new1;
    }
}

// ➕ Insert at Last
void insertLst() {
    int n;
    if (start == NULL) {
        printf("LIST EMPTY\n");
    } else {
        printf("\nEnter element to insert at last: ");
        scanf("%d", &n);

        new1 = (struct node *)malloc(sizeof(struct node));
        new1->data = n;
        new1->add = NULL;

        temp = start;
        while (temp->add != NULL) {
            temp = temp->add;
        }
        temp->add = new1;
    }
}

// ➕ Insert at Middle
void insertMdl() {
    int n, pos, i;
    if (start == NULL) {
        printf("LIST EMPTY\n");
    } else {
        printf("Enter element to insert in the middle: ");
        scanf("%d", &n);

        printf("Enter position (starting from 1): ");
        scanf("%d", &pos);

        new1 = (struct node *)malloc(sizeof(struct node));
        new1->data = n;
        new1->add = NULL;

        next = start;

        for (i = 1; i < pos; i++) {
            prev = next;
            next = next->add;
            if (next == NULL) break;
        }

        prev->add = new1;
        new1->add = next;
    }
}

// ❌ Delete from First
void dltFst() {
    if (start == NULL) {
        printf("LIST EMPTY\n");
    } else {
        temp = start;
        start = start->add;
        free(temp);
        printf("\nFIRST ELEMENT DELETED\n");
    }
}

// ❌ Delete from Last
void dltLst() {
    if (start == NULL) {
        printf("LIST EMPTY\n");
    } else {
        temp = start;
        while (temp->add != NULL) {
            prev = temp;
            temp = temp->add;
        }
        free(temp);
        prev->add = NULL;
        printf("\nLAST ELEMENT DELETED\n");
    }
}

// ❌ Delete from Middle
void dltMdl() {
    int pos;
    if (start == NULL) {
        printf("LIST EMPTY\n");
    } else {
        printf("\nEnter position to delete from middle: ");
        scanf("%d", &pos);

        temp = start;
        for (int i = 1; i < pos; i++) {
            prev = temp;
            temp = temp->add;
            if (temp == NULL) break;
        }

        if (temp != NULL) {
            next = temp->add;
            prev->add = next;
            free(temp);
            printf("\nMIDDLE ELEMENT DELETED\n");
        } else {
            printf("\nINVALID POSITION\n");
        }
    }
}

// 🔍 Search an element
void search() {
    int src, found = 0;
    temp = start;

    if (start == NULL) {
        printf("LIST EMPTY\n");
        return;
    }

    printf("\nEnter element to search: ");
    scanf("%d", &src);

    while (temp != NULL) {
        if (temp->data == src) {
            found = 1;
            break;
        }
        temp = temp->add;
    }

    if (found) {
        printf("DATA FOUND 😎\n");
    } else {
        printf("DATA NOT FOUND 😞\n");
    }
}

// 🚀 Main Function
int main() {
    create();
    insertFst();
    insertLst();
    insertMdl();
    dltFst();
    dltLst();
    dltMdl();
    search();
    display();

    return 0;
}

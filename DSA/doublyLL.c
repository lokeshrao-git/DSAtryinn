#include<stdio.h>
#include<stdlib.h>

int n;
char ch;

struct node{
    struct node* prev;
    int data;
    struct node* next;
};
struct node*start,*new1,*temp,*global,*global2;


void creation(){
printf("\nENTER DATA FOR FIRST\t");
scanf("%d",&n);

start=(struct node*)malloc(sizeof(struct node));
start->prev=NULL;
start->data=n;
start->next=NULL;

temp=start;
global=start;

printf("\nWANT NEXT?\t");
ch=getche();
while(ch=='y'){
printf("\nENTER DATA \t");
scanf("%d",&n);

new1=(struct node*)malloc(sizeof(struct node));
new1->prev=NULL;
new1->data=n;
new1->next=NULL;

temp->next=new1;
temp=temp->next;
temp->prev=global;
global=global->next;

printf("\nWANT NEXT?\t");
ch=getche();
}
};

void display(){
    temp=start;
    while(temp!=NULL){
        printf("%d->",temp->data);
        temp=temp->next;
    }
};

void dltFst(){
    temp=start;
    global=start;
    temp=temp->next;
    temp->prev=NULL;
    start=temp;
    printf("\n%d is deleating\n",global->data);
    free(global);
};
void dltLst(){
    temp=start;
    while(temp->next!=NULL){
        global=temp;
        temp=temp->next;
    }
    global->next=NULL;
    printf("\n%d is deleating\n",temp->data);
    free(temp);
};

void dltMdl() {
    int i, pos;

    printf("\nEnter position\t");
    scanf("%d", &pos);

    temp = start;
    for (i = 1; i < pos; i++) {
        global = temp;
        temp = temp->next;
    }

    // If position is invalid
    if (temp == NULL) {
        printf("\nInvalid position!\n");
        return;
    }

    global2 = temp->next;

    // Handling links
    if (global != NULL)
        global->next = global2;

    if (global2 != NULL)
        global2->prev = global;

    // If first node is deleted
    if (temp == start)
        start = global2;

    printf("\n%d is deleting\n", temp->data);
    free(temp);
}


// void dltMdl(){//to fix this
//     int i;
//     int pos;
//     printf("\nenter position\t");
//     scanf("%d",&pos);

//     for(i=1;i<pos;i++){
//         temp=temp->next;
//     }
//     global=temp->prev;
//     global2=temp->next;

//     printf("\n%d is deleating\n",temp->data);
//     free(temp);
// };

int main(){
    creation();
    display();
    dltMdl();
    display();
    printf("\nCODE SPRINTED\n");
}
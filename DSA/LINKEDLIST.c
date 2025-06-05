#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node*add;
};

struct node *start,*temp,*new1; //for creation and insertion
struct node *dot;//for displaying it is used
struct node *prev,*next;//for insertion at middle and deletion at last
struct node *temp1;//for deletion at last


// creation
void create(){
    int n;
    char ch;
    printf("Enter Element\t");
    scanf("%d",&n);

    start=(struct node*) malloc(sizeof(struct node));

    start->data=n;
    start->add=NULL;

    temp=start;

    printf("WANT NEXT?\t");
    ch=getche();

    while(ch=='y'){
    printf("\nEnter Element\t");
    scanf("%d",&n);

    new1=(struct node*)malloc(sizeof(struct node));
    new1->data=n;
    new1->add=NULL;

    temp->add=new1;
    temp=temp->add;
    printf("WaNt AGAIN?\t");
    ch=getche();
    }
};

void display(){
    dot=start;
    printf("\n");
    while(dot!=NULL){
        printf("%d->",dot->data);
        dot=dot->add;
    }
};

void insertFst(){
    int n;
    if(start==NULL){
        printf("LIST EMPTY\n");
    }
    else{
        printf("\nenter new element for insert at first\n");
        scanf("%d",&n);
        new1=(struct node*) malloc(sizeof(struct node));
        new1->data=n;
        // new1->add=NULL;
        new1->add=start;

        start=new1;
    }
};

void insertLst(){
    int n;
    if(start==NULL){
        printf("LIST EMPTY\n");
    }
    else{
        printf("\nEnter Element To Insert At Last\t");
        scanf("%d",&n);

        new1=(struct node*)malloc(sizeof(struct node));
        new1->data=n;
        new1->add=NULL;


        temp=start;
        while(temp->add!=NULL){
            temp=temp->add;
        }
        temp->add=new1;
    }
};

void insertMdl(){
    int n,pos;

    if(start==NULL){
        printf("LIST EMPTY\n");
    }
    else{
        printf("ENTER ELEMENT TO INSERT AT MIDDLE\n");
        scanf("%d",&n);

        new1=(struct node*)malloc(sizeof(struct node));
        new1->data=n;
        new1->add=NULL;

        printf("\nenter position\t");
        scanf("%d",&pos);

        next=start;
        for(int i=1;i<=pos;i++){
            prev=next;
            next=next->add;
        }

        prev->add=new1;
        new1->add=next;
    }
};

void dltFst(){
    if(start==NULL){
        printf("EMPTY LIST\n");
    }
    else{
        temp=start;
        start=start->add;
        free(temp);
        printf("DATA DELEATED\n");
    }
};

void dltLst(){
    if(start==NULL){
        printf("EMPTY LIST\n");
    }
    else{
        temp=start;
        while(temp->add!=NULL){
            prev=temp;
            temp=temp->add;
        }
        free(temp);
        prev->add=NULL;
        printf("\nLAST ELEMENT DELEATED");
    }
};

void dltMdl(){
    int pos;
    if(start==NULL){
        printf("EMPTY LIST\n");
    }
    else{
        temp=start;
        printf("\nENTER POSITION\t");
        scanf("%d",&pos);

        for(int i=1;i<pos;i++){
            prev=temp;
            temp=temp->add;
        }

        next=temp->add;
        prev->add=next;
        free(temp);
        printf("\nMIDDLE ELEMENT DELETED");
    }

}



int main(){
    create();
    // display();
    insertFst();
    // display();
    insertLst();
    // display();
    insertMdl();
    // display();
    dltFst();
    // display();
    dltLst();
    // display();
    dltMdl();
    display();


return 0;
}






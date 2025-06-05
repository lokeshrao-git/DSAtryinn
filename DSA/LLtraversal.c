void creation() {
    int n;
    char ch;

    printf("\nENTER DATA\t");
    scanf("%d", &n);

    start = (struct node*)malloc(sizeof(struct node));
    start->data = n;
    start->add = start;  // 👈 important for circular start

    temp = start;

    printf("\nWANT TO ENTER NEXT ELEMENT (y/n)?\t");
    ch = getche();

    while (ch == 'y') {
        printf("\nENTER DATA\t");
        scanf("%d", &n);

        new1 = (struct node*)malloc(sizeof(struct node));
        new1->data = n;
        new1->add = start;  // 👈 point to start (circular)

        temp->add = new1;   // 👈 link new node
        temp = new1;        // 👈 move temp forward

        printf("\nWANT AGAIN (y/n)?\t");
        ch = getche();
    }
}

//double-linked list!!
# include <stdio.h>
# include <conio.h>
# include <stdlib.h>

struct node //NODE STRUCTURE!!
{
int data;
struct node *next;
struct node *prev;
};

typedef struct node NODE;
NODE *head= NULL; //HEAD==START!! we created a head pointer  with node dt and stored as NULL!!

NODE *createnode();
void createlist(int n);
void insbeg();
void display();
void insend();
void countu();
void delbeg();
void delend();
void insmid();
void delmid();
void revdisplay();

int main()
{
    int choice,data,n;
    printf("\n 1.Create a list ");
    printf("\n--------------------------");
    printf("\n 2.Insert a node at beginning ");
    printf("\n 3.Insert a node at end");
    printf("\n 4.Insert a node at middle");
    printf("\n--------------------------");
    printf("\n 5.Delete a node from beginning");
    printf("\n 6.Delete a node from Last");
    printf("\n 7.Delete a node from Middle");
    printf("\n-----------------------");
    printf("\n 8.Traverse the list (Left to Right)");
    printf("\n 9.Traverse the list (Right to left)");
    printf("\n--------------------------");
    printf("\n 10. Count nodes ");
    printf("\n 11. Exit ");

    //clrscr();
    while(1){
    printf("\n\n Enter your choice: ");                                                     //MENU!
    scanf("%d",&choice);
    switch(choice){
        case 1:
            printf("enter the number of nodes to be created:");
            scanf("%d",&n);
            createlist(n);
            printf("\nall the %d nodes have been created sucssesfully!\n",n);
            break;
        case 2:
            insbeg();
            break;
        case 3:
            insend();
            break;
        case 4:
            insmid();
            break;
        case 5:
            delbeg();
            break;
        case 6:
            delend();
            break;
        case 7:
            delmid();
            break;
        case 8:
            display();
            break;
        case 9:
            revdisplay();
            break;
        case 10:
            countu();
            break;
        case 11:
            exit(1);
        default:
            printf("enter a valid number!\ntry again bro!!");
            continue;

    }
        }
}
NODE *createnode(){
    NODE* newnode;
    newnode=(NODE*)malloc(sizeof(NODE));
    if (newnode == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    printf("enter the data for this node:");
    scanf("%d",&newnode->data);
    newnode->next=NULL;
    newnode->prev=NULL;
    return (newnode);
}
void createlist(int n){
    NODE* newnode;
    NODE* temp;
    int i=0;
    for(i=0;i<n;i++){
        newnode=createnode();
        if(head==NULL)
            head=newnode;
        else{
            temp=head;
            while(temp->next!=NULL)
                temp=temp->next;
            temp->next=newnode;
            newnode->prev=temp;
        }
    }
    display();
}
void display(){
    int count=1;
    NODE *temp;
    temp=head;
    if(head == NULL)
        printf("\n Empty List");
    else{
        while(temp!=NULL)
            {
            printf("\n%d is the data in the %d node!",temp->data,count);
            temp=temp->next;
            count++;
            }
        }
}
void revdisplay() {
    int count = 1;
    NODE *temp = head;

    if (head == NULL) {
        printf("\n Empty List");
        return;
    }

    while (temp->next != NULL) {
        temp = temp->next;
        count++;
    }

    while (temp != NULL) {
        printf("\n%d is the data in the %d node!", temp->data, count);
        temp = temp->prev;
        count--;
    }
}

void insbeg(){}
void insend(){}
void countu(){}
void delbeg(){}
void delend(){}
void insmid(){}
void delmid(){}

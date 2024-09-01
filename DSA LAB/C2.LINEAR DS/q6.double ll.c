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
    printf("\nTHE DOUBLE LL:");
    if(head == NULL)
        printf("\n Empty List");
    else{
        while(temp!=NULL)
            {
            printf("%d ",temp->data);
            temp=temp->next;
            count++;
            }
        }
}
void revdisplay(){
    int count=1;
    NODE *temp;
    temp=head;
    printf("\nTHE REVERSED ORDER OF DOUBLE LL:");
    if(head == NULL)
        printf("\n Empty List");
    else{
        while(temp->next!=NULL)
            {
            temp=temp->next;
            count++;
            }
            while(temp!=NULL)
            {
            printf("%d ",temp->data);
            temp=temp->prev;
            count--;
            }
        }
}void insbeg(){
    NODE* newnode;
    if(head==NULL)
        printf("list is empty.create a list!!");
    else
        {
            newnode=createnode();
            head->prev=newnode;
            newnode->next=head;
            head=newnode;
        }
    display();
        
}
void insend(){
    NODE* newnode;
    NODE* temp;
    newnode=createnode();
    temp=head;
    if(head==NULL)
        printf("list is empty.create a list!!");
    else
        {
            while(temp->next!=NULL)
                temp=temp->next;
            temp->next=newnode;
            newnode->prev=temp;
            //not mandatory ig!!!!
        }
    display();
        
}
void countu(){
    NODE *temp=head;
    int count=1;
    while(temp!=NULL){
        count++;
        temp=temp->next;
    }
    printf("no of nodes are:%d",count);
}
void delbeg(){
    //NODE* newnode;
    NODE *temp;
    temp=head;
    if(head==NULL)
        printf("list is empty.create a list!!");
    else
        {
            head=temp->next;
            head->prev=NULL;
            free(temp);
        }
    display();
}
void delend(){
     //NODE* newnode;
    NODE *temp,*temp1;
    //NODE *prev=NULL;
    temp=head;
    int count=1;
    if(head==NULL)
        printf("list is empty.create a list!!");
    else
        {
            while(temp->next!=NULL){
                temp=temp->next;
            }
            temp1=temp->prev;
            }
            temp1->next=NULL;
            free(temp);
        display();
    }
void insmid(){
    int pos,count=1;
    NODE* temp=head;
    printf("enter the pos where u are going to enter NEW NODE:");
    scanf("%d",&pos);
    while(count!=pos){
        count++;
        temp=temp->next;
    }
    NODE *newnode=createnode();
    newnode->next=temp;
    newnode->prev=temp->prev;
    temp->prev->next=newnode;
    temp->prev=newnode;
    display();
}
void delmid(){
    int pos,count=1;
    NODE* temp=head;
    printf("enter the pos pf NODE where u want to delete:");
    scanf("%d",&pos);
    while(count!=pos){
        count++;
        temp=temp->next;
    }
    //NODE *newnode=createnode();
    temp->prev->next=temp->next;
    temp->next->prev=temp->prev;
    free(temp);
    display();
}

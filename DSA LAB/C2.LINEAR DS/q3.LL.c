//linked list!!
# include <stdio.h>
# include <conio.h>
# include <stdlib.h>

struct node //NODE STRUCTURE!!
{
int data;
struct node *next;
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
NODE *createnode(){                         //CREATING NODE!!!
    NODE *newnode;
    newnode=(NODE*)malloc(sizeof(NODE));
    printf("enter the data for this node:");
    scanf("%d",&newnode->data);
    newnode->next=NULL;
    return (newnode);
}
void createlist(int n){                     //CREATING A LIST!!
    NODE *newnode;
    NODE *temp;                             //TEMP!!!
    int i=0;
    for(i=1;i<=n;i++)
    {
        newnode=createnode();               //each time a newnode is created!
        if(head==NULL)
            head=newnode;                   //if head is NULL asusual,then ll is empty!
        else
            {
                temp=head;                  //we don't want to change head,so using temp!
                while(temp->next!=NULL)
                    temp=temp->next;        //traversing next by next!!
                temp->next=newnode;         //creating a LINK!!
            }
    }
    display();
}

void insbeg(){
    NODE* newnode;
    if(head==NULL)
        printf("list is empty.create a list!!");
    else
        {
            newnode=createnode();
            newnode->next=head;
            head=newnode;
        }
    display();
        
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
            free(temp);
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
            newnode->next=NULL; //not mandatory ig!!!!
        }
    display();
        
}
void delend(){
     //NODE* newnode;
    NODE *temp;
    NODE *prev=NULL;
    temp=head;
    int count=1;
    if(head==NULL)
        printf("list is empty.create a list!!");
    else
        {
            while(temp->next!=NULL){
                prev=temp;
                temp=temp->next;
            }
            if (prev == NULL) {
            //This means there is only one node in the list
                free(temp);
                head = NULL;
            } 
            else {
                prev->next = NULL;
                free(temp);
            }
            }
            prev->next=NULL;
            free(temp);
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
void countu(){
    NODE *temp;
    int count=1;
    temp=head;
    if(head == NULL)
        printf("\n Empty List");
    else{
        while(temp->next!=NULL)
            {
            //printf("\n%d is the data in the %d node!",temp->data,count);
            temp=temp->next;
            count++;
            }
            printf("\n total no of nodes:%d",count);
        }
}
void insmid(){
    int count=1,pos;
    NODE *newnode;
    newnode=createnode();
    printf("enter the position at which the current node to be inserted:");
    scanf("%d",&pos);
    
    NODE *temp=NULL;
    temp=head;
    NODE *prev;
    while(1){
        if(count==pos && temp!=NULL)
            break;
        prev=temp;
        temp=temp->next;
        count++;
    }
    prev->next=newnode;
    newnode->next=temp;
    display();

}
// void delmid(){
//     int n,count=1,pos;
//     //newnode=createnode();
//     printf("enter the position at which the node to be deleted:");
//     scanf("%d",&pos);
    
//     NODE *temp=NULL;
//     temp=head;
//     NODE *prev;
//     while(1){
//         if(count<pos && temp!=NULL){
//             if(count==pos){
//                 temp=temp->next;
//                 break;
//             }
//             break;
//         }
            
//         prev=temp;
//         temp=temp->next;
        
//         count++;
//     }
//     prev->next=temp;
//     display();

// }
void delmid() {
    int pos;
    printf("enter the position at which the node is to be deleted:");
    scanf("%d", &pos);
    
    NODE *temp = head;
    NODE *prev = NULL;
    int count = 1;
    
    while (temp != NULL && count < pos) {
        prev = temp;
        temp = temp->next;
        count++;
    }
    
    if (temp == NULL) {
        printf("Position is out of range.\n");
    } else {
        if (prev == NULL) {
            // Deleting the first node
            head = temp->next;
        } else {
            prev->next = temp->next;
        }
        free(temp);
        display();
    }
}


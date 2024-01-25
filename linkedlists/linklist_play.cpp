#include <iostream>
#include <string>



class node
{
    public:
    int data;
    node* next;

    node(int val)
    {
        data=val;
        next=NULL;
    }
};

void insertatTail(node* &head, int val)
{
    node* n= new node(val);

    if(head==NULL){head=n;return;}

    node* temp=head;
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    temp->next=n;
    
}
void insertatHead(node* &head, int val)
{
    node* n= new node(val);
    n->next=head;
    head=n;


}

bool search(node* head,int key)
{
    node* temp=head;
    while(temp!=NULL)
    {
        if(temp->data==key)
        {
            return true;
        }
        temp=temp->next;
    }
    return false;
}

void display(node* head)
{

    node* temp=head;
    while(temp!=NULL)
    {
        std::cout << temp->data << "->";
        temp=temp->next;
    }

    std::cout << std::endl;
}

void deleteatHead(node* &head)
{
    node* todelete=head;
    head=head->next;
    delete todelete;
}

void deletion(node* head, int val)
{


    if (head==NULL)
    {
        return;
    }
    if(head->next==NULL)
    {
        deleteatHead(head);
        return;
    }

    node* temp=head;
    while(temp->next->data!=val)
    {
        temp=temp->next;
    }
    node* todelete= temp->next;
    temp->next=temp->next->next;
    delete todelete;

    
}


int main()
    {

        node* head= NULL;
        insertatTail(head,1);
        insertatTail(head,7);
        insertatHead(head,0);
        deletion(head,7);
        display(head);
        deleteatHead(head);
        return 0;
    }
/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
class
cout
[]
template
###End banned keyword*/

#include <iostream>

using namespace std;

struct node
{
    int data;
    struct node *link;
};

void _append(node **, int);

void _addatbeg(node **, int);

void _addafter(node *, int, int);

int _count(node *);

void _delete(node **, int);

//###INSERT CODE HERE -
node *CreateNode(int value)
{
    node *temp;
    temp = new node;
    temp->data = value;
    temp->link = NULL;
    return temp;
}
void _append(node **head, int value)
{
    node *temp,*p;
    temp = CreateNode(value);
    if (*head == NULL)
    {
        *head = temp;
    } else
    {
        p = *head;
        while (p->link != NULL)
        {
            p = p->link;
        }
        p->link = temp;
    }
}
void _addatbeg(node **head, int value)
{
    node* temp = CreateNode(value);
    if(*head == NULL)
    {
        *head = temp;
    } else
    {
        temp->link = *head;
        *head = temp;
    }
}
void _addafter(node *head, int position, int value)
{
    node *temp, *p;
    temp = CreateNode(value);
    if (head == NULL)
    {
        head = temp;
    } else
    {
        p = head;
        int i = 0;
        while (p->link != NULL && i<position)
        {
            i++;
            p = p->link;
        }
        if(i<position) 
            _addatbeg(&head, value);
        else
            temp->link = p->link;
            p->link = temp;
    }
}
int _count(node *head)
{
    int i = 0;
    if (head == NULL)
    {
        return i;
    } else
    {
        node *temp = head;
        while (temp != NULL)
        {
            i++;
            temp = temp->link;
        }
        return i;
        
    }
}
void _delete(node **head, int value)
{
    node *p = *head;
    if (p==NULL) return;
    if (p->data == value) *head = p->link;
    while ( p->link->link!=NULL)
    {
        if (p->link->data == value)
        {
            p->link = p->link->link;
        } else
            p = p->link;
    }
    if (p->link->data == value)
    {
        p->link = p->link->link;
    }
}
void _display(node *q)
{
    while(q != NULL)
    {
        cout << q->data << " ";
        q = q->link;
    }
    cout << endl;
}

int main()
{
    node *head;
    head = NULL;

    _append(&head, 1);
    _append(&head, 2);
    _append(&head, 3);
    _append(&head, 4);
    _append(&head, 17);
  

    _display(head);

    _addatbeg(&head, 999);
    _addatbeg(&head, 888);
    _addatbeg(&head, 777);

    _display(head);

    _addafter(head, 7, 0);
    _addafter(head, 2, 1);
    _addafter(head, 1, 99);
    _display(head);

    cout << "No. of element in the Linked List = " << _count(head) << endl;

    _delete(&head, 888);
    _delete(&head, 1);
    _delete(&head, 10);

    _display(head);

    cout << "No. of element in the Linked List = " << _count(head) << endl;

    return 0;
}
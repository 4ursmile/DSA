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

    return 0;
}
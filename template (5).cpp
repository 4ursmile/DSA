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
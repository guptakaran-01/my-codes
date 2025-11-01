#include <iostream>
using namespace std;

class linkedlist
{

public:
    int data;
    linkedlist *next;

    linkedlist(int data)
    {
        this->data = data;
        this->next = NULL;
    }

    // ~linkedlist()
    // {
    //     while (this->next != NULL)
    //     {
    //         delete next;
    //         this->next = NULL;
    //     }
    // }
};

void inserathead(linkedlist *&head, int data)
{

    linkedlist *temp = new linkedlist(data);
    temp->next = head;
    head = temp;
}

void print(linkedlist *&head)
{
    linkedlist *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

void insertattail(linkedlist *&tail, int data)
{
    linkedlist *temp = new linkedlist(data);
    tail->next = temp;
    tail = temp;
}

void inseratmiddle(linkedlist *&head, int position, int data)
{

    linkedlist *temp = head;
    int count = 1;
    while (count < position - 1)
    {
        temp = temp->next;
        count++;
    }

    linkedlist *n = new linkedlist(data);
    n->next = temp->next;
    temp->next = n;
}

void deleteposition(linkedlist *&head, int position)
{
    linkedlist *temp = head;
    if (position == 1)
    {
        head = head->next;
        temp->next = NULL;
        delete temp;
    }
    else
    {
        linkedlist *prev = NULL;
        int count = 1;
        while (count < position)
        {
            prev = temp;
            temp = temp->next;
            count++;
        }

        prev->next = temp->next;
        temp->next = NULL;
        delete temp;
    }
}

void deletedata(linkedlist *&head, int data)
{
    linkedlist *temp = head;
    if (head->data == data)
    {
        head = head->next;
        temp->next = NULL;
        delete temp;
    }
    else
    {
        linkedlist *prev = NULL;
        while (temp != NULL && temp->data != data)
        {
            prev = temp;
            temp = temp->next;
        }
        if (temp == NULL)
            return;

        prev->next = temp->next;
        temp->next = NULL;
        delete temp;
    }
}

int main()
{
    linkedlist *node1 = new linkedlist(10);

    linkedlist *head = node1;
    linkedlist *tail = node1;

    inserathead(head, 12);

    insertattail(tail, 16);

    inseratmiddle(head, 2, 2);
    print(head);

    // deleteposition(head ,3);
    deletedata(head, 12);
    print(head);

    return 0;
}

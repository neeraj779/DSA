#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *prev;
    Node *next;
    Node(int data = 0)
    {
        this->data = data;
        this->prev = NULL;
        this->next = NULL;
    }
    ~Node()
    {
        cout << "Deleting node with data " << data << endl;
        if (next != NULL)
        {
            delete next;
            next = NULL;
        }
    }
};

void traverse(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data;
        if (temp->next != NULL)
        {
            cout << "->";
        }
        temp = temp->next;
    }
    cout << endl;
}

int getLength(Node *head)
{
    Node *temp = head;
    int count = 0;
    while (temp != NULL)
    {
        count++;
        temp = temp->next;
    }
    return count;
}

void insertAtHead(Node *&head, Node *&tail, int data)
{
    Node *temp = new Node(data);
    if (head == NULL)
    {
        head = temp;
        tail = temp;
        return;
    }
    temp->next = head;
    head->prev = temp;
    head = temp;
}

void insertAtTail(Node *&head, Node *&tail, int data)
{
    Node *temp = new Node(data);
    if (tail == NULL)
    {
        tail = temp;
        head = temp;
        return;
    }
    temp->prev = tail;
    tail->next = temp;
    tail = temp;
}

void insertAtPos(Node *&head, Node *&tail, int pos, int data)
{
    Node *toInsert = new Node(data);
    if (pos == 1)
    {
        toInsert->next = head;
        head->prev = toInsert;
        head = toInsert;
        return;
    }
    int count = 1;
    Node *temp = head;
    while (count != pos - 1)
    {
        temp = temp->next;
        count++;
    }
    if (temp->next == NULL)
    {
        insertAtTail(head, tail, data);
        return;
    }

    toInsert->next = temp->next;
    toInsert->prev = temp;
    temp->next = toInsert;
    temp->next->prev = toInsert;
}
void deleteAtPos(Node *&head, Node *&tail, int pos)
{
    if (pos == 1)
    {
        Node *temp = head;
        head = temp->next;
        temp->next->prev = NULL;
        temp->next = NULL;
        delete temp;
        return;
    }

    Node *curr = head;
    Node *prev = NULL;
    int count = 1;

    // pos>len
    int len = 0;
    while (curr != NULL)
    {
        len++;
        curr = curr->next;
    }

    if (pos > len)
    {
        cout << "Opps! Position not found!" << endl;
        return;
    }
    curr = head;

    while (count < pos)
    {
        prev = curr;
        curr = curr->next;
        count++;
    }

    curr->prev = NULL;
    prev->next = curr->next;
    // if not last node
    curr->next = NULL;
    // if last node
    if (curr->next == NULL)
    {
        tail = prev;
    }
    delete curr;
}

int main()
{
    Node *head = NULL;
    Node *tail = NULL;
    insertAtHead(head, tail, 6);
    insertAtTail(tail, tail, 7);
    insertAtPos(head, tail, 3, 9);
    traverse(head);
    deleteAtPos(head, tail, 3);
    traverse(head);
    cout << head->data << endl;
    cout << tail->data << endl;
}
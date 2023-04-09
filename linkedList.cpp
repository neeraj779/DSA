#include <iostream>
#include <map>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node(int data = 0)
    {
        this->data = data;
        this->next = NULL;
    }

    ~Node()
    {
        cout << "Deleting node with data " << data << endl;
        if (this->next != NULL)
        {
            this->next = NULL;
            delete next;
        }
    }
};

void traverse(Node *&head)
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

void insertAtHead(Node *&head, int data)
{
    Node *temp = new Node(data);
    temp->next = head;
    head = temp;
}

void insertAtTail(Node *&tail, int data)
{
    Node *temp = new Node(data);
    tail->next = temp;
    tail = temp;
}

void insertAtPos(Node *&head, Node *&tail, int pos, int data)
{
    Node *toInsert = new Node(data);
    if (pos == 1)
    {
        // insertAtHead();
        toInsert->next = head;
        head = toInsert;
        return;
    }
    Node *temp = head;
    int count = 1;
    while (count != pos - 1)
    {
        temp = temp->next;
        count++;
    }

    if (temp->next == NULL)
    {
        // insertAtTail()
        temp->next = toInsert;
        tail = toInsert;
        return;
    }

    toInsert->next = temp->next;
    temp->next = toInsert;
}

void deleteNodeAtPos(Node *&head, Node *&tail, int pos)
{
    if (pos == 1)
    {
        Node *toDelete = head;
        head = head->next;
        delete toDelete;
        return;
    }

    Node *curr = head;
    Node *prev = NULL;
    int count = 1;
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
    prev->next = curr->next;
    if (curr->next == NULL)
    {
        tail = prev;
    }
    delete curr;
}

void deleteNodeAtData(Node *&head, Node *&tail, int data)
{
    Node *curr = head;
    Node *prev = NULL;
    bool flag = 0;

    if (curr->data == data)
    {
        Node *toDelete = head;
        head = head->next;
        delete toDelete;
        return;
    }

    // while (curr->data != data)
    while (curr != NULL)
    {
        if (curr->data == data)
        {
            flag = 1;
            break;
        }
        prev = curr;
        curr = curr->next;
    }

    if (!flag)
    {
        cout << "Opps! Data not found!" << endl;
        return;
    }
    prev->next = curr->next;
    if (curr->next == NULL)
    {
        tail = prev;
    }
    delete curr;
}

bool detectLoop(Node *head)
{
    map<Node *, bool> visited;
    Node *temp = head;

    while (temp != NULL)
    {
        if (visited[temp] == 1)
            return 1;

        visited[temp] = 1;
        temp = temp->next;
    }
    return 0;
}

bool floydCycle(Node *head)
{
    if (head == NULL)
        return 0;

    Node *slow = head;
    Node *fast = head;

    while (fast != NULL && slow != NULL)
    {
        fast = fast->next;
        if (fast != NULL)
            fast = fast->next;
        slow = slow->next;

        if (slow == fast)
            return 1;
    }
    return 0;
}

int main()
{
    Node *node1 = new Node(10);
    Node *head = node1;
    Node *tail = node1;
    insertAtHead(head, 13);
    insertAtTail(tail, 12);
    insertAtPos(head, tail, 4, 8);
    traverse(head);
    // deleteNodeAtPos(head, tail, 3);
    deleteNodeAtPos(head, tail, 6);
    traverse(head);
    cout << head->data << endl;
    cout << tail->data << endl;
    tail->next = head->next;
    cout << floydCycle(head);

    return 0;
}
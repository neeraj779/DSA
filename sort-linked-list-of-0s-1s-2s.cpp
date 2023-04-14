/********************************
    class Node
    {
    public:
        int data;
        Node *next;
        Node(int data)
        {
            this->data = data;
            this->next = NULL;
        }
    };

********************************/

void insertAtTail(Node *&tail, Node *&curr){
    tail->next = curr;
    tail = curr;
}

Node* sortList(Node *head)
{
    // Write your code here.
    // int zero = 0, one = 0, two = 0;
    // Node *temp = head;
    // while(temp!=NULL){
    //     if(temp->data==0) zero++;
    //     else if(temp->data==1) one++;
    //     else two++;
    //     temp = temp->next;
    // }

    // temp = head;
    // while(temp !=NULL){
    //     if(zero!=0){
    //         temp->data = 0;
    //         zero--;
    //     }
    //     else if(one != 0){
    //         temp->data = 1;
    //         one--;
    //     }
    //     else{
    //         temp->data = 2;
    //         two--;
    //     }
    //     temp = temp->next;
    // }
    // return head;

    Node *zeroHead = new Node(-1);
    Node *zeroTail = zeroHead;
    Node *oneHead = new Node(-1);
    Node *oneTail = oneHead;
    Node *twoHead = new Node(-1);
    Node *twoTail = twoHead;

    Node *curr = head;

    while(curr != NULL){
        int val = curr->data;
        if(val==0)
            insertAtTail(zeroTail, curr);
        else if(val==1)
            insertAtTail(oneTail, curr);
        else if(val==2)
            insertAtTail(twoTail, curr);
        curr = curr->next;
    }

    if(oneHead->next !=NULL){
        zeroTail->next = oneHead->next;
    }
    else{
        zeroTail->next = twoHead->next;
    }

    oneTail->next = twoHead->next;
    twoTail->next = NULL;
    

    head = zeroHead->next;

    delete zeroHead;
    delete oneHead;
    delete twoHead;
    return head;


}

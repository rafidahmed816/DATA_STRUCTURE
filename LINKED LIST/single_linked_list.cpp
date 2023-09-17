#include <iostream>
#include <vector>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node(int data)
    {
        this->data = data;
        this->next = nullptr;
    }
};
class LinkedList
{
public:
    Node *head;
    LinkedList()
    {
        head = nullptr;
    }
    void Insert_front(int val)
    {
        // newnode=pointer variable which is a pointer
        // to a object of Node class .This
        // pointer holds the address of the newly created node
        Node *newnode = new Node(val);
        if (head == NULL)
        {
            head = newnode;
        }
        else
        {
            // next is assigned to present head
            newnode->next = head;
            head = newnode;
        }
    }
    // insert after key
    void Insert_after_node(int key, int val)
    {
        Node *newnode = new Node(val);
        if (head == NULL)
        {
            head = newnode;
            return;
        }
        /*
        Node * current =head;
        int current_pos=1;
        while(current_pos<pos-1 && current->next!=NULL){
            current=current->next;
            current_pos++;
        }
          // Insert the new node after the current node
        newnode->next=current->next;
        current->next=newnode;
        */
        Node *current = head;
        while (current != NULL)
        {
            if (current->data == key)
            {
                newnode->next = current->next;
                current->next = newnode;
                return;
            }
            current = current->next;
        }
    }
    void Insert_at_location(int pos, int val)
    {
        Node *newnode = new Node(val);
        if (head == NULL)
        {
            head = newnode;
            return;
        }

        Node *current = head;
        int current_pos = 1;
        while (current_pos < pos - 1 && current->next != NULL)
        {
            current = current->next;
            current_pos++;
        }
        // Insert the new node after the current node
        newnode->next = current->next;
        current->next = newnode;
    }
    void Insert_back(int val)
    {
        Node *newnode = new Node(val);
        if (head == NULL)
        {
            head = newnode;
        }
        else
        {
            Node *current = head;
            while (current->next != NULL)
            {
                current = current->next;
            }
            current->next = newnode;
        }
    }

    void Remove_head()
    {
        Node *current = head;
        head = head->next;
        delete current;
    }

    void Remove_element(int target)
    {
        Node *current = head;
        if(head==NULL)
        return;
        //check first node
        if(current->data==target){
             head = head->next;
             delete current;
        }
        while(current->next!=NULL && current->next->data!=target){
            current=current->next;
        }
        //if found .Not traversed the whole list
        if(current->next!=NULL){
            Node * temp= current->next;
            current->next = current->next->next;
            delete temp;
        }
    }

    void Remove_end()
    {
        Node *current = head;
        Node *previous = nullptr;
        if (head == NULL)
            return;
        if (current->next == NULL)
        {
            delete current;
            head = nullptr;
            return;
        }
        while (current->next != NULL)
        {
            previous = current;
            current = current->next;
        }
        // current is now pointing to the last node, and previous to the second-to-last node
        previous->next = nullptr;
        delete current;
    }

    void Remove_at_location(int pos){
        Node * current=head;
        Node* previous=NULL;
        int cnt=1;
        while(cnt<pos){
            previous=current;
            current=current->next;
            cnt++;
        }
        if(current!=NULL){
            previous->next = current->next;
            delete current;
        }
        
    }
    void print()
    {
        Node *temp = head;
        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main()
{
    LinkedList l1;
    l1.Insert_front(10);
    l1.Insert_front(20);
    l1.Insert_front(30);
    l1.Insert_front(40);
    l1.Insert_front(50);
    l1.Insert_front(60);
    l1.Insert_after_node(30, 5);
    l1.Insert_at_location(8, 40);
    l1.Remove_head();
    l1.Remove_end();
    l1.Remove_element(5);
    l1.Remove_at_location(3);
    l1.print();
}
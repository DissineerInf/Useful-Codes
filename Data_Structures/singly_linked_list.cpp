/*
Singly Linked List

Usage 
    -- Frequent insertion and deletions at one end;
    -- Sequential access only

Time Complexity 
    -- O(n)
        -- print_list
        -- push_back , pop_back 
        -- insert_position , delete_position
        -- reverse

    -- O(1)
        -- push_front , pop_front
        -- length

*/

#include <iostream>
#include <exception>

using namespace std;

template <typename T>
class Node {
public:
    T data;
    Node * next;
    Node(T data):data(data){next = NULL;}
};

template <typename T>
class SLL {
    Node<T> * head;
    int size;
public:
    SLL(){head = NULL; size =0;}

    void print_list()
    {
        Node<T>* p = head;
        while(p != NULL)
        {
            cout<<p->data<<" ";
            p=p->next;
        }
        cout<<endl;
    }

    int length(){return size;}

    void push_back(T data)
    {
        Node<T>* temp = new Node<T>(data);
        if(head == NULL)
        {
            head = temp;
            size++;
        }
        else
        {
            Node<T>* p = head;
            while(p->next != NULL)
                p=p->next;
            p->next = temp;
            size++;
        }
    }

    void push_front(T data)
    {
        Node<T>* temp = new Node<T>(data);
        temp->next = head;
        head= temp;
        size++;
    }

    void pop_back()
    {
        if(size == 0) return;
        if(size == 1)
        {
            size--;
            Node<T>* temp = head;
            delete temp;
            head = NULL;
        }
        else
        {
            size--;
            Node<T> * p = head;
            while(p->next->next != NULL)
                p=p->next;
            Node<T>* temp = p->next;
            p->next = p->next->next;
            delete temp;
        }

    }

    void pop_front()
    {
        if(size == 0) return;
        
        size--;
        Node<T>*temp = head;
        head= head->next; 
        delete temp;
    }
    // 0-indexed
    void insert_position (int position, T data)
    {
        if (position<0 || position > size) 
            throw std::out_of_range("Invalid position");
        else if(position == 0) push_front(data);
        else if (position == size) push_back(data);
        else
        {
            size++;
            Node<T>* temp = new Node<T>(data);
            Node<T>*p = head;
            while(--position > 0)
                p=p->next;
            temp->next = p->next;
            p->next =temp;
        }
    }
    // 0-indexed
    void delete_position (int position)
    {
        if (position<0 || position >= size) 
            throw std::out_of_range("Invalid position");
        else if (position == 0) pop_front();
        else if (position == size-1) pop_back();
        else
        {
            size--;
            Node<T>*p = head;
            while(--position > 0)
                p=p->next;
            Node<T> * temp = p->next;
            p->next = p->next->next;
            delete temp;
        }
    }

    void reverse()
    {
        Node<T>* prev = NULL, *curr, *front;
        curr = head;

        while(curr != NULL)
        {
            front = curr->next;
            curr->next = prev;
            prev = curr;
            curr = front;
        }

        head = prev;
    }

};

int main()
{

    SLL <string> list1;
    
    list1.push_back("World");
    list1.push_front("Hello");
    list1.insert_position(1,",");
    cout<<list1.length()<<":"; 
    list1.print_list();

    list1.reverse();
    list1.print_list();

    list1.delete_position(1);
    list1.print_list();

    list1.pop_back();
    list1.pop_front();
    list1.print_list();
   

    return 0;
}
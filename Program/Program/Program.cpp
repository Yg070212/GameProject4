#include <iostream>

using namespace std;

template<typename T>
class DoubleLinkedList
{
private:
    struct Node
    {
        T data;
        Node* previousNode;
        Node* next;
    };

    Node* head;
    Node* tail;

    int size;

public:
    DoubleLinkedList()
    {
        head = nullptr;
        tail = nullptr;
        size = 0;
    }

    void push_front(T data)
    {
        Node* newNode = new Node;

        if (head == nullptr)
        {
            head = tail = newNode;

            newNode->data = data;
            newNode->next = nullptr;
        }
        else
        {
            newNode->data = data;
            newNode->next = head;

            head = newNode;
        }
        size++;
    }

};

int main()
{
    DoubleLinkedList<int>doubleLinkedList;

    doubleLinkedList.push_front(10);
    doubleLinkedList.push_front(10);

    return 0;
}
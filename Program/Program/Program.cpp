#include <iostream>

using namespace std;

template<typename T>
class DoubleLinkedList
{
private:
    struct Node
    {
        T data;
        Node* previous;
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

        newNode->data = data;
        newNode->next = nullptr;
        newNode->previous = nullptr;

        if (head == nullptr)
        {
            head = tail = newNode;
        }
        else
        {
            head->previous = newNode;
            newNode->next = head;

            head = newNode;
        }
        size++;
    }

    void pop_front()
    {
        if (head == nullptr)
        {
            cout << "Linked List is Empty" << endl;
        }
        else
        {
            Node* deleteNode = head;

            if (head == tail)
            {
                head = nullptr;
                tail = nullptr;
            }
            else
            {
                deleteNode->next->previous = nullptr;

                head = head->next;
            }

            delete deleteNode;

            size--;
        }
    }

    void push_back(T data)
    {
        Node* newNode = new Node;

        newNode->data = data;
        newNode->next = nullptr;
        newNode->previous = nullptr;

        if (head == nullptr)
        {
            head = tail = newNode;

        }
        else
        {
            tail->next = newNode;
            newNode->previous = tail;

            tail = newNodel
        }
        size++;
    }

    void show()
    {
        Node* currentNode = head;

        while (currentNode != nullptr)
        {
            cout << currentNode->data << " ";

            currentNode = currentNode->next;
        }
    }

    ~DoubleLinkedList()
    {
        while (head != nullptr)
        {
            pop_front();
        }
    }

};

int main()
{
    DoubleLinkedList<int>doubleLinkedList;

    doubleLinkedList.push_front(30);
    doubleLinkedList.push_front(20);
    doubleLinkedList.push_front(10);
    doubleLinkedList.push_back(5);

    doubleLinkedList.pop_front();

    doubleLinkedList.show();

    return 0;
}
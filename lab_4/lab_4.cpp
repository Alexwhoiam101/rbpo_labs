#include <iostream>
#include <initializer_list>

using namespace std;

template<class T>
class Node {
public:
    T data;
    Node* prev;
    Node* next;

    Node(const T& value) : data(value), prev(nullptr), next(nullptr) {}
};

template<class T>
class QueueBasedOnBidirectionalLinkedList {
private:
    Node<T>* head;
    Node<T>* tail;
    unsigned size;

public:
    QueueBasedOnBidirectionalLinkedList() : head(nullptr), tail(nullptr), size(0) {}

    // Конструктор копирования
    QueueBasedOnBidirectionalLinkedList(const QueueBasedOnBidirectionalLinkedList<T>& other) {
        head = nullptr;
        tail = nullptr;
        size = 0;

        Node<T>* curr = other.head;
        while (curr != nullptr) {
            Push(curr->data);
            curr = curr->next;
        }
    }

    // Конструктор перемещения
    QueueBasedOnBidirectionalLinkedList(QueueBasedOnBidirectionalLinkedList<T>&& other) noexcept {
        head = other.head;
        tail = other.tail;
        size = other.size;

        other.head = nullptr;
        other.tail = nullptr;
        other.size = 0;
    }

    // Конструктор, принимающий на вход initializer_list
    QueueBasedOnBidirectionalLinkedList(initializer_list<T> ilist) : head(nullptr), tail(nullptr), size(0) {
        for (const T& value : ilist) {
            Push(value);
        }
    }

    ~QueueBasedOnBidirectionalLinkedList() {
        while (!IsEmpty()) {
            T element;
            Pop(element);
        }
    }

    unsigned GetSize() const {
        return size;
    }

    void InsertAt(const T& value, unsigned index) {
        if (index < 0 || index > size) {
            return;
        }

        Node<T>* newNode = new Node<T>(value);

        if (head == nullptr) {
            head = newNode;
            tail = newNode;
        }
        else if (index == 0) {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
        else if (index == size) {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
        else {
            Node<T>* curr = head;
            for (unsigned i = 0; i < index - 1; i++) {
                curr = curr->next;
            }
            newNode->prev = curr;
            newNode->next = curr->next;
            curr->next->prev = newNode;
            curr->next = newNode;
        }

        size++;
    }

    T RemoveAt(unsigned index) {
        if (IsEmpty() || index < 0 || index >= size) {
            return T();
        }

        Node<T>* curr = head;

        if (size == 1) {
            head = nullptr;
            tail = nullptr;
        }
        else if (index == 0) {
            head = head->next;
            head->prev = nullptr;
        }
        else if (index == size - 1) {
            curr = tail;
            tail = tail->prev;
            tail->next = nullptr;
        }
        else {
            for (unsigned i = 0; i < index; i++) {
                curr = curr->next;
            }
            curr->prev->next = curr->next;
            curr->next->prev = curr->prev;
        }

        T value = curr->data;
        delete curr;
        size--;

        return value;
    }

    QueueBasedOnBidirectionalLinkedList& operator=(const QueueBasedOnBidirectionalLinkedList& other) {
        if (this != &other) {
            while (!IsEmpty()) {
                T element;
                Pop(element);
            }

            Node<T>* curr = other.head;
            while (curr != nullptr) {
                Push(curr->data);
                curr = curr->next;
            }
        }
        return *this;
    }
    QueueBasedOnBidirectionalLinkedList& operator=(QueueBasedOnBidirectionalLinkedList&& other) noexcept {
        if (this != &other) {
            while (!IsEmpty()) {
                T element;
                Pop(element);
            }

            head = other.head;
            tail = other.tail;
            size = other.size;

            other.head = nullptr;
            other.tail = nullptr;
            other.size = 0;
        }
        return *this;
    }

    QueueBasedOnBidirectionalLinkedList& operator=(initializer_list<T> ilist) {
        while (!IsEmpty()) {
            T element;
            Pop(element);
        }

        for (const T& value : ilist) {
            Push(value);
        }

        return *this;
    }

    bool Push(const T& element) {
        Node<T>* newNode = new Node<T>(element);

        if (IsEmpty()) {
            head = newNode;
            tail = newNode;
        }
        else if (size == 1) {
            tail = newNode;
            head->next = tail;
            tail->prev = head;
        }
        else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }

        size++;
        return true;
    }

    bool Pop(T& element) {
        if (IsEmpty()) {
            return false;
        }

        element = head->data;

        if (size == 1) {
            delete head;
            head = nullptr;
            tail = nullptr;
        }
        else {
            Node<T>* temp = head;
            head = head->next;
            head->prev = nullptr;
            delete temp;
        }

        size--;
        return true;
    }

    bool Peek(T& element) {
        if (IsEmpty()) {
            return false;
        }

        element = head->data;
        return true;
    }

    friend ostream& operator<<(ostream& os, const QueueBasedOnBidirectionalLinkedList& queue) {
        Node<T>* curr = queue.head;
        while (curr != nullptr) {
            os << curr->data << " ";
            curr = curr->next;
        }
        return os;
    }

    bool IsEmpty() const {
        return size == 0;
    }
};

int main() {
    QueueBasedOnBidirectionalLinkedList<int> queue;
    queue.Push(1);
    queue.Push(2);
    queue.Push(3);

    cout << "Size: " << queue.GetSize() << endl;
    cout << "Queue: " << queue << endl;

    int removedElement;
    if (queue.Pop(removedElement)) {
        cout << "Popped Element: " << removedElement << endl;
    }

    cout << "Size: " << queue.GetSize() << endl;
    cout << "Queue: " << queue << endl;

    int frontElement;
    if (queue.Peek(frontElement)) {
        cout << "Front Element: " << frontElement << endl;
    }

    return 0;
}
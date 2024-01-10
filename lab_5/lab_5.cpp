#include <iostream>
#include <initializer_list>
#include <cassert>

using namespace std;

template<typename T>
class AbstractQueue {
public:
    virtual ~AbstractQueue() {};

    virtual unsigned GetSize() const = 0;
    virtual bool Push(const T& element) = 0;
    virtual bool Pop(T& element) = 0;
    virtual bool Peek(T& element) = 0;
    virtual bool IsEmpty() const = 0;
};

template<typename T>
class QueueBasedOnBidirectionalLinkedList : public AbstractQueue<T> {
private:
    // Внутренний класс узла двунаправленного списка
    class Node {
    public:
        T data;
        Node* prev;
        Node* next;

        Node(const T& value) : data(value), prev(nullptr), next(nullptr) {}
    };

    Node* head; // Указатель на начало списка
    Node* tail; // Указатель на конец списка
    unsigned size; // Количество элементов в очереди

public:
    // Конструкторы
    QueueBasedOnBidirectionalLinkedList() : head(nullptr), tail(nullptr), size(0) {}

    QueueBasedOnBidirectionalLinkedList(const QueueBasedOnBidirectionalLinkedList<T>& other) {
        head = nullptr;
        tail = nullptr;
        size = 0;

        Node* curr = other.head;
        while (curr != nullptr) {
            Push(curr->data);
            curr = curr->next;
        }
    }

    QueueBasedOnBidirectionalLinkedList(QueueBasedOnBidirectionalLinkedList<T>&& other) noexcept {
        head = other.head;
        tail = other.tail;
        size = other.size;

        other.head = nullptr;
        other.tail = nullptr;
        other.size = 0;
    }

    QueueBasedOnBidirectionalLinkedList(initializer_list<T> ilist) : head(nullptr), tail(nullptr), size(0) {
        for (const T& value : ilist) {
            Push(value);
        }
    }

    // Деструктор
    ~QueueBasedOnBidirectionalLinkedList() {
        while (!IsEmpty()) {
            T element;
            Pop(element);
        }
    }

    // Перегруженные операторы присваивания
    QueueBasedOnBidirectionalLinkedList& operator=(const QueueBasedOnBidirectionalLinkedList<T>& other) {
        if (this != &other) {
            while (!IsEmpty()) {
                T element;
                Pop(element);
            }

            Node* curr = other.head;
            while (curr != nullptr) {
                Push(curr->data);
                curr = curr->next;
            }
        }
        return *this;
    }

    QueueBasedOnBidirectionalLinkedList& operator=(QueueBasedOnBidirectionalLinkedList<T>&& other) noexcept {
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

    // Методы из абстрактного класса
    unsigned GetSize() const override {
        return size;
    }

    bool Push(const T& element) override {
        Node* newNode = new Node(element);

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
    bool Pop(T& element) override {
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
            Node* temp = head;
            head = head->next;
            head->prev = nullptr;
            delete temp;
        }

        size--;
        return true;
    }

    bool Peek(T& element) override {
        if (IsEmpty()) {
            return false;
        }

        element = head->data;
        return true;
    }

    bool IsEmpty() const override {
        return size == 0;
    }
};

template<typename T>
class QueueBasedOnArray : public AbstractQueue<T> {
private:
    T* elements;
    unsigned capacity;
    unsigned size;
    unsigned frontIndex;
    unsigned rearIndex;

public:
    QueueBasedOnArray(unsigned capacity) : capacity(capacity), size(0), frontIndex(0), rearIndex(0) {
        assert(capacity > 0);
        elements = new T[capacity];
    }

    QueueBasedOnArray(const QueueBasedOnArray<T>& other) : capacity(other.capacity), size(other.size), frontIndex(other.frontIndex), rearIndex(other.rearIndex) {
        elements = new T[capacity];
        for (unsigned i = 0; i < capacity; i++) {
            elements[i] = other.elements[i];
        }
    }

    QueueBasedOnArray(QueueBasedOnArray<T>&& other) noexcept {
        elements = other.elements;
        capacity = other.capacity;
        size = other.size;
        frontIndex = other.frontIndex;
        rearIndex = other.rearIndex;

        other.elements = nullptr;
        other.capacity = 0;
        other.size = 0;
        other.frontIndex = 0;
        other.rearIndex = 0;
    }

    ~QueueBasedOnArray() {
        delete[] elements;
    }

    QueueBasedOnArray& operator=(const QueueBasedOnArray<T>& other) {
        if (this != &other) {
            delete[] elements;

            capacity = other.capacity;
            size = other.size;
            frontIndex = other.frontIndex;
            rearIndex = other.rearIndex;

            elements = new T[capacity];
            for (unsigned i = 0; i < capacity; i++) {
                elements[i] = other.elements[i];
            }
        }
        return *this;
    }

    QueueBasedOnArray& operator=(QueueBasedOnArray<T>&& other) noexcept {
        if (this != &other) {
            delete[] elements;

            elements = other.elements;
            capacity = other.capacity;
            size = other.size;
            frontIndex = other.frontIndex;
            rearIndex = other.rearIndex;

            other.elements = nullptr;
            other.capacity = 0;
            other.size = 0;
            other.frontIndex = 0;
            other.rearIndex = 0;
        }
        return *this;
    }

    unsigned GetSize() const override {
        return size;
    }

    bool Push(const T& element) override {
        if (size == capacity) {
            return false;
        }

        elements[rearIndex] = element;
        rearIndex = (rearIndex + 1) % capacity;
        size++;
        return true;
    }

    bool Pop(T& element) override {
        if (IsEmpty()) {
            return false;
        }

        element = elements[frontIndex];
        frontIndex = (frontIndex + 1) % capacity;
        size--;
        return true;
    }

    bool Peek(T& element) override {
        if (IsEmpty()) {
            return false;
        }

        element = elements[frontIndex];
        return true;
    }

    bool IsEmpty() const override {
        return size == 0;
    }
};

void demonstrateAbstractQueue(AbstractQueue<int>& queue) {
    queue.Push(1);
    queue.Push(2);
    queue.Push(3);
    queue.Push(4);

    cout << "Size: " << queue.GetSize() << endl;
    cout << "Queue: ";
    int element;
    while (queue.Pop(element)) {
        cout << element << " ";
    }
    cout << endl;
}

void demonstrateAbstractQueue(AbstractQueue<int>* queue) {
    queue->Push(1);
    queue->Push(2);
    queue->Push(3);
    queue->Push(4);

    cout << "Size: " << queue->GetSize() << endl;
    cout << "Queue: ";
    int element;
    while (queue->Pop(element)) {
        cout << element << " ";
    }
    cout << endl;
}

int main() {
    QueueBasedOnBidirectionalLinkedList<int> queue1;
    demonstrateAbstractQueue(queue1);

    QueueBasedOnArray<int> queue2(5);
    demonstrateAbstractQueue(queue2);

    return 0;
}
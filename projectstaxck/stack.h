#ifndef STACK_H
#define STACK_H

template <typename T>
class Stack {
private:
    int top;
    int capacity;
    T* elements;

public:
    Stack(int size) {
        capacity = size;
        elements = new T[capacity];
        top = -1;
    }

    ~Stack() {
        delete[] elements;
    }

    bool isEmpty() {
        return top == -1;
    }

    bool isFull() {
        return top == capacity - 1;
    }

    void push(T item) {
        if (!isFull()) {
            elements[++top] = item;
        }
    }

    T pop() {
        if (!isEmpty()) {
            return elements[top--];
        }
        // Return default object if stack is empty
        return T();
    }

    T topElement() {
        if (!isEmpty()) {
            return elements[top];
        }
        return T();
    }

    int getTopIndex() {
        return top;
    }

    T getValue(int index) {
        if (index >= 0 && index <= top) {
            return elements[index];
        }
        return T();
    }
};

#endif

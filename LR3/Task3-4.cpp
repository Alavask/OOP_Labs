#include <iostream>

using namespace std;

template <class T>
class Elem {
public:
    Elem(T item, Elem<T>* next) : item(item), next(next) {};
    T item;
    Elem* next;
};

template <class T>
class Stack {
public:
    Stack() : tail(nullptr), length(0) {}

    bool empty() {
        return length == 0;
    }

    void push(const T& item) {
        Elem<T>* newElem = new Elem<T>(item, tail);
        tail = newElem;
        length++;
    }

    T& top() {
        if (!empty()) {
            return tail->item;
        }
    }

    void pop() {
        if (!empty()) {
            Elem<T>* result = tail;
            tail = result->next;
            delete result;
            length--;
        }
    }
    friend Stack<T> operator+ <> (const Stack<T>& s1, const Stack<T>& s2);
private:
    Elem<T>* tail;
    int length;
};

template <class T>
Stack<T> operator+ (const Stack<T>& s1, const Stack<T>& s2) { //a+b as s1+s2
    Stack<T> st;
    Elem<T>* head = nullptr;
    Elem<T>* pointer = s2.tail;
    
    while (pointer!=nullptr){ //Copy b to new stack
        if (head == nullptr) {
            st.tail = new Elem<T>(pointer->item, nullptr);
            head = st.tail;
            pointer = pointer->next;
            continue;
        }
        head->next = new Elem<T>(pointer->item, nullptr);
        head = head->next;
        pointer = pointer->next;
    }
    pointer = s1.tail;
    while (pointer != nullptr){ //Copy a to new stack
        if (head == nullptr) {
            st.tail = new Elem<T>(pointer->item, nullptr);
            head = st.tail;
            pointer = pointer->next;
            continue;
        }
        head->next = new Elem<T>(pointer->item, nullptr);
        head = head->next;
        pointer = pointer->next;
    }
    if (head == nullptr) { //both a and b empty
        st.tail = nullptr;
    }
    st.length = s1.length + s2.length;
    return st;
}

int main3()
{
    cout << "Stack1" << endl;
    Stack<int> st;
    st.push(1);
    cout << st.top() << endl;
    st.push(2);
    cout << st.top() << endl;
    st.push(3);
    cout << st.top() << endl;
    st.pop();
    cout << st.top() << endl;
    st.pop();
    cout << st.top() << endl;
    st.push(4);
    cout << st.top() << endl;


    cout << "Stack2" << endl;
    Stack<int> st2;
    st.push(1);
    cout << st.top() << endl;
    st.push(2);
    cout << st.top() << endl;
    st.push(3);
    cout << st.top() << endl;

    cout << "StackSum" << endl;
    Stack<int> stSum = st + st2;

    cout << stSum.top() << endl;
    stSum.pop();
    cout << stSum.top() << endl;
    stSum.pop();
    cout << stSum.top() << endl;
    stSum.pop();
    cout << stSum.top() << endl;
    stSum.pop();
    cout << stSum.top() << endl;
    return 0;
}
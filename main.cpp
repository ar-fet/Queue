#include <iostream>
#include <vector>
using namespace std;

struct Node
{
    int num;
    Node* next = NULL;
};

struct Queue {
    Node *begin = NULL, *end = NULL;
    Queue() {

    }
    void push(int num) {
        if (begin == NULL) {
            begin = new Node();
            end = begin;
            begin->num = num;
        }
        else {
            end->next = new Node();
            end = end->next;
            end->num = num;
        }
    }
    void pop()
    {
        Node* old = begin;
        begin = begin->next;
        delete(old);
        if (begin == NULL) end = NULL;
    }

    int front()
    {
        return begin->num;
    }

    int back()
    {
        return end->num;
    }

    bool empty()
    {
        if (begin == NULL) {
            return true;
        }
        else return false;
    }
};

int main() {
    Queue q;
    if (q.empty() == true) cout << 1;
    else cout << 0;

    q.push(7);
    if (q.empty() == false) cout << 1;
    else cout << 0;

    if (q.front() == 7) cout << 1;
    else cout << 0;
    if (q.back() == 7) cout << 1;
    else cout << 0;

    q.pop();
    if (q.empty() == true) cout << 1;
    else cout << 0;

    q.push(1);
    q.push(2);
    q.push(3);
    if (q.empty() == false) cout << 1;
    else cout << 0;

    if (q.front() == 1) cout << 1;
    else cout << 0;
    if (q.back() == 3) cout << 1;
    else cout << 0;

    q.pop();
    if (q.front() == 2) cout << 1;
    else cout << 0;
    if (q.back() == 3) cout << 1;
    else cout << 0;

    q.pop();
    if (q.front() == 3) cout << 1;
    else cout << 0;
    if (q.back() == 3) cout << 1;
    else cout << 0;

    if (q.empty() == false) cout << 1;
    else cout << 0;
}

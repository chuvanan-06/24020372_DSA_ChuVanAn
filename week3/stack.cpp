#include<iostream>
using namespace std;
//Stack bang list
struct ListStack {
    int arr[1000];
    int n; //so luong phan tu trong list
    ListStack() {
        n=0;
    }
    bool isEmpty() {
        return n == 0;
    }
    int size() {
        return n;
    }
    void push(int item) {
        arr[n]=item;
        n++;
    }
    int top() {
        if(isEmpty()) return -1;
        return arr[n-1];
    }
    int pop() {
        if(isEmpty()) return -1;
        int popItem = arr[n-1];
        n--;
        return popItem;
    }
};
//Stack bang linklist
struct Node{
    int data;
    Node* next;
    Node(int val) {
        data = val;
        next = NULL;
    }
};
Node* themdau(Node* head,int data) {
    Node* p = new Node(data);
    p->next = head;
    return p;
}
Node* xoadau(Node* head) {
    if(head == NULL) return NULL;
    Node* temp = head;
    head=head->next;
    delete temp;
    return head;
}
struct Stack {
    Node* head;
    int n;
    Stack() {
        head = NULL;
        n=0;
    }
    bool isEmpty() {
    return head == NULL;
    }
    int size() {
        return n;
    }
    int top() {
        if(isEmpty()) return -1;
        return head->data;
    }
    void push(int item) {
        head = themdau(head, item);
        n++;
    }
    int pop() {
        if(isEmpty()) return -1;
        int popItem = head->data;
        head = xoadau(head);
        n--;
        return popItem;
    }
};
int main() {
    ListStack s1;
    s1.push(1);
    s1.push(2);
    s1.push(3);
    cout<<"Kich thuoc s1: "<<s1.size()<<endl;
    cout<<s1.pop()<<" ";
    cout<<s1.pop()<<" ";
    cout<<s1.pop()<<endl;
    Stack s2;
    s2.push(4);
    s2.push(5);
    s2.push(6);
    cout<<"Kich thuoc s2: "<<s2.size()<<endl;
    cout<<s2.pop()<<" ";
    cout<<s2.pop()<<" ";
    cout<<s2.pop()<<endl;
 return 0;
}
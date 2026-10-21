#include<iostream>
using namespace std;
struct ListQueue {
    int arr[1000];
    int headIndex;
    int tailIndex;
    ListQueue() {
        headIndex = 0;
        tailIndex = 0;
    }
    bool isEmpty() {
        return headIndex == tailIndex;//dau cuoi gap nhau la rong
    }
    int size() {
        return tailIndex-headIndex;
    }
    void enqueue(int item) {
        arr[tailIndex]=item;
        tailIndex++;
    }
    int front() {//lay gia tri dau
        if(isEmpty()) return -1;
        return arr[headIndex];
    }
    int dequeue() {
        if(isEmpty()) return -1;
        int popItem = arr[headIndex]; //luu gtri dau
        headIndex++;
        return popItem;
    }
};
//queue bang linklist
struct Node{
    int data;
    Node* next;
    Node(int val) {
        data = val;
        next = NULL;
    }
};
Node* themcuoi(Node* head,int data) {
    Node* p = new Node(data);
    if(head==NULL) {
        return p;
    }
    Node* temp = head;
    while(temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = p;
    return head;
}
Node* xoadau(Node* head){
    if(head==NULL) return NULL;
    Node* temp = head;
    head = head->next;
    delete temp;
    return head;
}
struct Queue {
    Node* head;
    int n;
    Queue() {
        head = NULL;
        n = 0;
    }
    bool isEmpty() {
        return head == NULL;
    }
    int size() {
        return n;
    }
    int front() {
        if(isEmpty()) return -1;
        return head->data;
    }
    void enqueue(int item) {
        head = themcuoi(head,item);
        n++;
    }
    int dequeue() {
        if(isEmpty()) return -1;
        int popItem = head->data;
        head = xoadau(head);
        n--;
        return popItem;
    }
};
int main() {
    ListQueue q1;
    q1.enqueue(1);
    q1.enqueue(2);
    q1.enqueue(3);
    cout<<q1.dequeue()<<" ";
    cout<<q1.dequeue()<<" ";
    cout<<q1.dequeue()<<endl;
    Queue q2;
    q2.enqueue(4);
    q2.enqueue(5);
    q2.enqueue(6);
    cout<<q2.dequeue()<<" ";
    cout<<q2.dequeue()<<" ";
    cout<<q2.dequeue()<<endl;
    return 0;
}
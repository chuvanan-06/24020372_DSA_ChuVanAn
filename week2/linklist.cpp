#include<iostream>
using namespace std;
struct Node{
    int data;
    Node* next;
    Node(int val){
        data=val;
        next=nullptr;
    }
};
Node* themdau(Node* head,int val){
    Node* newnode=new Node(val);
    newnode->next=head;
    return newnode;
}
Node* themcuoi(Node* head,int val){
    Node* newnode=new Node(val);
    if(head==nullptr){
        return newnode;
    }
    Node* temp=head;
    while(temp->next!=nullptr){
        temp=temp->next;
    }
  temp->next=newnode;
  return head;
}
Node* themgiua(Node* head,int val,int pos) {
    if(pos == 0) return themdau(head, val); //chen vi tri 0
    int count = 0;
    Node* p = new Node(val);
    Node* temp = head;
    while(temp!=nullptr && count < pos-1) {
        temp=temp->next;
        count++;
    }
    if(temp!=nullptr){
        p->next=temp->next;
        temp->next=p;
    }
    return head;
}
Node* xoadau(Node* head) {
    if(head==nullptr) return nullptr;
    Node* current = head;
    head=head->next;
    delete current;
    return head;
}
Node* xoacuoi(Node* head) {
    if(head==nullptr) return nullptr;
    if(head->next==nullptr){
        delete head;
        return nullptr;
    }
    Node* temp=head;
    while(temp->next->next != nullptr){
        temp=temp->next;
    }
    Node* k = temp->next;
    temp->next=nullptr;
    delete k;
    return head;
}
Node* xoagiua(Node* head,int pos) {
    if(pos == 0) return xoadau(head);
    Node* temp = head;
    int count = 0;
    while(temp!=nullptr && count < pos-1){
        temp= temp->next;
        count++;
    }
    if (temp == nullptr || temp->next == nullptr) return head;
    Node* current = temp->next;
    temp->next=current->next;
    delete current;
    return head;
}
void duyetxuoi(Node* head) {
    Node* tmp = head;
    while (tmp != nullptr) {
        cout << tmp->data << " "; 
        tmp = tmp->next; 
    }
    cout << endl;
}

void duyetnguoc(Node* head) {
    if (head == nullptr) {
        return;
    }
    duyetnguoc(head->next); //dequy
    cout << head->data << " ";
}
int main() {
    Node* linklist = nullptr;
    linklist = themcuoi(linklist, 10);
    linklist = themcuoi(linklist, 20);
    linklist = themcuoi(linklist, 30);
    duyetxuoi(linklist);

    return 0;
}
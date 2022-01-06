//written by christian jarmon
/* 
Implement a Stack class, using a linked list of strings. Supply operations size, push,
pop, and top, just like in the standard stack template. 



*/
#include <vector>
#include <iostream>
using namespace std;
class Node{
public:
string str = "";
Node *next;
};//node class ends



class Stack{
    public:
    int sizecount = 0;
Node *head;

void push(string data) {
    Node *temp = new Node();
    if (!temp) {exit(9);}
    temp->str = data;
    temp->next = head;
    head = temp;
}//push ends



void pop() {
Node *temp;
if (head == NULL) {exit(99);}
else {
    temp = head;
    head = head->next;
    temp->next = NULL;
    free(temp); 
}
}//pop ends




int size(Node *n) {
   n = head;
    while (n != NULL) {sizecount++; n = n->next;}
    return sizecount;
}

Node* top() {
    return head;
}

void listStack(Node *n) {
    while (n != NULL) {cout << n->str << endl; n = n->next;}
}

};//stack class ends

int main() {
Stack test;
cout << "pushing stuff\n"; 
test.push("test1");
test.push("test2");
test.push("test3");
test.push("test4");
cout << "current top is " << test.top()->str << endl;
cout << "\nlisting stuff\n";
test.listStack(test.head);
cout << "\nprinting size\n";
cout << test.size(test.head) << endl;

cout << "\npoping stuff\n";
test.pop();
test.listStack(test.head);
cout << "\ncurrent top is " << test.top()->str << endl;
}//main ends
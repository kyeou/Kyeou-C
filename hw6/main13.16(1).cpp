//written by christian jarmon
/*

Implement a Queue class, using a linked list of strings. Supply operations size, push,
pop, front, and back, just like in the standard queue template.
*/

#include <vector>
#include <iostream>
using namespace std;
class Node{
public:
string str = "";
Node *next;
};//node class ends



class Queue{
    public:
    int sizecount = 0;
Node *head, *ass;

void push(string data) {
    Node* a = new Node(); a->str = data;
   if (ass == NULL) {head= ass = a; return;}
   
   ass->next = a;
   ass = a;
   
   
   }//push ends



void pop() {
if (head == NULL) return;
Node* temp = head;
head = head->next;
ass = (head == NULL) ? NULL : ass;
delete (temp);
}//pop ends




int size(Node *n) {
    while (n != NULL) {++sizecount; n = n->next;}
    return sizecount;
}

Node* front() {
    return head;
}
Node *back() {
    return ass;
}

void listStack(Node *n) {
    while (n != NULL) {cout << n->str << endl; n = n->next;}
}

};//stack class ends

int main() {
Queue test;
cout << "pushing stuff\n"; 
test.push("test1");
test.push("test2");
test.push("test3");
test.push("test4");
cout << "front data is " << test.front()->str << " and back data is " << test.back()->str << endl;
cout << "\nlisting stuff\n";
test.listStack(test.head);
cout << "\nprinting size\n";
cout << test.size(test.head) << endl;

cout << "\npoping stuff\n";
test.pop();
test.listStack(test.head);

cout << "\nfront data is " << test.front()->str << " and back data is " << test.back()->str << endl;
}//main ends
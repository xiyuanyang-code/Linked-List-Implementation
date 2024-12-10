#include "linkedlist.h"
int main() {
    LinkedList thelklist;
    cout << thelklist.isempty() << endl;
    thelklist.insertAtEnd(6);
    thelklist.insertAtEnd(5);
    thelklist.insertAtEnd(3);
    thelklist.insertAfter(thelklist.sentinel, 2);
    thelklist.insertAtHead(11);
    thelklist.insertAtPosition(7, 4);
    thelklist.deleteNode(2);
    thelklist.deletetheend();
    thelklist.deletetheplace(3);
    cout << thelklist.isempty() << endl;
    cout << thelklist.search(6) << endl;
    cout << thelklist.search(2) << endl;
    thelklist.modify(0,4);
    thelklist.printList();
    cout << thelklist.size << endl;
    return 0;
}
//
// Created by 29349 on 2024/12/10.
//

#ifndef LINKEDLIST_H
#define LINKEDLIST_H
/*
 * @Author: Xiyuan Yang   xiyuan_yang@outlook.com
 * @Date: 2024-12-08 10:28:07
 * @LastEditors: Xiyuan Yang   xiyuan_yang@outlook.com
 * @LastEditTime: 2024-12-08 14:11:49
 * @FilePath: \CODE_for_Vscodec:\Users\29349\Desktop\Linked_list.cpp
 * @Description:
 * Do you code and make progress today?
 * Copyright (c) 2024 by Xiyuan Yang, All Rights Reserved.
 */
#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int value = 0, ListNode *next = nullptr) : val(value), next(next) {}
};

struct LinkedList {
    // By default, construct a sentinel node that does not store any value, and its reference points to the first element of the list
    // Initially, it points to nullptr
    ListNode* sentinel;
    int size = 0;

    // Constructor: Initialize the sentinel node, allocate memory on the heap for it
    LinkedList(): sentinel(new ListNode()), size(0) {
        cout << "Created successfully" << endl;
    };

    // Destructor: Iteratively delete all nodes (including the memory pointed to by the sentinel node initially)
    // Once the sentinel points to a null pointer, the destruction process is complete
    ~LinkedList() {
        while (sentinel != nullptr) {
            ListNode* temp = sentinel;
            sentinel = sentinel->next;
            delete temp;
        }
        cout << "Destroyed successfully" << endl;
    }

    // Four insertion functions
    // Insert a node at the head of the list
    void insertAtHead(int value) {
        // Set the reference of the new node to the reference of the sentinel node
        ListNode* newNode = new ListNode{value, sentinel->next};
        // Change the reference of the sentinel node because the first element of the list has changed
        sentinel->next = newNode;
        size++;
    }

    // Insert a new node after the specified node
    // current represents the node after which you want to insert
    void insertAfter(ListNode* current, int value) {
        // If the current node is null, return or throw an exception
        if (current == nullptr) {
            throw std::invalid_argument("Current node is null");
            return;
        }

        // Create a new node
        ListNode* newNode = new ListNode{value, current->next};
        // Insert the new node after the current node
        current->next = newNode;
        size++;
    }

    void insertAtPosition(int value, int position) {
        // If the position is 0 or the list is empty, insert at the head
        if (position == 0 || sentinel->next == nullptr) {
            insertAtHead(value);
            return;
        }

        ListNode* current = sentinel->next;
        int currentPosition = 0;
        // Set a pointer to start the traversal

        // Find the node before the insertion position
        while (current->next != nullptr && currentPosition < position - 1) {
            current = current->next;
            currentPosition++;
        }

        // If the position exceeds the end of the list, insert at the end
        if (currentPosition < position - 1) {
            ListNode* newNode = new ListNode{value, nullptr};
            current->next = newNode;
            size++;
        } else {
            // Insert the new node
            // current represents the node at index n-1, inserting after it achieves the desired index
            insertAfter(current, value);
        }
    }

    // Insert directly at the end
    void insertAtEnd(int value) {
        if (sentinel->next == nullptr) {
            ListNode* newNode = new ListNode{value, nullptr};
            sentinel->next = newNode;
            size++;
            return;
        }
        ListNode* current = sentinel->next;
        while (current->next != nullptr) {
            current = current->next;
        }
        // Traverse to the last node
        // Create a new node
        ListNode* newNode = new ListNode{value, nullptr};
        current->next = newNode;
        size++;
    }

    // Delete operation
    // Delete the node with the specified value
    void deleteNode(int key) {
        if (sentinel->next == nullptr) return; // Empty list

        ListNode* current = sentinel->next;
        ListNode* prev = sentinel;

        while (current != nullptr) {
            if (current->val == key) {
                break;
            }
            prev = current;
            current = current->next;
        }

        if (current == nullptr) return; // Node does not exist

        prev->next = current->next;
        delete current;
        size--;
    }

    // Delete the last element of the list
    void deletetheend() {
        if (sentinel->next == nullptr) return; // Empty list

        ListNode* current = sentinel->next;
        ListNode* prev = sentinel;

        while (current->next != nullptr) {
            prev = current;
            current = current->next;
        }
        // At this point, current is the last element of the list
        prev->next = nullptr;
        delete current;
        size--;
    }

    // Delete the element at a specific index in the list
    void deletetheplace(int index) {
        if (sentinel->next == nullptr) return; // Empty list

        ListNode* current = sentinel->next;
        ListNode* prev = sentinel;
        int count = 0;

        while (current != nullptr && count < index) {
            prev = current;
            current = current->next;
            count++;
        }
        if (count < index) {
            // Index is too large, no corresponding index
            return;
        } else {
            // Then current is the node at the target index
            prev->next = current->next;
            delete current;
            size--;
        }
    }
    void modify(int index,int replacement){
        ListNode* current = sentinel->next;
        // At this point, current points to the address of the first element of the list
        int count = 0;
        if (count >= size) {
            throw out_of_range("Out of range");
        } else {
            while (count < index) {
                current = current->next;
                count++;
            }
            // At this point, current points to the element at the target index
            current->val=replacement;
        }
    }
    // List search
    int at(int index) {
        ListNode* current = sentinel->next;
        // At this point, current points to the address of the first element of the list
        int count = 0;
        if (count >= size) {
            throw out_of_range("Out of range");
        } else {
            while (count < index) {
                current = current->next;
                count++;
            }
            // At this point, current points to the element at the target index
            return current->val;
        }
    }

    int search(int target) {
        int count = 0;
        ListNode* current = sentinel->next;
        // At this point, current points to the address of the first element of the list
        while (current != nullptr) {
            if (current->val == target) {
                return count;
            }
            count++;
            current = current->next;
        }
        return -1;
    }

    // Print list content
    void printList() {
        ListNode* current = sentinel->next;
        while (current != nullptr) {
            std::cout << current->val << " -> ";
            current = current->next;
        }
        std::cout << "NULL" << std::endl;
    }

    // Check if the list is empty
    bool isempty() {
        if (sentinel->next == nullptr) {
            return true;
        } else {
            return false;
        }
    }
};



#endif //LINKEDLIST_H

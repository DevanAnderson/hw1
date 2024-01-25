/*
CSCI 104: Homework 1 Problem 1

Use this file to test your split.cpp file.

Create linked lists and split them with your split() function.

You can compile this file like this:
g++ split.cpp test_split.cpp -o test_split
*/

#include "split.h"

#include <iostream>
using namespace std;

//append to the end of the linked list
void append(Node* head, int val);
//print the contents of the linked list
void print(Node* head);
//deallocate the linked list
void deallocate(Node* head);

int main(int argc, char* argv[])
{
    Node* head = new Node(4, nullptr);
    for(int i = 4; i < 10; i++){
        append(head, i + 3);
    }

    print(head);
    
    Node* even = nullptr;
    Node* odd = nullptr;

    //split and print what the values are
    split(head, even, odd);
    print(head);
    print(even);
    print(odd);


    //prevent mem leaks
    deallocate(even);
    deallocate(odd);
}

void append(Node* head, int val){
    while(head->next != nullptr){
        head = head->next;
    }
    head->next = new Node(val, nullptr);
}

void print(Node* head){
    while(head != nullptr){
        cout << head->value << ' ';
        head = head->next;
    }
    cout << endl;
}

void deallocate(Node* head){
    Node* temp = head;
    while(head != nullptr){
        head = head->next;
        delete temp;
        temp = head;
    }
}

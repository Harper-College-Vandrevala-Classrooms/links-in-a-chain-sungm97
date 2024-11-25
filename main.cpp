#include <iostream>
#include <string>

using namespace std;

class ChainLink {
private:
    string color;

public:
    ChainLink(string color) {
        this->color = color;
    }

    string get_color() {
        return this->color;
    }
};

class Node {
public:
    ChainLink* chain; 
    Node* next;    

    Node(ChainLink* link) : chain(link), next(nullptr) {}
};

class SinglyLinkedList {
private:
    Node* head;
    Node* tail;

public:
    SinglyLinkedList() : head(nullptr), tail(nullptr) {}

    void append(ChainLink* link) {
        Node* new_node = new Node(link);
        if (!head) {
            head = new_node;
            tail = new_node;
        } else {
            tail->next = new_node;
            tail = new_node;
        }
    }

    ChainLink* get_at(int index) {
        Node* current = head;
        int current_index = 0;

        while (current) {
            if (current_index == index) {
                return current->chain;
            }
            current = current->next;
            current_index++;
        }

        return nullptr;
    }

    void display() {
        Node* current = head;
        while (current) {
            cout << current->chain->get_color() << " -> ";
            current = current->next;
        }
        cout << "null" << endl;
    }
};

int main() {
    SinglyLinkedList list;

    ChainLink* red = new ChainLink("red");
    ChainLink* blue = new ChainLink("blue");
    ChainLink* green = new ChainLink("green");
    list.append(red);
    list.append(blue);
    list.append(green);
    list.display();

    ChainLink* test1 = list.get_at(1);
    cout << "Color at Index 1: " << test1->get_color() << endl;
    ChainLink* test2 = list.get_at(2);
    cout << "Color at Index 2: " << test2->get_color() << endl;
    ChainLink* test3 = list.get_at(3);
    if (test3) {
        cout << "Color at Index 3: " << test3->get_color() << endl;
    } else {
        cout << "Index out of bounds!" << endl;
    }  

    

    return 0;
}

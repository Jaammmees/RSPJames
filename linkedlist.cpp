#include <iostream>

struct Node {
    int data; 
    Node* next; 
    // Constructor in longhand
    Node(int val) {
        data = val;
        next = nullptr;
    }
};

class LinkedList {
private:
    Node* head;

public:
    LinkedList() {
        head = nullptr;
    }

    void insert(int value) {
        //traverse till end and insert
        Node* newNode = new Node(value);
        if (head == nullptr) {
            head = newNode;
        } else {
            Node* current = head;
            while (current->next != nullptr) {
                current = current->next;
            }
            current->next = newNode;
        }
    }

    // Remove method
    void deleteNode(int value) {
        //uses dummy node to handle case of root itself being deleted
        if (head == nullptr) return;
        if (head->data == value) {
            Node* temp = head;
            head = head->next;
            return;
        }
        //skips the node and re-assigns pointer to next to "delete"
        Node* current = head;
        while (current->next != nullptr && current->next->data != value) {
            current = current->next;
        }

        if (current->next == nullptr) return; 

        Node* temp = current->next;
        current->next = temp->next;
    }

    // print method
    void print() {
        Node* current = head;
        while (current != nullptr) {
            std::cout << current->data << " ";
            current = current->next;
        }
        std::cout << std::endl;
    }

};

int main() {
    LinkedList list;
    list.insert(1);
    list.insert(2);
    list.insert(3);
    list.print(); 
    list.deleteNode(2);
    list.print(); 

    return 0;
}

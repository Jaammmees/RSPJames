#include <iostream>
using namespace std;

struct Node {
    int value;
    Node* left;
    Node* right;

    Node(int val) : value(val), left(nullptr), right(nullptr) {}
};

class BinaryTree {
private:
    Node* root;

    Node* insertNode(Node* node, int value) {
        if (node == nullptr) {
            return new Node(value);
        }
        if (value < node->value) {
            node->left = insertNode(node->left, value);
        } else {
            node->right = insertNode(node->right, value);
        }
        return node;
    }

    Node* deleteNode(Node* node, int value) {
        if (node == nullptr) {
            return nullptr;
        }

        if (value < node->value) {
            node->left = deleteNode(node->left, value);
        } else if (value > node->value) {
            node->right = deleteNode(node->right, value);
        } else {
            if (node->left == nullptr) {
                Node* temp = node->right;
                delete node;
                return temp;
            } else if (node->right == nullptr) {
                Node* temp = node->left;
                delete node;
                return temp;
            }

            Node* successor = minValueNode(node->right);
            node->value = successor->value;
            node->right = deleteNode(node->right, successor->value);
        }
        return node;
    }

    Node* minValueNode(Node* node) {
        Node* current = node;
        while (current && current->left != nullptr) {
            current = current->left;
        }
        return current;
    }

    void inOrderPrint(Node* node) {
        if (node != nullptr) {
            inOrderPrint(node->left);
            cout << node->value << " ";
            inOrderPrint(node->right);
        }
    }

public:
    BinaryTree() : root(nullptr) {}

    void insert(int value) {
        root = insertNode(root, value);
    }

    void remove(int value) {
        root = deleteNode(root, value);
    }

    void printInOrder() {
        inOrderPrint(root);
        cout << endl;
    }
};

int main() {
    BinaryTree tree;

    tree.insert(8);
    tree.insert(3);
    tree.insert(10);
    tree.insert(1);
    tree.insert(6);
    tree.insert(14);
    tree.insert(4);
    tree.insert(7);
    tree.insert(13);

    cout << "In-order traversal before deletion: ";
    tree.printInOrder();

    tree.remove(10); // Deleting node with value 10

    cout << "In-order traversal after deletion: ";
    tree.printInOrder();

    return 0;
}

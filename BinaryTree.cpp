#include <iostream>
using namespace std;

struct Node{
    int value;
    Node* left = nullptr;
    Node* right = nullptr;
};

class BinaryTree{
    private:
        Node* root = nullptr;

        void inOrderTraversalHelper(Node* root){
            if(root == nullptr){
                return;
            }
            inOrderTraversalHelper(root->left);
            cout << root->value << " ";
            inOrderTraversalHelper(root->right);
        }
    public:
        void insertNode(int value){
            //empty
            if(root == nullptr){
                root = new Node();
                root->value = value;
                return;
            }

            Node* current = root;
            Node* parent = nullptr;
            
            while (current != nullptr){
                parent = current;

                if(value < current->value){
                    current = current->left;
                } else {
                    current = current->right;
                }

            }

            if(value < parent->value){
                parent->left = new Node();
                parent->left->value = value;
            } else {
                parent->right = new Node();
                parent->right->value = value;
            }
        }
        void deleteNode(int value){
            Node* current = root;
            Node* parent = nullptr;

            //find the parent and child
            while (current != nullptr && current->value != value){
                parent = current;
                if(value < current->value){
                    current = current->left;
                } else {
                    current = current->right;
                }
            }

            if(current == nullptr){
                return;
            }

            //no children or 1 child
            //find child
            if (current->left == nullptr || current->right == nullptr){
                Node* child;
                if (current->left != nullptr){
                    child = current->left;
                    parent->left = child;
                } else {
                    child = current->right;  
                    parent->right = child;
                }

            } else {
                Node* successorParent = current;
                Node* inOrderSuccessor = current->right;
                while (inOrderSuccessor->left != nullptr){
                    successorParent = inOrderSuccessor;
                    inOrderSuccessor = inOrderSuccessor->left;
                }
                current->value = inOrderSuccessor->value;

                if (successorParent != current){
                    successorParent->left = inOrderSuccessor->right;
                } else {
                    successorParent->right = inOrderSuccessor->right;
                }

                delete inOrderSuccessor;
            };
            //2 child
            //find inOrdersucessor
            
        }
        void inOrderTraversal() {
            inOrderTraversalHelper(root);
        }
        // void preOrderTraversal(Node* root){
            
        // }
        // void postOrderTraversal(Node* root){
            
        // }
};

int main() {
    BinaryTree tree;

    tree.insertNode(3);
    tree.insertNode(1);
    tree.insertNode(5);

    cout << "In-order Traversal: ";
    tree.inOrderTraversal();
    cout << endl;

    tree.deleteNode(5);
    cout << "In-order Traversal: ";
    tree.inOrderTraversal();
    cout << endl;


    return 0;
}

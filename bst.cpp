#include<iostream>
#include<vector>

using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;
    Node(int value) {
        data = value;
        left = nullptr;
        right = nullptr;
    }
};

class BST {
public:
    Node* root;
    BST() {
        root = nullptr;
    }

    void insert(int value) {
        Node* newNode = new Node(value);
        if (root == nullptr) {
            root = newNode;
        } else {
            Node* current = root;
            Node* parent;
            while (true) {
                parent = current;
                if (value < current->data) {
                    current = current->left;
                    if (current == nullptr) {
                        parent->left = newNode;
                        return;
                    }
                } else {
                    current = current->right;
                    if (current == nullptr) {
                        parent->right = newNode;
                        return;
                    }
                }
            }
        }
    }
};

int main() {
    vector<int> values = { 5, 3, 7, 1, 9 };

    BST bst;
    for (int value : values) {
        bst.insert(value);
    }

    // Example usage: printing the inorder traversal of the BST
    // Inorder traversal of a BST gives elements in sorted order
    cout << "Inorder Traversal of BST: ";
    // Perform inorder traversal and print the nodes
    function<void(Node*)> inorder = [&](Node* node) {
        if (node == nullptr) return;
        inorder(node->left);
        cout << node->data << " ";
        inorder(node->right);
    };
    inorder(bst.root);
    cout << endl;

    return 0;
}

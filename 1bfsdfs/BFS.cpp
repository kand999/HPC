#include <iostream>
#include <queue>

class Node {
public:
    Node *left, *right;
    int data;
};

class BreadthFS {
public:
    Node* insert(Node* root, int data);
    void bfs(Node* root);
};

Node* BreadthFS::insert(Node* root, int data) {
    if (!root) {
        root = new Node;
        root->left = NULL;
        root->right = NULL;
        root->data = data;
        return root;
    }

    std::queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        Node* temp = q.front();
        q.pop();

        if (temp->left == NULL) {
            temp->left = new Node;
            temp->left->left = NULL;
            temp->left->right = NULL;
            temp->left->data = data;
            return root;
        } else {
            q.push(temp->left);
        }

        if (temp->right == NULL) {
            temp->right = new Node;
            temp->right->left = NULL;
            temp->right->right = NULL;
            temp->right->data = data;
            return root;
        } else {
            q.push(temp->right);
        }
    }
    return root;
}

void BreadthFS::bfs(Node* root) {
    if (!root) {
        return;
    }

    std::queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        int qSize = q.size();

        for (int i = 0; i < qSize; i++) {
            Node* currNode = q.front();
            q.pop();
            std::cout << "\t" << currNode->data;

            if (currNode->left) {
                q.push(currNode->left);
            }

            if (currNode->right) {
                q.push(currNode->right);
            }
        }
    }
}

int main() {
    Node* root = NULL;
    int data;
    char ans;

    do {
        std::cout << "\nEnter data: ";
        std::cin >> data;
        root = BreadthFS().insert(root, data);
        std::cout << "Do you want to insert one more node? (y/n): ";
        std::cin >> ans;
    } while (ans == 'y' || ans == 'Y');

    BreadthFS().bfs(root);

    return 0;
}

#include <iostream>
#include <queue>
using namespace std;

struct Node {
    int id;
    Node *left, *right;

    Node(int x) {
        id = x;
        left = right = NULL;
    }
};

Node* root = NULL;

void buildTree() {
    int id, l, r;

    cout << "Enter CEO ID: ";
    cin >> id;

    root = new Node(id);

    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        Node* cur = q.front();
        q.pop();

        cout << "Enter left subordinate of "
             << cur->id << " (-1 for none): ";
        cin >> l;

        if (l != -1) {
            cur->left = new Node(l);
            q.push(cur->left);
        }

        cout << "Enter right subordinate of "
             << cur->id << " (-1 for none): ";
        cin >> r;

        if (r != -1) {
            cur->right = new Node(r);
            q.push(cur->right);
        }
    }

    cout << "Company structure created!\n";
}

void displayTree() {
    if (root == NULL) {
        cout << "Structure is empty\n";
        return;
    }

    queue<Node*> q;
    q.push(root);
    int level = 1;

    while (!q.empty()) {
        int n = q.size();

        cout << "Level " << level << ": ";

        for (int i = 0; i < n; i++) {
            Node* cur = q.front();
            q.pop();

            cout << cur->id << " ";

            if (cur->left)
                q.push(cur->left);

            if (cur->right)
                q.push(cur->right);
        }

        cout << endl;
        level++;
    }
}

void classifyNodes() {
    if (root == NULL) {
        cout << "Structure is empty\n";
        return;
    }

    int leaf = 0, one = 0, two = 0;
    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        Node* cur = q.front();
        q.pop();

        if (cur->left == NULL &&
            cur->right == NULL) {
            leaf++;
        }
        else if (cur->left != NULL &&
                 cur->right != NULL) {
            two++;
        }
        else {
            one++;
        }

        if (cur->left)
            q.push(cur->left);

        if (cur->right)
            q.push(cur->right);
    }

    cout << "Leaf Nodes: " << leaf << endl;
    cout << "One-Child Nodes: " << one << endl;
    cout << "Two-Child Nodes: " << two << endl;
    cout << "Total Employees: "
         << leaf + one + two << endl;
}

int main() {
    int choice;

    do {
        cout << "\n--- COMPANY STRUCTURE ---\n";
        cout << "1. Build Structure\n";
        cout << "2. Display Structure\n";
        cout << "3. Classify Nodes\n";
        cout << "4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                buildTree();
                break;

            case 2:
                displayTree();
                break;

            case 3:
                classifyNodes();
                break;

            case 4:
                cout << "Program ended\n";
                break;

            default:
                cout << "Invalid choice\n";
        }

    } while (choice != 4);

    return 0;
}

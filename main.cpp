#include <iostream>
using namespace std;

struct Node {
    int matchstick;
    Node* next;
};

// Create a linked list of matchsticks
Node* createMatchsticks(int n) {
    Node* head = nullptr;
    Node* temp = nullptr;

    for (int i = 1; i <= n; i++) {
        Node* newNode = new Node;
        newNode->matchstick = i;
        newNode->next = nullptr;

        if (head == nullptr) {
            head = newNode;
            temp = newNode;
        } else {
            temp->next = newNode;
            temp = newNode;
        }
    }

    return head;
}

// Count the remaining matchsticks
int countMatchsticks(Node* head) {
    int count = 0;

    while (head != nullptr) {
        count++;
        head = head->next;
    }

    return count;
}

// Display the remaining matchsticks
void displayMatchsticks(Node* head) {
    cout << "\nRemaining matchsticks: ";

    while (head != nullptr) {
        cout << "| ";
        head = head->next;
    }

    cout << '\n';
}

// Remove matchsticks from the beginning
void removeMatchsticks(Node*& head, int n) {
    for (int i = 0; i < n && head != nullptr; i++) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}

// Free the remaining linked list memory
void deleteList(Node*& head) {
    while (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}

int main() {
    Node* head = createMatchsticks(21);
    int player = 1;
    int choice;

    cout << "===== MATCHSTICKS GAME =====\n";
    cout << "Rules:\n";
    cout << "1. Total matchsticks = 21\n";
    cout << "2. Pick 1 to 4 matchsticks per turn\n";
    cout << "3. The player who picks the last matchstick loses\n";

    while (countMatchsticks(head) > 0) {
        displayMatchsticks(head);

        cout << "\nPlayer " << player
             << ", pick matchsticks (1-4): ";

        cin >> choice;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Invalid input! Enter a number.\n";
            continue;
        }

        int remaining = countMatchsticks(head);

        if (choice < 1 || choice > 4) {
            cout << "Invalid choice! Pick between 1 and 4.\n";
            continue;
        }

        if (choice > remaining) {
            cout << "Not enough matchsticks remaining!\n";
            continue;
        }

        removeMatchsticks(head, choice);

        if (head == nullptr) {
            cout << "\nPlayer " << player
                 << " picked the last matchstick(s).\n";

            cout << "Player " << player << " loses!\n";

            cout << "Player " << (player == 1 ? 2 : 1)
                 << " wins!\n";

            break;
        }

        player = (player == 1) ? 2 : 1;
    }

    deleteList(head);
    return 0;
}

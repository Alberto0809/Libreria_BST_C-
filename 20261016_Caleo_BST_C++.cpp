#include <iostream>

struct Node {
    int value;
    Node* childLeft;
    Node* childRight;
};
Node* creaNodo(int val) {
    Node* nuovo = new Node();
    nuovo->value = val;
    nuovo->childLeft = NULL;
    nuovo->childRight = NULL;
    return nuovo;
}
Node* insert(Node* r, int val) {
    if (r == NULL) {
        return creaNodo(val);
    }

    Node* dad = NULL;
    Node* current = r;

    while (current != NULL) {
        dad = current;

        if (val < current->value) {
            current = current->childLeft;
        } 
        else if (val > current->value) {
            current = current->childRight;
        } 
        else {
            return r;
        }
    }

    if (val < dad->value) {
        dad->childLeft = creaNodo(val);
    } 
    else {
        dad->childRight = creaNodo(val);
    }

    return r;
}

int main() {
    Node* radice = NULL;
    radice = insert(radice, 10);
    radice = insert(radice, 5);
    radice = insert(radice, 15);

    std::cout << "Albero creato con successo!" << std::endl;

    return 0;
}

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

Node* findMin(Node* r) {
    if (r == NULL) {
        return NULL;
    }

    Node* current = r;
    while (current->childLeft != NULL) {
        current = current->childLeft;
    }

    return current;
}

Node* findMax(Node* r) {
    if (r == NULL) {
        return NULL;
    }

    Node* current = r;
    while (current->childRight != NULL) {
        current = current->childRight;
    }

    return current;
}

int countNodes(Node* r) {
    if (r == NULL) {
        return 0;
    }
    return 1 + countNodes(r->childLeft) + countNodes(r->childRight);
}

int countLeaves(Node* r) {
    if (r == NULL) {
        return 0;
    }
    if (r->childLeft == NULL && r->childRight == NULL) {
        return 1;
    }
    return countLeaves(r->childLeft) + countLeaves(r->childRight);
}

int countInRange(Node* r, int min, int max) {
    if (r == NULL) {
        return 0;
    }

    if (r->value < min) {
        return countInRange(r->childRight, min, max);
    }
    if (r->value > max) {
        return countInRange(r->childLeft, min, max);
    }

    return 1 + countInRange(r->childLeft, min, max) + countInRange(r->childRight, min, max);
}

int main() {
    Node* radice = NULL;

    radice = insert(radice, 10);
    radice = insert(radice, 5);
    radice = insert(radice, 15);
    radice = insert(radice, 2);
    radice = insert(radice, 7);
    radice = insert(radice, 12);
    radice = insert(radice, 20);

    Node* minNodo = findMin(radice);
    Node* maxNodo = findMax(radice);

    if (minNodo != NULL) {
        std::cout << "Minimo: " << minNodo->value << std::endl;
    }

    if (maxNodo != NULL) {
        std::cout << "Massimo: " << maxNodo->value << std::endl;
    }

    std::cout << "Totale nodi: " << countNodes(radice) << std::endl;
    std::cout << "Totale foglie: " << countLeaves(radice) << std::endl;
    std::cout << "Nodi compresi tra 6 e 16: " << countInRange(radice, 6, 16) << std::endl;

    return 0;
}
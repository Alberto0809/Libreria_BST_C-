include <iostream>
using namespace std;

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
        cout << "Minimo: " << minNodo->value << endl;
    }

    if (maxNodo != NULL) {
        cout << "Massimo: " << maxNodo->value << endl;
    }

    cout << "Totale nodi: " << countNodes(radice) << endl;
    cout << "Totale foglie: " << countLeaves(radice) << endl;
    cout << "Nodi compresi tra 6 e 16: " << countInRange(radice, 6, 16) << endl;

    return 0;
}
}

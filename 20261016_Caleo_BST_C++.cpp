#include <iostream>
#include <algorithm>
using namespace std;

// =====================================================================
// PARTE A - La classe Node
// =====================================================================

class Node {
private:
    int data;
    Node* left;
    Node* right;

public:
    
    Node(int d) {
        data = d;
        left = nullptr;
        right = nullptr;
    }

    int getData() const { return data; }
    void setData(int d) { data = d; }

    Node* getLeft() const { return left; }
    Node* getRight() const { return right; }

    void setLeft(Node* l) { left = l; }
    void setRight(Node* r) { right = r; }

    bool isLeaf() const { 
        return (left == nullptr && right == nullptr); 
    }
};

// =====================================================================
// PARTE B e C - La classe BST
// =====================================================================

class BST {
private:
    Node* root;
    int numNodi;

   
    
    void inOrderRic(Node* p) const {
        if (p == nullptr) return;
        inOrderRic(p->getLeft());
        cout << p->getData() << " ";
        inOrderRic(p->getRight());
    }

    int altezzaRic(Node* p) const {
        if (p == nullptr) return 0;
        return 1 + max(altezzaRic(p->getLeft()), altezzaRic(p->getRight()));
    }

    int contaFoglieRic(Node* p) const {
        if (p == nullptr) return 0;
        if (p->isLeaf()) return 1;
        return contaFoglieRic(p->getLeft()) + contaFoglieRic(p->getRight());
    }

    int contaIntervalloRic(Node* p, int low, int high) const {
        if (p == nullptr) return 0;
        int count = 0;
        if (p->getData() >= low && p->getData() <= high) count = 1;
        if (p->getData() > low) count += contaIntervalloRic(p->getLeft(), low, high);
        if (p->getData() < high) count += contaIntervalloRic(p->getRight(), low, high);
        return count;
    }

    void svuotaRic(Node* p) {
        if (p == nullptr) return;
        svuotaRic(p->getLeft());
        svuotaRic(p->getRight());
        delete p;
    }

    Node* rimuoviRic(Node* p, int val, bool &trovato) {
        if (p == nullptr) return nullptr;

        if (val < p->getData()) {
            p->setLeft(rimuoviRic(p->getLeft(), val, trovato));
        } else if (val > p->getData()) {
            p->setRight(rimuoviRic(p->getRight(), val, trovato));
        } else {
            trovato = true;
            if (p->getLeft() == nullptr) {
                Node* temp = p->getRight();
                delete p;
                return temp;
            } else if (p->getRight() == nullptr) {
                Node* temp = p->getLeft();
                delete p;
                return temp;
            }
            Node* minDx = p->getRight();
            while (minDx->getLeft() != nullptr) minDx = minDx->getLeft();
            p->setData(minDx->getData());
            bool dummy = false;
            p->setRight(rimuoviRic(p->getRight(), minDx->getData(), dummy));
        }
        return p;
    }

public:
    
    BST() {
        root = nullptr;
        numNodi = 0;
    }
    ~BST() { svuota(); }

 
    bool isEmpty() const { return root == nullptr; }
    int size() const { return numNodi; }

  
    bool insert(int key) {
        if (root == nullptr) {
            root = new Node(key);
            numNodi++;
            return true;
        }
        Node* current = root;
        Node* parent = nullptr;
        while (current != nullptr) {
            parent = current;
            if (key == current->getData()) return false;
            if (key < current->getData()) current = current->getLeft();
            else current = current->getRight();
        }
        if (key < parent->getData()) parent->setLeft(new Node(key));
        else parent->setRight(new Node(key));
        numNodi++;
        return true;
    }

    // Ricerca e Visita
    bool search(int key) const {
        Node* current = root;
        while (current != nullptr) {
            if (key == current->getData()) return true;
            if (key < current->getData()) current = current->getLeft();
            else current = current->getRight();
        }
        return false;
    }

    void inOrder() const { inOrderRic(root); }
    int height() const { return altezzaRic(root); }

    int minimo() const {
        if (root == nullptr) return -1;
        Node* p = root;
        while (p->getLeft() != nullptr) p = p->getLeft();
        return p->getData();
    }

    int massimo() const {
        if (root == nullptr) return -1;
        Node* p = root;
        while (p->getRight() != nullptr) p = p->getRight();
        return p->getData();
    }

    int contaFoglie() const { return contaFoglieRic(root); }
    int contaIntervallo(int low, int high) const { return contaIntervalloRic(root, low, high); }

    bool remove(int key) {
        bool trovato = false;
        root = rimuoviRic(root, key, trovato);
        if (trovato) numNodi--;
        return trovato;
    }

    void svuota() {
        svuotaRic(root);
        root = nullptr;
        numNodi = 0;
    }
};

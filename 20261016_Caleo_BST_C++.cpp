
 
#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
using namespace std;

struct Node{
    int data;
    Node* l_child;
    Node* r_child;
    Node(int n){
        data = n;
        l_child = r_child = nullptr;
    }
};

Node* insert(Node* root, int valore);
bool search(Node* root, int valore);
Node* findMin(Node* root);
Node* findMax(Node* root);
int countNodes(Node* root);
int countLeaves(Node* root);
int countInRange(Node* root, int min, int max);

int main(){
    
    system("PAUSE");
    return 0;
}

Node* insert(Node* root, int valore){
    if(root == nullptr){
        return new Node(valore);
    }
    if(root->data == valore){
        return root;
    }

    if(valore > root->data){
        root->r_child = insert(root->r_child, valore);
    }else{
        root->l_child = insert(root->l_child, valore);
    }

    return root;
}

bool search(Node* root, int valore){
    while(root != nullptr){
        if(root->data == valore){
            return true;
        }

        if(valore > root->data){
            root = root->r_child;
        }else{
            root = root->l_child;
        }
    }
    return false;
}
Node* findMin(Node* root){
    if(root == nullptr){
        return nullptr;
    }
    Node* current = root;
    while(current->l_child != nullptr){
        current = current->l_child;
    }
    return current;

}
Node* findMax(Node* root){
    if(root == nullptr){
        return nullptr;
    }
    Node* current = root;
    while(current->r_child != nullptr){
        current = current->r_child;
    }
    return current;

}

int countNodes(Node* root){
    if(root == nullptr){
        return 0;
    }
    return 1 + countNodes(root->l_child) + countNodes(root->r_child);
}

int countLeaves(Node* root){
    if(root == nullptr){
        return 0;
    }
    if(root->l_child == nullptr && root->r_child == nullptr){
        return 1;
    }
    return countLeaves(root->l_child) + countLeaves(root->r_child);
}

int countInRange(Node* root, int min, int max){
    if(root == nullptr){
        return 0;
    }
    if(root->data < min){
        return countInRange(root->r_child, min, max);
    }else if(root->data > max){
        return countInRange(root->l_child, min, max);
    }else{
        return 1 + countInRange(root->l_child, min, max) + countInRange(root->r_child, min, max);
    }
}

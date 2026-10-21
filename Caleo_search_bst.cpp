#include <iostream>

struct Nodo {
    int valore;
    Nodo* sinistra;
    Nodo* destra;
};

Nodo* creaNodo(int valore) {
    Nodo* nuovoNodo = new Nodo();
    nuovoNodo->valore = valore;
    nuovoNodo->sinistra = nullptr;
    nuovoNodo->destra = nullptr;
    return nuovoNodo;
}

Nodo* inserisci(Nodo* radice, int valore) {
    if (radice == nullptr) {
        return creaNodo(valore);
    }
    if (valore < radice->valore) {
        radice->sinistra = inserisci(radice->sinistra, valore);
    } else if (valore > radice->valore) {
        radice->destra = inserisci(radice->destra, valore);
    }
    return radice;
}

Nodo* cerca(Nodo* radice, int valoreCercato) {
    if (radice == nullptr) {
        return nullptr;
    }
    
    if (radice->valore == valoreCercato) {
        return radice;
    }
    
    if (valoreCercato < radice->valore) {
        return cerca(radice->sinistra, valoreCercato);
    } else {
        return cerca(radice->destra, valoreCercato);
    }
}

int main() {
    Nodo* radice = nullptr;
    
    radice = inserisci(radice, 50);
    inserisci(radice, 30);
    inserisci(radice, 70);
    inserisci(radice, 20);
    inserisci(radice, 40);
    inserisci(radice, 60);
    inserisci(radice, 80);

    Nodo* risultato = cerca(radice, 40);

    if (risultato != nullptr) {
        std::cout << "Trovato" << std::endl;
    } else {
        std::cout << "Non trovato" << std::endl;
    }

    return 0;
}
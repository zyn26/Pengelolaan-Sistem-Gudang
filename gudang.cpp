#include "gudang.h"

address alokasi(infotype x, int s = 0) {
    address P = new tNode;
    if (P != nullptr) {
        P->info = x;
        P->stok = s;
        P->firstChild = nullptr;
        P->nextSibling = nullptr;
    }
    return P;
}

address findNode(address root, infotype x) {
    if (root == nullptr) return nullptr;
    if (root->info == x) return root;
    address hasil = findNode(root->firstChild, x);
    if (hasil != nullptr) return hasil;
    return findNode(root->nextSibling, x);
}

void insertNode(address &root, infotype parentName, infotype childName, int s = 0) {
    if (root == nullptr) {
        root = alokasi(childName, s);
    } else {
        address P = findNode(root, parentName);
        if (P != nullptr) {
            address newNode = alokasi(childName, s);
            if (P->firstChild == nullptr) {
                P->firstChild = newNode;
            } else {
                address last = P->firstChild;
                while (last->nextSibling != nullptr) {
                    last = last->nextSibling;
                }
                last->nextSibling = newNode;
            }
        }
    }
}

// DATA DUMMY SEDERHANA (HANYA 2 ZONA)
void isiDataDummy(address &root) {
    insertNode(root, "", "Gudang Pusat", 0);

    // Zona 1
    insertNode(root, "Gudang Pusat", "Zona Elektronik", 0);
    insertNode(root, "Zona Elektronik", "Rak Laptop", 0);
    insertNode(root, "Rak Laptop", "MacBook Air", 10);

    // Zona 2
    insertNode(root, "Gudang Pusat", "Zona Furniture", 0);
    insertNode(root, "Zona Furniture", "Rak Kursi", 0);
    insertNode(root, "Rak Kursi", "Kursi Gaming", 5);
}

void printPreOrder(address root, int level = 0) {
    if (root != nullptr) {
        for (int i = 0; i < level; i++) cout << "   ";
        cout << "|-- " << root->info;
        if (root->stok > 0) cout << " [Stok: " << root->stok << "]";
        cout << endl;
        printPreOrder(root->firstChild, level + 1);
        printPreOrder(root->nextSibling, level);
    }
}

void printInOrder(address root) {
    if (root != nullptr) {
        printInOrder(root->firstChild);
        cout << "[" << root->info << "] ";
        printInOrder(root->nextSibling);
    }
}

void printPostOrder(address root) {
    if (root != nullptr) {
        printPostOrder(root->firstChild);
        printPostOrder(root->nextSibling);
        cout << "[" << root->info << "] ";
    }
}

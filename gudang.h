#ifndef GUDANG_H
#define GUDANG_H

#include <iostream>
#include <string>

using namespace std;

typedef string infotype;
typedef struct tNode *address;

struct tNode {
    infotype info;
    int stok;
    address firstChild;
    address nextSibling;
};

address alokasi(infotype x, int s);
address findNode(address root, infotype x);
void insertNode(address &root, infotype parentName, infotype childName, int s);
void isiDataDummy(address &root);

void printPreOrder(address root, int level);
void printInOrder(address root);
void printPostOrder(address root);

#endif

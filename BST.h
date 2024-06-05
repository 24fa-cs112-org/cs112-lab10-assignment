/* BST.h declares a "classic" binary search tree of linked nodes.
 * Joel Adams, for CS 112 at Calvin University.
 */

#ifndef BST_H_
#define BST_H_

#include <iostream>

#include "Exception.h"
using namespace std;

template <class Item>
class BST {
public:
    BST();
    virtual ~BST();
    bool isEmpty() const;
    unsigned getNumItems() const;
    void traversePreorder(ostream& out) const;

    // This stuff below should be private: but because
    // we need to access it for testing, we leave it as public.
public:
    struct Node {
        Node(const Item& it);
        virtual ~Node();

        void traversePreorder(ostream& out) const;
        virtual void processItem(ostream& out) const;

        Item myItem;
        Node* myLeft;
        Node* myRight;
    };

    Node* myRoot;
    unsigned myNumItems;
};

template <class Item>
BST<Item>::BST() {
    myRoot = nullptr;
    myNumItems = 0;
}

template <class Item>
BST<Item>::~BST() {
    delete myRoot;
}

template <class Item>
BST<Item>::Node::Node(const Item& it) {
    myItem = it;
    myLeft = nullptr;
    myRight = nullptr;
}

template <class Item>
BST<Item>::Node::~Node() {
    delete myLeft;
    delete myRight;
}

template <class Item>
bool BST<Item>::isEmpty() const {
    return myNumItems == 0;
}

template <class Item>
unsigned BST<Item>::getNumItems() const {
    return myNumItems;
}

template <class Item>
void BST<Item>::Node::processItem(ostream& out) const {
    out << ' ' << myItem;
}

template <class Item>
void BST<Item>::traversePreorder(ostream& out) const {
    if (!isEmpty()) {
        myRoot->traversePreorder(out);
    }
}

template <class Item>
void BST<Item>::Node::traversePreorder(ostream& out) const {
    // 1. process myItem first (preorder)
    processItem(out);
    // 2. then recursively process the items in the left subtree
    if (myLeft != nullptr) {
        myLeft->traversePreorder(out);
    }
    // 3. then recursively process the items in the right subtree
    if (myRight != nullptr) {
        myRight->traversePreorder(out);
    }
}

#endif /*BST_H_*/

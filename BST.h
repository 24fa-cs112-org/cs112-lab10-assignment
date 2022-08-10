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
    void traversePreorder() const;

    // This stuff below should be private: but because
    // we need to access it for testing, we leave it as public.
public:
    struct Node {
        Node(const Item& it);
        virtual ~Node();

        void traversePreorder() const;
        virtual void processItem();

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
    myRoot = nullptr;
    myNumItems = 0;
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
void BST<Item>::Node::processItem() {
    cout << ' ' << myItem;
}

template <class Item>
void BST<Item>::traversePreorder() const {
    if (!isEmpty()) {
        myRoot->traversePreorder();
    }
}

template <class Item>
void BST<Item>::Node::traversePreorder() const {
    // 1. process myItem first (preorder)
    processItem();
    // 2. then recursively process the items in the left subtree
    if (myLeft != nullptr) {
        myLeft->traversePreorder();
    }
    // 3. then recursively process the items in the right subtree
    if (myRight != nullptr) {
        myRight->traversePreorder();
    }
}

#endif /*BST_H_*/

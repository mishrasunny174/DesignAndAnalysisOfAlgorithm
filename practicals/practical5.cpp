#include<iostream>

using namespace std;

enum Color{
    RED,BLACK
};

class RBTreeNode{
    int value;
    RBTreeNode* parent;
    RBTreeNode* leftChild;
    RBTreeNode* rightChild;
    Color color;
    RBTreeNode(int value, RBTreeNode* parent=NULL) {
        this->color = RED;
        this->leftChild = NULL;
        this->rightChild = NULL;
        this->value = value;
        this->parent = parent;
    }
    friend class RBTree;
};

class RBTree{
    RBTreeNode* root;
protected:
    void insert(RBTreeNode* node, int value);
    void leftRotate(RBTreeNode* node);
    void rightRotate(RBTreeNode* node);
    void traverse(RBTreeNode* node);
    void fixup(RBTreeNode* node);
    string getColor(Color color) {
        if(color == RED) 
            return "RED";
        return "BLACK";
    }
public:
    RBTree() {
        this->root = NULL;
    }
    void insert(int value) {
        if(this->root == NULL) {
            this->root = new RBTreeNode(value);
            this->root->color = BLACK;
        } else {
            insert(this->root, value);
        }
    }
    void traverse(){
        if(this->root == NULL) {
            cout<<"ERROR: tree is empty"<<endl;
        } else {
            cout<<"Inorder traversal is: ";
            this->traverse(this->root);
            cout<<endl;
        }
    }
    void search(int value) {
        if(this->root==NULL) {
            cout<<"ERROR: tree is empty";
        } else {
            RBTreeNode *node = this->root;
            while(node!=NULL) {
                if(node->value == value) {
                    cout<<value<<" found in the tree, the node has color "<<this->getColor(node->color)<<endl;
                    return;
                } else if(value < node->value) {
                    node = node->leftChild;
                } else {
                    node = node->rightChild;
                }
            }
            cout<<value<<" not found in the tree"<<endl;
        }
    }
};

int main(int argc, char** argv){
    RBTree tree;
    int choice, value;
    while(true) {
        cout<<"\n### MENU ###"<<endl<<endl;
        cout<<"1) Insert a new element"<<endl;
        cout<<"2) Traverse (inorder the tree)"<<endl;
        cout<<"3) Search for a element in tree"<<endl;
        cout<<"Enter 0 to exit..."<<endl;
        cout<<"Enter you choice: ";
        cin>>choice;
        switch (choice)
        {
            case 0:
                return 0;
            case 1:
                cout<<"Enter item to be inserted: ";
                cin>>value;
                tree.insert(value);
                break;
            case 2:
                tree.traverse();
                break;
            case 3:
                cout<<"Enter item to be searched: ";
                cin>>value;
                tree.search(value);
                break;
            default:
                cout<<"ERROR: wrong choice try again..."<<endl;
                break;
        }
    }
    return 0;
}

void RBTree::insert(RBTreeNode* node, int value) {
    if(value < node->value) {
        if(node->leftChild == NULL) {
            node->leftChild = new RBTreeNode(value, node);
            this->fixup(node->leftChild);
        } else {
            this->insert(node->leftChild, value);
        }
    } else {
        if(node->rightChild == NULL) {
            node->rightChild = new RBTreeNode(value, node);
            this->fixup(node->rightChild);
        } else {
            this->insert(node->rightChild, value);
        }
    }
}

void RBTree::fixup(RBTreeNode* node) {
    RBTreeNode *uncle = NULL;
    while(  node != this->root &&
            node->parent->color == RED) 
    {
        if(node->parent == node->parent->parent->leftChild) {
            uncle = node->parent->parent->rightChild;
            if(uncle != NULL && uncle->color == RED) {
                uncle->color = BLACK;
                node->parent->color = BLACK;
                node->parent->parent->color = RED;
                node = node->parent->parent;
            } else {
                if(node == node->parent->rightChild) {
                    node = node->parent;
                    leftRotate(node);
                }
                node->parent->color = BLACK;
                node->parent->parent->color = RED;
                rightRotate(node->parent->parent);
            }
        } else {
            uncle = node->parent->parent->leftChild;
            if(uncle != NULL && uncle->color == RED) {
                uncle->color = BLACK;
                node->parent->color = BLACK;
                node->parent->parent->color = RED;
                node = node->parent->parent;
            } else {
                if(node == node->parent->leftChild) {
                    node=node->parent;
                    rightRotate(node);
                }
                node->parent->color = BLACK;
                node->parent->parent->color = RED;
                leftRotate(node->parent->parent);
            }
        }
    }
    this->root->color = BLACK;
}

void RBTree::leftRotate(RBTreeNode* node) {
    RBTreeNode *temp = node->rightChild;
    node->rightChild = temp->leftChild;
    if(node->rightChild != NULL)
        node->rightChild->parent = node;
    if(node==this->root)
        this->root = temp;
    else if(node == node->parent->leftChild) 
        node->parent->leftChild = temp;
    else
        node->parent->rightChild = temp;
    node->parent = temp;
    temp->leftChild = node;
}

void RBTree::rightRotate(RBTreeNode* node) {
    RBTreeNode* temp = node->leftChild;
    node->leftChild = temp->rightChild;
    if(node->leftChild!=NULL)
        node->leftChild->parent = node;
    if(node == this->root)
        this->root = temp;
    else if(node == node->parent->leftChild)
        node->parent->leftChild = temp;
    else 
        node->parent->rightChild = temp;
    node->parent = temp;
    temp->rightChild = node;
}

void RBTree::traverse(RBTreeNode* node) {
    if(node->leftChild!=NULL) {
        this->traverse(node->leftChild);
    }
    cout<<node->value<<":"<<this->getColor(node->color)<<" ";
    if(node->rightChild!=NULL) {
        this->traverse(node->rightChild);
    }
}
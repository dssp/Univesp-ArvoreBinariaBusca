#include <iostream>
#include "student.h"


struct Node{
    Student student;
    Node* leftNode;
    Node* rightNode;
};

class BSTree{
    private:
    Node* root;    

    public:
    BSTree();
    ~BSTree();
    Node* getRoot();
    bool isFull();
    bool isEmpty();
    void add(Student student);
    void remove(Student student);
    void search(Student& student, bool& busca);
    void remSearch(Student student, Node*& nodeActual);
    void deletNode(Node*& nodeActual);
    void getSucessor(Student& studentSucessor, Node* t);
    void deletTree(Node* nodeActual);
    void printPreOrden(Node* nodeActual);
    void printInOrden(Node* nodeActual);
    void printPosOrden(Node* nodeActual);
    void printNodes(Node* nodeActual);
    void printNode(Node* nodeActual);
    void printNode(Student student);
    void printMsg(string msg);
};
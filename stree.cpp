#include <iostream>
#include <string>
#include <cstddef>
#include "stree.h"

using namespace std;

BSTree::BSTree()
{
    root = NULL;
}

BSTree::~BSTree()
{
    deletTree(root);
}

Node *BSTree::getRoot()
{
    return root;
}

bool BSTree::isFull()
{
    try
    {
        Node *t = new Node;
        delete t;
        return false;
    }
    catch (bad_alloc exception)
    {
        return true;
    }
}

bool BSTree::isEmpty()
{
    return (root == NULL);
}

void BSTree::add(Student student)
{
    if (isFull())
    {
        printMsg("A arvore esta cheia.");
    }
    else
    {
        bool alreadyAdded = false;
        Node *NewNode = new Node;
        NewNode->student = student;
        NewNode->rightNode = NULL;
        NewNode->leftNode = NULL;
        if (root == NULL)
        {
            root = NewNode;
        }
        else
        {
            Node *t = root;
            while (t != NULL)
            {
                if (student.GetRa() < t->student.GetRa())
                {
                    if (t->leftNode == NULL)
                    {
                        t->leftNode = NewNode;
                        break;
                    }
                    else
                    {
                        t = t->leftNode;
                    }
                }
                else if (student.GetRa() > t->student.GetRa())
                {
                    if (t->rightNode == NULL)
                    {
                        t->rightNode = NewNode;
                        break;
                    }
                    else
                    {
                        t = t->rightNode;
                    }
                }
                else if (student.GetRa() == t->student.GetRa())
                {
                    alreadyAdded = true;
                    break;
                }
            }
        }
        if (!alreadyAdded)
        {
            printNode(NewNode);
        }
        else
        {
            printMsg("RA ja cadastrado, tente outro.");
        }
    }
}

void BSTree::remove(Student student)
{
    if (isEmpty())
    {
        printMsg("A arvore esta vazia.");
    }
    else
    {
        remSearch(student, root);
    }
}

void BSTree::remSearch(Student student, Node *&nodeActual)
{
    if (nodeActual != NULL)
    {
        if (student.GetRa() < nodeActual->student.GetRa())
        {
            remSearch(student, nodeActual->leftNode);
        }
        else if (student.GetRa() > nodeActual->student.GetRa())
        {
            remSearch(student, nodeActual->rightNode);
        }
        else if (student.GetRa() == nodeActual->student.GetRa())
        {
            printNode(nodeActual);
            deletNode(nodeActual);
        }
    }
    else
    {
        printMsg("Student nao encontrado.");
    }
}

void BSTree::deletNode(Node *&nodeActual)
{
    Node *temp = nodeActual;
    if (nodeActual->leftNode == NULL)
    {
        nodeActual = nodeActual->rightNode;
        delete temp;
    }
    else if (nodeActual->rightNode == NULL)
    {
        nodeActual = nodeActual->leftNode;
        delete temp;
    }
    else
    {
        Student studentSucessor;
        getSucessor(studentSucessor, nodeActual);
        nodeActual->student = studentSucessor;
        remSearch(studentSucessor, nodeActual->rightNode);
    }
}

void BSTree::getSucessor(Student &studentSucessor, Node *t)
{
    t = t->rightNode;
    while (t->leftNode != NULL)
    {
        t = t->leftNode;
    }
    studentSucessor = t->student;
}

void BSTree::search(Student &student, bool &busca)
{
    busca = false;
    Node *nodeActual = root;
    while (nodeActual != NULL)
    {
        if (student.GetRa() < nodeActual->student.GetRa())
        {
            nodeActual = nodeActual->leftNode;
        }
        else if (student.GetRa() > nodeActual->student.GetRa())
        {
            nodeActual = nodeActual->rightNode;
        }
        else
        {
            busca = true;
            student = nodeActual->student;
            break;
        }
    }
}

void BSTree::deletTree(Node *nodeActual)
{
    if (nodeActual != NULL)
    {
        deletTree(nodeActual->leftNode);

        deletTree(nodeActual->rightNode);

        delete nodeActual;
    }
}

void BSTree::printPreOrden(Node *nodeActual)
{
    if (nodeActual != NULL)
    {
        printNodes(nodeActual);

        printPreOrden(nodeActual->leftNode);

        printPreOrden(nodeActual->rightNode);
    }
}

void BSTree::printInOrden(Node *nodeActual)
{
    if (nodeActual != NULL)
    {
        printInOrden(nodeActual->leftNode);

        printNodes(nodeActual);

        printInOrden(nodeActual->rightNode);
    }
}

void BSTree::printPosOrden(Node *nodeActual)
{
    if (nodeActual != NULL)
    {
        printPosOrden(nodeActual->leftNode);

        printPosOrden(nodeActual->rightNode);

        printNodes(nodeActual);
    }
}

void BSTree::printNodes(Node *nodeActual)
{
    cout << "RA " << nodeActual->student.GetRa() << " - " << nodeActual->student.GetName() << endl;
}

void BSTree::printNode(Node *nodeActual)
{
    string x = "RA " + to_string(nodeActual->student.GetRa()) + " - " + nodeActual->student.GetName();
    printMsg(x);
}

void BSTree::printNode(Student Student)
{
    string x = "RA " + to_string(Student.GetRa()) + " - " + Student.GetName();
    printMsg(x);
}

void BSTree::printMsg(string msg)
{
    cout << "--------------------------------------" << endl;
    cout << msg << endl;
    cout << "--------------------------------------" << endl;
}
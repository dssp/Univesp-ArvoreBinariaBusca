#include <iostream>
#include <string>
#include "stree.h"

using namespace std;

    void StartMsg(BSTree b){
        system("CLS");
        cout << "Programa gerador de Arvore de Busca Binaria!" << endl;
        b.printMsg("by Durval Sproesser");
    };


int main()
{
    BSTree studentTree;
    int option, ra;
    string name;
    bool search;
    system("CLS");

    StartMsg(studentTree);

    do
    {
        cout << "Digite 0 para parar o programa." << endl;
        cout << "Digite 1 para inserir um aluno." << endl;
        cout << "Digite 2 para remover um aluno." << endl;
        cout << "Digite 3 para buscar um aluno." << endl;
        cout << "Digite 4 para imprimir a Arvore em Pre-Ordem." << endl;
        cout << "Digite 5 para imprimir a Arvore em Ordem" << endl;
        cout << "Digite 6 para imprimir a Arvore em Pos-Ordem" << endl;
        cout << "Digite 9 para limpar a tela" << endl;
        cout << "--------------------------------------" << endl;
        cout << ">>> ";

        cin >> option;

        system("CLS");

        if (option == 1)
        {
            cout << "Digite o RA do aluno: ";
            cin >> ra;
            cout << "Digite o Nome do aluno: ";
            cin >> name;
            Student student(ra, name);
            studentTree.add(student);
        }
        if (option == 2)
        {
            cout << "Digite o RA do aluno: ";
            cin >> ra;
            Student student(ra, "");
            studentTree.remove(student);
        }
        if (option == 3)
        {
            cout << "Digite o RA do aluno: ";
            cin >> ra;
            Student student(ra, "");
            studentTree.search(student, search);
            if (search)
            {
                studentTree.printNode(student);
            }
            else
            {
                studentTree.printMsg("Aluno nao encontrado.");
            }
        }
        if (option == 4)
        {
            if (studentTree.isEmpty())
            {
                studentTree.printMsg("A arvore esta vazia.");
            }
            else
            {
                studentTree.printMsg("Impressao da Arvore em Pre-ordem");
                studentTree.printPreOrden(studentTree.getRoot());
                cout << "--------------------------------------" << endl;
            }
        }
        if (option == 5)
        {
            if (studentTree.isEmpty())
            {
                studentTree.printMsg("A arvore esta vazia.");
            }
            else
            {
                studentTree.printMsg("Impressao da Arvore em Ordem");
                studentTree.printInOrden(studentTree.getRoot());
                cout << "--------------------------------------" << endl;
            }
        }
        if (option == 6)
        {
            if (studentTree.isEmpty())
            {
                studentTree.printMsg("A arvore esta vazia.");
            }
            else
            {
                studentTree.printMsg("Impressao da Arvore em Pos-ordem");
                studentTree.printPosOrden(studentTree.getRoot());
                cout << "--------------------------------------" << endl;
            }
        }
        if(option == 9){
            StartMsg(studentTree);
        }
    } while (option != 0);

    return 0;
}

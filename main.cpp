#include <iostream>
#include <vector>
#include <windows.h>
#include <chrono>
#include "funcoesOrdenacao.cpp"

using namespace std;
using namespace chrono;

int main()
{
    UINT CPAGE_UTF8 = 65001;
    SetConsoleOutputCP(CPAGE_UTF8);

    int escolhaMetodo;
    int escolhaArq;

    unsigned long long trocas = 0;
    unsigned long long comp = 0;

    vector<int> vetorInt;
    vector<string> vetorString;

    menuMetodos();
    cin >> escolhaMetodo;
    if (escolhaMetodo > 0 && escolhaMetodo < 7) // if para validar a escolha do usuário (método de ordenação).
    {
        menuArquivos();
        cin >> escolhaArq;
        if (escolhaMetodo == 1) // Todos as estruturas de if a partir daqui combinam a escolha do usuário em relação ao método com
                                // o arquivo que o usuário deseja ordenar.
        {
            if (escolhaArq >= 1 && escolhaArq <= 6) // Menu 1
            {
                limpaTela();
                cout << "Ordenando...\n\n\n";
                vetorString = listaString(arqDicionario[escolhaArq - 1]);
                steady_clock::time_point t1 = steady_clock::now();
                bubbleSortString(vetorString, &trocas, &comp);
                steady_clock::time_point t2 = steady_clock::now();
                duration<double> time_span = duration_cast<duration<double>>(t2 - t1);

                // As linhas que possuem funções da biblioteca <chrono> servem para contar o tempo que o algoritmo demora
                // para ordenar um dado arquivo, retornando o tempo total em segundos.

                imprimeVetorString(vetorString);
                cout << "Comparações: " << comp << endl;
                cout << "Trocas: " << trocas << endl;
                cout << "Tempo de ordenação: " << time_span.count() << "s\n\n";
                criaArquivo(time_span.count(), comp, trocas, vetorString.size(), "Bubble Sort");
            }
            if (escolhaArq >= 7 && escolhaArq <= 22) // Menu 2
            {
                limpaTela();
                cout << "Ordenando...\n\n\n";
                vetorInt = listaInt(arqNum[escolhaArq - 7]);
                steady_clock::time_point t1 = steady_clock::now();
                bubbleSortInt(vetorInt, &trocas, &comp);
                steady_clock::time_point t2 = steady_clock::now();
                duration<double> time_span = duration_cast<duration<double>>(t2 - t1);
                imprimeVetorInt(vetorInt);
                cout << "Comparações: " << comp << endl;
                cout << "Trocas: " << trocas << endl;
                cout << "Tempo de ordenação: " << time_span.count() << "s\n\n";
                criaArquivo(time_span.count(), comp, trocas, vetorInt.size(), "Bubble Sort");
            }
        }

        if (escolhaMetodo == 2)
        {
            if (escolhaArq >= 1 && escolhaArq <= 6)
            {
                limpaTela();
                cout << "Ordenando...\n\n\n";
                vetorString = listaString(arqDicionario[escolhaArq - 1]);
                steady_clock::time_point t1 = steady_clock::now();
                insertionSortString(vetorString, &trocas, &comp);
                steady_clock::time_point t2 = steady_clock::now();
                duration<double> time_span = duration_cast<duration<double>>(t2 - t1);
                imprimeVetorString(vetorString);
                cout << "Comparações: " << comp << endl;
                cout << "Trocas: " << trocas << endl;
                cout << "Tempo de ordenação: " << time_span.count() << "s\n\n";
                criaArquivo(time_span.count(), comp, trocas, vetorString.size(), "Insertion Sort");
            }
            if (escolhaArq >= 7 && escolhaArq <= 22)
            {
                limpaTela();
                cout << "Ordenando...\n\n\n";
                vetorInt = listaInt(arqNum[escolhaArq - 7]);
                steady_clock::time_point t1 = steady_clock::now();
                insertionSortInt(vetorInt, &trocas, &comp);
                steady_clock::time_point t2 = steady_clock::now();
                duration<double> time_span = duration_cast<duration<double>>(t2 - t1);
                imprimeVetorInt(vetorInt);
                cout << "Comparações: " << comp << endl;
                cout << "Trocas: " << trocas << endl;
                cout << "Tempo de ordenação: " << time_span.count() << "s\n\n";
                criaArquivo(time_span.count(), comp, trocas, vetorInt.size(), "Insertion Sort");
            }
        }

        if (escolhaMetodo == 3)
        {
            if (escolhaArq >= 1 && escolhaArq <= 6)
            {
                limpaTela();
                cout << "Ordenando...\n\n\n";
                vetorString = listaString(arqDicionario[escolhaArq - 1]);
                steady_clock::time_point t1 = steady_clock::now();
                mergeSortString(vetorString, 0, vetorString.size() - 1, &trocas, &comp);
                steady_clock::time_point t2 = steady_clock::now();
                duration<double> time_span = duration_cast<duration<double>>(t2 - t1);
                imprimeVetorString(vetorString);
                cout << "Comparações: " << comp << endl;
                cout << "Trocas: " << trocas << endl;
                cout << "Tempo de ordenação: " << time_span.count() << "s\n\n";
                criaArquivo(time_span.count(), comp, trocas, vetorString.size(), "Merge Sort");
            }
            if (escolhaArq >= 7 && escolhaArq <= 22)
            {
                limpaTela();
                cout << "Ordenando...\n\n\n";
                vetorInt = listaInt(arqNum[escolhaArq - 7]);
                steady_clock::time_point t1 = steady_clock::now();
                mergeSortInt(vetorInt, 0, vetorInt.size() - 1, &trocas, &comp);
                steady_clock::time_point t2 = steady_clock::now();
                duration<double> time_span = duration_cast<duration<double>>(t2 - t1);
                imprimeVetorInt(vetorInt);
                cout << "Comparações: " << comp << endl;
                cout << "Trocas: " << trocas << endl;
                cout << "Tempo de ordenação: " << time_span.count() << "s\n\n";
                criaArquivo(time_span.count(), comp, trocas, vetorInt.size(), "Merge Sort");
            }
        }

        if (escolhaMetodo == 4)
        {
            if (escolhaArq >= 1 && escolhaArq <= 6)
            {
                limpaTela();
                cout << "Ordenando...\n\n\n";
                vetorString = listaString(arqDicionario[escolhaArq - 1]);
                steady_clock::time_point t1 = steady_clock::now();
                quickSortString(vetorString, 0, vetorString.size() - 1, &trocas, &comp);
                steady_clock::time_point t2 = steady_clock::now();
                duration<double> time_span = duration_cast<duration<double>>(t2 - t1);
                imprimeVetorString(vetorString);
                cout << "Comparações: " << comp << endl;
                cout << "Trocas: " << trocas << endl;
                cout << "Tempo de ordenação: " << time_span.count() << "s\n\n";
                criaArquivo(time_span.count(), comp, trocas, vetorString.size(), "Quick Sort");
            }
            if (escolhaArq >= 7 && escolhaArq <= 22)
            {
                limpaTela();
                cout << "Ordenando...\n\n\n";
                vetorInt = listaInt(arqNum[escolhaArq - 7]);
                steady_clock::time_point t1 = steady_clock::now();
                quickSortInt(vetorInt, 0, vetorInt.size() - 1, &trocas, &comp);
                steady_clock::time_point t2 = steady_clock::now();
                duration<double> time_span = duration_cast<duration<double>>(t2 - t1);
                imprimeVetorInt(vetorInt);
                cout << "Comparações: " << comp << endl;
                cout << "Trocas: " << trocas << endl;
                cout << "Tempo de ordenação: " << time_span.count() << "s\n\n";
                criaArquivo(time_span.count(), comp, trocas, vetorInt.size(), "Quick Sort");
            }
        }

        if (escolhaMetodo == 5)
        {
            if (escolhaArq >= 1 && escolhaArq <= 6)
            {
                limpaTela();
                cout << "Ordenando...\n\n\n";
                vetorString = listaString(arqDicionario[escolhaArq - 1]);
                steady_clock::time_point t1 = steady_clock::now();
                selectionSortString(vetorString, &trocas, &comp);
                steady_clock::time_point t2 = steady_clock::now();
                duration<double> time_span = duration_cast<duration<double>>(t2 - t1);
                imprimeVetorString(vetorString);
                cout << "Comparações: " << comp << endl;
                cout << "Trocas: " << trocas << endl;
                cout << "Tempo de ordenação: " << time_span.count() << "s\n\n";
                criaArquivo(time_span.count(), comp, trocas, vetorString.size(), "Selection Sort");
            }
            if (escolhaArq >= 7 && escolhaArq <= 22)
            {
                limpaTela();
                cout << "Ordenando...\n\n\n";
                vetorInt = listaInt(arqNum[escolhaArq - 7]);
                steady_clock::time_point t1 = steady_clock::now();
                selectionSortInt(vetorInt, &trocas, &comp);
                steady_clock::time_point t2 = steady_clock::now();
                duration<double> time_span = duration_cast<duration<double>>(t2 - t1);
                imprimeVetorInt(vetorInt);
                cout << "Comparações: " << comp << endl;
                cout << "Trocas: " << trocas << endl;
                cout << "Tempo de ordenação: " << time_span.count() << "s\n\n";
                criaArquivo(time_span.count(), comp, trocas, vetorInt.size(), "Selection Sort");
            }
        }

        if (escolhaMetodo == 6)
        {
            if (escolhaArq >= 1 && escolhaArq <= 6)
            {
                limpaTela();
                cout << "Ordenando...\n\n\n";
                vetorString = listaString(arqDicionario[escolhaArq - 1]);
                steady_clock::time_point t1 = steady_clock::now();
                shellSortString(vetorString, &trocas, &comp);
                steady_clock::time_point t2 = steady_clock::now();
                duration<double> time_span = duration_cast<duration<double>>(t2 - t1);
                imprimeVetorString(vetorString);
                cout << "Comparações: " << comp << endl;
                cout << "Trocas: " << trocas << endl;
                cout << "Tempo de ordenação: " << time_span.count() << "s\n\n";
                criaArquivo(time_span.count(), comp, trocas, vetorString.size(), "Shell Sort");
            }
            if (escolhaArq >= 7 && escolhaArq <= 22)
            {
                limpaTela();
                cout << "Ordenando...\n\n\n";
                vetorInt = listaInt(arqNum[escolhaArq - 7]);
                steady_clock::time_point t1 = steady_clock::now();
                shellSortInt(vetorInt, &trocas, &comp);
                steady_clock::time_point t2 = steady_clock::now();
                duration<double> time_span = duration_cast<duration<double>>(t2 - t1);
                imprimeVetorInt(vetorInt);
                cout << "Comparações: " << comp << endl;
                cout << "Trocas: " << trocas << endl;
                cout << "Tempo de ordenação: " << time_span.count() << "s\n\n";
                criaArquivo(time_span.count(), comp, trocas, vetorInt.size(), "Shell Sort");
            }
        }
    }
}

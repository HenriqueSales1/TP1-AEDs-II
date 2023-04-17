#include <iostream>
#include <cstdlib>
#include <windows.h>
#include <cstring>
#include <fstream>
#include <vector>

using namespace std;

string arqDicionario[6] = {
    "../Instancias-TP1/DicionarioAleatorio-29855.txt",
    "../Instancias-TP1/DicionarioAleatorio-261791.txt",
    "../Instancias-TP1/DicionarioInversamenteOrdenado-29855.txt",
    "../Instancias-TP1/DicionarioInversamenteOrdenado-261791.txt",
    "../Instancias-TP1/DicionarioOrdenado-29855.txt",
    "../Instancias-TP1/DicionarioOrdenado-261791.txt"};

string arqNum[16] = {
    "../Instancias-TP1/ListaAleatoria-1000.txt",
    "../Instancias-TP1/ListaAleatoria-10000.txt",
    "../Instancias-TP1/ListaAleatoria-100000.txt",
    "../Instancias-TP1/ListaAleatoria-1000000.txt",
    "../Instancias-TP1/ListaInversamenteOrdenada-1000.txt",
    "../Instancias-TP1/ListaInversamenteOrdenada-10000.txt",
    "../Instancias-TP1/ListaInversamenteOrdenada-100000.txt",
    "../Instancias-TP1/ListaInversamenteOrdenada-1000000.txt",
    "../Instancias-TP1/ListaOrdenada-1000.txt",
    "../Instancias-TP1/ListaOrdenada-10000.txt",
    "../Instancias-TP1/ListaOrdenada-100000.txt",
    "../Instancias-TP1/ListaOrdenada-1000000.txt",
    "../Instancias-TP1/ListaQuaseOrdenada-1000.txt",
    "../Instancias-TP1/ListaQuaseOrdenada-10000.txt",
    "../Instancias-TP1/ListaQuaseOrdenada-100000.txt",
    "../Instancias-TP1/ListaQuaseOrdenada-1000000.txt",
};

// Funções gerais (menus e limpeza do prompt).

void limpaTela()
{
    system("cls");
}

void menuMetodos()
{
    cout << "==================================================\n\n";
    cout << "\tSELECIONE O MÉTODO DE ORDENAÇÃO\n\n";
    cout << "==================================================\n\n";
    cout << "1. Bubble Sort\n"
            "2. Insertion Sort\n"
            "3. Merge Sort\n"
            "4. Quick Sort\n"
            "5. Selection Sort\n"
            "6. Shell Sort\n"
            "\n"
            "0. Sair\n";
    cout << "==================================================\n\n";
    cout << "Escolha: ";
}

void menuArquivos()
{
    cout << "==================================================\n\n";
    cout << "SELECIONE O TIPO DE ARQUIVO QUE DESEJA ORDENAR\n\n";
    cout << "==================================================\n\n";
    cout << "1. Dicionário aleatório (29855)\n"
            "2. Dicionário aleatório (261791)\n"
            "3. Dicionário inversamente ordenado (29855)\n"
            "4. Dicionário inversamente ordenado (261791)\n"
            "5. Dicionário ordenado (29855)\n"
            "6. Dicionário ordenado (261791)\n"
            "7. Lista de números aleatórios (até 1000)\n"
            "8. Lista de números aleatórios (até 10000)\n"
            "9. Lista de números aleatórios (até 100000)\n"
            "10. Lista de números aleatórios (até 1000000)\n"
            "11. Lista de números inversamente ordenada (até 1000)\n"
            "12. Lista de números inversamente ordenada (até 10000)\n"
            "13. Lista de números inversamente ordenada (até 100000)\n"
            "14. Lista de números inversamente ordenada (até 1000000)\n"
            "15. Lista de números ordenada (até 1000)\n"
            "16. Lista de números ordenada (até 10000)\n"
            "17. Lista de números ordenada (até 100000)\n"
            "18. Lista de números ordenada (até 1000000)\n"
            "19. Lista de números quase ordenada (até 1000)\n"
            "20. Lista de números quase ordenada (até 10000)\n"
            "21. Lista de números quase ordenada (até 100000)\n"
            "22. Lista de números quase ordenada (até 1000000)\n"
            "\n"
            "0. Voltar\n";
    cout << "==================================================\n\n";
    cout << "Escolha: ";
}

// As funções a seguir são as funções para ordenar cada um dos arquivos pedidos.

void insertionSortInt(vector<int> &vetor, unsigned long long *trocas, unsigned long long *comp)
{
    int chave, j;
    for (int i = 1; i < vetor.size(); i++)
    {
        chave = vetor[i];
        j = i - 1;
        (*comp)++;
        while (j >= 0 && vetor[j] > chave)
        {
            (*comp)++;
            vetor[j + 1] = vetor[j];
            j--;
            (*trocas)++;
        }
        vetor[j + 1] = chave;
    }
}

void insertionSortString(vector<string> &vetor, unsigned long long *trocas, unsigned long long *comp)
{
    int j;
    string chave;
    for (int i = 1; i < vetor.size(); i++)
    {
        chave = vetor[i];
        j = i - 1;
        (*comp)++;
        while (j >= 0 && vetor[j] > chave)
        {
            (*comp)++;
            vetor[j + 1] = vetor[j];
            j--;
            (*trocas)++;
        }
        vetor[j + 1] = chave;
    }
}

void selectionSortInt(vector<int> &vetor, unsigned long long *trocas, unsigned long long *comp)
{
    int min, aux;

    for (int i = 0; i < vetor.size(); i++)
    {
        min = i;
        for (int j = i + 1; j < vetor.size(); j++)
        {
            if (vetor[j] < vetor[min])
            {
                (*comp)++;
                min = j;
            }
            else
            {
                (*comp)++;
            }
        }
        aux = vetor[i];
        vetor[i] = vetor[min];
        vetor[min] = aux;
        (*trocas)++;
    }
}

void selectionSortString(vector<string> &vetor, unsigned long long *trocas, unsigned long long *comp)
{
    int min;
    string aux;

    for (int i = 0; i < vetor.size(); i++)
    {
        min = i;
        for (int j = i + 1; j < vetor.size(); j++)
        {
            if (vetor[j] < vetor[min])
            {
                (*comp)++;
                min = j;
            }
            else
            {
                (*comp)++;
            }
        }
        aux = vetor[i];
        vetor[i] = vetor[min];
        vetor[min] = aux;
        (*trocas)++;
    }
}

void bubbleSortInt(vector<int> &vetor, unsigned long long *trocas, unsigned long long *comp)
{

    int aux, troca;

    for (int i = 0; i < vetor.size() - 1; i++)
    {

        troca = 0;

        for (int j = 1; j < vetor.size() - i; j++)
        {
            if (vetor[j] < vetor[j - 1])
            {
                (*comp)++;
                aux = vetor[j];
                vetor[j] = vetor[j - 1];
                vetor[j - 1] = aux;
                troca = 1;
                (*trocas)++;
            }
            else
            {
                (*comp)++;
            }
        }
        if (troca == 0)
        {
            break;
        }
    }
}

void bubbleSortString(vector<string> &vetor, unsigned long long *trocas, unsigned long long *comp)
{

    string aux;
    int troca;

    for (int i = 0; i < vetor.size() - 1; i++)
    {

        troca = 0;

        for (int j = 1; j < vetor.size() - i; j++)
        {
            if (vetor[j] < vetor[j - 1])
            {
                (*comp)++;
                aux = vetor[j];
                vetor[j] = vetor[j - 1];
                vetor[j - 1] = aux;
                troca = 1;
                (*trocas)++;
            }
            else
            {
                (*comp)++;
            }
        }
        if (troca == 0)
        {
            break;
        }
    }
}

void shellSortInt(vector<int> &vetor, unsigned long long *trocas, unsigned long long *comp)
{
    int h, x, i, j;
    for (h = 1; h < vetor.size(); h = 3 * h + 1)
        ;
    while (h > 1)
    {
        h = h / 3;
        for (i = h; i < vetor.size(); i++)
        {
            x = vetor[i];
            j = i;
            while (j >= h && vetor[j - h] > x)
            {
                (*comp)++;
                vetor[j] = vetor[j - h];
                j = j - h;
                (*trocas)++;
            }
            vetor[j] = x;
            (*trocas)++;
        }
    }
}

void shellSortString(vector<string> &vetor, unsigned long long *trocas, unsigned long long *comp)
{
    int h, i, j;
    string x;
    for (h = 1; h < vetor.size(); h = 3 * h + 1)
        ;
    while (h > 1)
    {
        h = h / 3;
        for (i = h; i < vetor.size(); i++)
        {
            x = vetor[i];
            j = i;
            while (j >= h && vetor[j - h] > x)
            {
                (*comp)++;
                vetor[j] = vetor[j - h];
                j = j - h;
                (*trocas)++;
            }
            vetor[j] = x;
            (*trocas)++;
        }
    }
}

void quickSortInt(vector<int> &vetor, int esquerda, int direita, unsigned long long *trocas, unsigned long long *comp)
{
    int aux, i = esquerda, j = direita;
    int pivo = vetor[(esquerda + direita) / 2];

    while (i <= j)
    {
        while (vetor[i] < pivo)
        {
            i++;
        }
        while (vetor[j] > pivo)
        {
            j--;
        }
        (*comp)++;
        if (i <= j)
        {
            aux = vetor[i];
            vetor[i] = vetor[j];
            vetor[j] = aux;
            i++;
            j--;
            (*trocas)++;
        }
    }
    (*comp)++;
    if (esquerda < j)
    {
        quickSortInt(vetor, esquerda, j, trocas, comp);
    }
    (*comp)++;
    if (direita > i)
    {
        quickSortInt(vetor, i, direita, trocas, comp);
    }
}

void quickSortString(vector<string> &vetor, int esquerda, int direita, unsigned long long *trocas, unsigned long long *comp)
{
    int i = esquerda, j = direita;
    auto pivo = vetor[(esquerda + direita) / 2];

    while (i <= j)
    {
        while (vetor[i] < pivo)
        {
            i++;
        }
        while (vetor[j] > pivo)
        {
            j--;
        }
        (*comp)++;
        if (i <= j)
        {
            auto aux = vetor[i];
            vetor[i] = vetor[j];
            vetor[j] = aux;
            i++;
            j--;
            (*trocas)++;
        }
    }
    (*comp)++;
    if (esquerda < j)
    {
        quickSortString(vetor, esquerda, j, trocas, comp);
    }
    (*comp)++;
    if (direita > i)
    {
        quickSortString(vetor, i, direita, trocas, comp);
    }
}

void imprimeVetorInt(vector<int> &vetor)
{
    for (int i = 0; i < vetor.size(); i++)
    {
        cout << vetor[i] << endl;
    }
    cout << endl;
}

void imprimeVetorString(vector<string> &vetor)
{
    for (int i = 0; i < vetor.size(); i++)
    {
        cout << vetor[i] << endl;
    }
    cout << endl;
}

void mergeString(vector<string> &vetor, int inicio, int meio, int fim, unsigned long long *trocas, unsigned long long *comp)
{
    string *vetorAux = (string *)calloc(fim + 1, sizeof(string));
    int i, j;

    for (i = inicio; i <= meio; i++)
    {
        vetorAux[i] = vetor[i];
    }

    for (j = meio + 1; j <= fim; j++)
    {
        vetorAux[fim + meio + 1 - j] = vetor[j];
    }

    i = inicio;
    j = fim;

    for (int k = inicio; k <= fim; k++)
    {
        (*comp)++;
        if (vetorAux[i] <= vetorAux[j])
        {
            vetor[k] = vetorAux[i];
            i++;
            (*trocas)++;
        }
        else
        {
            vetor[k] = vetorAux[j];
            j--;
            (*trocas)++;
        }
    }
    free(vetorAux);
}

void mergeSortString(vector<string> &vetor, int inicio, int fim, unsigned long long *trocas, unsigned long long *comp)
{
    int meio = (inicio + fim) / 2;
    if (inicio < fim)
    {

        mergeSortString(vetor, inicio, meio, trocas, comp);
        mergeSortString(vetor, meio + 1, fim, trocas, comp);
        mergeString(vetor, inicio, meio, fim, trocas, comp);
        (*comp)++;
    }
}

void mergeInt(vector<int> &vetor, int inicio, int meio, int fim, unsigned long long *trocas, unsigned long long *comp)
{

    int *vetorAux = (int *)malloc(sizeof(int) * (fim + 1));
    int i, j;

    for (i = inicio; i <= meio; i++)
    {
        vetorAux[i] = vetor[i];
    }

    for (j = meio + 1; j <= fim; j++)
    {
        vetorAux[fim + meio + 1 - j] = vetor[j];
    }

    i = inicio;
    j = fim;

    for (int k = inicio; k <= fim; k++)
    {
        (*comp)++;
        if (vetorAux[i] <= vetorAux[j])
        {
            vetor[k] = vetorAux[i];
            i++;
            (*trocas)++;
        }
        else
        {
            vetor[k] = vetorAux[j];
            j--;
            (*trocas)++;
        }
    }
    free(vetorAux);
}

void mergeSortInt(vector<int> &vetor, int inicio, int fim, unsigned long long *trocas, unsigned long long *comp)
{
    if (inicio < fim)
    {
        int middle = inicio + (fim - inicio) / 2;

        mergeSortInt(vetor, inicio, middle, trocas, comp);
        mergeSortInt(vetor, middle + 1, fim, trocas, comp);
        mergeInt(vetor, inicio, middle, fim, trocas, comp);
        (*comp)++;
    }
}

// As funções abaixo servem para pegar o nome dos arquivos introduzidos em um vetor de strings, e passando-os como parâmetro
// para as funções de arquivo.

vector<string> listaString(string nomeArquivo)
{
    ifstream archive;
    archive.open(nomeArquivo);

    if (!archive.is_open())
    {
        cerr << "erro\n";
        archive.clear();
    }

    vector<string> dicionario;
    while (!archive.eof())
    {
        string aux;
        archive >> aux;
        dicionario.push_back(aux);
    }

    archive.close();
    return dicionario;
}

vector<int> listaInt(string nomeArquivo)

{
    ifstream archive;
    archive.open(nomeArquivo);

    if (!archive.is_open())
    {
        cerr << "erro\n";
        archive.clear();
    }

    vector<int> numeros;
    while (!archive.eof())
    {
        int aux;
        archive >> aux;
        numeros.push_back(aux);
    }

    archive.close();
    return numeros;
}

// A função abaixo gera um arquivo em formato .csv (Excel) contendo os dados da última iteração (tempo, trocas e comparações).

void gerarResultados(double tempos, unsigned long long comp, unsigned long long trocas, int tamanho, string metodo)
{
    string endereco = "./" + metodo + ".csv";
    ofstream archive(endereco);

    archive << ";Tempo;Comparacoes;Trocas" << endl
            << ";";
    archive << metodo;
    archive << ";";
    archive << metodo;
    archive << ";";
    archive << metodo;
    archive << endl;

    archive << tamanho << ";";
    archive << tempos;
    archive << ";";
    archive << comp;
    archive << ";";
    archive << trocas;
    archive << endl;
}
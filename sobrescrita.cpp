#include <iostream>
#include <algorithm>

#define MAX 60

using namespace std;

class Lista {
protected:
    int dados[MAX];
    int n;
public:
    Lista() {
        n=0;
    }
    void inserir (int elemento) {
        dados[n] = elemento;
        n++;
    }
    bool buscar (int elemento) {
        for(int i =0; i<n; i++)
            if(dados[i]==elemento)
                return true;
        return false;
    }
    bool remover (int elemento) {
        int pos;
        for (pos=0; pos<n; pos++) {
            if (dados[pos] == elemento)
                break;
        }
        // percorreu todo o vetor e não encontrou
        // retorna false, indicando que não apagou
        if (pos == n) {
            return false;
        }
        else {
            for(; pos < n-1; pos++) {
                dados[pos] = dados[pos+1];
            }
            // "apaga" o último elemento, que
            // estaria duplicado, e decrementa n
            dados[n-1] = 0;
            n--;
            return true;
        }
    }
    void imprimir() {
        for(int i =0; i<n; i++)
            cout << dados[i] << " ";
        cout << endl;
    }
};

class ListaOrdenada : public Lista {
public:
    void inserir(int elemento) {
        Lista::inserir(elemento);
        for (int i=n-1; i>0;i--) {
            if(dados[i] < dados[i-1])
                swap(dados[i], dados[i-1]);
            else
                return;
        }
    }
};

int main()
{
    ListaOrdenada l;
    l.inserir(21);
    l.inserir(27);
    l.inserir(24);
    l.inserir(03);
    l.imprimir();

    if (l.buscar(27))
        cout << "27 foi encontrado";
    else
        cout << "27 não foi encontrado";

    return 0;
}

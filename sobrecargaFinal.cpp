#include<iostream>
#include<string>
#include<sstream>
#include<cstdlib>

#define MAX 60

using namespace std;

class Lista {
protected:
    int dados[MAX];
    int n;
public:
    Lista() : n(0) {}

    Lista(int n) : n(n) {
        for (int i=0; i<n; i++) {
            dados[i] = 0;
        }
    }

    Lista(int n, int valor) : n(n) {
        for (int i=0; i<n; i++) {
            dados[i] = valor;
        }
    }

    void inserir (int elemento) {
        dados[n] = elemento;
        n++;
    }

    bool buscar (int elemento) {
        for(int i=0; i<n; i++)
            if(dados[i]==elemento)
                return true;
        return false;
    }

    string dadosLista() {
        string s = "[ ";
        stringstream stream;
        for(int i=0; i<n; i++)
            stream << dados[i] << " ";
        s += stream.str();
        s += "]";
        return s;
    }

    int somar() {
        return somar(0, n);
    }

    int somar(int inicio, int fim) {
        int soma = 0;
        for (int i=inicio; i<fim; i++)
            soma += dados[i];
        return soma;
    }

    int& operator[](int posicao) {
        if (posicao < this->n)
            return this->dados[posicao];
        else {
            cerr << "Posicao nao existe";
            exit(-1);
        }
    }

    Lista operator+(int elemento) {
        Lista novaLista = (*this);
        novaLista.inserir(elemento);
        return novaLista;
    }

    void operator+=(int elemento) {
        this->inserir(elemento);
    }

};

ostream& operator<<(ostream& stream, Lista l) {
    stream << l.dadosLista();
    return stream;
}

int main()
{
    Lista l;

    l += 11;
    l += 04;
    l += 30;
    l += 03;
    l += 22;

    cout << "Elemento na posicao 0: " << l[0] << endl;

    cout << "Digite novo valor para a posicao 0: ";
    cin >> l[0];

    cout << "Elemento na posicao 0: " << l[0] << endl;

    cout << "Valores presentes na lista: " << l << endl;

    return 0;
}


#include<iostream>
#include<string>
#include<sstream>

#define MAX 60

using namespace std;

class Lista {
protected:
    int dados[MAX];
    int n;
public:
    Lista() : n(0) {}

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

};

int main()
{
    Lista l;

    l.inserir(21);
    l.inserir(27);
    l.inserir(04);
    l.inserir(23);

    cout << l.dadosLista() << endl;

    if (l.buscar(27))
        cout << "27 foi encontrado" << endl;
    else
        cout << "27 não foi encontrado" << endl;

    return 0;
}


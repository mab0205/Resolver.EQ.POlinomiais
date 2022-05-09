#include <iostream>
#include <vector>

using namespace std;
class Equacoes{

public:
    //unico metodo
    virtual int resolver() = 0;


    ~Equacoes();
};

class Eq1Grau : public Equacoes{
    int A, B;
public:

    //sobrecarga dos operadores
    Eq1Grau(int a, int b) : A(a), B(b){}
    //int resolver() = 0;

    int getA(){
        return A;
    }
    int getB(){
        return B;
    }

    void operator+(int elemento) {
       // this->inserir(elemento);
    }
};

class Eq2Grau : public Equacoes{
int A, B, C;
public:
     Eq2Grau(int a, int b, int c) : A(a), B(b), C(c){}
    int getA(){
        return A;
    }
    int getB(){
        return B;
    }
    int getC(){
        return C;
    }
    //sobrecarga dos operadores 
   // int resolver() = 0;
    void operator+(int elemento) {
       // this->inserir(elemento);
    }

};




int main(int argc, char const *argv[]){
    

    Eq1Grau eq1(2, 3); //2*x + 3 = 0
    cout << "Eq1: "  << endl;
    //eq1.resolver();
    Eq2Grau eq2(1, 1, -6); // 1*x^2 + 1*x – 6 = 0

}

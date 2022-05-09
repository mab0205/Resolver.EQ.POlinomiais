#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

class Equacoes{
public:
    virtual void Resolver() = 0;
};

class Eq1Grau : public Equacoes {
    int a, b, resp;
public:
    Eq1Grau(int a, int b) : a(a), b(b) {}
     int getA(){
        return a;
    }
    int getB(){
        return b;
    }
    int getResp(){
        return resp;
    }
    
    void operator+(int elemento) {

    }
    void operator-(int elemento) {

    }
    Eq1Grau operator+(Eq1Grau &eq1){ return Eq1Grau(a + eq1.getA(), b + eq1.getB()); } 
    Eq1Grau operator-(Eq1Grau &eq1) {return Eq1Grau(a - eq1.getA(), b - eq1.getB());}
    
     
    void Resolver() { int resp = (-1*b)/a;}
   
};

class Eq2Grau : public Equacoes {
     int a, b, c, resp1, resp2;
public:
    Eq2Grau(int a, int b, int c) : a(a), b(b), c(c){}
    int getA(){
        return a;
    }
    int getB(){
        return b;
    }
    int getC(){
        return c;
    }
    int getResp1(){
        return resp1;
    }
    int getResp2(){
        return resp1;
    }
    

    Eq2Grau operator+(Eq2Grau &eq2){ return Eq2Grau(a + eq2.getA(), b + eq2.getB(), c + eq2.getC()); } 
    Eq2Grau operator-(Eq2Grau &eq2) {return Eq2Grau(a - eq2.getA(), b - eq2.getB(), c - eq2.getC());}
    

   void Resolver() {
       resp1 = -1*b+sqrt((pow(b, 2))-4*a*c) /2*a; 
       resp2 = -1*b-sqrt((pow(b, 2))-4*a*c) /2*a;
    }
   
};

ostream& operator<<(ostream& stream, Eq1Grau eq1) {
    stream << eq1.getA();
    stream << "*x";
    if( eq1.getB()>0){
        stream << "+";
        stream << eq1.getB();}
    else  stream << eq1.getB();
    stream << "=0";
    return stream;
}
ostream& operator<<(ostream& stream, Eq2Grau eq2) {
    stream << eq2.getA();
    stream << "*x^2";
    if( eq2.getB()>0) stream <<"+"<< eq2.getB();
        else  stream << eq2.getB();
    stream << "*x";
    if( eq2.getC()>0)stream << "+"<< eq2.getC();
        else  stream << eq2.getC();
    stream << "=0";
    return stream;
}

int main(){
    Eq1Grau eq1(2,3);
    Eq2Grau eq2(1,1,-6);

    eq1.Resolver();
    eq2.Resolver();

    cout << "Eq1: " << eq1 << endl;
    cout << "Eq2: "<< eq2 << endl;

    Eq2Grau eq3 (1,1,1); // 1*x^2 + 1*x + 1 = 0
    Eq1Grau eq7 (1,1);
    Eq2Grau eq4 = eq2 + eq3;
        cout << "Eq4: " << eq4 << endl;

    eq4 = eq4 - eq3;
        cout << "Eq4: " << eq4 << endl;

    Eq1Grau eq8 = eq1 + eq7;
        cout << "Eq8: " << eq8 << endl;
    
    return 0;
}

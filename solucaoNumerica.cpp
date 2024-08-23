#include <iostream>
#include <stdio.h>
#include <math.h>
#include "aproximacaoIntegrais.h"
#include "aproximacaoIntegrais.cpp"
#include "raizFuncao.h"
#include "raizFuncao.cpp"

#define DELTA_X 0.0000000001
#define ERRO 0.001

using namespace std;

double f (double x) {
    return x*x;
}

double derivada_f (double x) {
    return ((f(x + DELTA_X) - f(x)) / DELTA_X);
}

double comprimento_arco(double x) {
    return sqrt(1.0 + derivada_f(x) * derivada_f(x));
}


int main () {
    int opcao, quantidade_intervalos, tipo;
    double resposta, limite_inferior, limite_superior, erro, x0, x1;

    cout << "Programa para aproximacoes numericas.\n";
    cout << "1: Integrais\n2: Derivadas\n3: Raizes\n";

    cin >> opcao;

    if (opcao == 1) {
        cout << "1: Riemann\n2: Trapezios\n3: Simpson\n";
        cin >> opcao;
        cout << "Quantidade de intervalos: ";
        cin >> quantidade_intervalos;
        cout << "Limite inferior: ";
        cin >> limite_inferior;
        cout << "Limite superior: ";
        cin >> limite_superior;

        if (opcao == 1) {
            cout << "1: Esquerda\n2: Direita\n3: Pontos Medios\n";
            cin >> tipo;
            resposta = riemann(quantidade_intervalos, limite_inferior, limite_superior, tipo, &f);
        }
        if (opcao == 2)
            resposta = trapezio(quantidade_intervalos, limite_inferior, limite_superior, &f);
        if (opcao == 3)
            resposta = simpson(quantidade_intervalos, limite_inferior, limite_superior, &f);
        printf("A integral aproximada eh: %.15f", resposta);
    }
    else if (opcao == 2) {
        cout << "Informe o ponto: ";
        cin >> x0;
        resposta = derivada_f(x0);
        printf("A derivada aproximada no ponto eh: %.15f", resposta);
    }
    else if (opcao == 3) {
        cout << "Informe o primeiro ponto: ";
        cin >> x0;
        cout << "Informe o segundo ponto: ";
        cin >> x1;
        cout << "Informe o erro: ";
        cin >> erro;
        resposta = metodoSecantes(x0, x1, erro, &f);
        printf("Uma raiz aproximada eh: %.15f", resposta);
    }

    return 0;
}
#include "aproximacaoIntegrais.h"

double riemann (int quantidade_retangulos, double limite_inferior, double limite_superior, int tipo, double (*funcao)(double)) {
    double delta_x = (limite_superior - limite_inferior) / quantidade_retangulos;
    double x0;
    if (tipo == 0) x0 = limite_inferior;
    else if (tipo == 1) x0 = limite_inferior + delta_x;
    else x0 = limite_inferior + delta_x/2;

    double resultado = 0;
    for (int i = 0; i < quantidade_retangulos; i++)
        resultado += funcao(x0 + i*delta_x) * delta_x;

    return resultado;
}

double trapezio (int quantidade_trapezios, double limite_inferior, double limite_superior, double (*funcao)(double)) {
    double delta_x = (limite_superior - limite_inferior) / quantidade_trapezios;
    double x1 = limite_inferior, x2 = limite_inferior + delta_x;

    double resultado = 0;
    for (int i = 0; i < quantidade_trapezios; i++) {
        resultado += (funcao(x1) + funcao(x2));
        x1 = x2; x2 += delta_x;
    }
    resultado = resultado * delta_x / 2;

    return resultado;
}

double simpson (int quantidade_intervalos, double limite_inferior, double limite_superior, double (*funcao)(double)) {
    return trapezio(quantidade_intervalos/2, limite_inferior, limite_superior, funcao)/3 + 
        riemann(quantidade_intervalos/2, limite_inferior, limite_superior, 2, funcao) * 2 / 3;
}
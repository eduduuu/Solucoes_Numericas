#include "raizFuncao.h"
#include <math.h>

using namespace std;

double metodoSecantes(double x0, double x1, double erro, double (*funcao)(double)) {
    double erro_relativo = 1000, x2;

    while (erro_relativo > erro) {
        x2 = (x0*funcao(x1) - x1*funcao(x0)) / (funcao(x1) - funcao(x0));
        erro_relativo = abs(x2 - x1)/ abs(x2);
        x0 = x1; x1 = x2;
    }

    return x2;
}
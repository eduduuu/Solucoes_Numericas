double riemann (int quantidade_retangulos, double limite_inferior, double limite_superior, int tipo, double (*funcao)(double));
double trapezio (int quantidade_trapezios, double limite_inferior, double limite_superior, double (*funcao)(double));
double simpson (int quantidade_intervalos, double limite_inferior, double limite_superior, double (*funcao)(double));
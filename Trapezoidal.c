#include <stdio.h>
#include <math.h>

// Funci�n que queremos integrar
double funcion(double x) {
    // El usuario proporcionar� la funci�n
    return x * x;
}

// M�todo de la regla trapezoidal
double reglaTrapezoidal(double (*f)(double), double a, double b, int n) {
    double h = (b - a) / n; // Ancho de cada subintervalo
    double suma = 0.0; // Inicializamos la suma de �reas
	int i;
    // Calculamos la suma de �reas de los trapecios
    for (i = 1; i < n; i++) {
        double xi = a + i * h; // Punto medio del trapecio
        suma += f(xi); // �rea del trapecio
    }

    // Sumamos las �reas de los extremos del intervalo
    suma += (f(a) + f(b)) / 2.0;

    return suma * h; // Devolvemos el �rea total
}

int main() {
    double a, b; // L�mites de la integral
    int n; // N�mero de subintervalos

    // Solicitar al usuario los l�mites de integraci�n y el n�mero de subintervalos
    printf("Ingrese el limite inferior de la integral: ");
    scanf("%lf", &a);
    printf("Ingrese el limite superior de la integral: ");
    scanf("%lf", &b);
    printf("Ingrese el numero de subintervalos: ");
    scanf("%d", &n);

    // Aproximaci�n de la integral usando la regla trapezoidal
    double resultado = reglaTrapezoidal(funcion, a, b, n);

    // Mostrar el resultado
    printf("Aproximacion de la integral: %lf\n", resultado);

    return 0;
}


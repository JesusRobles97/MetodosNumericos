#include <stdio.h>
#include <math.h>

// Función que queremos integrar
double funcion(double x) {
    // El usuario proporcionará la función
    return x * x;
}

// Método de la regla trapezoidal
double reglaTrapezoidal(double (*f)(double), double a, double b, int n) {
    double h = (b - a) / n; // Ancho de cada subintervalo
    double suma = 0.0; // Inicializamos la suma de áreas
	int i;
    // Calculamos la suma de áreas de los trapecios
    for (i = 1; i < n; i++) {
        double xi = a + i * h; // Punto medio del trapecio
        suma += f(xi); // Área del trapecio
    }

    // Sumamos las áreas de los extremos del intervalo
    suma += (f(a) + f(b)) / 2.0;

    return suma * h; // Devolvemos el área total
}

int main() {
    double a, b; // Límites de la integral
    int n; // Número de subintervalos

    // Solicitar al usuario los límites de integración y el número de subintervalos
    printf("Ingrese el limite inferior de la integral: ");
    scanf("%lf", &a);
    printf("Ingrese el limite superior de la integral: ");
    scanf("%lf", &b);
    printf("Ingrese el numero de subintervalos: ");
    scanf("%d", &n);

    // Aproximación de la integral usando la regla trapezoidal
    double resultado = reglaTrapezoidal(funcion, a, b, n);

    // Mostrar el resultado
    printf("Aproximacion de la integral: %lf\n", resultado);

    return 0;
}


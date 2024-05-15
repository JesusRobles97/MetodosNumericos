#include <stdio.h>
#include <math.h>

// Función que queremos integrar
double funcion(double x) {
    // El usuario proporcionará la función
    return x * x;
}

// Método de integración de Simpson 1/3
double integracionSimpson13(double (*f)(double), double a, double b, int n) {
	int i;
    double h = (b - a) / n; // Ancho de cada subintervalo
    double suma = f(a) + f(b); // Suma de los extremos

    // Sumamos los valores pares
    for (i = 1; i < n; i += 2) {
        double xi = a + i * h; // Punto en el interior del intervalo
        suma += 4 * f(xi); // Multiplicamos por 4
    }

    // Sumamos los valores impares
    for (i = 2; i < n - 1; i += 2) {
        double xi = a + i * h; // Punto en el interior del intervalo
        suma += 2 * f(xi); // Multiplicamos por 2
    }

    return suma * h / 3; // Devolvemos el área total
}

int main() {
    double a, b; // Límites de la integral
    int n; // Número de subintervalos

    // Solicitar al usuario los límites de integración y el número de subintervalos
    printf("Ingrese el limite inferior de la integral: ");
    scanf("%lf", &a);
    printf("Ingrese el limite superior de la integral: ");
    scanf("%lf", &b);
    printf("Ingrese el numero de subintervalos (debe ser par): ");
    scanf("%d", &n);

    // Aproximación de la integral usando el método de integración de Simpson 1/3
    double resultado = integracionSimpson13(funcion, a, b, n);

    // Mostrar el resultado
    printf("Aproximacion de la integral: %lf\n", resultado);

    return 0;
}


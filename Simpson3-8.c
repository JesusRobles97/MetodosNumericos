#include <stdio.h>
#include <math.h>

// Función que queremos integrar
double funcion(double x) {
    // El usuario proporcionará la función
    return x * x;
}

// Método de integración de Simpson 3/8
double integracionSimpson38(double (*f)(double), double a, double b, int n) {
	int i;
    double h = (b - a) / n; // Ancho de cada subintervalo
    double suma = f(a) + f(b); // Suma de los extremos

    // Sumamos los valores que son múltiplos de 3
    for (i = 3; i < n; i += 3) {
        double xi = a + i * h; // Punto en el interior del intervalo
        suma += 2 * f(xi); // Multiplicamos por 2
    }

    // Sumamos los valores restantes
    for (i = 1; i < n; i++) {
        if (i % 3 != 0) {
            double xi = a + i * h; // Punto en el interior del intervalo
            suma += 3 * f(xi); // Multiplicamos por 3
        }
    }

    return 3 * h / 8 * suma; // Devolvemos el área total
}

int main() {
    double a, b; // Límites de la integral
    int n; // Número de subintervalos

    // Solicitar al usuario los límites de integración y el número de subintervalos
    printf("Ingrese el limite inferior de la integral: ");
    scanf("%lf", &a);
    printf("Ingrese el limite superior de la integral: ");
    scanf("%lf", &b);
    printf("Ingrese el numero de subintervalos (debe ser multiplo de 3): ");
    scanf("%d", &n);

    // Aproximación de la integral usando el método de integración de Simpson 3/8
    double resultado = integracionSimpson38(funcion, a, b, n);

    // Mostrar el resultado
    printf("Aproximacion de la integral: %lf\n", resultado);

    return 0;
}


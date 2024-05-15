#include <stdio.h>
#include <math.h>

// Funci�n que queremos integrar
double funcion(double x) {
    // El usuario proporcionar� la funci�n
    return x * x;
}

// M�todo de integraci�n de Simpson 3/8
double integracionSimpson38(double (*f)(double), double a, double b, int n) {
	int i;
    double h = (b - a) / n; // Ancho de cada subintervalo
    double suma = f(a) + f(b); // Suma de los extremos

    // Sumamos los valores que son m�ltiplos de 3
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

    return 3 * h / 8 * suma; // Devolvemos el �rea total
}

int main() {
    double a, b; // L�mites de la integral
    int n; // N�mero de subintervalos

    // Solicitar al usuario los l�mites de integraci�n y el n�mero de subintervalos
    printf("Ingrese el limite inferior de la integral: ");
    scanf("%lf", &a);
    printf("Ingrese el limite superior de la integral: ");
    scanf("%lf", &b);
    printf("Ingrese el numero de subintervalos (debe ser multiplo de 3): ");
    scanf("%d", &n);

    // Aproximaci�n de la integral usando el m�todo de integraci�n de Simpson 3/8
    double resultado = integracionSimpson38(funcion, a, b, n);

    // Mostrar el resultado
    printf("Aproximacion de la integral: %lf\n", resultado);

    return 0;
}


#include <stdio.h>
#include <math.h>

// Funci�n que queremos integrar
double funcion(double x) {
    // El usuario proporcionar� la funci�n
    return x * x;
}

// M�todo de la regla rectangular por la derecha
double reglaRectangularDerecha(double (*f)(double), double a, double b, int n) {
    double h = (b - a) / n; // Ancho de cada subintervalo
    double suma = 0.0; // Inicializamos la suma de �reas
	int i;
    // Calculamos la suma de �reas de los rect�ngulos
    for (i = 1; i <= n; i++) {
        double xi = a + i * h; // Punto de inicio del rect�ngulo
        suma += f(xi); // �rea del rect�ngulo
    }

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

    // Aproximaci�n de la integral usando la regla rectangular por la derecha
    double resultado = reglaRectangularDerecha(funcion, a, b, n);

    // Mostrar el resultado
    printf("Aproximacion de la integral: %lf\n", resultado);

    return 0;
}


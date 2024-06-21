#include <iostream>
#include <vector>

using namespace std;

vector<int> obtenerSecuenciaCrecienteMaxima(const vector<int>& v) {
    int n = v.size();

    // Arreglo para almacenar la longitud de la secuencia creciente hasta el índice i
    vector<int> longitud(n, 1);

    // Calcular la longitud de la secuencia creciente hasta cada índice i
    for (int i = 1; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            if (v[i] > v[j] && longitud[i] < longitud[j] + 1) {
                longitud[i] = longitud[j] + 1;
            }
        }
    }

    // Encontrar la longitud máxima
    int maxLongitud = 0;
    int maxIndice = 0;
    for (int i = 0; i < n; ++i) {
        if (longitud[i] > maxLongitud) {
            maxLongitud = longitud[i];
            maxIndice = i;
        }
    }

    // Reconstruir la secuencia creciente máxima
    vector<int> secuenciaMaxima;
    secuenciaMaxima.push_back(v[maxIndice]);
    int actualLongitud = maxLongitud - 1;

    for (int i = maxIndice - 1; i >= 0; --i) {
        if (v[i] < secuenciaMaxima.back() && longitud[i] == actualLongitud) {
            secuenciaMaxima.push_back(v[i]);
            --actualLongitud;
        }
    }

    reverse(secuenciaMaxima.begin(), secuenciaMaxima.end());
    return secuenciaMaxima;
}

int main() {
    vector<int> v = {11, 17, 5, 8, 6, 4, 7, 12, 3};
    vector<int> secuenciaMaxima = obtenerSecuenciaCrecienteMaxima(v);

    // Imprimir la secuencia creciente de máxima longitud
    cout << "Secuencia creciente de máxima longitud: ";
    for (int i : secuenciaMaxima) {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}
#include <iostream>
#include <vector>
using namespace std;

struct Item {
  int valor;
  int peso;
};

void imprimirSolucion(const vector<Item> &solucion) {
  cout << "Solucion: ";
  for (const Item &item : solucion) {
    cout << "(" << item.valor << ", " << item.peso << ") ";
  }
  cout << endl;
}

void mochilaBacktracking(const vector<Item> &items, vector<Item> &solucion,
                         int capacidadRestante, int &valorActual,
                         int &mejorValor, int indice) {
  if (indice == items.size()) {
    // Llegamos al final de la lista de elementos
    if (valorActual > mejorValor) {
      mejorValor = valorActual;
      imprimirSolucion(solucion);
    }
    return;
  }

  mochilaBacktracking(items, solucion, capacidadRestante, valorActual,
                      mejorValor, indice + 1);

  // Incluir el elemento actual si cabe en la mochila
  if (capacidadRestante >= items[indice].peso) {
    solucion.push_back(items[indice]);
    valorActual += items[indice].valor;
    capacidadRestante -= items[indice].peso;

    mochilaBacktracking(items, solucion, capacidadRestante, valorActual,
                        mejorValor, indice + 1);

    // Deshacer la selección del elemento actual
    solucion.pop_back();
    valorActual -= items[indice].valor;
    capacidadRestante += items[indice].peso;
  }
}

int main() {
  vector<Item> items = {{10, 30}, {7, 15}, {6, 11}, {4, 8}, {2, 2}};
  int capacidadMochila = 20;

  vector<Item> solucionActual;
  int valorActual = 0;
  int mejorValor = 0;

  mochilaBacktracking(items, solucionActual, capacidadMochila, valorActual,
                      mejorValor, 0);

  cout << "Mejor valor obtenido: " << mejorValor << endl;

  return 0;
}

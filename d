##### Mochila 
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int mochila(int capacidad, const vector<int>& pesos, const vector<int>& valores, int n) {
    vector<vector<int>> dp(n + 1, vector<int>(capacidad + 1, 0));

    for (int i = 1; i <= n; ++i) {
        for (int w = 1; w <= capacidad; ++w) {
            if (pesos[i - 1] <= w) {
                dp[i][w] = max(valores[i - 1] + dp[i - 1][w - pesos[i - 1]], dp[i - 1][w]);
            }
            else {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    return dp[n][capacidad];
}

int main() {
    
    vector<int> pesos = { 1,2, 5, 6, 7 };
    vector<int> valores = { 1,6,18, 22, 28 };
    int capacidad = 11;
    int n = pesos.size();

    int resultado = mochila(capacidad, pesos, valores, n);

    cout << "ebenfiocio maximo: " << resultado << endl;

    return 0;
}
#### Moneda
#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int monedas_cambio(const vector<int>& nonedass, int cantidad) {
    vector<int> num_monedas(cantidad + 1, INT_MAX);
    vector<int> seleccion(cantidad + 1, -1);

    num_monedas[0] = 0;

    for (int monto = 1; monto <= cantidad; ++monto) {
        for (int tipo_moneda = 0; tipo_moneda < nonedass.size(); ++tipo_moneda) {
            if (nonedass[tipo_moneda] <= monto) {
                int subproblema = num_monedas[monto - nonedass[tipo_moneda]];
                if (subproblema != INT_MAX && subproblema + 1 < num_monedas[monto]) {
                    num_monedas[monto] = subproblema + 1;
                    seleccion[monto] = tipo_moneda; 
            }
        }
    }

    if (num_monedas[cantidad] == INT_MAX) {
        return -1;  
    }
    else {
        cout << "monedas que se utilizan: ";
        int monto_restante = cantidad;
        while (monto_restante > 0) {
            int tipo_moneda_index = seleccion[monto_restante];
            cout << nonedass[tipo_moneda_index] << " ";
            monto_restante -= nonedass[tipo_moneda_index];
        }
        cout << endl;
        return num_monedas[cantidad];
    }
}

int main() {
   
    vector<int> nonedass = { 100, 90, 1 };
    int cantidad = 180;

    int resultado = monedas_cambio(nonedass, cantidad);

    if (resultado != -1) {
        cout << "minimo mondeas: " << resultado << endl;
    }
    else {
        cout << "no es posible" << endl;
    }

    return 0;

}
#### SEC 

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;




vector<int> secuenciass(const vector<int>& V) {
    int n = V.size();
    vector<int> lis(n, 1);
    vector<int> prev(n, -1);

    int endIndex = 0;

    for (int i = 1; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            if (V[i] > V[j] && lis[i] < lis[j] + 1) {
                lis[i] = lis[j] + 1;
                prev[i] = j;
            }
        }

        if (lis[i] > lis[endIndex]) {
            endIndex = i;
        }
    }

    vector<int> result;
    while (endIndex != -1) {
        result.push_back(V[endIndex]);
        endIndex = prev[endIndex];
    }

    reverse(result.begin(), result.end());
    return result;
}

int main() {
    vector<int> V = { 11, 17, 5, 8, 6, 4, 7, 12, 3 };

   
    vector<int> secuencias = secuenciass(V);


    cout << "secuencia mmx: ";
    for (int num : secuencias) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}

###### sub1
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;



string subsecuencia(const string& X, const string& Y) {
    int m = X.length();
    int n = Y.length();


    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));


    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (X[i - 1] == Y[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    int length = dp[m][n];
    string result(length, ' ');

    int i = m, j = n;
    while (i > 0 && j > 0) {
        if (X[i - 1] == Y[j - 1]) {
            result[--length] = X[i - 1];
            --i;
            --j;
        }
        else if (dp[i - 1][j] > dp[i][j - 1]) {
            --i;
        }
        else {
            --j;
        }
    }

    return result;
}

int main() {
    string X = "ABCBDAB";
    string Y = "BDCABA";

   
    string subsequence =subsecuencia(X, Y);

    cout << "Subsecuencia común más larga: " << subsequence << endl;

    return 0;
}

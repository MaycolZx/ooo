#include <iostream>
#include <vector>
using namespace std;

// Función para encontrar la longitud de la subsecuencia común más larga
int longitudSubsecuenciaComun(const string &X, const string &Y) {
  int m = X.length();
  int n = Y.length();

  // Crear una matriz para almacenar los resultados de subproblemas
  vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

  // Llenar la matriz dp usando programación dinámica
  for (int i = 1; i <= m; ++i) {
    for (int j = 1; j <= n; ++j) {
      if (X[i - 1] == Y[j - 1]) {
        dp[i][j] = dp[i - 1][j - 1] + 1;
      } else {
        dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
      }
    }
  }

  return dp[m][n];
}

// Función para encontrar la subsecuencia común más larga
string subsecuenciaComun(const string &X, const string &Y) {
  int m = X.length();
  int n = Y.length();

  // Crear una matriz para almacenar los resultados de subproblemas
  vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

  // Llenar la matriz dp usando programación dinámica
  for (int i = 1; i <= m; ++i) {
    for (int j = 1; j <= n; ++j) {
      if (X[i - 1] == Y[j - 1]) {
        dp[i][j] = dp[i - 1][j - 1] + 1;
      } else {
        dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
      }
    }
  }

  // Reconstruir la subsecuencia común más larga
  string subsecuencia;
  int i = m, j = n;
  while (i > 0 && j > 0) {
    if (X[i - 1] == Y[j - 1]) {
      subsecuencia = X[i - 1] + subsecuencia;
      i--;
      j--;
    } else if (dp[i - 1][j] > dp[i][j - 1]) {
      i--;
    } else {
      j--;
    }
  }

  return subsecuencia;
}

int main() {
  string X = "ABCBDAB";
  string Y = "BDCABA";

  int longitud = longitudSubsecuenciaComun(X, Y);
  string subseq = subsecuenciaComun(X, Y);

  cout << "Longitud de la subsecuencia comun mas larga: " << longitud << endl;
  cout << "Subsecuencia comun mas larga: " << subseq << endl;

  return 0;
}

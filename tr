#include <iostream>
#include <vector>

using namespace std;

struct objeto {
    int valor;
    int peso;
};

void print1(const vector<int>& sol, const vector<objeto>& objs) {
    cout << "objetoss:" << endl;
    for (int i = 0; i < sol.size(); ++i) {
        if (sol[i] == 1) {
            cout << "Obj. " << i + 1 << ": v = " << objs[i].valor << ", p = " << objs[i].peso << endl;
        }
    }
    cout << endl;
}

void mochila(int ind, int cap_rest, int val_act, const vector<objeto>& objs, vector<int>& sol, int& mejor_val) {
    if (ind == objs.size() || cap_rest == 0) {
        if (val_act > mejor_val) {
            mejor_val = val_act;
            print1(sol, objs);
        }
        return;
    }

    mochila(ind + 1, cap_rest, val_act, objs, sol, mejor_val);

    if (objs[ind].peso <= cap_rest) {
        sol[ind] = 1;
        mochila(ind + 1, cap_rest - objs[ind].peso, val_act + objs[ind].valor, objs, sol, mejor_val);
        sol[ind] = 0;
    }
}

int main() {
    int n = 5;
    int m = 20;

    vector<int> v = { 10, 7, 6, 4, 2 };
    vector<int> w = { 30, 15, 11, 8, 2 };

    vector<objeto> objs(n);
    for (int i = 0; i < n; ++i) {
        objs[i].valor = v[i];
        objs[i].peso = w[i];
    }

    vector<int> sol(n, 0);
    int mejor_val = 0;

    mochila(0, m, 0, objs, sol, mejor_val);

    cout << "Mejor valor: " << mejor_val << endl;

    return 0;
}

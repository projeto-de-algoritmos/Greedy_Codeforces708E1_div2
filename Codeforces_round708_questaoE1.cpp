#include <bits/stdc++.h>

using namespace std;

vector<int> primos;

int divide_por_maior_quadrado(int valor){
    int resposta = 1, contador;

    for (auto primo: primos){
        if (primo > valor) break;
        contador = 0;
        while (valor % primo == 0) contador++, valor/=primo;
        if (contador % 2 == 1) resposta = resposta * primo;
    }
    resposta = resposta * valor;
    return resposta;
}

int resolve(){
    int tamanho_vetor, qtde_mudanca, resposta = 1;
    cin >> tamanho_vetor >> qtde_mudanca;

    set<int> grupo_atual;

    for (int i=0; i<tamanho_vetor; i++){
        int valor;
        cin >> valor;
        valor = divide_por_maior_quadrado(valor);
        if (grupo_atual.count(valor)) grupo_atual.clear(), resposta++;
        grupo_atual.insert(valor);
    }
    return resposta;
}

void crivo_erastotones(){
    bitset<10000> eh_primo;
    eh_primo.set();
    primos.push_back(2);

    for (int i=3; i<10000; i+=2){
        if (eh_primo[i]){
            primos.push_back(i);
            for (int j=3*i; j<10000; j+=2*i){
                eh_primo[j] = 0;
            }
        }
    }
}

int main(){
    int casos_teste;
    cin >> casos_teste;

    crivo_erastotones();

    while (casos_teste--){
        auto resposta = resolve();
        cout << resposta << endl;
    }

    return 0;
}
#include <iostream>
#include <cstdlib>
#include <ctime>

#define N 3 // Define o número de portas

using namespace std;

enum {
    PREMIO,
    BODE
};

int sortear() {
    return rand() % N;
}

void inicializarPortas(int portas[]) {
    for (int i = 0; i < N; i++) {
        portas[i] = BODE; 
    }
}

void distribuirObjetos(int portas[]) {
    int posicaoPremio = sortear();
    portas[posicaoPremio] = PREMIO; 
}

void imprimirPortas(int portas[]) {
    for (int i = 0; i < N; i++) {
        cout << "[";
        
        switch (portas[i]) {
            case BODE:
                cout << "B";
                break;
            case PREMIO:
                cout << "P";
                break;
        }

        cout << "]";
    }

    cout << endl;
}

int escolherPrimeiraPorta(){
    return sortear();
}

int portaBode(int portas[], int escolhaJogador){
    int i;
    do {
        i = sortear();
    } while (i == escolhaJogador || portas[i] == PREMIO);
    return i;
}

int portaPremio(int portas[], int n){
    if(portas[0] == PREMIO)
        return n;
    else 
        return portaPremio(portas+1, n++);
}

bool acertouPorta(int portaEscolhida, int portaCorreta){
    return portaEscolhida == portaCorreta;
}

int mudarEscolha(int escolhaInicial, int portaBode){
    int novaEscolha = escolhaInicial;
    
    do {
        novaEscolha = sortear();
    } while (novaEscolha == escolhaInicial || novaEscolha == portaBode);

    return novaEscolha;
}


int main() {

    int portas[N];
    srand(time(NULL));
    int escolha;
    int vezesQueAcertou = 0;
    int vezesQueErrou = 0;
    int rep;

    cin >> rep;


    for(int i =0; i< rep; i++){
        inicializarPortas(portas);
        distribuirObjetos(portas);
        // imprimirPortas(portas);

        escolha = escolherPrimeiraPorta();
        int portaBodeRevelada = portaBode(portas, escolha);
        int novaEscolha = mudarEscolha(escolha, portaBodeRevelada);

        if(acertouPorta(portas[novaEscolha], portaPremio(portas, 0))){
            vezesQueAcertou++;
        } else {
            vezesQueErrou++;
        }
    }

    cout << "Acertos: " << vezesQueAcertou << endl;
    cout << "Erros: " << vezesQueErrou << endl;

    return 0;
}

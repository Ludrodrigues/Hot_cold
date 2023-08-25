/*!
 * This program implements the game Hot or Cold.
 * @authors Ludmilla and Julia
 * @date August 25rd, 2023.
 */

#include <iostream>
#include <ctime>
using namespace std;


//exibe as regras do jogo
void game_rules(){
    cout << "===================================================" << endl;
    cout << "Welcome to the Hot-Cold Guess game, copyright 2023."<< endl << endl;
    cout << "___________________________________________________" << endl;
    cout << "These are the rules:" << endl;
    cout << " * I’ll choose a random number in [1,30]. Your job is to guess that number." << endl;
    cout << " * From the second guess onward, I’ll tell you if your guessis hot (closer than the previous guess) or cold (farther fromthe previous guess)." << endl;
    cout << " * If you wish to quit the game, just type in a negative number." << endl;
    cout << "Good luck!" << endl;
    cout << "===================================================" << endl; 
};

//exibe como ultilzar o programa
void usage() {
    cout << "===================================================" << endl;
    cout << "Usage:" << endl;
    cout << "  >>> O valor do parâmetro deve ser de 0 - 100." << endl;
    cout << "  >>> Caso o parâmetro não seja informado o valor máximo sera 30." << endl;
    cout << "  >>> Só são permitridos chutes entre 1 - 100." << endl;
    cout << "===================================================" << endl;
};

//mecânica do jogo
void game(int valor_escolhido, int valor_maximo) {
    int chute, alvo, chute_anterior, distancia1, distancia2;

    alvo = rand() % valor_escolhido;

    cout << "Informe o chute inicial: ";
    cin >> chute;

    if (alvo != chute) {
        chute_anterior = chute;

        cout << "Errado, tente novamente: ";
        cin >> chute;
    }

    while (alvo != chute) {
        //calcula a 'diferenca1' entre o chute inicial e o alvo
        if (chute_anterior > alvo) {
            distancia1 = chute_anterior -  alvo;
        } else {
            distancia1 =  alvo - chute_anterior;
        } 

        //calcula a 'diferenca2' entre o chute e o alvo
        if (chute > alvo) {
            distancia2 = chute -  alvo;
        } else {
            distancia2 =  alvo - chute;
        }

        //comparação entre as distancias
        if (distancia2 > distancia1 ){
            cout << "Errado, mas está frio. Tente novamente:";
            cin >> chute;
        } else {
            cout << "Errado, mas está quente. Tente novamente:";
            cin >> chute;
        } 
    }
    
    cout << "Parabéns! Você acertou o número!" << endl;
};

//arcg: 2; //passa dois argumentos
//argv: {"./hot_cold" "50";}
int main(int argc, char *argv[]) {
    //Gerar números aleatórios
    srand(static_cast<unsigned int>(time(nullptr)));
     
    //conferindo a quantidade de parâmetros
    if (argc > 2) {
        cout << " >>> Argumentos em excesso." << endl;
        usage();
        exit(1); 
    }

    int valor_maximo = 100;
    int valor_escolhido;

    if (argc == 1) { //TA DANDO ERRO AQUI, NÃO TA LENDO 2 ARGUMENTOS ENTÃO NÃO TEM COMO TESTAR A CONDIÇÃO
        valor_escolhido = 30; //valor padrão se nenhum padrão for fornecido
        cout << "Valor máximo é o valor padrão: " << valor_escolhido << endl;
        game_rules();
        game(valor_escolhido, valor_maximo);

    } else if (argc == 2) {
        valor_escolhido = stoi(argv[1]);
        if(valor_escolhido < 1 || valor_escolhido > 100){
            cout << "Valor fora do valor permitido (1 - 100)." << endl;
            usage();
            exit(1);
        }

        cout << "Valor máximo é: " << valor_escolhido << endl;
        game_rules();
        game(valor_escolhido, valor_maximo);
    } else {
        cout << "Argumentos em excesso." << endl;
        usage();
        exit(1);
    }

    return 0;    
}
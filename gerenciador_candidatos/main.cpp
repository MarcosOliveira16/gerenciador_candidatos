#include <iostream>
#include <cstdlib> // Necessário para usar o 'system'
#include <unistd.h> // Necessário para usar o 'sleep'
#include <locale> // Necessário para usar setlocale
#include <limits> // Necessário para usar numeric_limits
#include <regex> // Necessário para usar regex

// Author: Marcos O. - ADS02 P2 2024

using namespace std;

// Definição da estrutura do candidato
struct candidato {
    string nome;
    string cpf;
    int idade;
    candidato *prox;
};

// METODOS AUXILIARES
void menu() {
    cout << "====== Gerenciamento de candidatos =====" << endl;
    cout << "1 - Adicionar ao início\n2 - Adicionar ao final\n3 - Remover do início\n4 - Remover do final\n5 - Quantidade de candidatos\n6 - Exibir todos os candidatos\n0 - Sair\nR: ";
}

void limpaTela() {
    system("cls"); // Para Windows
    // system("clear"); // Para Unix-based (Linux, macOS)
}

void pausa() {
    system("pause"); // Para Windows
    // cout << "Pressione Enter para continuar...";
    // cin.ignore();
    // cin.get();
}

// Função para verificar se a entrada de dados falhou e limpar o buffer
void verificaEntrada() {
    if (cin.fail()) {
        cin.clear(); // Limpa o estado de falha
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignora os caracteres no buffer até a nova linha
        throw invalid_argument("Entrada inválida. Tente novamente.");
    }
}

// Função para validar o CPF no formato XXX.XXX.XXX-XX
bool validarCPF(const string &cpf) {
    const regex padraoCPF("\\d{3}\\.\\d{3}\\.\\d{3}-\\d{2}");
    return regex_match(cpf, padraoCPF);
}

// Função auxiliar para obter dados do candidato
void obterDados(string &nome, string &cpf, int &idade) {
    bool entradaValida = false;
    while (!entradaValida) {
        try {
            cout << "Digite o nome: ";
            cin >> nome;
            verificaEntrada();
            entradaValida = true;
        } catch (const invalid_argument &e) {
            cout << e.what() << endl;
        }
    }
    entradaValida = false;
    while (!entradaValida) {
        try {
            cout << "Digite o CPF (no formato XXX.XXX.XXX-XX): ";
            cin >> cpf;
            verificaEntrada();
            if (!validarCPF(cpf)) {
                throw invalid_argument("Formato de CPF inválido. Tente novamente.");
            }
            entradaValida = true;
        } catch (const invalid_argument &e) {
            cout << e.what() << endl;
        }
    }
    entradaValida = false;
    while (!entradaValida) {
        try {
            cout << "Digite a idade: ";
            cin >> idade;
            verificaEntrada();
            entradaValida = true;
        } catch (const invalid_argument &e) {
            cout << e.what() << endl;
        }
    }
}

// METODOS PRINCIPAIS
// Função para inicializar a lista ligada
void inicializar(candidato *&head) {
    head = NULL;
}

// Função para adicionar um candidato no início da lista
void add_inicio(candidato *&head, string nome, string cpf, int idade) {
    // Criando um novo nó
    candidato *novo = new candidato;

    // Atribuindo valores aos campos do nó
    novo->nome = nome;
    novo->cpf = cpf;
    novo->idade = idade;

    // Inserindo o novo nó no início da lista
    novo->prox = head;
    head = novo;

    cout << "Candidato adicionado com sucesso." << endl;
}

// Função para adicionar um candidato no final da lista
void add_fim(candidato *&head, string nome, string cpf, int idade) {
    // Criando um novo nó
    candidato *novo = new candidato;

    // Atribuindo valores aos campos do nó
    novo->nome = nome;
    novo->cpf = cpf;
    novo->idade = idade;

    // O próximo nó do novo nó será NULL, pois ele será o último
    novo->prox = NULL;

    // Verificando se a lista está vazia
    if (head == NULL) {
        head = novo;
    }
    // Se não estiver vazia, percorrer até o final e adicionar o novo nó
    else {
        candidato *perc = head;
        while (perc->prox != NULL)
            perc = perc->prox;
        perc->prox = novo;
    }

    cout << "Candidato adicionado com sucesso." << endl;
}

// Função para obter o tamanho da lista
int tamanho(candidato *head) {
    int cont = 0;
    candidato *perc = head;

    while (perc != NULL) {
        cont++;
        perc = perc->prox;
    }

    return cont;
}

// Função para remover o primeiro nó da lista
bool remove_inicio(candidato *&head) {
    if (head == NULL) {
        return false;
    }

    candidato *aux = head;
    head = head->prox;
    delete aux;
    return true;
}

// Função para remover o último nó da lista
bool remove_fim(candidato *&head) {
    if (head == NULL) {
        return false;
    }

    if (head->prox == NULL) {
        delete head;
        head = NULL;
        return true;
    }

    candidato *perc = head;
    while (perc->prox->prox != NULL) {
        perc = perc->prox;
    }

    delete perc->prox;
    perc->prox = NULL;
    return true;
}

// Função para exibir todos os candidatos na lista
void exibir_lista(candidato *head) {
    candidato *perc = head;
    if (perc != NULL) {
        while (perc != NULL) {
            cout << "Nome: " << perc->nome << ", CPF: " << perc->cpf << ", Idade: " << perc->idade << endl;
            perc = perc->prox;
        }
    } else {
        cout << "Nenhum candidato cadastrado." << endl;
    }
}

int main() {
    setlocale(LC_ALL, ""); // Permite caracteres especiais

    candidato *head; // Ponteiro para a lista de candidatos
    string nome, cpf;
    int idade, op;
    inicializar(head); // Inicializa a lista como vazia

    do {
        bool entradaValida = false;
        while (!entradaValida) {
            menu();
            try {
                cin >> op;
                verificaEntrada();
                entradaValida = true;
            } catch (const invalid_argument &e) {
                cout << e.what() << endl;
                pausa();
            }
            limpaTela();
        }

        switch (op) {
            case 0:
                cout << "Saindo do sistema..." << endl;
                sleep(3); // delay
                break;
            case 1:
                obterDados(nome, cpf, idade);
                add_inicio(head, nome, cpf, idade);
                pausa();
                limpaTela();
                break;
            case 2:
                obterDados(nome, cpf, idade);
                add_fim(head, nome, cpf, idade);
                pausa();
                limpaTela();
                break;
            case 3:
                if (remove_inicio(head)) {
                    cout << "Removido o primeiro candidato." << endl;
                } else {
                    cout << "A lista está vazia, não há como remover do início." << endl;
                }
                pausa();
                limpaTela();
                break;
            case 4:
                if (remove_fim(head)) {
                    cout << "Removido o último candidato." << endl;
                } else {
                    cout << "A lista está vazia, não há como remover do fim." << endl;
                }
                pausa();
                limpaTela();
                break;
            case 5:
                cout << "Tamanho da lista: " << tamanho(head) << endl;
                pausa();
                limpaTela();
                break;
            case 6:
                cout << "Lista de candidatos:" << endl;
                exibir_lista(head);
                pausa();
                limpaTela();
                break;
            default:
                cout << "Opção inválida, tente novamente!" << endl;
                pausa();
                limpaTela();
        }
    } while (op != 0);

    return 0;
}

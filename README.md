# Gerenciador de Candidatos

Projeto básico elaborado no início de estudos sobre ponteiros na linguagem de C++.

## Análise e Metodologia

### Inclusão de Bibliotecas Necessárias
- `#include <iostream>` para operações de entrada e saída.
- `#include <cstdlib>` para uso do `system`.
- `#include <unistd.h>` para usar `sleep`.
- `#include <locale>` para permitir caracteres especiais.
- `#include <limits>` para tratar erros de entrada.
- `#include <regex>` para validação de formatos de string (CPF).

### Estrutura de Dados
Uso de uma estrutura `candidato` para representar cada nó da lista ligada. A estrutura contém os campos:
- `nome`
- `cpf`
- `idade`
- um ponteiro para o próximo candidato (`prox`).

### Funções Auxiliares
- **`menu`**: Exibe o menu de opções.
- **`limpaTela`** e **`pausa`**: Funções para limpar a tela e pausar a execução para melhorar a usabilidade.
- **`verificaEntrada`**: Verifica se a entrada de dados falhou e limpa o buffer de entrada. Isso ajuda a garantir que entradas inválidas sejam tratadas adequadamente.
- **`validarCPF`**: Usa expressões regulares para validar se o CPF está no formato `XXX.XXX.XXX-XX`.

### Função `obterDados`
Obtém os dados do usuário (`nome`, `cpf` e `idade`), garantindo que sejam válidos antes de permitir a continuação. Utiliza a função `verificaEntrada` para tratamento de erros e a função `validarCPF` para garantir que o CPF esteja no formato correto.

### Funções Principais para Manipulação da Lista
- **`inicializar`**: Inicializa a lista como vazia.
- **`add_inicio`** e **`add_fim`**: Adicionam um candidato no início ou no final da lista, respectivamente.
- **`tamanho`**: Calcula e retorna o tamanho da lista.
- **`remove_inicio`** e **`remove_fim`**: Removem um candidato do início ou do final da lista, respectivamente.
- **`exibir_lista`**: Exibe todos os candidatos na lista.

### Função Principal (`main`)
Inicializa a lista e executa um loop que exibe o menu, obtém a opção do usuário, chama as funções apropriadas com base na opção e limpa a tela após cada operação.

## Boas Práticas Adotadas

### Modularidade
O código é bem modularizado, com funções específicas para cada tarefa, o que facilita a manutenção e a legibilidade.

### Tratamento de Erros
Uso de exceções (`invalid_argument`) para tratar entradas inválidas e garantir que o programa não quebre com entradas incorretas.

### Validação de Dados
- Validação do formato do CPF usando expressões regulares.
- Verificação de falhas de entrada para garantir a robustez.

### Interface de Usuário
Funções `menu`, `limpaTela` e `pausa` melhoram a experiência do usuário, tornando o programa mais amigável.

### Comentários e Documentação
Comentários explicativos no código ajudam a entender a função de cada parte do programa.

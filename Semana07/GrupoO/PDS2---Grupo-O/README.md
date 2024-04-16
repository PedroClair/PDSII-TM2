<div id="top"></div>

# Trabalho Prático - PDS2

## Começando 🚀

O projeto presente neste repositório e nomeado pelos seus colaboradores como "Sitema de transferências" tem como seu principal objetivo replicar o funcionamento de um sistema de banco. As funções que serão  implementadas são as seguintes:


🔸Logar: responsável por exercer a função do cartão nos caixas, essa função pede o usuário e sua respectiva senha;

🔸Sacar: o usuário pode realizar um saque de determinado valor (é preciso ser um valor disponível tanto em sua conta, quanto no limite do caixa);

🔸Depositar: o usuário tem o poder de depositar um valor para sua conta (ilimitado);

🔸Transferir: o caixa suporta inúmeros usuário que podem fazer transferências entre si;

🔸Extrato: é possível visualizar todas as operações realizadas por todos os usuários usando essa função.

🔸Conta Internacional: o usuário tem o poder de converter o patrimonio presente no banco para qualquer tipo de moeda desejada, seja ela dólar, euro, peso ou qualquer outra que a plataforma contenha;

🔸Ativos: é possível comprar e vender ações e criptomoedas dentro do banco, também podendo existir transferências entre usuários desses tipos de moeda;

⚠️ Além destas funções que são expostas ao rodar o código, também foi sugerido para implementar ao código a verificação de CPF e a atribuição de idade, nome e o próprio CPF para todos os usuários. 



### Pré-requisitos
Para começar a utilizar o repositório, você precisa cumprir todos os requisitos abaixo:

* Ter um compilador c++ instalado.
* Ter o mingw na versão 11.2.0 e/ou c++ na versão 17 ou superior.
* Ter o git instalado.
* Estar em um ambiente linux e/ou derivado.


<p align="right">(<a href="#top">Voltar para o topo</a>)</p>

### Instalação

1. Clone o repositório.
   ```sh
   git clone https://github.com/joaoalves31/PDS2---Grupo-O
   ```
2. Execute o comando `make run` para gerar e rodar o projeto.
    ```sh
    make run
    ```

<p align="right">(<a href="#top">Voltar para o topo</a>)</p>

## Como utilizar o Trabalho Prático

Para começar a utilizar, após a instalação, basta rodar:

- Para Linux:

```sh
  ./bin/main
```
- Para Windows:

```sh
  ./bin/main.exe
```

<p align="right">(<a href="#top">Voltar para o topo</a>)</p>


## Contruibuindo

As contribuições são o que tornam a comunidade de código aberto um lugar incrível para aprender, inspirar e criar. Quaisquer contribuições que você fizer são **muito apreciadas**.

Se você tiver uma sugestão para melhorar o projeto, por favor, faça um fork do repositório e crie um pull request. Você também pode simplesmente abrir um issue com a tag "melhoria".
Não se esqueça de dar uma estrela ao projeto! Obrigado novamente!

1. Dê um fork no projeto
2. Cria sua branch de melhoria (`git checkout -b feature/MelhoriaIncrivel`)
3. Faça um commit de suas mudanças (`git commit -m 'feat: adicionado uma melhoria incrível'`)
4. Faça um push para sua branch (`git push origin feature/MelhoriaIncrivel`)
5. Abra um pull request.

<p align="right">(<a href="#top">Voltar para o topo</a>)</p>


## Histórias de Usuário

As User Stories são para representar as principais funcionalidades que o sistema oferecerá aos usuários. Cada uma é acompanhada por um cenário de teste correspondente, visando validar o comportamento do sistema em diferentes situações de uso.

### Cadastro de Usuário

Como novo usuário, desejo me cadastrar no sistema bancário, fornecendo informações básicas, para que eu possa começar a usar os serviços ofertados pelo banco. 
* Um novo usuário acessa a página de cadastro, preenche todos os campos obrigatórios corretamente e clica em "Cadastrar". O sistema cria com sucesso uma nova conta para o usuário.
* Se o CPF fornecido já estiver cadastrado no sistema, exibir uma mensagem de erro indicando que o usuário já possui uma conta.
* Se os campos obrigatórios não forem preenchidos corretamente, exibir mensagens de erro.

### Realizar Saque 

Como um cliente do banco, desejo poder sacar um valor específico da minha conta, para que eu possa ter acesso ao meu dinheiro em espécie quando necessário, respeitando o saldo disponível em minha conta. 
* Um cliente acessa a opção de saque, informa o valor desejado e confirma a transação. O sistema verifica o saldo disponível na conta do cliente e realiza o saque com sucesso, atualizando o saldo.
* Se o saldo disponível na conta for insuficiente para o saque solicitado, exibir uma mensagem de erro informando ao usuário.

### Proteger as Operações com Senha

Como um cliente preocupado com a segurança das minhas transações financeiras, desejo que todas as operações de saque, depósito e transferências sejam autenticadas com minha senha de acesso, para garantir que apenas eu possa autorizar essas transações.
* O usuário acessa a opção de realizar uma operação de saque, depósito ou transferência no sistema. Antes de concluir a operação, o sistema solicita a senha de acesso do usuário. Após inserir a senha corretamente, a operação é autorizada e concluída com sucesso
* Se a senha inserida estiver incorreta, o sistema exibe uma mensagem de erro e não permite a conclusão da operação.

### Realizar Transferência Internacional

Como um cliente do banco, desejo poder transferir dinheiro para uma conta internacional em uma moeda estrangeira, para realizar transações comerciais ou enviar dinheiro para familiares no exterior.
* O usuário acessa a opção de transferência internacional, informa os dados da conta de destino, seleciona a moeda estrangeira desejada e confirma a transação. O sistema converte automaticamente o valor para a moeda de destino, e realiza a transferência com sucesso.
* Se o saldo disponível na conta for insuficiente para a transação solicitada, exibir uma mensagem de erro informando ao usuário.

### Compra de Ações e Criptomoedas

Como um investidor interessado em diversificar meu portfólio, desejo poder comprar e vender ações e criptomoedas diretamente do sistema bancário, para facilitar minhas transações financeiras e gerenciar meus investimentos.
* Um cliente acessa a opção de compra de ativos no sistema, seleciona o tipo de ativo desejado (ações ou criptomoedas), informa a quantidade desejada e confirma a transação. O sistema verifica se há saldo suficiente na conta do cliente e executa a compra do ativo pelo preço atual de mercado, atualizando o saldo do cliente e registrando a transação no extrato.
* Um cliente acessa a opção de venda de ativos no sistema, seleciona o tipo de ativo que deseja vender (ações ou criptomoedas), informa a quantidade a ser vendida e confirma a transação. O sistema verifica se o cliente possui o ativo em sua carteira e executa a venda pelo preço atual de mercado, atualizando o saldo do cliente e registrando a transação no extrato.
* Se o saldo disponível na conta do usuário for insuficiente para a compra da quantidade desejada de ações ou criptomoedas, exibir uma mensagem de erro informando ao usuário.

### Visualização de Extrato

Como um cliente do banco, desejo poder visualizar o extrato da minha conta, para acompanhar todas as transações realizadas e verificar o histórico de movimentações.
* Um cliente acessa a opção de visualização de extrato no menu do sistema, seleciona o período desejado e confirma a solicitação. O sistema exibe todas as transações realizadas dentro do período especificado, incluindo depósitos, saques, transferências e compras de criptomoedas ou ações, em ordem cronológica.
* Se não houver nenhuma transação registrada na conta, exibir uma mensagem indicando que o extrato está vazio.


<p align="right">(<a href="#top">Voltar para o topo</a>)</p>

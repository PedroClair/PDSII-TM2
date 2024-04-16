#include <iostream>

int main()
{
	std::cout << "\nCadastro de Usuário\n" << std::endl;
	std::cout << "Como novo usuário, desejo me cadastrar no sistema bancário, fornecendo informações básicas, para que eu possa começar a usar os serviços ofertados pelo banco. \n * Um novo usuário acessa a página de cadastro, preenche todos os campos obrigatórios corretamente e clica em 'Cadastrar'. O sistema cria com sucesso uma nova conta para o usuário. \n* Se o CPF fornecido já estiver cadastrado no sistema, exibir uma mensagem de erro indicando que o usuário já possui uma conta. \n* Se os campos obrigatórios não forem preenchidos corretamente, exibir mensagens de erro." << std::endl;

	std::cout << "\nRealizar Saque\n" << std::endl; 
	std::cout << "Como um cliente do banco, desejo poder sacar um valor específico da minha conta, para que eu possa ter acesso ao meu dinheiro em espécie quando necessário, respeitando o saldo disponível em minha conta. \n* Um cliente acessa a opção de saque, informa o valor desejado e confirma a transação. O sistema verifica o saldo disponível na conta do cliente e realiza o saque com sucesso, atualizando o saldo. \n* Se o saldo disponível na conta for insuficiente para o saque solicitado, exibir uma mensagem de erro informando ao usuário." << std::endl;

	std::cout << "\nProteger as Operações com Senha\n" << std::endl;
	std::cout << "Como um cliente preocupado com a segurança das minhas transações financeiras, desejo que todas as operações de saque, depósito e transferências sejam autenticadas com minha senha de acesso, para garantir que apenas eu possa autorizar essas transações. \n* O usuário acessa a opção de realizar uma operação de saque, depósito ou transferência no sistema. Antes de concluir a operação, o sistema solicita a senha de acesso do usuário. Após inserir a senha corretamente, a operação é autorizada e concluída com sucesso. \n* Se a senha inserida estiver incorreta, o sistema exibe uma mensagem de erro e não permite a conclusão da operação." << std::endl;

	std::cout << "\nRealizar Transferência Internacional\n" << std::endl;
	std::cout << "Como um cliente do banco, desejo poder transferir dinheiro para uma conta internacional em uma moeda estrangeira, para realizar transações comerciais ou enviar dinheiro para familiares no exterior. \n* O usuário acessa a opção de transferência internacional, informa os dados da conta de destino, seleciona a moeda estrangeira desejada e confirma a transação. O sistema converte automaticamente o valor para a moeda de destino, e realiza a transferência com sucesso. \n* Se o saldo disponível na conta for insuficiente para a transação solicitada, exibir uma mensagem de erro informando ao usuário." << std::endl;

	std::cout << "\nCompra de Ações e Criptomoedas\n" << std::endl;
	std::cout << "Como um investidor interessado em diversificar meu portfólio, desejo poder comprar e vender ações e criptomoedas diretamente do sistema bancário, para facilitar minhas transações financeiras e gerenciar meus investimentos. \n* Um cliente acessa a opção de compra de ativos no sistema, seleciona o tipo de ativo desejado (ações ou criptomoedas), informa a quantidade desejada e confirma a transação. O sistema verifica se há saldo suficiente na conta do cliente e executa a compra do ativo pelo preço atual de mercado, atualizando o saldo do cliente e registrando a transação no extrato. \n* Um cliente acessa a opção de venda de ativos no sistema, seleciona o tipo de ativo que deseja vender (ações ou criptomoedas), informa a quantidade a ser vendida e confirma a transação. O sistema verifica se o cliente possui o ativo em sua carteira e executa a venda pelo preço atual de mercado, atualizando o saldo do cliente e registrando a transação no extrato. \n* Se o saldo disponível na conta do usuário for insuficiente para a compra da quantidade desejada de ações ou criptomoedas, exibir uma mensagem de erro informando ao usuário." << std::endl;

}

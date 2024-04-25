# Sugestões
Oi, galera

Primeiramente gostaria de parabenizar todos pela apresentação, achei todos os temas legais. Sei que programar em C++ pode ser duro as vezes, mas não [desistam](https://www.youtube.com/watch?v=tYzMYcUty6s), vocês precisam dos pontos do trabalho :')

Com o intuito guiar o desenvolvimento das próximas tarefas do trabalho, deixo aqui algumas dicas gerais e outros pontos que não consideramos na avaliação dessa primeira parte do TP, mas que percebemos que podem ser melhorados para as próximas entregas. 

## gitignore
Não suba o binário (executável) e os arquivos objetos (**.o**) no Github. Isso não é uma boa prática e também o binário gerado pelo seu compilador nem sempre executa no computador do seu colega.

Você pode utilizar um arquivo chamado **.gitignore** para dizer ao git quais arquivos ele não deve rastrear, isto é, aqueles que ele não deve considerar que podem ser adicionados junto a um commit.

O link abaixo é de um repositório que já tem vários modelos de arquivos .gitignore para cada linguagem de programação.

https://github.com/github/gitignore

Mais sobre o gitignore pode ser lido em:

https://git-scm.com/docs/gitignore

## includes
Durante as apresentações, vi muitos includes no estilo:

``` c++
#include "../include/isso_eh_feio.hpp"
```

Sim, isso é realmente bem feio. O ideal e sempre fazer assim:

``` c++
#include "isso_eh_menos_feio.hpp"
```

Como a maioria das pessoas usam o vscode, o link abaixo pode ser útil. Em geral, você só precisa dizer ao vscode onde é o diretório dos headers (arquivos .hpp) e ele para de mostrar os erros de arquivo não encontrado.

https://code.visualstudio.com/docs/cpp/c-cpp-properties-schema-reference

Para compilar com o makefile você só precisa definir a constante INCLUDE como o nome do diretório onde está os headers e ai quando for se referir a qualquer um deles, é só colocar o diretório, por exemplo, ${INCLUDE}/meu_arquivo.hpp

## Automatize tarefas maçantes com makefile
A sintaxe do makefile é de fato bem triste, mas você pode fazer a sua vida mais fácil automatizando certas tarefas com ele, tipo 'make clean' para limpar os arquivos derivados do processo de compilação (.o e arquivos binários).

Um tutorial não tão inútil de como fazer sua vida mais fácil com makefile:

https://www.digitalocean.com/community/tutorials/how-to-use-makefiles-to-automate-repetitive-tasks-on-an-ubuntu-vps

Para saber como pegar o nome de todos os arquivos .cpp e .hpp automaticamente e não precisar alterar o makefile sempre que criar um arquivo novo no projeto:

https://stackoverflow.com/questions/3774568/makefile-issue-smart-way-to-scan-directory-tree-for-c-files

## Banco de dados e interface gráfica
Acho muito legal a ideia de integrar banco de dados nos projetos. No entanto, devo dizer que utilizar banco de dados não afeta a nota final do TP. Não é objetivo da disciplina que vocês aprendam a criar e manipular banco de dados. Existem disciplinas especificamente para isso. Outro ponto é que não é tão trivial assim trabalhar com banco de dados, inclusive em C++.

Digo isso não com o intuito de desencorajar o uso de banco de dados, mas sim para que vocês saibam que o caminho pode não ser tão fácil assim. Implementar e fazer isso funcionar corretamente vai demandar um bom tempo a mais. 

No fim, é legal sim fazer um projeto que usa banco de dados, é a oportunidade de aprender algo a mais. Mas, para os fins dessa disciplina, armazenar tudo que seu programa precisa guardar em um arquivo .txt tem a mesma finalidade e é exponencialmente mais fácil.

Para interface gráfica é o mesmo. Você obviamente vai aprender algo a mais, o que é super foda. Maassss, demanda tempo, muito tempo, e de novo, para os fins dessa disciplina, ter interface gráfica ou interagir com o programa somente pela linha de comando não faz muita diferença.

Tenham em mente que o objetivo da disciplina é aprender C++, o Paradigma de Programação Orientada a Objetos e outras práticas relacionadas ao desenvolvimento de software.

Resumo da opera: se você quer e tem tempo, lança um banco de dados e interface gráfica. Se não, faz o básico e vai ser feliz.

## Git
O git foi criado literalmente para solucionar o problema de trabalho em equipe no desenvolvimento de software. Logo, você precisa aprender o básico dele para evitar surtar (se você estiver surtando, pare e escute [essa música](https://www.youtube.com/watch?v=RqjXn2NflqU)) durante o desenvolvimento do trabalho. Abaixo deixo alguns sugestões de leitura que podem lhe economizar tempo no futuro.

Se duas ou mais pessoas precisam trabalhar em funcionalidades no projeto ao mesmo tempo, o que você quer aprender é sobre **Branchs**

https://docs.github.com/pt/pull-requests/collaborating-with-pull-requests/proposing-changes-to-your-work-with-pull-requests/about-branches

Se duas pessoas editaram as mesmas partes de um mesmo arquivo e o git sangrou em mensagens de erro, você quer aprender sobre como resolver **conflitos**

https://docs.github.com/en/pull-requests/collaborating-with-pull-requests/addressing-merge-conflicts/resolving-a-merge-conflict-using-the-command-line

Se você quebrou o código, ele não compila mais (vi isso na apresentação, F) e você não faz ideia de como resolver, você quer aprender sobre como voltar a qualquer commit anterior na linha do tempo do git

https://stackoverflow.com/questions/4114095/how-do-i-revert-a-git-repository-to-a-previous-commit

No mais, o gitflow e uma forma de trabalhar em equipe com o git. Você não precisa implementar isso no projeto, mas ajuda a organizar a festa e muitas empresas de software utilizam esse método (sei que a maioria de vocês são engenheiros, mas vai que né)

https://www.alura.com.br/artigos/git-flow-o-que-e-como-quando-utilizar

# O fim é triste
É isso. Mais dicas na monitoria :')

Lucas

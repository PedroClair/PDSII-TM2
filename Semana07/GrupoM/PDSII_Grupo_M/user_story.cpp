

#include "user_story.hpp"

void User_story::story_status(){

    cout << "\nComo um jogador, eu gostaria de poder visualiazar meus status para saber se estou progredindo no jogo." << endl;
    cout << "Criterios de avaliacao:\nVisualizar vida, forca e defesa em qualquer ponto do jogo." << endl;
    cout << "Apos o personagem ganhar um nivel, deve mostrar o quanto ele ganhou em cada atributo." << endl;
    cout << "Exibir em numeros inteiros o status." << endl;
    cout << "Pausar o jogo enquanto o status esta sendo visualizado." << endl;
}

void User_story::story_customizacao(){
    std::cout << "\nEu, como jogador, quero poder criar um personagem para comecar o jogo." << std::endl;
    std::cout << "Criterios de Avaliacao:" << std::endl;
    std::cout << "Poder escolher raca entre humano, anao, elfo e gnomo." << std::endl;
    std::cout << "Poder escolher classe entre guerreiro, ladino, mago e clerigo." << std::endl;
    std::cout << "Poder distribuir 25 pontos em 5 atributos: forca, agilidade, defesa, inteligencia e vida." << std::endl;
    std::cout << "Comeca pelo nivel 1." << std::endl;
}

void User_story::story_interacaoNPCs(){
    std::cout << "\nEu, como um jogador, quero poder interagir com NPCs para entender melhor o enredo do jogo." << std::endl;
    std::cout << "Criterios de Avaliacao:" << std::endl;
    std::cout << "O NPC deve ter uma historia ou uma missao a ser realizada." << std::endl;
    std::cout << "O jogador deve escolher entre aceitar a missao ou recusar." << std::endl;
    std::cout << "Apos a missao ser realizada o personagem do jogador deve ser recompensado." << std::endl;
    std::cout << "Exibir na tela a recompensa." << std::endl;
}

void User_story::story_menu(){

    cout << "\nEu, como Jogador, gostaria de ter um menu para configurar minha experiencia de jogo." << endl;
    cout << "Criterios de Avaliacao:" << endl;
    cout << "Deve ser exibido assim que o programa inciar." << endl;
    cout << "Possuir opcao salvar o jogo." << endl;
    cout << "Possuir opcao carregar jogo salvo. " << endl;
    cout << "Permite ao jogador sair do jogo e encerrar o programa." << endl;

}
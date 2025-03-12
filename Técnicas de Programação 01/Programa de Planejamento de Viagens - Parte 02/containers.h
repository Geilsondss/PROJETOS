#ifndef CONTAINERS_H_INCLUDED
#define CONTAINERS_H_INCLUDED
#include "entidades.h"
#include <list>
#include <map>


using namespace std;
/**
 * @file Container.h
 * @brief Classes de cont�ineres para armazenamento em mem�ria das entidades do sistema.
 * @date 2025
 */

/**
 * @brief A classe ContainerConta implementa o salvamento em mem�ria dos dados passados em cada um dos m�todos.
 *
 * Nela ficam armazenados todos os dados e informa��es das contas.
 */
class ContainerConta { // Tau� Valentim - 231021389
private:
    /**
     * @brief Cont�iner que armazena as contas, onde a chave � o c�digo da conta e o valor � o objeto Conta.
     */
    map<string, Conta> container;

    /**
     * @brief Ponteiro para a inst�ncia �nica da classe ContainerConta, implementando o padr�o Singleton.
     */
    static ContainerConta *instancia;

    /**
     * @brief Construtor privado da classe.
     */
    ContainerConta(){};

public:
    /**
     * @brief Retorna a inst�ncia �nica da classe ContainerConta.
     *
     * Implementa o padr�o Singleton para garantir que exista apenas uma inst�ncia.
     *
     * @return Ponteiro para a inst�ncia �nica de ContainerConta.
     */
    static ContainerConta* getInstancia(){
        static ContainerConta instancia;
        return &instancia;
    };

    /**
     * @brief Autentica uma conta no sistema.
     *
     * @param codigo Refer�ncia para o c�digo da conta.
     * @param senha Refer�ncia para a senha da conta.
     * @return Retorna true se a autentica��o for bem-sucedida, false caso contr�rio.
     */
    bool autenticar(Codigo&, Senha&);

    /**
     * @brief Inclui uma nova conta no cont�iner.
     *
     * @param conta Objeto Conta que ser� inserido no cont�iner.
     * @return Retorna true se a conta foi criada com sucesso, false caso contr�rio.
     */
    bool criar(Conta);

    /**
     * @brief Remove uma conta do cont�iner.
     *
     * @param codigo C�digo da conta que ser� removida.
     * @return Retorna true se a conta foi removida com sucesso, false caso contr�rio.
     */
    bool excluir(Codigo);

    /**
     * @brief Pesquisa uma conta pelo seu c�digo.
     *
     * @param conta Ponteiro para o objeto Conta que ser� preenchido com os dados encontrados.
     * @return Retorna true se a conta for encontrada, false caso contr�rio.
     */
    bool pesquisar(Conta*);

    /**
     * @brief Atualiza as informa��es de uma conta existente.
     *
     * @param conta Objeto Conta que cont�m as novas informa��es.
     * @return Retorna true se a atualiza��o foi realizada com sucesso, false caso contr�rio.
     */
    bool atualizar(Conta);
};




//Jo�o Vitor Santos de Sena - 190089890
// Forward declaration da classe Container
class Container;

/**
 * @brief Cont�iner para armazenamento e gerenciamento de viagens.
 */
class ContainerViagem {
    friend class Container;
private:
    static list<Viagem> viagens;  ///< Lista est�tica para armazenamento de viagens

public:
    /**
     * @brief Inclui uma nova viagem no cont�iner.
     *
     * @param viagem Objeto Viagem a ser inclu�do.
     * @throw invalid_argument Se j� existir uma viagem com o mesmo c�digo.
     */
    static void incluir(Viagem viagem);

    /**
     * @brief Remove uma viagem do cont�iner.
     *
     * @param codigo C�digo da viagem a ser removida.
     * @throw invalid_argument Se n�o existir viagem com o c�digo especificado.
     */
    static void remover(Codigo codigo);

    /**
     * @brief Atualiza os dados de uma viagem existente.
     *
     * @param viagem Objeto Viagem com os novos dados.
     * @throw invalid_argument Se n�o existir viagem com o c�digo especificado.
     */
    static void atualizar(Viagem viagem);

    /**
     * @brief Pesquisa uma viagem pelo seu c�digo.
     *
     * @param codigo C�digo da viagem a ser pesquisada.
     * @return Viagem Objeto encontrado.
     * @throw invalid_argument Se n�o existir viagem com o c�digo especificado.
     */
    static Viagem pesquisar(Codigo codigo);

    /**
     * @brief Retorna todas as viagens armazenadas.
     *
     * @return list<Viagem> Lista de todas as viagens.
     */
    static list<Viagem> getViagens();

    /**
     * @brief Retorna todas as viagens associadas a uma conta.
     *
     * @param codigo C�digo da conta.
     * @return list<Viagem> Lista de viagens da conta especificada.
     */
    static list<Viagem> getViagensPorConta(Codigo codigo);
};

/**
 * @brief Cont�iner para armazenamento e gerenciamento de destinos.
 */
class ContainerDestino {
    friend class Container;
private:
    static list<Destino> destinos;  ///< Lista est�tica para armazenamento de destinos

public:
    /**
     * @brief Inclui um novo destino no cont�iner.
     *
     * @param destino Objeto Destino a ser inclu�do.
     * @throw invalid_argument Se j� existir um destino com o mesmo c�digo.
     */
    static void incluir(Destino destino);

    /**
     * @brief Remove um destino do cont�iner.
     *
     * @param codigo C�digo do destino a ser removido.
     * @throw invalid_argument Se n�o existir destino com o c�digo especificado.
     */
    static void remover(Codigo codigo);

    /**
     * @brief Atualiza os dados de um destino existente.
     *
     * @param destino Objeto Destino com os novos dados.
     * @throw invalid_argument Se n�o existir destino com o c�digo especificado.
     */
    static void atualizar(Destino destino);

    /**
     * @brief Pesquisa um destino pelo seu c�digo.
     *
     * @param codigo C�digo do destino a ser pesquisado.
     * @return Destino Objeto encontrado.
     * @throw invalid_argument Se n�o existir destino com o c�digo especificado.
     */
    static Destino pesquisar(Codigo codigo);

    /**
     * @brief Retorna todos os destinos armazenados.
     *
     * @return list<Destino> Lista de todos os destinos.
     */
    static list<Destino> getDestinos();

    /**
     * @brief Retorna todos os destinos associados a uma viagem.
     *
     * @param codigo C�digo da viagem.
     * @return list<Destino> Lista de destinos da viagem especificada.
     */
    static list<Destino> getDestinosPorViagem(Codigo codigo);
};

/**
 * @brief Cont�iner para armazenamento e gerenciamento de hospedagens.
 */
class ContainerHospedagem {
    friend class Container;
private:
    static list<Hospedagem> hospedagens;  ///< Lista est�tica para armazenamento de hospedagens

public:
    /**
     * @brief Inclui uma nova hospedagem no cont�iner.
     *
     * @param hospedagem Objeto Hospedagem a ser inclu�do.
     * @throw invalid_argument Se j� existir uma hospedagem com o mesmo c�digo.
     */
    static void incluir(Hospedagem hospedagem);

    /**
     * @brief Remove uma hospedagem do cont�iner.
     *
     * @param codigo C�digo da hospedagem a ser removida.
     * @throw invalid_argument Se n�o existir hospedagem com o c�digo especificado.
     */
    static void remover(Codigo codigo);

    /**
     * @brief Atualiza os dados de uma hospedagem existente.
     *
     * @param hospedagem Objeto Hospedagem com os novos dados.
     * @throw invalid_argument Se n�o existir hospedagem com o c�digo especificado.
     */
    static void atualizar(Hospedagem hospedagem);

    /**
     * @brief Pesquisa uma hospedagem pelo seu c�digo.
     *
     * @param codigo C�digo da hospedagem a ser pesquisada.
     * @return Hospedagem Objeto encontrado.
     * @throw invalid_argument Se n�o existir hospedagem com o c�digo especificado.
     */
    static Hospedagem pesquisar(Codigo codigo);

    /**
     * @brief Retorna todas as hospedagens armazenadas.
     *
     * @return list<Hospedagem> Lista de todas as hospedagens.
     */
    static list<Hospedagem> getHospedagens();

    /**
     * @brief Retorna todas as hospedagens associadas a um destino.
     *
     * @param codigo C�digo do destino.
     * @return list<Hospedagem> Lista de hospedagens do destino especificado.
     */
    static list<Hospedagem> getHospedagensPorDestino(Codigo codigo);
};

/**
 * @brief Cont�iner para armazenamento e gerenciamento de atividades.
 */
class ContainerAtividade {
    friend class Container;
private:
    static list<Atividade> atividades;  ///< Lista est�tica para armazenamento de atividades

public:
    /**
     * @brief Inclui uma nova atividade no cont�iner.
     *
     * @param atividade Objeto Atividade a ser inclu�do.
     * @throw invalid_argument Se j� existir uma atividade com o mesmo c�digo.
     */
    static void incluir(Atividade atividade);

    /**
     * @brief Remove uma atividade do cont�iner.
     *
     * @param codigo C�digo da atividade a ser removida.
     * @throw invalid_argument Se n�o existir atividade com o c�digo especificado.
     */
    static void remover(Codigo codigo);

    /**
     * @brief Atualiza os dados de uma atividade existente.
     *
     * @param atividade Objeto Atividade com os novos dados.
     * @throw invalid_argument Se n�o existir atividade com o c�digo especificado.
     */
    static void atualizar(Atividade atividade);

    /**
     * @brief Pesquisa uma atividade pelo seu c�digo.
     *
     * @param codigo C�digo da atividade a ser pesquisada.
     * @return Atividade Objeto encontrado.
     * @throw invalid_argument Se n�o existir atividade com o c�digo especificado.
     */
    static Atividade pesquisar(Codigo codigo);

    /**
     * @brief Retorna todas as atividades armazenadas.
     *
     * @return list<Atividade> Lista de todas as atividades.
     */
    static list<Atividade> getAtividades();

    /**
     * @brief Retorna todas as atividades associadas a um destino.
     *
     * @param codigo C�digo do destino.
     * @return list<Atividade> Lista de atividades do destino especificado.
     */
    static list<Atividade> getAtividadesPorDestino(Codigo codigo);
};

/**
 * @brief Classe est�tica que fornece acesso aos cont�ineres do sistema.
 */
class Container {
public:
    /**
     * @brief Inclui uma nova viagem no cont�iner.
     *
     * @param viagem Objeto Viagem a ser inclu�do.
     * @throw invalid_argument Se j� existir uma viagem com o mesmo c�digo.
     */
    static void incluirViagem(Viagem viagem) {
        ContainerViagem::incluir(viagem);
    }

    /**
     * @brief Remove uma viagem do cont�iner.
     *
     * @param codigo C�digo da viagem a ser removida.
     * @throw invalid_argument Se n�o existir viagem com o c�digo especificado.
     */
    static void removerViagem(Codigo codigo) {
        ContainerViagem::remover(codigo);
    }

    /**
     * @brief Atualiza os dados de uma viagem existente.
     *
     * @param viagem Objeto Viagem com os novos dados.
     * @throw invalid_argument Se n�o existir viagem com o c�digo especificado.
     */
    static void atualizarViagem(Viagem viagem) {
        ContainerViagem::atualizar(viagem);
    }

    /**
     * @brief Pesquisa uma viagem pelo seu c�digo.
     *
     * @param codigo C�digo da viagem a ser pesquisada.
     * @return Viagem Objeto encontrado.
     * @throw invalid_argument Se n�o existir viagem com o c�digo especificado.
     */
    static Viagem pesquisarViagem(Codigo codigo) {
        return ContainerViagem::pesquisar(codigo);
    }

    /**
     * @brief Retorna todas as viagens armazenadas.
     *
     * @return list<Viagem> Lista de todas as viagens.
     */
    static list<Viagem> getViagens() {
        return ContainerViagem::getViagens();
    }

    /**
     * @brief Retorna todas as viagens associadas a uma conta.
     *
     * @param codigo C�digo da conta.
     * @return list<Viagem> Lista de viagens da conta especificada.
     */
    static list<Viagem> getViagensPorConta(Codigo codigo) {
        return ContainerViagem::getViagensPorConta(codigo);
    }

    /**
     * @brief Inclui um novo destino no cont�iner.
     *
     * @param destino Objeto Destino a ser inclu�do.
     * @throw invalid_argument Se j� existir um destino com o mesmo c�digo.
     */
    static void incluirDestino(Destino destino) {
        ContainerDestino::incluir(destino);
    }

    /**
     * @brief Remove um destino do cont�iner.
     *
     * @param codigo C�digo do destino a ser removido.
     * @throw invalid_argument Se n�o existir destino com o c�digo especificado.
     */
    static void removerDestino(Codigo codigo) {
        ContainerDestino::remover(codigo);
    }

    /**
     * @brief Atualiza os dados de um destino existente.
     *
     * @param destino Objeto Destino com os novos dados.
     * @throw invalid_argument Se n�o existir destino com o c�digo especificado.
     */
    static void atualizarDestino(Destino destino) {
        ContainerDestino::atualizar(destino);
    }

    /**
     * @brief Pesquisa um destino pelo seu c�digo.
     *
     * @param codigo C�digo do destino a ser pesquisado.
     * @return Destino Objeto encontrado.
     * @throw invalid_argument Se n�o existir destino com o c�digo especificado.
     */
    static Destino pesquisarDestino(Codigo codigo) {
        return ContainerDestino::pesquisar(codigo);
    }

    /**
     * @brief Retorna todos os destinos armazenados.
     *
     * @return list<Destino> Lista de todos os destinos.
     */
    static list<Destino> getDestinos() {
        return ContainerDestino::getDestinos();
    }

    /**
     * @brief Retorna todos os destinos associados a uma viagem.
     *
     * @param codigo C�digo da viagem.
     * @return list<Destino> Lista de destinos da viagem especificada.
     */
    static list<Destino> getDestinosPorViagem(Codigo codigo) {
        return ContainerDestino::getDestinosPorViagem(codigo);
    }

    /**
     * @brief Inclui uma nova hospedagem no cont�iner.
     *
     * @param hospedagem Objeto Hospedagem a ser inclu�do.
     * @throw invalid_argument Se j� existir uma hospedagem com o mesmo c�digo.
     */
    static void incluirHospedagem(Hospedagem hospedagem) {
        ContainerHospedagem::incluir(hospedagem);
    }

    /**
     * @brief Remove uma hospedagem do cont�iner.
     *
     * @param codigo C�digo da hospedagem a ser removida.
     * @throw invalid_argument Se n�o existir hospedagem com o c�digo especificado.
     */
    static void removerHospedagem(Codigo codigo) {
        ContainerHospedagem::remover(codigo);
    }

    /**
     * @brief Atualiza os dados de uma hospedagem existente.
     *
     * @param hospedagem Objeto Hospedagem com os novos dados.
     * @throw invalid_argument Se n�o existir hospedagem com o c�digo especificado.
     */
    static void atualizarHospedagem(Hospedagem hospedagem) {
        ContainerHospedagem::atualizar(hospedagem);
    }

    /**
     * @brief Pesquisa uma hospedagem pelo seu c�digo.
     *
     * @param codigo C�digo da hospedagem a ser pesquisada.
     * @return Hospedagem Objeto encontrado.
     * @throw invalid_argument Se n�o existir hospedagem com o c�digo especificado.
     */
    static Hospedagem pesquisarHospedagem(Codigo codigo) {
        return ContainerHospedagem::pesquisar(codigo);
    }

    /**
     * @brief Retorna todas as hospedagens armazenadas.
     *
     * @return list<Hospedagem> Lista de todas as hospedagens.
     */
    static list<Hospedagem> getHospedagens() {
        return ContainerHospedagem::getHospedagens();
    }

    /**
     * @brief Retorna todas as hospedagens associadas a um destino.
     *
     * @param codigo C�digo do destino.
     * @return list<Hospedagem> Lista de hospedagens do destino especificado.
     */
    static list<Hospedagem> getHospedagensPorDestino(Codigo codigo) {
        return ContainerHospedagem::getHospedagensPorDestino(codigo);
    }

    /**
     * @brief Inclui uma nova atividade no cont�iner.
     *
     * @param atividade Objeto Atividade a ser inclu�do.
     * @throw invalid_argument Se j� existir uma atividade com o mesmo c�digo.
     */
    static void inserirAtividade(Atividade atividade) {
        ContainerAtividade::incluir(atividade);
    }

    /**
     * @brief Obt�m uma atividade pelo c�digo.
     * @param codigo C�digo da atividade.
     * @param atividade Ponteiro para armazenar a atividade.
     */
    static void getAtividade(Codigo codigo, Atividade* atividade) {
        *atividade = ContainerAtividade::pesquisar(codigo);
    }

    /**
     * @brief Atualiza uma atividade existente.
     * @param atividade Atividade com os novos dados.
     */
    static void atualizarAtividade(Atividade atividade) {
        ContainerAtividade::atualizar(atividade);
    }

    /**
     * @brief Exclui uma atividade.
     * @param codigo C�digo da atividade a ser exclu�da.
     */
    static void excluirAtividade(Codigo codigo) {
        ContainerAtividade::remover(codigo);
    }

    /**
     * @brief Obt�m todas as atividades.
     * @return Lista de todas as atividades.
     */
    static list<Atividade> getAtividades() {
        return ContainerAtividade::getAtividades();
    }

    /**
     * @brief Obt�m todas as atividades de um destino.
     * @param codigo C�digo do destino.
     * @return Lista de atividades do destino.
     */
    static list<Atividade> getAtividadesPorDestino(Codigo codigo) {
        return ContainerAtividade::getAtividadesPorDestino(codigo);
    }
};



#endif // CONTAINERS_H_INCLUDED

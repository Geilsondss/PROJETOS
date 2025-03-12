#ifndef INTERFACES_H_INCLUDED
#define INTERFACES_H_INCLUDED
#include "entidades.h"
#include <stdexcept>
#include <list>
#include <iostream>


/**
 * @file interfaces.h
 * @brief Declara��o das interfaces do sistema de gerenciamento de viagens.
 * @date 2025
 */

using namespace std;

//ARTHUS CESAR DIAS FERNANDES - 231006103
class IntServAutenticacao;

/**
*@brief A classe IntAprAutenticacao implementa uma classe abstrata com um metodo virtual "autenticar" e um destrutor.
*/

class IntAprAutenticacao{ //Geilson dos Santos - 231006239
public:
     /**
     * @brief Autentica os dados de uma conta.
     */
    virtual bool autenticar(Codigo*) = 0;
    /**
     * @brief Define a controladora de servi�o a ser utilizada.
     */
    virtual void setCntrIntServAutenticacao(IntServAutenticacao*) = 0;
    /**
     * @brief Destrutor padr�o.
     */
    virtual ~IntAprAutenticacao(){}
};

/**
*@brief A classe IntAprConta implementa uma classe abstrata com metodos virtuais "criar" e "executar" para Conta e um destrutor.
*/
class IntAprConta{ //Michele Nakagomi (232029078)
public:
    /**
     * @brief M�todo para criar uma conta, permitindo a cria��o de uma conta conforme as regras estabelecidas.
     */
    virtual void criar() = 0;
    /**
     * @brief Executa opera��es em uma conta associada por meio do c�digo fornecido, podendo o usu�rio consultar, atualizar ou excluir uma conta.
     * @param codigo C�digo identificador da conta a ser manipulada.
     * @return true se a opera��o foi bem-sucedida, false caso contr�rio.
     */
    virtual bool executar(Codigo) = 0;
    /**
     * @brief Destrutor padr�o.
     */
    virtual ~IntAprConta(){}
};



/**
*@brief A classe IntServAutenticacao implementa uma classe abstrata com um metodo virtual "autenticar" e um destrutor.
*/
class IntServAutenticacao{ // Tau� Valentim - 231021389
public:
    virtual bool autenticar(Codigo&, Senha&) = 0;
    /**
     * @brief Destrutor padr�o.
     */
    virtual ~IntServAutenticacao(){}
};

/**
*@brief A classe IntServConta implementa uma classe abstrata com metodos virtuais "criar", "pesquisar", "excluir" e "atualizar" para Conta e um destrutor.
*/
class IntServConta{ // Tau� Valentim - 231021389
public:
    /**
     * @brief Cria uma nova conta, utilizando um codigo de 6 digitos e um senha de 5 digitos.
     */
    virtual bool criar(Conta) = 0;
    /**
     * @brief Pesquisa por uma conta existente, caso nao exista o metodo retorna o erro.
     */
    virtual bool pesquisar(Conta*) = 0;
    /**
     * @brief Atualiza os dados de uma conta (Nova senha)
     */
    virtual bool atualizar(Conta) = 0;
    /**
     * @brief Exclui a conta.
     */
    virtual bool excluir(Codigo) = 0;
    /**
     * @brief Destrutor padr�o.
     */
    virtual ~IntServConta(){}
};


//Jo�o Vitor Santos de Sena - 190089890
/**
 * @brief Interface para servi�os de gerenciamento de viagens.
 *
 * Esta interface define os m�todos que devem ser implementados por
 * uma classe que forne�a servi�os de gerenciamento de viagens,
 * destinos e hospedagens.
 */
class ISV {
public:
    /**
     * @brief Destrutor virtual.
     */
    virtual ~ISV() {}

    // M�todos para gerenciamento de viagens

    /**
     * @brief Cria uma nova viagem.
     * @param viagem Objeto Viagem a ser criado.
     * @throw invalid_argument Se j� existir uma viagem com o mesmo c�digo.
     */
    virtual void criarViagem(Viagem viagem) = 0;

    /**
     * @brief Visualiza os dados de uma viagem.
     * @param codigo C�digo da viagem a ser visualizada.
     * @param[out] viagem Ponteiro onde ser�o armazenados os dados da viagem.
     * @throw invalid_argument Se a viagem n�o for encontrada.
     */
    virtual void visualizarViagem(Codigo codigo, Viagem* viagem) = 0;

    /**
     * @brief Atualiza os dados de uma viagem.
     * @param viagem Objeto Viagem com os novos dados.
     * @throw invalid_argument Se a viagem n�o for encontrada.
     */
    virtual void atualizarViagem(Viagem viagem) = 0;

    /**
     * @brief Exclui uma viagem.
     * @param codigo C�digo da viagem a ser exclu�da.
     * @throw invalid_argument Se a viagem n�o for encontrada.
     */
    virtual void excluirViagem(Codigo codigo) = 0;

    /**
     * @brief Lista todas as viagens.
     * @return Lista de todas as viagens cadastradas.
     */
    virtual list<Viagem> listarViagens() = 0;

    /**
     * @brief Lista as viagens de uma conta espec�fica.
     * @param codigo C�digo da conta.
     * @return Lista de viagens da conta especificada.
     */
    virtual list<Viagem> listarViagensPorConta(Codigo codigo) = 0;

    // M�todos para gerenciamento de destinos

    /**
     * @brief Cria um novo destino.
     * @param destino Objeto Destino a ser criado.
     * @throw invalid_argument Se j� existir um destino com o mesmo c�digo.
     */
    virtual void criarDestino(Destino destino) = 0;

    /**
     * @brief Visualiza os dados de um destino.
     * @param codigo C�digo do destino a ser visualizado.
     * @param[out] destino Ponteiro onde ser�o armazenados os dados do destino.
     * @throw invalid_argument Se o destino n�o for encontrado.
     */
    virtual void visualizarDestino(Codigo codigo, Destino* destino) = 0;

    /**
     * @brief Atualiza os dados de um destino.
     * @param destino Objeto Destino com os novos dados.
     * @throw invalid_argument Se o destino n�o for encontrado.
     */
    virtual void atualizarDestino(Destino destino) = 0;

    /**
     * @brief Exclui um destino.
     * @param codigo C�digo do destino a ser exclu�do.
     * @throw invalid_argument Se o destino n�o for encontrado.
     */
    virtual void excluirDestino(Codigo codigo) = 0;

    /**
     * @brief Lista todos os destinos.
     * @return Lista de todos os destinos cadastrados.
     */
    virtual list<Destino> listarDestinos() = 0;

    /**
     * @brief Lista os destinos de uma viagem espec�fica.
     * @param codigo C�digo da viagem.
     * @return Lista de destinos da viagem especificada.
     */
    virtual list<Destino> listarDestinosPorViagem(Codigo codigo) = 0;

    // M�todos para gerenciamento de hospedagens

    /**
     * @brief Cria uma nova hospedagem.
     * @param hospedagem Objeto Hospedagem a ser criado.
     * @throw invalid_argument Se j� existir uma hospedagem com o mesmo c�digo.
     */
    virtual void criarHospedagem(Hospedagem hospedagem) = 0;

    /**
     * @brief Visualiza os dados de uma hospedagem.
     * @param codigo C�digo da hospedagem a ser visualizada.
     * @param[out] hospedagem Ponteiro onde ser�o armazenados os dados da hospedagem.
     * @throw invalid_argument Se a hospedagem n�o for encontrada.
     */
    virtual void visualizarHospedagem(Codigo codigo, Hospedagem* hospedagem) = 0;

    /**
     * @brief Atualiza os dados de uma hospedagem.
     * @param hospedagem Objeto Hospedagem com os novos dados.
     * @throw invalid_argument Se a hospedagem n�o for encontrada.
     */
    virtual void atualizarHospedagem(Hospedagem hospedagem) = 0;

    /**
     * @brief Exclui uma hospedagem.
     * @param codigo C�digo da hospedagem a ser exclu�da.
     * @throw invalid_argument Se a hospedagem n�o for encontrada.
     */
    virtual void excluirHospedagem(Codigo codigo) = 0;

    /**
     * @brief Lista todas as hospedagens.
     * @return Lista de todas as hospedagens cadastradas.
     */
    virtual list<Hospedagem> listarHospedagens() = 0;

    /**
     * @brief Lista as hospedagens de um destino espec�fico.
     * @param codigo C�digo do destino.
     * @return Lista de hospedagens do destino especificado.
     */
    virtual list<Hospedagem> listarHospedagensPorDestino(Codigo codigo) = 0;

    /**
     * @brief Calcula o custo total de uma viagem.
     * @param codigo C�digo da viagem.
     * @return Custo total da viagem em reais.
     * @throw invalid_argument Se a viagem n�o for encontrada.
     */
    virtual float calcularCustoViagem(Codigo codigo) = 0;

    /**
     * @brief Valida as datas de um destino.
     * @param destino Destino a ser validado.
     * @throw invalid_argument Se a data de t�rmino for anterior � data de in�cio.
     */
    virtual void validarDatasDestino(const Destino& destino) = 0;

    // M�todos para gerenciamento de atividades

    /**
     * @brief Cria uma nova atividade.
     * @param atividade Objeto Atividade a ser criado.
     * @throw invalid_argument Se j� existir uma atividade com o mesmo c�digo.
     */
    virtual void criarAtividade(Atividade atividade) = 0;

    /**
     * @brief Visualiza os dados de uma atividade.
     * @param codigo C�digo da atividade a ser visualizada.
     * @param[out] atividade Ponteiro onde ser�o armazenados os dados da atividade.
     * @throw invalid_argument Se a atividade n�o for encontrada.
     */
    virtual void visualizarAtividade(Codigo codigo, Atividade* atividade) = 0;

    /**
     * @brief Atualiza os dados de uma atividade.
     * @param atividade Objeto Atividade com os novos dados.
     * @throw invalid_argument Se a atividade n�o for encontrada.
     */
    virtual void atualizarAtividade(Atividade atividade) = 0;

    /**
     * @brief Exclui uma atividade.
     * @param codigo C�digo da atividade a ser exclu�da.
     * @throw invalid_argument Se a atividade n�o for encontrada.
     */
    virtual void excluirAtividade(Codigo codigo) = 0;

    /**
     * @brief Lista todas as atividades.
     * @return Lista de todas as atividades cadastradas.
     */
    virtual list<Atividade> listarAtividades() = 0;

    /**
     * @brief Lista as atividades de um destino espec�fico.
     * @param codigo C�digo do destino.
     * @return Lista de atividades do destino especificado.
     */
    virtual list<Atividade> listarAtividadesPorDestino(Codigo codigo) = 0;

    /**
     * @brief Valida a data de uma atividade em rela��o ao seu destino.
     * @param atividade Atividade a ser validada.
     * @param destino Destino associado � atividade.
     * @throw invalid_argument Se a data da atividade estiver fora do per�odo do destino.
     */
    virtual void validarDataAtividade(const Atividade& atividade, const Destino& destino) = 0;
};

/**
 * @brief Interface para apresenta��o de viagens.
 *
 * Esta interface define os m�todos que devem ser implementados por
 * uma classe que forne�a a interface com o usu�rio para o gerenciamento
 * de viagens.
 */
class IAV {
public:
    /**
     * @brief Destrutor virtual.
     */
    virtual ~IAV() {}

    /**
     * @brief Define a controladora de servi�o a ser utilizada.
     * @param cntrServViagem Ponteiro para a controladora de servi�o.
     */
    virtual void setCntrServViagem(ISV* cntrServViagem) = 0;

    /**
     * @brief Executa a interface principal de gerenciamento de viagens.
     * @param codigoUsuario C�digo do usu�rio logado.
     */
    virtual void executar(Codigo codigoUsuario) = 0;
};


#endif // INTERFACES_H_INCLUDED

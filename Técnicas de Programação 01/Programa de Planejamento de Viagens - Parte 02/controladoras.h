#ifndef CONTROLADORAS_H_INCLUDED
#define CONTROLADORAS_H_INCLUDED
#include "interfaces.h"
#include "containers.h"
#include <iomanip>
#include <list>


using namespace std;

/**
 * @file Controladoras.h
 * @brief Declara��o das classes controladoras de apresenta��o do sistema.
 * @date 2025
 */

/**
*@brief A classe CntrIntAprAutenticacao controla a chamada da camada de servico responsavel pela autenticacao, al�m de interagir com o usuario validando os dados (Codigo e Senha) passados por ele.
*/

class CntrIntAprAutenticacao:public IntAprAutenticacao { //Geilson dos Santos - 231006239
private:
    IntServAutenticacao *cntrIntServAutenticacao;
public:
    bool autenticar(Codigo*);
    void setCntrIntServAutenticacao(IntServAutenticacao*);
};

void inline CntrIntAprAutenticacao::setCntrIntServAutenticacao(IntServAutenticacao *cntrIntServAutenticacao){
        this->cntrIntServAutenticacao = cntrIntServAutenticacao;
}

/**
*@brief A classe CntrIntAprConta controla a chamada da camada de servico responsavel pela criacao e gereciamento da conta, al�m de interagir com o usuario validando os dados (Codigo e Senha) passados por ele na criacao da conta.
*/

class CntrIntAprConta:public IntAprConta { //Michele Nakagomi (232029078)
private:
    IntServConta *cntrIntServConta;
public:
    /**
     * @brief M�todo para criar uma nova conta.
     */
    void criar();
    /**
     * @brief Executa opera��es em uma conta associada ao c�digo fornecido, permitindo o usu�rio visualizar, atualizar ou excluir uma conta.
     * @param codigo C�digo identificador da conta a ser manipulada.
     * @return true se a opera��o foi bem-sucedida, false caso contr�rio.
     */
    bool executar(Codigo);
    /**
     * @brief Define o controlador de servi�o de conta.
     * @param cntrIntServConta Ponteiro para a interface de servi�o de conta.
     */
    void setCntrIntServConta(IntServConta*);
};

void inline CntrIntAprConta::setCntrIntServConta(IntServConta *cntrIntServConta){
        this->cntrIntServConta = cntrIntServConta;
}

/**
*@brief A classe CntrIntAprInvestimento controla a chamada da camada de servico responsavel pela criacao e gereciamento da conta, al�m de interagir com o usuario validando os dados (Codigo e Senha) passados por ele na criacao da conta.
*/


/**
*@brief A classe CntrIntServAutenticacao controla o chamamento do container resposavel pelo comparacao dos dados passados em cada um dos metodos e o que esta salvo em memoria, com ela e possivel gerenciar a autenticacao.
*/
class CntrIntServAutenticacao:public IntServAutenticacao { //ARTHUS CESAR DIAS FERNANDES - 231006103
public:
    bool autenticar(Codigo&, Senha&);
    static CntrIntServAutenticacao* getInstancia();

private:
    static CntrIntServAutenticacao* instancia;
    CntrIntServAutenticacao() {};
};

/**
*@brief A classe CntrIntServConta controla o chamamento do container resposavel pelo salvamento em memoria dos dados passados em cada um dos metodos, com ela e possivel gerenciar a criacao de uma conta.
*/
class CntrIntServConta:public IntServConta{ // Tau� Valentim - 231021389
public:
    bool criar(Conta);
    bool pesquisar(Conta*);
    bool atualizar(Conta);
    bool excluir(Codigo);
    static CntrIntServConta* getInstancia();

private:
    static CntrIntServConta* instancia;
    CntrIntServConta() {};
};



//Jo�o Vitor Santos de Sena - 190089890
/**
 * @brief Controladora de apresenta��o para gerenciamento de viagens.
 *
 * Esta classe � respons�vel por implementar a interface com o usu�rio
 * para as opera��es de gerenciamento de viagens, destinos e hospedagens.
 */
class CntrApresentacaoViagem : public IAV {
private:
    ISV* cntrServViagem;  ///< Ponteiro para a controladora de servi�o
    Codigo codigoUsuarioAtual;  // Armazena o c�digo do usu�rio atual

    /**
     * @brief Exibe o menu de gerenciamento de viagens.
     * @param codigoUsuario C�digo do usu�rio logado.
     */
    void menuViagem(Codigo codigoUsuario);

    /**
     * @brief Exibe o menu de gerenciamento de destinos.
     */
    void menuDestino();

    /**
     * @brief Exibe o menu de gerenciamento de hospedagens.
     */
    void menuHospedagem();

    /**
     * @brief Exibe o menu de gerenciamento de atividades.
     */
    void menuAtividade();

    // M�todos para gerenciamento de viagens
    void criarViagem(Codigo codigoUsuario);
    void visualizarViagem();
    void atualizarViagem();
    void excluirViagem();
    void listarViagens(Codigo codigoUsuario);

    // M�todos para gerenciamento de destinos
    void criarDestino();
    void visualizarDestino();
    void atualizarDestino();
    void excluirDestino();

    // M�todos para gerenciamento de hospedagens
    void criarHospedagem();
    void visualizarHospedagem();
    void atualizarHospedagem();
    void excluirHospedagem();

    // M�todos para gerenciamento de atividades
    void criarAtividade();
    void visualizarAtividade();
    void atualizarAtividade();
    void excluirAtividade();

    // M�todo para c�lculo de custos
    void calcularCustoViagem();

public:
    /**
     * @brief Define a controladora de servi�o a ser utilizada.
     * @param cntrServViagem Ponteiro para a controladora de servi�o.
     */
    void setCntrServViagem(ISV* cntrServViagem);

    /**
     * @brief Executa a interface principal de gerenciamento de viagens.
     * @param codigoUsuario C�digo do usu�rio logado.
     */
    void executar(Codigo codigoUsuario);
};



//Jo�o Vitor Santos de Sena - 190089890
class CntrServViagem : public ISV {
public:
    // M�todos para gerenciamento de viagens
    void criarViagem(Viagem viagem) override;
    void visualizarViagem(Codigo codigo, Viagem* viagem) override;
    void atualizarViagem(Viagem viagem) override;
    void excluirViagem(Codigo codigo) override;
    list<Viagem> listarViagens() override;
    list<Viagem> listarViagensPorConta(Codigo codigo) override;

    // M�todos para gerenciamento de destinos
    void criarDestino(Destino destino) override;
    void visualizarDestino(Codigo codigo, Destino* destino) override;
    void atualizarDestino(Destino destino) override;
    void excluirDestino(Codigo codigo) override;
    list<Destino> listarDestinos() override;
    list<Destino> listarDestinosPorViagem(Codigo codigo) override;

    // M�todos para gerenciamento de hospedagens
    void criarHospedagem(Hospedagem hospedagem) override;
    void visualizarHospedagem(Codigo codigo, Hospedagem* hospedagem) override;
    void atualizarHospedagem(Hospedagem hospedagem) override;
    void excluirHospedagem(Codigo codigo) override;
    list<Hospedagem> listarHospedagens() override;
    list<Hospedagem> listarHospedagensPorDestino(Codigo codigo) override;

    // M�todo para c�lculo de custos
    float calcularCustoViagem(Codigo codigo) override;

    // M�todo para valida��o de datas
    void validarDatasDestino(const Destino& destino) override;

    // M�todos para gerenciamento de atividades
    void criarAtividade(Atividade atividade) override;
    void visualizarAtividade(Codigo codigo, Atividade* atividade) override;
    void atualizarAtividade(Atividade atividade) override;
    void excluirAtividade(Codigo codigo) override;
    list<Atividade> listarAtividades() override;
    list<Atividade> listarAtividadesPorDestino(Codigo codigo) override;
    void validarDataAtividade(const Atividade& atividade, const Destino& destino) override;
};


#endif // CONTROLADORAS_H_INCLUDED

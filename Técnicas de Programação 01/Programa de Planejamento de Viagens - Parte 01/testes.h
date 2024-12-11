/**
 * @file teste.h
 * @brief Declara��o das classes de teste para os dom�nios e entidades.
 */

#ifndef TESTE_H_INCLUDED
#define TESTE_H_INCLUDED
#include <iostream>
#include "dominios.h"
#include "entidades.h"
using namespace std;

/**
 * @class TUAvaliacao
 * @brief Classe de teste para o dom�nio Avaliacao.
 *
 * Testa valores v�lidos e inv�lidos para o dom�nio Avaliacao.
 */
class TUAvaliacao{
private:
    const string VALORES_VALIDOS = "5";    /**< Valor v�lido de avalia��o. */
    const string VALORES_INVALIDOS = "6";  /**< Valor inv�lido de avalia��o. */

    Avaliacao *avaliacao;    /**< Ponteiro para objeto do tipo Avaliacao a ser testado. */
    EstadoTeste estado;      /**< Estado do teste (sucesso ou falha). */

    /**
     * @brief Configura o ambiente de teste (instancia objeto).
     */
    void setUp();

    /**
     * @brief Limpa o ambiente de teste (deleta objeto).
     */
    void tearDown();

    /**
     * @brief Testa cen�rios de sucesso.
     */
    void testarCenariosSucesso();

    /**
     * @brief Testa cen�rios de falha.
     */
    void testarCenariosFalha();

public:
    /**
     * @brief Executa o teste do dom�nio Avaliacao.
     * @return EstadoTeste indicando sucesso ou falha.
     */
    EstadoTeste run();
};


/**
 * @class TUCodigo
 * @brief Classe de teste para o dom�nio Codigo.
 *
 * Testa valores v�lidos e inv�lidos para o dom�nio Codigo.
 */
class TUCodigo {
private:
    const string VALORES_VALIDOS = "ABCDEF";   /**< Valor v�lido de c�digo. */
    const string VALORES_INVALIDOS = "-asetf"; /**< Valor inv�lido de c�digo. */

    Codigo *codigo;     /**< Ponteiro para objeto do tipo Codigo a ser testado. */
    EstadoTeste estado; /**< Estado do teste. */

    void setUp();
    void tearDown();
    void testarCenariosSucesso();
    void testarCenariosFalha();

public:
    EstadoTeste run();
};

/**
 * @class TU_Data
 * @brief Classe de teste para o dom�nio Data.
 *
 * Testa valores v�lidos e inv�lidos para o dom�nio Data.
 */
class TU_Data{
private:
    string data_valida = "29-02-20";    /**< Valor v�lido de data. */
    string data_invalida = "29-02-23"; /**< Valor inv�lido de data. */

    Data data;           /**< Objeto Data a ser testado. */
    EstadoTeste estado;  /**< Estado do teste. */

    /**
     * @brief Testa cen�rio v�lido.
     */
    void testar_cenario_valido();

    /**
     * @brief Testa cen�rio inv�lido.
     */
    void testar_cenario_invalido();

public:
    EstadoTeste run();
};

/**
 * @class TU_Dinheiro
 * @brief Classe de teste para o dom�nio Dinheiro.
 *
 * Testa valores v�lidos e inv�lidos para o dom�nio Dinheiro.
 */
class TU_Dinheiro{
private:
    string valor_valido = "20.158,56";   /**< Valor v�lido de dinheiro. */
    string valor_invalido = "1.000.000,01"; /**< Valor inv�lido de dinheiro. */

    Dinheiro dinheiro;   /**< Objeto Dinheiro a ser testado. */
    EstadoTeste estado;  /**< Estado do teste. */

    void testar_cenario_valido();
    void testar_cenario_invalido();

public:
    EstadoTeste run();
};

/**
 * @class TUDuracao
 * @brief Classe de teste para o dom�nio Duracao.
 *
 * Testa valores v�lidos e inv�lidos para o dom�nio Duracao.
 */
class TUDuracao{
private:
    const int VALORES_VALIDOS = 360;  /**< Valor v�lido de dura��o. */
    const int VALORES_INVALIDOS = -1; /**< Valor inv�lido de dura��o. */

    Duracao *duracao;     /**< Ponteiro para objeto Duracao a ser testado. */
    EstadoTeste estado;    /**< Estado do teste. */

    void setUp();
    void tearDown();
    void testarCenariosSucesso();
    void testarCenariosFalha();

public:
    EstadoTeste run();
};

/**
 * @class TUHorario
 * @brief Classe de teste para o dom�nio Horario.
 *
 * Testa valores v�lidos e inv�lidos para o dom�nio Horario.
 */
class TUHorario{
private:
    const string VALORES_VALIDOS = "04:45"; /**< Valor v�lido de hor�rio. */
    const string VALORES_INVALIDOS = "00500"; /**< Valor inv�lido de hor�rio. */

    Horario *horario;   /**< Ponteiro para objeto Horario a ser testado. */
    EstadoTeste estado;  /**< Estado do teste. */

    void setUp();
    void tearDown();
    void testarCenariosSucesso();
    void testarCenariosFalha();

public:
    EstadoTeste run();
};

/**
 * @class TUNome
 * @brief Classe de teste para o dom�nio Nome.
 *
 * Testa valores v�lidos e inv�lidos para o dom�nio Nome.
 */
class TUNome{
private:
    const string VALORES_VALIDOS = "michele";
    /**< Valor v�lido de nome. */

    const string VALORES_INVALIDOS = "-1fdisjfvisjfcsidofjkcsdfjsfisfjmifjosd";
    /**< Valor inv�lido de nome (muito extenso). */

    Nome *nome;       /**< Ponteiro para objeto Nome a ser testado. */
    EstadoTeste estado; /**< Estado do teste. */

    void setUp();
    void tearDown();
    void testarCenariosSucesso();
    void testarCenariosFalha();

public:
    EstadoTeste run();
};

/**
 * @class TUSenha
 * @brief Classe de teste para o dom�nio Senha.
 *
 * Testa valores v�lidos e inv�lidos para o dom�nio Senha.
 */
class TUSenha{
private:
    const string VALORES_VALIDOS = "26485";  /**< Valor v�lido de senha. */
    const string VALORES_INVALIDOS = "12345"; /**< Valor inv�lido de senha (sequ�ncia). */

    Senha *senha;    /**< Ponteiro para objeto Senha a ser testado. */
    EstadoTeste estado; /**< Estado do teste. */

    void setUp();
    void tearDown();
    void testarCenariosSucesso();
    void testarCenariosFalha();

public:
    EstadoTeste run();
};

/**
 * @class TUHospedagem
 * @brief Classe de teste para a entidade Hospedagem.
 *
 * Testa cen�rios com valores v�lidos para a entidade Hospedagem.
 */
class TUHospedagem{
private:
    string VALORES_VALIDOS_Nome = "michele";    /**< Valor v�lido de nome. */
    string VALORES_VALIDOS_Codigo = "ABCDEF";   /**< Valor v�lido de c�digo. */
    string VALORES_VALIDOS_Avaliacao = "5";     /**< Valor v�lido de avalia��o. */
    string VALORES_VALIDOS_Dinheiro = "9.000,99"; /**< Valor v�lido de valor monet�rio. */

    Hospedagem hospedagem; /**< Objeto Hospedagem a ser testado. */
    EstadoTeste estado;    /**< Estado do teste. */

    /**
     * @brief Testa cen�rio com valores v�lidos.
     */
    void testarCenario();

public:
    EstadoTeste run();
};

/**
 * @class TUViagem
 * @brief Classe de teste para a entidade Viagem.
 *
 * Testa cen�rios com valores v�lidos para a entidade Viagem.
 */
class TUViagem{
private:
    string VALORES_VALIDOS_Nome = "Paulo";   /**< Valor v�lido de nome para viagem. */
    string VALORES_VALIDOS_Codigo = "123456"; /**< Valor v�lido de c�digo para viagem. */
    string VALORES_VALIDOS_Avaliacao = "3";   /**< Valor v�lido de avalia��o para viagem. */

    Viagem viagem;    /**< Objeto Viagem a ser testado. */
    EstadoTeste estado; /**< Estado do teste. */

    /**
     * @brief Testa cen�rio com valores v�lidos.
     */
    void testarCenario();

public:
    EstadoTeste run();
};

/**
 * @class TUDestino
 * @brief Classe de teste para a entidade Destino.
 *
 * Testa cen�rios com valores v�lidos para a entidade Destino.
 */
class TUDestino{
private:
    string VALORES_VALIDOS_Nome = "Paulo";       /**< Valor v�lido de nome para destino. */
    string VALORES_VALIDOS_Codigo = "123456";    /**< Valor v�lido de c�digo para destino. */
    string VALORES_VALIDOS_Avaliacao = "3";      /**< Valor v�lido de avalia��o para destino. */
    string VALORES_VALIDOS_DataI = "05-10-99";   /**< Valor v�lido de data inicial para destino. */
    string VALORES_VALIDOS_DataF = "26-10-99";   /**< Valor v�lido de data final para destino. */

    Destino destino;  /**< Objeto Destino a ser testado. */
    EstadoTeste estado; /**< Estado do teste. */

    /**
     * @brief Testa cen�rio com valores v�lidos.
     */
    void testarCenario();

public:
    EstadoTeste run();
};

/**
 * @class TUConta
 * @brief Classe de teste para a entidade Conta.
 *
 * Testa cen�rios com valores v�lidos para a entidade Conta.
 */
class TUConta {
private:
    const string VALOR_VALIDO_CODIGO = "1W2e33"; /**< Valor v�lido de c�digo para conta. */
    const string VALOR_VALIDO_SENHA = "19283";   /**< Valor v�lido de senha para conta. */

    Conta* conta;     /**< Ponteiro para objeto Conta a ser testado. */
    EstadoTeste estado; /**< Estado do teste. */

    /**
     * @brief Configura ambiente de teste.
     */
    void setUp();

    /**
     * @brief Limpa ambiente de teste.
     */
    void tearDown();

    /**
     * @brief Testa cen�rio com valores v�lidos.
     */
    void testarCenario();
public:
    EstadoTeste run();
};

/**
 * @class TUAtividade
 * @brief Classe de teste para a entidade Atividade.
 *
 * Testa cen�rios com valores v�lidos para a entidade Atividade.
 */
class TUAtividade {
private:
    Atividade *atividade; /**< Ponteiro para objeto Atividade a ser testado. */
    EstadoTeste estado;   /**< Estado do teste. */

    /**
     * @brief Configura ambiente de teste.
     */
    void setUp();

    /**
     * @brief Limpa ambiente de teste.
     */
    void tearDown();

    /**
     * @brief Testa cen�rio de sucesso.
     */
    void testarCenarioSucesso();

public:
    const static int SUCESSO =  0;
    const static int FALHA   = -1;

    EstadoTeste run();
};

#endif // TESTE_H_INCLUDED

#ifndef DOMINIOS_H_INCLUDED
#define DOMINIOS_H_INCLUDED

/**
 * @file dominios.h
 * @brief Declara��o das classes de dom�nio utilizadas no sistema.
 */

#include <iostream>
using namespace std;

/**
 * @class Avaliacao
 * @brief Classe respons�vel pelo dom�nio Avaliacao.
 *
 * A classe Avaliacao representa uma avalia��o num�rica entre 0 e 5.
 * O valor armazenado � uma string, por�m o valor v�lido � garantido
 * pelo m�todo validar().
 */
class Avaliacao{ //Geilson dos Santos - 231006239
private:
    string valor; /**< Armazena a avalia��o. */

public:

    /**
     * @brief Retorna o valor da avalia��o.
     * @return string com o valor da avalia��o.
     */
    string getValor() const;

    /**
     * @brief Define o valor da avalia��o.
     *
     * @param val Valor a ser definido.
     * @throws invalid_argument se o valor n�o for uma avalia��o v�lida (entre 0 e 5).
     */
    void setValor(string val);

    /**
     * @brief Valida o valor da avalia��o.
     *
     * Verifica se o valor passado � um d�gito entre 0 e 5.
     * @param valor String representando o valor a ser validado.
     * @throws invalid_argument se o valor n�o for v�lido.
     */
    void validar(string valor);

};

inline string Avaliacao::getValor() const
{
    return valor;
}

/**
 * @class Codigo
 * @brief Classe respons�vel pelo dom�nio Codigo.
 *
 * A classe Codigo representa um c�digo alfanum�rico de 6 caracteres.
 * O valor armazenado � garantido pelo m�todo validar().
 */
class Codigo{ // Tau Frade - 231021389
private:
    int TAMANHO = 6; /**< Tamanho fixo do c�digo. */
    string valor; /**< Armazena o c�digo. */

    /**
     * @brief Valida o valor do c�digo.
     *
     * Verifica se o c�digo possui 6 caracteres alfanum�ricos.
     * @param cod String com o c�digo a ser validado.
     * @throws invalid_argument se o c�digo n�o tiver o tamanho correto ou contiver caracteres inv�lidos.
     */
    void validar(string cod);

public:
    /**
     * @brief Define o valor do c�digo.
     *
     * @param val String com o c�digo.
     * @throws invalid_argument se o valor n�o for um c�digo v�lido.
     */
    void setValor(string val);

    /**
     * @brief Retorna o valor do c�digo.
     * @return string com o c�digo.
     */
    string getValor() const;
};

inline string Codigo::getValor() const
{
    return valor;
}

/**
 * @class Data
 * @brief Classe respons�vel pelo dom�nio Data.
 *
 * A classe Data representa uma data no formato DD-MM-AA.
 */
class Data{//ARTHUS CESAR DIAS FERNANDES - 231006103
private:
    string valor; /**< Armazena a data no formato DD-MM-AA. */

public:
    /**
     * @brief Retorna o valor da data.
     * @return string com a data.
     */
    string getValor() const;

    /**
     * @brief Define o valor da data.
     *
     * @param data Data no formato DD-MM-AA.
     * @throws invalid_argument se a data n�o for v�lida.
     */
    void setValor(string data);

    /**
     * @brief Valida o valor da data.
     *
     * Verifica se a data est� no formato correto e se � v�lida (dia, m�s, ano).
     * @param data String com a data a ser validada.
     * @throws invalid_argument se a data for inv�lida.
     */
    void validar(string data);
};

inline string Data::getValor() const
{
    return valor;
}

/**
 * @class Dinheiro
 * @brief Classe respons�vel pelo dom�nio Dinheiro.
 *
 * Representa um valor monet�rio entre 0 e 200000.00, com duas casas decimais.
 */
class Dinheiro{// Richard Otto - 231006186

private:
    string valor; /**< Armazena o valor monet�rio. */
    double LIMITE_MAX = 200000.00; /**< Limite m�ximo do valor. */
    double LIMITE_MIN = 0;         /**< Limite m�nimo do valor. */

public:
    /**
     * @brief Retorna o valor do dinheiro.
     * @return string com o valor monet�rio.
     */
    string getValor() const;

    /**
     * @brief Define o valor do dinheiro.
     *
     * @param valor_str String representando o valor monet�rio.
     * @throws invalid_argument se o valor n�o for v�lido.
     */
    void setValor(string valor_str);

    /**
     * @brief Valida o valor do dinheiro.
     *
     * Verifica formato, limites e presen�a de duas casas decimais.
     * @param valor_str String com o valor a ser validado.
     * @throws invalid_argument se o valor for inv�lido.
     */
    void validar(string valor_str);

};

inline string Dinheiro::getValor() const
{
    return valor;
}

/**
 * @class Duracao
 * @brief Classe respons�vel pelo dom�nio Duracao.
 *
 * Representa uma dura��o inteira em minutos, entre 0 e 360.
 */
class Duracao{// Richard Otto - 231006186
private:
    int MINIMO = 0;   /**< Valor m�nimo da dura��o. */
    int MAXIMO = 360; /**< Valor m�ximo da dura��o. */

    int valor; /**< Armazena a dura��o em minutos. */

    /**
     * @brief Valida a dura��o.
     *
     * Verifica se o valor est� entre 0 e 360.
     * @param val Dura��o em minutos.
     * @throws invalid_argument se o valor n�o estiver dentro do intervalo.
     */
    void validar(int val);

public:
    /**
     * @brief Define o valor da dura��o.
     *
     * @param val Inteiro com a dura��o (em minutos).
     * @throws invalid_argument se a dura��o for inv�lida.
     */
    void setValor(int val);

    /**
     * @brief Retorna a dura��o.
     * @return int com a dura��o em minutos.
     */
    int getValor() const;
};

inline int Duracao::getValor() const
{
    return valor;
}

/**
 * @class Horario
 * @brief Classe respons�vel pelo dom�nio Horario.
 *
 * Representa um hor�rio no formato HH:MM.
 */
class Horario{ //Geilson dos Santos - 231006239
private:
    string valor; /**< Armazena o hor�rio no formato HH:MM. */

    /**
     * @brief Valida o hor�rio.
     *
     * Verifica se o hor�rio est� no formato HH:MM e se � v�lido (00 <= HH <= 23, 00 <= MM <= 59).
     * @param valor String com o hor�rio.
     * @throws invalid_argument se o hor�rio for inv�lido.
     */
    void validar(string valor);

public:
    /**
     * @brief Retorna o valor do hor�rio.
     * @return string com o hor�rio.
     */
    string getValor() const;

    /**
     * @brief Define o valor do hor�rio.
     *
     * @param valor Hor�rio no formato HH:MM.
     * @throws invalid_argument se o hor�rio for inv�lido.
     */
    void setValor(string valor);

};
inline string Horario::getValor() const
{
    return valor;
}

/**
 * @class Nome
 * @brief Classe respons�vel pelo dom�nio Nome.
 *
 * Representa um nome com no m�ximo 30 caracteres.
 */
class Nome{ // Michele Nakagomi - 232029078
private:
    int VALOR_MAXIMO = 30; /**< Tamanho m�ximo do nome. */

    string valor; /**< Armazena o nome. */

    /**
     * @brief Valida o nome.
     *
     * Verifica se o nome n�o ultrapassa 30 caracteres.
     * @param val String com o nome.
     * @throws invalid_argument se o nome for muito longo.
     */
    void validar(string val);

public:
    /**
     * @brief Define o valor do nome.
     *
     * @param val String com o nome.
     * @throws invalid_argument se o nome for inv�lido.
     */
    void setValor(string val);

    /**
     * @brief Retorna o valor do nome.
     * @return string com o nome.
     */
    string getValor() const;
};

inline string Nome::getValor() const
{
    return valor;
}

/**
 * @class Senha
 * @brief Classe respons�vel pelo dom�nio Senha.
 *
 * Representa uma senha de 5 d�gitos num�ricos, n�o sequenciais e sem repeti��o.
 */
class Senha{ //Geilson dos Santos - 231006239
private:
    string valor; /**< Armazena a senha. */

public:
    /**
     * @brief Retorna o valor da senha.
     * @return string com a senha.
     */
    string getValor() const;

    /**
     * @brief Define o valor da senha.
     *
     * @param valor Senha de 5 d�gitos.
     * @throws invalid_argument se a senha n�o for v�lida.
     */
    void setValor(string valor);

    /**
     * @brief Valida a senha.
     *
     * Verifica se a senha possui 5 d�gitos, todos num�ricos, n�o formam sequ�ncia nem possuem d�gitos repetidos.
     * @param valor String com a senha.
     * @throws invalid_argument se a senha for inv�lida.
     */
    void validar(string valor);

};

inline string Senha::getValor() const
{
    return valor;
}

/**
 * @enum EstadoTeste
 * @brief Representa o estado de um teste.
 *
 * @var EstadoTeste::sucesso Representa que o teste foi bem-sucedido.
 * @var EstadoTeste::falha Representa que o teste falhou.
 */
enum EstadoTeste
{
    sucesso = -1, /**< Teste bem-sucedido. */
    falha         /**< Teste falhou. */
};


#endif // DOMINIOS_H_INCLUDED

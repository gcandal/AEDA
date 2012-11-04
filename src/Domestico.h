#ifndef DOMESTICO_H_
#define DOMESTICO_H_
#include <vector>
#include <string>
#include "Trabalho.h"

using namespace std;

class Domestico: public Trabalho {
	unsigned int idHabitacao;
public:
	/*
	 * @brief Construtor da classe Dom�stico
	 * @param Dura��o, custo, empresa respons�vel e id da habita��o onde vai ser realizado o trabalho
	 */
	Domestico(int duracao, int custo, string empresa, int idHabitacao);
	/*
	 * @result Devolve o ID da habita��o onde est� a ser realizado o trabalho
	 */
	int getIdHabitacao() const;
	/*
	 * @brief Altera o ID da habita��o
	 * @param Novo ID
	 */
	void setID(unsigned int n);
	virtual int getId() const {
		return idHabitacao;
	}
	/*
	 * @brief Imprime informa��es sobre o trabalho
	 */
	virtual void imprime() const;
};

class Trolha: public Domestico {
	unsigned int quantBetao;
	const static tipoTrabalho tipo = trolha;
public:
	/*
	 * @brief Construtor da classe Trolha
	 * @param Dura��o, custo, empresa respons�vel, id da rua onde vai ser realizado o trabalho e quantidade de bet�o disponivel
	 */
	Trolha(int duracao, int custo, string empresa, int idRua, int quantBetao);
	/*
	 * @return Devolve a quantidade de bet�o disponivel
	 */
	int getBetao() const;
	int getAsfalto() const;
	int getCabo() const;
	int getMadeira() const;
	/*
	 * @brief Altera a quantidade de material disponivel
	 * @param Nova quantidade de material
	 */
	void setMaterial(unsigned int n);
	/*
	 * @brief Guarda no ficheiro .txt as informa��es do trabalho
	 * @param Ficheiro de texto que vai receber as informa��es
	 */
	void imprimeFicheiro(ofstream& ficheiro_escrita) const;
	/*
	 * @return Devolve o tipo de trabalho
	 */
	virtual tipoTrabalho getTipoTrabalho() const {
		return tipo;
	}
	/*
	 * @brief Imprime informa��es sobre o trabalho
	 */
	void imprime() const;
};

class Eletricista: public Domestico {
	unsigned int compCabo;
	const static tipoTrabalho tipo = eletricista;
public:
	/*
	 * @brief Construtor da classe Eletricista
	 * @param Dura��o, custo, empresa respons�vel, id da rua onde vai ser realizado o trabalho e comprimento de cabo disponivel
	 */
	Eletricista(int duracao, int custo, string empresa, int idRua,
			int compCabo);
	/*
	 * @return Devolve o comprimento de cabo disponivel
	 */
	int getCabo() const;
	int getBetao() const;
	int getAsfalto() const;
	int getMadeira() const;
	/*
	 * @brief Altera a quantidade de material disponivel
	 * @param Nova quantidade de material
	 */
	void setMaterial(unsigned int n);
	/*
	 * @brief Guarda no ficheiro .txt as informa��es do trabalho
	 * @param Ficheiro de texto que vai receber as informa��es
	 */
	void imprimeFicheiro(ofstream& ficheiro_escrita) const;
	/*
	 * @return Devolve o tipo de trabalho
	 */
	virtual tipoTrabalho getTipoTrabalho() const {
		return tipo;
	}
	/*
	 * @brief Imprime informa��es sobre o trabalho
	 */
	void imprime() const;
};

class Carpinteiro: public Domestico {
	unsigned int areaMadeira;
	const static tipoTrabalho tipo = carpinteiro;
public:
	Carpinteiro(int duracao, int custo, string empresa, int idRua,
			unsigned int areaMadeira);
	int getCabo() const;
	int getBetao() const;
	int getAsfalto() const;
	/*
	 * @return Devolve a �rea de madeira disponivel
	 */
	int getMadeira() const;
	/*
	 * @brief Altera a quantidade de material disponivel
	 * @param Nova quantidade de material
	 */
	void setMaterial(unsigned int n);
	/*
	 * @brief Guarda no ficheiro .txt as informa��es do trabalho
	 * @param Ficheiro de texto que vai receber as informa��es
	 */
	void imprimeFicheiro(ofstream& ficheiro_escrita) const;
	/*
	 * @return Devolve o tipo de trabalho
	 */
	virtual tipoTrabalho getTipoTrabalho() const {
		return tipo;
	}
	/*
	 * @brief Imprime informa��es sobre o trabalho
	 */
	void imprime() const;
};

#endif /* DOMESTICO_H_ */

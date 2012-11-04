#ifndef INFRAESTRUTURA_H_
#define INFRAESTRUTURA_H_
#include <vector>
#include <string>
#include "Trabalho.h"

using namespace std;

class InfraEstrutura: public Trabalho {
private:
	unsigned int idRua;
public:
	/*
	 * @brief Construtor da classe InfraEstrutura
	 * @param Dura��o, custo, empresa respons�vel e id da habita��o onde vai ser realizado o trabalho
	 */
	InfraEstrutura(int duracao, int custo, string empresa, int idRua);
	/*
	 * @result Devolve o ID da rua onde est� a ser realizado o trabalho
	 */
	int getIdRua() const;
	/*
	 * @brief Altera o ID da rua
	 * @param Novo ID
	 */
	void setID(unsigned int n);
	//FUN��O REPETIDA, ESCOLHER UMA
	virtual int getId() const {
		return idRua;
	}
	/*
	 * @brief Imprime na consola informa��es sobre o trabalho
	 */
	virtual void imprime() const;
};

class Arruamento: public InfraEstrutura {
	unsigned int quantAsfalto;
	const static tipoTrabalho tipo = arruamento;
public:
	/*
	 * @brief Construtor da classe Arruamento
	 * @param Dura��o, custo, empresa respons�vel, id da rua onde vai ser realizado o trabalho e quantidade de asfalto disponivel
	 */
	Arruamento(int duracao, int custo, string empresa, int idRua,
			int quantAsfalto);
	/*
	 * @return Devolve a quantidade de asfalto disponivel
	 */
	int getAsfalto() const;
	int getBetao() const;
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
	tipoTrabalho getTipoTrabalho() const {
		return tipo;
	}
	/*
	 * @brief Imprime na consola informa��es sobre o trabalho
	 */
	void imprime() const;
};

class Saneamento: public InfraEstrutura {
	unsigned int quantBetao;
	const static tipoTrabalho tipo = saneamento;
public:
	/*
	 * @brief Construtor da classe Saneamento
	 * @param Dura��o, custo, empresa respons�vel, id da rua onde vai ser realizado o trabalho e quantidade de bet�o disponivel
	 */
	Saneamento(int duracao, int custo, string empresa, int idRua,
			int quantBetao);
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
	tipoTrabalho getTipoTrabalho() const {
		return tipo;
	}
	/*
	 * @brief Imprime na consola informa��es sobre o trabalho
	 */
	void imprime() const;
};

#endif /* INFRAESTRUTURA_H_ */

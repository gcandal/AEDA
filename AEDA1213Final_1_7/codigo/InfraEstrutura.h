#ifndef INFRAESTRUTURA_H_
#define INFRAESTRUTURA_H_
#include <vector>
#include <string>
#include "Trabalho.h"

using namespace std;

/*!
 * \brief Classe que representa os trabalhos de Infra-Estruturas
 */
class InfraEstrutura: public Trabalho {
private:
	unsigned int idRua;
public:
	/*!
	 * \brief Construtor da classe InfraEstrutura
	 * \param Duracao, custo, empresa responsavel e id da habitacao onde vai ser realizado o trabalho
	 */
	InfraEstrutura(int duracao, int custo, string empresa, int idRua);
	/*!
	 * \result Devolve o ID da rua onde está a ser realizado o trabalho
	 */
	int getIdRua() const;
	/*!
	 * \brief Altera o ID da rua
	 * \param Novo ID
	 */
	void setID(unsigned int n);
	/*!
	 * \result Devolve o ID da rua onde esta a ser realizado o trabalho
	 */
	virtual int getId() const {
		return idRua;
	}
	/*!
	 * \brief Imprime na consola informacoes sobre o trabalho
	 */
	virtual void imprime() const;
};

/*!
 * \brief Classe que representa os trabalhos de arruamentos
 */
class Arruamento: public InfraEstrutura {
	unsigned int quantAsfalto;
	const static tipoTrabalho tipo = arruamento;
public:
	/*!
	 * \brief Construtor da classe Arruamento
	 * \param Duracao, custo, empresa responsavel, id da rua onde vai ser realizado o trabalho e quantidade de asfalto disponivel
	 */
	Arruamento(int duracao, int custo, string empresa, int idRua,
			int quantAsfalto);
	/*!
	 * \return Devolve a quantidade de asfalto disponivel
	 */
	int getAsfalto() const;
	int getBetao() const;
	int getCabo() const;
	int getMadeira() const;
	/*!
	 * \brief Altera a quantidade de material disponivel
	 * \param Nova quantidade de material
	 */
	void setMaterial(unsigned int n);
	/*!
	 * \brief Guarda no ficheiro .txt as informacoes do trabalho
	 * \param Ficheiro de texto que vai receber as informacoes
	 */
	void imprimeFicheiro(ofstream& ficheiro_escrita) const;
	/*!
	 * \return Devolve o tipo de trabalho
	 */
	tipoTrabalho getTipoTrabalho() const {
		return tipo;
	}
	/*!
	 * \brief Imprime na consola informacoes sobre o trabalho
	 */
	void imprime() const;
};

/*!
 * \brief Classe que representa os trabalhos de saneamentos
 */
class Saneamento: public InfraEstrutura {
	unsigned int quantBetao;
	const static tipoTrabalho tipo = saneamento;
public:
	/*!
	 * \brief Construtor da classe Saneamento
	 * \param Duracao, custo, empresa responsavel, id da rua onde vai ser realizado o trabalho e quantidade de betao disponivel
	 */
	Saneamento(int duracao, int custo, string empresa, int idRua,
			int quantBetao);
	/*!
	 * \return Devolve a quantidade de betao disponivel
	 */
	int getBetao() const;
	int getAsfalto() const;
	int getCabo() const;
	int getMadeira() const;
	/*!
	 * \brief Altera a quantidade de material disponivel
	 * \param Nova quantidade de material
	 */
	void setMaterial(unsigned int n);
	/*!
	 * \brief Guarda no ficheiro .txt as informacoes do trabalho
	 * \param Ficheiro de texto que vai receber as informacoes
	 */
	void imprimeFicheiro(ofstream& ficheiro_escrita) const;
	/*!
	 * \return Devolve o tipo de trabalho
	 */
	tipoTrabalho getTipoTrabalho() const {
		return tipo;
	}
	/*!
	 * \brief Imprime na consola informacoes sobre o trabalho
	 */
	void imprime() const;
};

#endif /* INFRAESTRUTURA_H_ */

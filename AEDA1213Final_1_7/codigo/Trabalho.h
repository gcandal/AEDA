#ifndef TRABALHO_H_
#define TRABALHO_H_
#include <string>
#include <iostream>
#include <sstream>

using namespace std;

enum tipoTrabalho {
	arruamento, saneamento, trolha, eletricista, carpinteiro
};

/*!
 * \brief Classe que representa um trabalho
 */
class Trabalho {
	unsigned int duracao, custo;
	string empresa;
	static unsigned int ultimoNum;
	unsigned int num;
public:
	/*!
	 * \brief Construtor da classe Trabalho
	 * \param Duracao, custo e empresa responsavel pelo trabalho
	 */
	Trabalho(int duracao, int custo, string empresa);
	/*!
	 * \brief Destrutor da classe Trabalho
	 */
	virtual ~Trabalho() {
	}
	/*!
	 * \return Devolve o numero do trabalho
	 */
	unsigned int getNum() const;
	/*!
	 * \return Devolve a empresa responsavel pelo trabalho
	 */
	string getEmpresa() const;
	/*!
	 * \return Devolve o custo do trabalho
	 */
	/*!virtual*/
	int getCusto() const;
	/*!
	 * \return Devolve a duracao do trabalho
	 */
	/*!virtual*/
	int getDuracao() const;
	virtual int getAsfalto() const = 0;
	virtual int getBetao() const;
	virtual int getCabo() const;
	virtual int getMadeira() const;
	virtual void setMaterial(unsigned int n) = 0;
	virtual void setID(unsigned int n) =0;
	virtual void imprimeFicheiro(ofstream& ficheiro_escrita) const =0;
	virtual tipoTrabalho getTipoTrabalho() const =0;
	virtual int getId() const =0;
	/*!
	 * \brief Altera a empresa responsavel
	 * \param Empresa pretendida
	 */
	void setEmpresa(string str);
	/*!
	 * \brief Altera a duracao do trabalho
	 * \param Duracao pretendida
	 */
	void setDuracao(unsigned int n);
	/*!
	 * \brief Altera o custo do trabalho
	 * \param Custo pretendido
	 */
	void setCusto(unsigned int n);
	/*!
	 *  \brief Guarda no ficheiro de escrita informacoes sobre o trabalho
	 *  \param Ficheiro onde se pretende guardar as informacoes
	 */
	virtual void imprime() const;
	/*!
	 *  \brief Classe que representa um valor incorreto
	 */
	class ValorIncorrecto {
	public:
		int v;
		ValorIncorrecto(int v) :
				v(v) {
		}
	};
};

#endif

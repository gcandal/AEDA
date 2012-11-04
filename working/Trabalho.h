#ifndef TRABALHO_H_
#define TRABALHO_H_
#include <string>
#include <iostream>
#include <sstream>

using namespace std;

enum tipoTrabalho {
	arruamento, saneamento, trolha, eletricista, carpinteiro
};

class Trabalho {
	unsigned int duracao, custo;
	string empresa;
	static unsigned int ultimoNum;
	unsigned int num;
public:
	/*
	 * @brief Construtor da classe Trabalho
	 * @param Duração, custo e empresa responsavél pelo trabalho
	 */
	Trabalho(int duracao, int custo, string empresa);
	/*
	 * @brief Destrutor da classe Trabalho
	 */
	virtual ~Trabalho() {
	}
	/*
	 * @return Devolve o número do trabalho
	 */
	unsigned int getNum() const;
	/*
	 * @return Devolve a empresa responsavél pelo trabalho
	 */
	string getEmpresa() const;
	/*
	 * @return Devolve o custo do trabalho
	 */
	/*virtual*/
	int getCusto() const;
	/*
	 * @return Devolve a duração do trabalho
	 */
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
	/*
	 * @brief Altera a empresa responsavél
	 * @param Empresa pretendida
	 */
	void setEmpresa(string str);
	/*
	 * @brief Altera a duração do trabalho
	 * @param Duração pretendida
	 */
	void setDuracao(unsigned int n);
	/*
	 * @brief Altera o custo do trabalho
	 * @param Custo pretendido
	 */
	void setCusto(unsigned int n);
	/*
	 *  @brief Guarda no ficheiro de escrita informações sobre o trabalho
	 *  @param Ficheiro onde se pretende guardar as informações
	 */
	virtual void imprime() const;

	class ValorIncorrecto {
	public:
		int v;
		ValorIncorrecto(int v) :
				v(v) {
		}
	};
};

#endif

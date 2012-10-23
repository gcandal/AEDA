#ifndef DOMESTICO_H_
#define DOMESTICO_H_
#include <vector>
#include <string>

using namespace std;

/*
 * Classe virtual dos trabalhos domesticos
 *
 */
class Domestico: public Trabalho {
	const unsigned int idHabitacao;			/*<ID da habitacao na qual o trabalho esta a ser efetuado */
public:
	/* Construtor de Domestico
	 *
	 * @param duracao Tempo que o trabalho demorara a realizar
	 * @param custo Custo que o trabalho tera
	 * @param empresa Empresa a qual o trabalho esta entregue
	 * @param idHabitacao ID da habitacao na qual o trabalho sera efetuado
	 *
	 */
	Domestico(int duracao, int custo, string empresa, int idHabitacao);
	/*
	 * @return ID da habitacao na qual o trabalho esta a ser efetuado
	 */
	int getIdHabitacao() const;
	virtual int getAsfalto() const;
	virtual int getBetao() const;
	virtual int getCabo() const;
	virtual int getMadeira() const;
	//virtual int getCusto() const;
	//virtual int getDuracao() const;
	virtual tipoTrabalho getTipoTrabalho() const;
	virtual int getId() const {return idHabitacao;}
};

class Trolha: public Domestico {
	const unsigned int quantBetao;
	const static tipoTrabalho tipo = trolha;
public:
	Trolha(int duracao, int custo, string empresa, int idRua, int quantBetao);
	int getBetao() const;
	int getAsfalto() const;
	int getCabo() const;
	int getMadeira() const;
	//int getCusto() const;
	//int getDuracao() const;
	void imprimeFicheiro(ofstream& ficheiro_escrita) const;
	virtual tipoTrabalho getTipoTrabalho() const {return tipo;}
};

class Eletricista: public Domestico {
	const unsigned int compCabo;
	const static tipoTrabalho tipo = eletricista;
public:
	Eletricista(int duracao, int custo, string empresa, int idRua,
			int compCabo);
	int getCabo() const;
	int getBetao() const;
	int getAsfalto() const;
	int getMadeira() const;
	//int getCusto() const;
	//int getDuracao() const;
	void imprimeFicheiro(ofstream& ficheiro_escrita) const;
	virtual tipoTrabalho getTipoTrabalho() const {return tipo;}
};

class Carpinteiro: public Domestico {
	const unsigned int areaMadeira;
	const static tipoTrabalho tipo = carpinteiro;
public:
	Carpinteiro(int duracao, int custo, string empresa, int idRua,
			unsigned int areaMadeira);
	int getMadeira() const;
	//int getCusto() const;
	//int getDuracao() const;
	void imprimeFicheiro(ofstream& ficheiro_escrita) const;
	virtual tipoTrabalho getTipoTrabalho() const {return tipo;}
};


#endif /* DOMESTICO_H_ */

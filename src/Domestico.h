#ifndef DOMESTICO_H_
#define DOMESTICO_H_
#include <vector>
#include <string>
#include "Trabalho.h"

using namespace std;

class Domestico: public Trabalho {
	unsigned int idHabitacao;
public:
	Domestico(int duracao, int custo, string empresa, int idHabitacao);
	int getIdHabitacao() const;
	void setID(unsigned int n);
	virtual int getId() const {return idHabitacao;}
	virtual void imprime() const;
};

class Trolha: public Domestico {
	unsigned int quantBetao;
	const static tipoTrabalho tipo = trolha;
public:
	Trolha(int duracao, int custo, string empresa, int idRua, int quantBetao);
	int getBetao() const;
	int getAsfalto() const;
	int getCabo() const;
	int getMadeira() const;
	void setMaterial(unsigned int n);
	void imprimeFicheiro(ofstream& ficheiro_escrita) const;
	virtual tipoTrabalho getTipoTrabalho() const {return tipo;}
	void imprime() const;
};

class Eletricista: public Domestico {
	unsigned int compCabo;
	const static tipoTrabalho tipo = eletricista;
public:
	Eletricista(int duracao, int custo, string empresa, int idRua,
			int compCabo);
	int getCabo() const;
	int getBetao() const;
	int getAsfalto() const;
	int getMadeira() const;
	void setMaterial(unsigned int n);
	void imprimeFicheiro(ofstream& ficheiro_escrita) const;
	virtual tipoTrabalho getTipoTrabalho() const {return tipo;}
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
	int getMadeira() const;
	void setMaterial(unsigned int n);
	void imprimeFicheiro(ofstream& ficheiro_escrita) const;
	virtual tipoTrabalho getTipoTrabalho() const {return tipo;}
	void imprime() const;
};


#endif /* DOMESTICO_H_ */

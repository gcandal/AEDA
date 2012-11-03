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
	/*
	 * Useless
	virtual int getAsfalto() const;
	virtual int getBetao() const;
	virtual int getCabo() const;
	virtual int getMadeira() const;*/
	virtual int getId() const {return idHabitacao;}
	virtual string info() const;
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
	//int getCusto() const;
	//int getDuracao() const;
	void setMaterial(unsigned int n);
	void imprimeFicheiro(ofstream& ficheiro_escrita) const;
	virtual tipoTrabalho getTipoTrabalho() const {return tipo;}
	virtual string info() const;
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
	//int getCusto() const;
	//int getDuracao() const;
	void setMaterial(unsigned int n);
	void imprimeFicheiro(ofstream& ficheiro_escrita) const;
	virtual tipoTrabalho getTipoTrabalho() const {return tipo;}
	virtual string info() const;
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
	//int getCusto() const;
	//int getDuracao() const;
	void setMaterial(unsigned int n);
	void imprimeFicheiro(ofstream& ficheiro_escrita) const;
	virtual tipoTrabalho getTipoTrabalho() const {return tipo;}
	virtual string info() const;
};


#endif /* DOMESTICO_H_ */

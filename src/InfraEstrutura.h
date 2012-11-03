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
	InfraEstrutura(int duracao, int custo, string empresa, int idRua);
	int getIdRua() const;
	void setID(unsigned int n);
	/*
	 * Useless
	virtual int getAsfalto() const;
	virtual int getBetao() const;
	virtual int getCabo() const;
	virtual int getMadeira() const;*/
	virtual int getId() const {return idRua;}
	virtual string info() const;
	virtual void imprime() const;
};

class Arruamento: public InfraEstrutura {
	unsigned int quantAsfalto;
	const static tipoTrabalho tipo = arruamento;
public:
	Arruamento(int duracao, int custo, string empresa, int idRua,
			int quantAsfalto);
	int getAsfalto() const;
	int getBetao() const;
	int getCabo() const;
	int getMadeira() const;
	//int getCusto() const;
	//int getDuracao() const;
	void setMaterial(unsigned int n);
	void imprimeFicheiro(ofstream& ficheiro_escrita) const;
	tipoTrabalho getTipoTrabalho() const {return tipo;}
	string info() const;
	void imprime() const;
};

class Saneamento: public InfraEstrutura {
	unsigned int quantBetao;
	const static tipoTrabalho tipo = saneamento;
public:
	Saneamento(int duracao, int custo, string empresa, int idRua,
			int quantBetao);
	int getBetao() const;
	int getAsfalto() const;
	int getCabo() const;
	int getMadeira() const;
	//int getCusto() const;
	//int getDuracao() const;
	void setMaterial(unsigned int n);
	void imprimeFicheiro(ofstream& ficheiro_escrita) const;
	tipoTrabalho getTipoTrabalho() const {return tipo;}
	string info() const;
	void imprime() const;
};

#endif /* INFRAESTRUTURA_H_ */

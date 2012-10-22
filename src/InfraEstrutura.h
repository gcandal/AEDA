#ifndef INFRAESTRUTURA_H_
#define INFRAESTRUTURA_H_
#include <vector>
#include <string>

using namespace std;

class InfraEstrutura: public Trabalho {
	const unsigned int idRua;
public:
	InfraEstrutura(int duracao, int custo, string empresa, int idRua);
	int getIdRua() const;
	virtual int getAsfalto() const;
	virtual int getBetao() const;
	virtual int getCabo() const;
	virtual int getMadeira() const;
	//virtual int getCusto() const;
	//virtual int getDuracao() const;
	//virtual void imprimeEcra() const;
	//virtual void imprimeFicheiro() const;
};

class Arruamento: public InfraEstrutura {
	const unsigned int quantAsfalto;
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
	//virtual void imprimeEcra() const;
	//virtual void imprimeFicheiro() const;
};

class Saneamento: public InfraEstrutura {
	const unsigned int quantBetao;
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
	//virtual void imprimeEcra() const;
	//virtual void imprimeFicheiro() const;
};

#endif /* INFRAESTRUTURA_H_ */

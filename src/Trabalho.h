#ifndef TRABALHO_H_
#define TRABALHO_H_
#include <string>
#include <iostream>
#include <sstream>

using namespace std;


enum tipoTrabalho{arruamento, saneamento, trolha, eletricista, carpinteiro};

class Trabalho {
	const unsigned int duracao, custo;
	string empresa;
public:
	Trabalho(int duracao, int custo, string empresa);
	virtual ~Trabalho() {}
	string getEmpresa() const;
	/*virtual*/ int getCusto() const;
	/*virtual*/ int getDuracao() const;
	virtual int getAsfalto() const = 0;
	virtual int getBetao() const;
	virtual int getCabo() const;
	virtual int getMadeira() const;
	virtual void imprimeFicheiro(ofstream& ficheiro_escrita) const;
	virtual tipoTrabalho getTipoTrabalho() const;
	virtual int getId() const;
	virtual string info() const;
};

#endif

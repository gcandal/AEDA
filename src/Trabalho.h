#ifndef TRABALHO_H_
#define TRABALHO_H_
#include <string>
#include <iostream>
#include <sstream>

using namespace std;


enum tipoTrabalho{arruamento, saneamento, trolha, eletricista, carpinteiro};

class Trabalho {
	unsigned int duracao, custo;
	string empresa;
	static unsigned int ultimoNum;
	unsigned int num;
public:
	Trabalho(int duracao, int custo, string empresa);
	virtual ~Trabalho() {}
	unsigned int getNum() const;
	string getEmpresa() const;
	/*virtual*/ int getCusto() const;
	/*virtual*/ int getDuracao() const;
	virtual int getAsfalto() const = 0;
	virtual int getBetao() const;
	virtual int getCabo() const;
	virtual int getMadeira() const;
	virtual void setMaterial(unsigned int n) = 0;
	virtual void setID(unsigned int n) =0;
	virtual void imprimeFicheiro(ofstream& ficheiro_escrita) const =0;
	virtual tipoTrabalho getTipoTrabalho() const =0;
	virtual int getId() const =0;
	virtual string info() const;
	void setEmpresa(string str);
	void setDuracao(unsigned int n);
	void setCusto(unsigned int n);

	class ValorIncorrecto {
	public:
		int v;
		ValorIncorrecto(int v): v(v) {}
	};
};

#endif

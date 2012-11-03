#include "Trabalho.h"

//CLASSE TRABALHO
unsigned int Trabalho::ultimoNum = 0;

Trabalho::Trabalho(int duracao, int custo, string empresa) :
		duracao(duracao), custo(custo), empresa(empresa), num(++ultimoNum) {

}

unsigned int Trabalho::getNum() const {
	return num;
};

int Trabalho::getDuracao() const {
	return duracao;
}

int Trabalho::getCusto() const {
	return custo;
}

string Trabalho::getEmpresa() const {
	return empresa;
}

int Trabalho::getAsfalto() const {
	return 0;
}

int Trabalho::getBetao() const {
	return 0;
}

int Trabalho::getCabo() const {
	return 0;
}

int Trabalho::getMadeira() const {
	return 0;
}

string Trabalho::info() const {

	stringstream ss;

	ss << "Empresa: " << empresa << "\nDuracao: " << duracao << "\nCusto: " << custo << "\nID: " << num << '\n';

	return ss.str();
}

void Trabalho::setEmpresa(string str) {
	empresa=str;
};

void Trabalho::setDuracao(unsigned int str) {

	duracao=str;

	if(str<0)
		throw ValorIncorrecto(str);
};

void Trabalho::setCusto(unsigned int str) {

	custo=str;

	if(str<0)
		throw ValorIncorrecto(str);
};

void Trabalho::imprime() const {

	cout << endl << "Trabalho numero: " << num << endl
			<< "Duracao: " << duracao << ", "<< "Custo " << custo << ", " << "Empresa associada: " << empresa << endl;
}


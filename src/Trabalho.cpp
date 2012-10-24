#include "Trabalho.h"

//CLASSE TRABALHO
Trabalho::Trabalho(int duracao, int custo, string empresa) :
		duracao(duracao), custo(custo), empresa(empresa) {

}

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

	ss << "Empresa: " << empresa << "\nDuracao: " << duracao << "\nCusto: " << custo << '\n';

	return ss.str();
}




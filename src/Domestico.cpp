#include "Obra.h"
#include "Domestico.h"

//CLASSE DOMESTICO
Domestico::Domestico(int duracao, int custo, string empresa, int idHabitacao) :
		Trabalho(duracao, custo, empresa), idHabitacao(idHabitacao) {
}

int Domestico::getIdHabitacao() const {
	return idHabitacao;
}

void Domestico::setID(unsigned int n) {
	idHabitacao=n;
}

string Domestico::info() const {
	stringstream ss;

	ss << "ID Habitacao: " << idHabitacao << '\n';
	ss << Trabalho::info();

	return ss.str();
}

//CLASSE TROLHA
Trolha::Trolha(int duracao, int custo, string empresa, int idHabitacao,
		int quantBetao) :
		Domestico(duracao, custo, empresa, idHabitacao), quantBetao(quantBetao) {
}

int Trolha::getBetao() const {
	return quantBetao;
}

int Trolha::getAsfalto() const {
	return 0;
}

int Trolha::getCabo() const {
	return 0;
}

int Trolha::getMadeira() const {
	return 0;
}

/*int Trolha::getCusto() const {
 return Trabalho::getCusto();
 }

 int Trolha::getDuracao() const {
 return Trabalho::getDuracao();
 }*/

void Trolha::setMaterial(unsigned int n) {
	quantBetao=n;

	if(n<0)
		throw ValorIncorrecto(n);
}

void Trolha::imprimeFicheiro(ofstream& ficheiro_escrita) const {

	ficheiro_escrita << Trabalho::getDuracao() << '\n' << Trabalho::getCusto() << '\n' << Domestico::getIdHabitacao() << '\n'
			<< quantBetao << '\n' << "Trolha" << '\n' << Trabalho::getEmpresa() << '\n';
}

string Trolha::info() const {
	stringstream ss;

	ss << "Tipo de trabalho: Trolha \n";
	ss << "Quantidade de betao: " << quantBetao << '\n';
	ss << Domestico::info();
	ss << Trabalho::info();

	return ss.str();
}

//CLASSE ELETRICISTA
Eletricista::Eletricista(int duracao, int custo, string empresa,
		int idHabitacao, int compCabo) :
		Domestico(duracao, custo, empresa, idHabitacao), compCabo(compCabo) {
}

int Eletricista::getCabo() const {
	return compCabo;
}

int Eletricista::getBetao() const {
	return 0;
}

int Eletricista::getAsfalto() const {
	return 0;
}

int Eletricista::getMadeira() const {
	return 0;
}

/*int Eletricista::getCusto() const {
 return Trabalho::getCusto();
 }

 int Eletricista::getDuracao() const {
 return Trabalho::getDuracao();
 }*/

void Eletricista::setMaterial(unsigned int n) {
	compCabo=n;

	if(n<0)
		throw ValorIncorrecto(n);
}

void Eletricista::imprimeFicheiro(ofstream& ficheiro_escrita) const {

	ficheiro_escrita << Trabalho::getDuracao() << '\n' << Trabalho::getCusto() << '\n' << Domestico::getIdHabitacao() << '\n'
			<< compCabo << '\n' << "Eletricista" << '\n' << Trabalho::getEmpresa() << '\n';
}

string Eletricista::info() const {
	stringstream ss;

	ss << "Tipo de trabalho: Eletricista \n";
	ss << "Comprimento de cabo: " << compCabo << '\n';
	ss << Domestico::info();
	ss << Trabalho::info();

	return ss.str();
}
//CLASSE CARPINTEIRO
Carpinteiro::Carpinteiro(int duracao, int custo, string empresa,
		int idHabitacao, unsigned int areaMadeira) :
		Domestico(duracao, custo, empresa, idHabitacao), areaMadeira(
				areaMadeira) {
}

int Carpinteiro::getCabo() const {
	return 0;
}

int Carpinteiro::getBetao() const {
	return 0;
}

int Carpinteiro::getAsfalto() const {
	return 0;
}

int Carpinteiro::getMadeira() const {
	return areaMadeira;
}

/*int Carpinteiro::getCusto() const {
 return Trabalho::getCusto();
 }

 int Carpinteiro::getDuracao() const {
 return Trabalho::getDuracao();
 }*/

void Carpinteiro::setMaterial(unsigned int n) {
	areaMadeira=n;

	if(n<0)
		throw ValorIncorrecto(n);
}

void Carpinteiro::imprimeFicheiro(ofstream& ficheiro_escrita) const {

	ficheiro_escrita << Trabalho::getDuracao() << '\n' << Trabalho::getCusto() << '\n' << Domestico::getIdHabitacao() << '\n'
			<< areaMadeira << '\n' << "Carpinteiro" << '\n' << Trabalho::getEmpresa() << '\n';
}

string Carpinteiro::info() const {
	stringstream ss;

	ss << "Tipo de trabalho: Carpinteiro \n";
	ss << "Area de madeira: " << areaMadeira << '\n';
	ss << Domestico::info();
	ss << Trabalho::info();

	return ss.str();
}

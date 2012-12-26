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

void Domestico::imprime() const {

	Trabalho::imprime();
	cout << "ID Habitacao: " << idHabitacao << endl;
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

void Trolha::setMaterial(unsigned int n) {
	quantBetao=n;

	if(n<0)
		throw ValorIncorrecto(n);
}

void Trolha::imprimeFicheiro(ofstream& ficheiro_escrita) const {

	ficheiro_escrita << Trabalho::getDuracao() << '\n' << Trabalho::getCusto() << '\n' << Domestico::getIdHabitacao() << '\n'
			<< quantBetao << '\n' << "Trolha" << '\n' << Trabalho::getEmpresa() << '\n';
}

void Trolha::imprime() const {

	Domestico::imprime();
	cout << "Tipo de trabalho: Trolha" << ", " << "Quantidade de betao: " << quantBetao << endl;
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

void Eletricista::setMaterial(unsigned int n) {
	compCabo=n;

	if(n<0)
		throw ValorIncorrecto(n);
}

void Eletricista::imprimeFicheiro(ofstream& ficheiro_escrita) const {

	ficheiro_escrita << Trabalho::getDuracao() << '\n' << Trabalho::getCusto() << '\n' << Domestico::getIdHabitacao() << '\n'
			<< compCabo << '\n' << "Eletricista" << '\n' << Trabalho::getEmpresa() << '\n';
}

void Eletricista::imprime() const {

	Domestico::imprime();
	cout << "Tipo de trabalho: Eletricista" << ", " << "Quantidade de cabo: " << compCabo << endl;
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

void Carpinteiro::setMaterial(unsigned int n) {
	areaMadeira=n;

	if(n<0)
		throw ValorIncorrecto(n);
}

void Carpinteiro::imprimeFicheiro(ofstream& ficheiro_escrita) const {

	ficheiro_escrita << Trabalho::getDuracao() << '\n' << Trabalho::getCusto() << '\n' << Domestico::getIdHabitacao() << '\n'
			<< areaMadeira << '\n' << "Carpinteiro" << '\n' << Trabalho::getEmpresa() << '\n';
}

void Carpinteiro::imprime() const {

	Domestico::imprime();
	cout << "Tipo de trabalho: Carpinteiro" << ", " << "Area de madeira: " << areaMadeira << endl;
}

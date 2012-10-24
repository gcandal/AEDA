#include "Obra.h"
#include "Domestico.h"

//CLASSE DOMESTICO
Domestico::Domestico(int duracao, int custo, string empresa, int idHabitacao) :
		Trabalho(duracao, custo, empresa), idHabitacao(idHabitacao) {
}

int Domestico::getIdHabitacao() const {
	return idHabitacao;
}

int Domestico::getAsfalto() const {
	return 0;
}

int Domestico::getBetao() const {
	return 0;
}

int Domestico::getCabo() const {
	return 0;
}

int Domestico::getMadeira() const {
	return 0;
}

string Domestico::info() const {
	stringstream ss;

	ss << "ID Habitacao: " << idHabitacao << '\n';
	ss << Trabalho::info();

	return ss.str();
}

/*int Domestico::getCusto() const {
 return Trabalho::getCusto();
 }

 int Domestico::getDuracao() const {
 return Trabalho::getDuracao();
 }*/

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

void Trolha::imprimeFicheiro(ofstream& ficheiro_escrita) const {

	ficheiro_escrita << Trabalho::getDuracao() << '\n' << Trabalho::getCusto() << '\n' << Domestico::getIdHabitacao() << '\n'
			<< quantBetao << '\n' << "Trolha" << '\n' << Trabalho::getEmpresa() << '\n'
			<< '\n';
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

void Eletricista::imprimeFicheiro(ofstream& ficheiro_escrita) const {

	ficheiro_escrita << Trabalho::getDuracao() << '\n' << Trabalho::getCusto() << '\n' << Domestico::getIdHabitacao() << '\n'
			<< compCabo << '\n' << "Eletricista" << '\n' << Trabalho::getEmpresa() << '\n'
			<< '\n';
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

int Carpinteiro::getMadeira() const {
	return areaMadeira;
}

/*int Carpinteiro::getCusto() const {
 return Trabalho::getCusto();
 }

 int Carpinteiro::getDuracao() const {
 return Trabalho::getDuracao();
 }*/

void Carpinteiro::imprimeFicheiro(ofstream& ficheiro_escrita) const {

	ficheiro_escrita << Trabalho::getDuracao() << '\n' << Trabalho::getCusto() << '\n' << Domestico::getIdHabitacao() << '\n'
			<< areaMadeira << '\n' << "Carpinteiro" << '\n' << Trabalho::getEmpresa() << '\n'
			<< '\n';
}

string Carpinteiro::info() const {
	stringstream ss;

	ss << "Tipo de trabalho: Carpinteiro \n";
	ss << "Area de madeira: " << areaMadeira << '\n';
	ss << Domestico::info();
	ss << Trabalho::info();

	return ss.str();
}

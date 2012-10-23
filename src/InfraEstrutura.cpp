#include "Obra.h"
#include "InfraEstrutura.h"

//CLASSE INFRA-ESTRUTURA
InfraEstrutura::InfraEstrutura(int duracao, int custo, string empresa,
		int idRua) :
		Trabalho(duracao, custo, empresa), idRua(idRua) {
}

int InfraEstrutura::getIdRua() const {
	return idRua;
}

int InfraEstrutura::getAsfalto() const {
	return 0;
}

int InfraEstrutura::getBetao() const {
	return 0;
}

int InfraEstrutura::getCabo() const {
	return 0;
}

int InfraEstrutura::getMadeira() const {
	return 0;
}

/*int InfraEstrutura::getCusto() const {
 return Trabalho::getCusto();
 }

 int InfraEstrutura::getDuracao() const {
 return Trabalho::getDuracao();
 }*/

string InfraEstrutura::info() const {
	stringstream ss;

	ss << "ID Rua: " << idRua << '\n';
	ss << Trabalho::info();

	return ss.str();
}
//CLASSE ARRUAMENTO
Arruamento::Arruamento(int duracao, int custo, string empresa, int idRua,
		int quantAsfalto) :
		InfraEstrutura(duracao, custo, empresa, idRua), quantAsfalto(
				quantAsfalto) {
}

/*int Arruamento::getCusto() const {
 return Trabalho::getCusto();
 }

 int Arruamento::getDuracao() const {
 return Trabalho::getDuracao();
 }*/

int Arruamento::getAsfalto() const {
	return quantAsfalto;
}

int Arruamento::getBetao() const {
	return 0;
}

int Arruamento::getCabo() const {
	return 0;
}

int Arruamento::getMadeira() const {
	return 0;
}

void Arruamento::imprimeFicheiro(ofstream& ficheiro_escrita) const {

	ficheiro_escrita << duracao << '\n' << custo << '\n' << idRua << '\n'
			<< quantAsfalto << '\n' << "Arruamento" << '\n' << empresa << '\n'
			<< '\n';
}

string Arruamento::info() const {
	stringstream ss;

	ss << "Tipo de trabalho: Arruamento \n";
	ss << "Quantidade de asfalto: " << quantAsfalto << '\n';
	ss << InfraEstrutura::info();
	ss << Trabalho::info();

	return ss.str();
}

//CLASSE SANEAMENTO
Saneamento::Saneamento(int duracao, int custo, string empresa, int idRua,
		int quantBetao) :
		InfraEstrutura(duracao, custo, empresa, idRua), quantBetao(quantBetao) {
}

int Saneamento::getBetao() const {
	return quantBetao;
}

int Saneamento::getAsfalto() const {
	return 0;
}

int Saneamento::getCabo() const {
	return 0;
}

int Saneamento::getMadeira() const {
	return 0;
}

/*int Saneamento::getCusto() const {
 return Trabalho::getCusto();
 }

 int Saneamento::getDuracao() const {
 return Trabalho::getDuracao();
 }*/

void Saneamento::imprimeFicheiro(ofstream& ficheiro_escrita) const {

	ficheiro_escrita << duracao << '\n' << custo << '\n' << idRua << '\n'
			<< quantBetao << '\n' << "Saneamento" << '\n' << empresa << '\n'
			<< '\n';
}

string Saneamento::info() const {
	stringstream ss;

	ss << "Tipo de trabalho: Saneamento \n";
	ss << "Quantidade de betao: " << quantBetao << '\n';
	ss << InfraEstrutura::info();
	ss << Trabalho::info();

	return ss.str();
}

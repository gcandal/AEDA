#include "Obra.h"
#include "InfraEstrutura.h"

using namespace std;

//CLASSE INFRA-ESTRUTURA
InfraEstrutura::InfraEstrutura(int duracao, int custo, string empresa,
		int idRua) :
		Trabalho(duracao, custo, empresa), idRua(idRua) {
}

int InfraEstrutura::getIdRua() const {
	return idRua;
}

void InfraEstrutura::setID(unsigned int n) {
	idRua=n;
}

void InfraEstrutura::imprime() const {

	Trabalho::imprime();
	cout << "ID Rua: " << idRua << endl;
}

//CLASSE ARRUAMENTO
Arruamento::Arruamento(int duracao, int custo, string empresa, int idRua,
		int quantAsfalto) :
		InfraEstrutura(duracao, custo, empresa, idRua), quantAsfalto(
				quantAsfalto) {
}

void Arruamento::setMaterial(unsigned int n) {
	quantAsfalto=n;

	if(n<0)
		throw ValorIncorrecto(n);
}

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

	ficheiro_escrita << Trabalho::getDuracao() << '\n' << Trabalho::getCusto() << '\n' << InfraEstrutura::getIdRua() << '\n'
			<< quantAsfalto << '\n' << "Arruamento" << '\n' << Trabalho::getEmpresa() << '\n';
}

void Arruamento::imprime() const {

	InfraEstrutura::imprime();
	cout << "Tipo de trabalho: Arruamento" << ", " << "Quantidade de asfalto: " << quantAsfalto << endl;
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

void Saneamento::setMaterial(unsigned int n) {
	quantBetao=n;

	if(n<0)
		throw ValorIncorrecto(n);
}

void Saneamento::imprimeFicheiro(ofstream & ficheiro_escrita) const {

	ficheiro_escrita << Trabalho::getDuracao() << '\n' << Trabalho::getCusto() << '\n' << InfraEstrutura::getIdRua() << '\n'
			<< quantBetao << '\n' << "Saneamento" << '\n' << Trabalho::getEmpresa() << '\n';
}

void Saneamento::imprime() const {

	InfraEstrutura::imprime();
	cout << "Tipo de trabalho: Saneamento" << ", " << "Quantidade de betao: " << quantBetao << endl;
}

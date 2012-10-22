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



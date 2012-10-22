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



#include "Obra.h"
#include <iostream>

using namespace std;

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

//CLASSE OBRA
unsigned int Obra::nr = 0;

Obra::Obra() {
	this->nr=nr++;
}

int Obra::getTamanho() const {
	return trabalhos.size();
}

unsigned int Obra::getNr() {
	return nr;
}

void Obra::adicionaTrabalho(Trabalho *t1) {
	trabalhos.push_back(t1);
}

int Obra::getCustoTotal() const {
	int count = 0;

	for (int i = 0; i < getTamanho(); i++)
		count += trabalhos[i]->getCusto();

	return count;
}

int Obra::getDuracaoTotal() const {
	int count = 0;

	for (int i = 0; i < getTamanho(); i++)
		count += trabalhos[i]->getDuracao();

	return count;
}

int Obra::getAsfaltoTotal() const {
	int count = 0;

	for (int i = 0; i < getTamanho(); i++)
		count += trabalhos[i]->getAsfalto();

	return count;
}

int Obra::getBetaoTotal() const {
	int count = 0;

	for (int i = 0; i < getTamanho(); i++)
		count += trabalhos[i]->getBetao();

	return count;
}

int Obra::getCaboTotal() const {
	int count = 0;

	for (int i = 0; i < getTamanho(); i++)
		count += trabalhos[i]->getCabo();

	return count;
}

int Obra::getMadeiraTotal() const {
	int count = 0;

	for (int i = 0; i < getTamanho(); i++)
		count += trabalhos[i]->getMadeira();

	return count;
}

Trabalho & Obra::trabalhoMaisBarato() {
	int j = 0;

	for (int i = 1; i < getTamanho(); i++) {
		if (trabalhos[j]->getCusto() < trabalhos[i]->getCusto())
			j = i;
	}
	return *trabalhos[j];
}

Trabalho & Obra::trabalhoMaisCaro() {
	int j = 0;

	for (int i = 1; i < getTamanho(); i++) {
		if (trabalhos[j]->getCusto() > trabalhos[i]->getCusto())
			j = i;
	}
	return *trabalhos[j];
}

Trabalho & Obra::trabalhoMenorDuracao() {
	int j = 0;

	for (int i = 1; i < getTamanho(); i++) {
		if (trabalhos[j]->getDuracao() < trabalhos[i]->getDuracao())
			j = i;
	}
	return *trabalhos[j];
}

Trabalho & Obra::trabalhoMaiorDuracao() {
	int j = 0;

	for (int i = 1; i < getTamanho(); i++) {
		if (trabalhos[j]->getDuracao() > trabalhos[i]->getDuracao())
			j = i;
	}
	return *trabalhos[j];
}

vector<Trabalho *> Obra::trabalhosCustoMenor(int c) {
	vector<Trabalho *> t;

	for (int i = 0; i < getTamanho(); i++) {
		if (trabalhos[i]->getCusto() < c)
			t.push_back(trabalhos[i]);
	}
	return t;
}

vector<Trabalho *> Obra::trabalhosDuracaoMenor(int d) {
	vector<Trabalho *> t;

	for (int i = 0; i < getTamanho(); i++) {
		if (trabalhos[i]->getDuracao() < d)
			t.push_back(trabalhos[i]);
	}
	return t;
}

vector<Trabalho *> Obra::trabalhosAsfaltoMenor(int a) {
	vector<Trabalho *> t;

	for (int i = 0; i < getTamanho(); i++) {
		if (trabalhos[i]->getAsfalto() < a)
			t.push_back(trabalhos[i]);
	}
	return t;
}

vector<Trabalho *> Obra::trabalhosBetaoMenor(int b) {
	vector<Trabalho *> t;

	for (int i = 0; i < getTamanho(); i++) {
		if (trabalhos[i]->getBetao() < b)
			t.push_back(trabalhos[i]);
	}
	return t;
}

vector<Trabalho *> Obra::trabalhosCaboMenor(int c) {
	vector<Trabalho *> t;

	for (int i = 0; i < getTamanho(); i++) {
		if (trabalhos[i]->getCabo() < c)
			t.push_back(trabalhos[i]);
	}
	return t;
}

vector<Trabalho *> Obra::trabalhosMadeiraMenor(int m) {
	vector<Trabalho *> t;

	for (int i = 0; i < getTamanho(); i++) {
		if (trabalhos[i]->getMadeira() < m)
			t.push_back(trabalhos[i]);
	}
	return t;
}

vector<Trabalho *> Obra::trabalhosCustoMaior(int c) {
	vector<Trabalho *> t;

	for (int i = 0; i < getTamanho(); i++) {
		if (trabalhos[i]->getCusto() > c)
			t.push_back(trabalhos[i]);
	}
	return t;
}

vector<Trabalho *> Obra::trabalhosDuracaoMaior(int d) {
	vector<Trabalho *> t;

	for (int i = 0; i < getTamanho(); i++) {
		if (trabalhos[i]->getDuracao() > d)
			t.push_back(trabalhos[i]);
	}
	return t;
}

vector<Trabalho *> Obra::trabalhosAsfaltoMaior(int a) {
	vector<Trabalho *> t;

	for (int i = 0; i < getTamanho(); i++) {
		if (trabalhos[i]->getAsfalto() > a)
			t.push_back(trabalhos[i]);
	}
	return t;
}

vector<Trabalho *> Obra::trabalhosBetaoMaior(int b) {
	vector<Trabalho *> t;

	for (int i = 0; i < getTamanho(); i++) {
		if (trabalhos[i]->getBetao() > b)
			t.push_back(trabalhos[i]);
	}
	return t;
}

vector<Trabalho *> Obra::trabalhosCaboMaior(int c) {
	vector<Trabalho *> t;

	for (int i = 0; i < getTamanho(); i++) {
		if (trabalhos[i]->getCabo() > c)
			t.push_back(trabalhos[i]);
	}
	return t;
}

vector<Trabalho *> Obra::trabalhosMadeiraMaior(int m) {
	vector<Trabalho *> t;

	for (int i = 0; i < getTamanho(); i++) {
		if (trabalhos[i]->getMadeira() > m)
			t.push_back(trabalhos[i]);
	}
	return t;
}

vector<Trabalho *> Obra::trabalhosEmpresa(string emp) {
	vector<Trabalho *> t;

	for (int i = 0; i < getTamanho(); i++) {
		if (trabalhos[i]->getEmpresa() == emp)
			t.push_back(trabalhos[i]);
	}
	return t;

}

/*vector<Trabalho *> Obra::trabalhosRua(int id) {
	vector<Trabalho *> t;

	for (int i = 0; i < getTamanho(); i++) {
		if (trabalhos[i]->getTipoTrabalho() == arruamento
				|| trabalhos[i]->getTipoTrabalho() == saneamento) {
			if (trabalhos[i]->getId() == id)
				t.push_back(trabalhos[i]);
		}
	}
	return t;
}

vector<Trabalho *> Obra::trabalhosHabitacao(int id) {
	vector<Trabalho *> t;

	for (int i = 0; i < getTamanho(); i++) {
		if ((trabalhos[i]->getTipoTrabalho() == trolha
				|| trabalhos[i]->getTipoTrabalho() == eletricista
				|| trabalhos[i]->getTipoTrabalho() == carpinteiro)) {
			if (trabalhos[i]->getId() == id)
				t.push_back(trabalhos[i]);
		}
	}
	return t;
}*/

void Obra::imprimeFicheiro(ofstream& ficheiro_escrita) const {

	ficheiro_escrita << "+Obra " << nr << endl << endl;

	vector<Trabalho *>::iterator it = trabalhos.begin();

	for (; it != trabalhos.end(); it++)
		(*it)->imprimeFicheiro(ficheiro_escrita);
}

//CLASSE CONSTRUTORA
string Construtora::getNome() const {
	return nome;
}

int Construtora::getTamanho() const {
	return obras.size();
}

void Construtora::adicionaObra(Obra o1) {
	obras.push_back(o1);
}

int Construtora::getCustoTotal() const {
	int count = 0;

	for (int i = 0; i < getTamanho(); i++)
		count += obras[i].getCustoTotal();

	return count;
}

int Construtora::getDuracaoTotal() const {
	int count = 0;

	for (int i = 0; i < getTamanho(); i++)
		count += obras[i].getDuracaoTotal();

	return count;
}

int Construtora::getAsfaltoTotal() const {
	int count = 0;

	for (int i = 0; i < getTamanho(); i++)
		count += obras[i].getAsfaltoTotal();

	return count;
}

int Construtora::getBetaoTotal() const {
	int count = 0;

	for (int i = 0; i < getTamanho(); i++)
		count += obras[i].getBetaoTotal();

	return count;
}

int Construtora::getCaboTotal() const {
	int count = 0;

	for (int i = 0; i < getTamanho(); i++)
		count += obras[i].getCaboTotal();

	return count;
}

int Construtora::getMadeiraTotal() const {
	int count = 0;

	for (int i = 0; i < getTamanho(); i++)
		count += obras[i].getMadeiraTotal();

	return count;
}

Obra & Construtora::obraMaisBarato() {
	int j = 0;

	for (int i = 1; i < getTamanho(); i++) {
		if (obras[j].getCustoTotal() > obras[i].getCustoTotal())
			j = i;
	}
	return obras[j];
}

Obra & Construtora::obraMaisCaro() {
	int j = 0;

	for (int i = 1; i < getTamanho(); i++) {
		if (obras[j].getCustoTotal() > obras[i].getCustoTotal())
			j = i;
	}
	return obras[j];
}

Obra & Construtora::obraMenorDuracao() {
	int j = 0;

	for (int i = 1; i < getTamanho(); i++) {
		if (obras[j].getDuracaoTotal() < obras[i].getDuracaoTotal())
			j = i;
	}
	return obras[j];
}

Obra & Construtora::obraMaiorDuracao() {
	int j = 0;

	for (int i = 1; i < getTamanho(); i++) {
		if (obras[j].getDuracaoTotal() > obras[i].getDuracaoTotal())
			j = i;
	}
	return obras[j];
}

vector<Obra> Construtora::obrasCustoMenor(int c) {
	vector<Obra> o;

	for (int i = 1; i < getTamanho(); i++) {
		if (obras[i].getCustoTotal() < c)
			o.push_back(obras[i]);
	}
	return o;
}

vector<Obra> Construtora::obrasDuracaoMenor(int d) {
	vector<Obra> o;

	for (int i = 1; i < getTamanho(); i++) {
		if (obras[i].getDuracaoTotal() < d)
			o.push_back(obras[i]);
	}
	return o;
}

vector<Obra> Construtora::obrasAsfaltoMenor(int a) {
	vector<Obra> o;

	for (int i = 1; i < getTamanho(); i++) {
		if (obras[i].getAsfaltoTotal() < a)
			o.push_back(obras[i]);
	}
	return o;
}

vector<Obra> Construtora::obrasBetaoMenor(int b) {
	vector<Obra> o;

	for (int i = 1; i < getTamanho(); i++) {
		if (obras[i].getBetaoTotal() < b)
			o.push_back(obras[i]);
	}
	return o;
}

vector<Obra> Construtora::obrasCaboMenor(int c) {
	vector<Obra> o;

	for (int i = 1; i < getTamanho(); i++) {
		if (obras[i].getCaboTotal() < c)
			o.push_back(obras[i]);
	}
	return o;
}

vector<Obra> Construtora::obrasMadeiraMenor(int m) {
	vector<Obra> o;

	for (int i = 1; i < getTamanho(); i++) {
		if (obras[i].getMadeiraTotal() < m)
			o.push_back(obras[i]);
	}
	return o;
}

vector<Obra> Construtora::obrasCustoMaior(int c) {
	vector<Obra> o;

	for (int i = 1; i < getTamanho(); i++) {
		if (obras[i].getCustoTotal() > c)
			o.push_back(obras[i]);
	}
	return o;
}

vector<Obra> Construtora::obrasDuracaoMaior(int d) {
	vector<Obra> o;

	for (int i = 1; i < getTamanho(); i++) {
		if (obras[i].getDuracaoTotal() > d)
			o.push_back(obras[i]);
	}
	return o;
}

vector<Obra> Construtora::obrasAsfaltoMaior(int a) {
	vector<Obra> o;

	for (int i = 1; i < getTamanho(); i++) {
		if (obras[i].getAsfaltoTotal() > a)
			o.push_back(obras[i]);
	}
	return o;
}

vector<Obra> Construtora::obrasBetaoMaior(int b) {
	vector<Obra> o;

	for (int i = 1; i < getTamanho(); i++) {
		if (obras[i].getBetaoTotal() > b)
			o.push_back(obras[i]);
	}
	return o;
}

vector<Obra> Construtora::obrasCaboMaior(int c) {
	vector<Obra> o;

	for (int i = 1; i < getTamanho(); i++) {
		if (obras[i].getCaboTotal() > c)
			o.push_back(obras[i]);
	}
	return o;
}

vector<Obra> Construtora::obrasMadeiraMaior(int m) {
	vector<Obra> o;

	for (int i = 1; i < getTamanho(); i++) {
		if (obras[i].getMadeiraTotal() > m)
			o.push_back(obras[i]);
	}
	return o;
}

void Construtora::lerFicheiroTrabalho(Obra& o1, ifstream& ficheiro_leitura) {/*

	string tmp;
	int tmpn[4];
	stringstream ss;

	getline(ficheiro_leitura, tmp);
	getline(ficheiro_leitura, tmp);

	for (int i = 0; i < 5; i++) {
		getline(ficheiro_leitura, tmp);
		ss << tmp;
		ss >> tmpn[i];
	}

	getline(ficheiro_leitura, tmp);

	switch (tmp[0]) {
	case 'A':
		getline(ficheiro_leitura, tmp);
		Trabalho *t1 = new Arruamento(tmpn[0], tmpn[1], tmp, tmpn[2], tmpn[3]);
		o1.adicionaTrabalho(t1);
		break;

	case 'S':
		getline(ficheiro_leitura, tmp);
		Trabalho *t2 = new Saneamento(tmpn[0], tmpn[1], tmp, tmpn[2], tmpn[3]);
		o1.adicionaTrabalho(t2);
		break;

	case 'T':
		getline(ficheiro_leitura, tmp);
		Trabalho *t3 = new Trolha(tmpn[0], tmpn[1], tmp, tmpn[2], tmpn[3]);
		o1.adicionaTrabalho(t3);
		break;

	case 'E':
		getline(ficheiro_leitura, tmp);
		Trabalho * t4 = new Eletricista(tmpn[0], tmpn[1], tmp, tmpn[2], tmpn[3]);
		o1.adicionaTrabalho(t4);
		break;

	case 'C':
		getline(ficheiro_leitura, tmp);
		Trabalho *t5 = new Carpinteiro(tmpn[0], tmpn[1], tmp, tmpn[2], tmpn[3]);
		o1.adicionaTrabalho(t5);
		break;
	}

	getline(ficheiro_leitura, tmp);

	if (tmp.length() == 0)
		lerFicheiroTrabalho(o1, ficheiro_leitura);*/

}

void Construtora::lerFicheiro(ifstream& ficheiro_leitura) {

	if (!ficheiro_leitura)
		throw ErroFicheiro(time(NULL));
	else {

		string tmp;
		int tmpn[4];
		stringstream ss;

		getline(ficheiro_leitura, tmp);
		this->nome = tmp;

		while (!ficheiro_leitura.eof()) {
			Obra o1;

			lerFicheiroTrabalho(o1, ficheiro_leitura);
			getline(ficheiro_leitura, tmp);

			adicionaObra(o1);
		}
	}

}

void Construtora::escreverFicheiro(ofstream& ficheiro_escrita) const {

	ficheiro_escrita << nome << endl;

	vector<Obra>::iterator it = obras.begin();

	for (; it != obras.end(); it++)
		it->imprimeFicheiro(ficheiro_escrita);
}

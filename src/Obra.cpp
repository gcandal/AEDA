#include "Obra.h"
#include <iostream>

using namespace std;

//CLASSE OBRA
unsigned int Obra::ultimoNr = 0;

Obra::Obra(): nr(++ultimoNr) {}

unsigned int Obra::getNr() const {
	return nr;
};

int Obra::getTamanho() const {
	return trabalhos.size();
}

unsigned int Obra::getUltimoNr() {
	return ultimoNr;
}

void Obra::adicionaTrabalho(Trabalho *t1) {
	trabalhos.push_back(t1);
}

bool Obra::eliminaTrab(unsigned int n) {

	for(unsigned int i=0; i<trabalhos.size(); i++) {
		if(trabalhos[i]->getNum() ==  n) {
			trabalhos.erase(trabalhos.begin()+i);
			return true;
		}
	}
	throw TrabalhoInexistente(n);
	return false;
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
	{
		cout << "Id " << i << endl;
		cout << trabalhos[i]->getAsfalto() << endl;
		count += trabalhos[i]->getAsfalto();
	}

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

	for (int i = 0; i < getTamanho(); i++) {
		if (trabalhos[j]->getCusto() < trabalhos[i]->getCusto())
			j = i;
	}
	return *trabalhos[j];
}

Trabalho & Obra::trabalhoMaisCaro() {
	int j = 0;

	for (int i = 0; i < getTamanho(); i++) {
		if (trabalhos[j]->getCusto() > trabalhos[i]->getCusto())
			j = i;
	}
	return *trabalhos[j];
}

Trabalho & Obra::trabalhoMenorDuracao() {
	int j = 0;

	for (int i = 0; i < getTamanho(); i++) {
		if (trabalhos[j]->getDuracao() < trabalhos[i]->getDuracao())
			j = i;
	}
	return *trabalhos[j];
}

Trabalho & Obra::trabalhoMaiorDuracao() {
	int j = 0;

	for (int i = 0; i < getTamanho(); i++) {
		if (trabalhos[j]->getDuracao() > trabalhos[i]->getDuracao())
			j = i;
	}
	return *trabalhos[j];
}

/*string Obra::searchNum(int search)
{
	string result = "Trabalho nao encontrado/n";
	for (unsigned int i = 0; i < trabalhos.size(); i++)
	{
		if(trabalhos[i]->getNum() == (unsigned) search)
		{
			result = trabalhos[i]->imprime();
			break;
		}
	}
	return result;
}*/

vector<Trabalho *> Obra::trabalhosCustoMenor(int c) const {
	vector<Trabalho *> t;

	for (int i = 0; i < getTamanho(); i++) {
		if (trabalhos[i]->getCusto() < c)
			t.push_back(trabalhos[i]);
	}
	return t;
}

vector<Trabalho *> Obra::trabalhosDuracaoMenor(int d) const {
	vector<Trabalho *> t;

	for (int i = 0; i < getTamanho(); i++) {
		if (trabalhos[i]->getDuracao() < d)
			t.push_back(trabalhos[i]);
	}
	return t;
}

vector<Trabalho *> Obra::trabalhosAsfaltoMenor(int a) const {
	vector<Trabalho *> t;

	for (int i = 0; i < getTamanho(); i++) {
		if (trabalhos[i]->getAsfalto() < a)
			t.push_back(trabalhos[i]);
	}
	return t;
}

vector<Trabalho *> Obra::trabalhosBetaoMenor(int b) const {
	vector<Trabalho *> t;

	for (int i = 0; i < getTamanho(); i++) {
		if (trabalhos[i]->getBetao() < b)
			t.push_back(trabalhos[i]);
	}
	return t;
}

vector<Trabalho *> Obra::trabalhosCaboMenor(int c) const {
	vector<Trabalho *> t;

	for (int i = 0; i < getTamanho(); i++) {
		if (trabalhos[i]->getCabo() < c)
			t.push_back(trabalhos[i]);
	}
	return t;
}

vector<Trabalho *> Obra::trabalhosMadeiraMenor(int m) const {
	vector<Trabalho *> t;

	for (int i = 0; i < getTamanho(); i++) {
		if (trabalhos[i]->getMadeira() < m)
			t.push_back(trabalhos[i]);
	}
	return t;
}

vector<Trabalho *> Obra::trabalhosCustoMaior(int c) const {
	vector<Trabalho *> t;

	for (int i = 0; i < getTamanho(); i++) {
		if (trabalhos[i]->getCusto() > c)
			t.push_back(trabalhos[i]);
	}
	return t;
}

vector<Trabalho *> Obra::trabalhosDuracaoMaior(int d) const {
	vector<Trabalho *> t;

	for (int i = 0; i < getTamanho(); i++) {
		if (trabalhos[i]->getDuracao() > d)
			t.push_back(trabalhos[i]);
	}
	return t;
}

vector<Trabalho *> Obra::trabalhosAsfaltoMaior(int a) const {
	vector<Trabalho *> t;

	for (int i = 0; i < getTamanho(); i++) {
		if (trabalhos[i]->getAsfalto() > a)
			t.push_back(trabalhos[i]);
	}
	return t;
}

vector<Trabalho *> Obra::trabalhosBetaoMaior(int b) const {
	vector<Trabalho *> t;

	for (int i = 0; i < getTamanho(); i++) {
		if (trabalhos[i]->getBetao() > b)
			t.push_back(trabalhos[i]);
	}
	return t;
}

vector<Trabalho *> Obra::trabalhosCaboMaior(int c) const {
	vector<Trabalho *> t;

	for (int i = 0; i < getTamanho(); i++) {
		if (trabalhos[i]->getCabo() > c)
			t.push_back(trabalhos[i]);
	}
	return t;
}

vector<Trabalho *> Obra::trabalhosMadeiraMaior(int m) const {
	vector<Trabalho *> t;

	for (int i = 0; i < getTamanho(); i++) {
		if (trabalhos[i]->getMadeira() > m)
			t.push_back(trabalhos[i]);
	}
	return t;
}

vector<Trabalho *> Obra::trabalhosEmpresa(string emp) const {
	vector<Trabalho *> t;

	for (int i = 0; i < getTamanho(); i++) {
		if (trabalhos[i]->getEmpresa() == emp)
			t.push_back(trabalhos[i]);
	}
	return t;

}

vector<Trabalho *> Obra::trabalhosRua(int id) const {
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

vector<Trabalho *> Obra::trabalhosHabitacao(int id) const {
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
}

vector<Trabalho *> Obra::trabalhosTipo(tipoTrabalho tp){
	vector<Trabalho *> t;

	for (int i = 0; i < getTamanho(); i++)
	{
		if (trabalhos[i]->getTipoTrabalho() == tp)
		{
			t.push_back(trabalhos[i]);
		}
	}

	return t;
}

void Obra::imprimeFicheiro(ofstream& ficheiro_escrita) const {

	ficheiro_escrita << "+Obra " << nr << endl << endl;

	for (unsigned int i = 0; i < trabalhos.size(); i++) {
		trabalhos[i]->imprimeFicheiro(ficheiro_escrita);
		if(i==trabalhos.size()-1)
			ficheiro_escrita << "*";
		else ficheiro_escrita << "\n";
	}
}

int Obra::getCustoTrab(tipoTrabalho t) const {
	int count=0;

	for(unsigned int i=0; i<trabalhos.size(); i++) {
		if(trabalhos[i]->getTipoTrabalho() == t)
			count += trabalhos[i]->getCusto();
	}
	return count;
}

int Obra::getDuracaoTrab(tipoTrabalho t) const {
	int count=0;

	for(unsigned int i=0; i<trabalhos.size(); i++) {
		if(trabalhos[i]->getTipoTrabalho() == t)
			count += trabalhos[i]->getDuracao();
	}
	return count;
}

Trabalho* Obra::getTrabalho(unsigned int n) {

	for(vector<Trabalho *>::iterator it=trabalhos.begin(); it!=trabalhos.end(); it++)
		if((*it)->getNum()==n)
			return *it;

	throw TrabalhoInexistente(n);
}

void Obra::imprime() const {

	cout << "Obra numero: " << nr << endl;
	for(unsigned int i=0; i<trabalhos.size(); i++) {
		trabalhos[i]->imprime();
	}
}

//CLASSE CONSTRUTORA
Construtora::Construtora() {};

Construtora::Construtora(string nome): nome(nome) {};

string Construtora::getNome() const {
	return nome;
}

int Construtora::getTamanho() const {
	return obras.size();
}

void Construtora::adicionaObra(Obra o1) {
	obras.push_back(o1);
}

bool Construtora::eliminaObra(unsigned int n) {

	for(unsigned int i=0; i<obras.size(); i++) {
		if(obras[i].getNr()==n) {
			obras.erase(obras.begin()+i);
			return true;
		}
	}
	throw ObraInexistente(n);
	return false;
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

	for (int i = 0; i < getTamanho(); i++) {
		if (obras[j].getCustoTotal() > obras[i].getCustoTotal())
			j = i;
	}
	return obras[j];
}

Obra & Construtora::obraMaisCaro() {
	int j = 0;

	for (int i = 0; i < getTamanho(); i++) {
		if (obras[j].getCustoTotal() > obras[i].getCustoTotal())
			j = i;
	}
	return obras[j];
}

Obra & Construtora::obraMenorDuracao() {
	int j = 0;

	for (int i = 0; i < getTamanho(); i++) {
		if (obras[j].getDuracaoTotal() < obras[i].getDuracaoTotal())
			j = i;
	}
	return obras[j];
}

Obra & Construtora::obraMaiorDuracao() {
	int j = 0;

	for (int i = 0; i < getTamanho(); i++) {
		if (obras[j].getDuracaoTotal() > obras[i].getDuracaoTotal())
			j = i;
	}
	return obras[j];
}

vector<Obra> Construtora::obrasCustoMenor(int c) const {
	vector<Obra> o;

	for (int i = 0; i < getTamanho(); i++) {
		if (obras[i].getCustoTotal() < c)
			o.push_back(obras[i]);
	}
	return o;
}

vector<Obra> Construtora::obrasDuracaoMenor(int d) const {
	vector<Obra> o;

	for (int i = 0; i < getTamanho(); i++) {
		if (obras[i].getDuracaoTotal() < d)
			o.push_back(obras[i]);
	}
	return o;
}

vector<Obra> Construtora::obrasAsfaltoMenor(int a) const {
	vector<Obra> o;

	for (int i = 0; i < getTamanho(); i++) {
		if (obras[i].getAsfaltoTotal() < a)
			o.push_back(obras[i]);
	}
	return o;
}

vector<Obra> Construtora::obrasBetaoMenor(int b) const {
	vector<Obra> o;

	for (int i = 0; i < getTamanho(); i++) {
		if (obras[i].getBetaoTotal() < b)
			o.push_back(obras[i]);
	}
	return o;
}

vector<Obra> Construtora::obrasCaboMenor(int c) const {
	vector<Obra> o;

	for (int i = 0; i < getTamanho(); i++) {
		if (obras[i].getCaboTotal() < c)
			o.push_back(obras[i]);
	}
	return o;
}

vector<Obra> Construtora::obrasMadeiraMenor(int m) const {
	vector<Obra> o;

	for (int i = 0; i < getTamanho(); i++) {
		if (obras[i].getMadeiraTotal() < m)
			o.push_back(obras[i]);
	}
	return o;
}

vector<Obra> Construtora::obrasCustoMaior(int c) const {
	vector<Obra> o;

	for (int i = 0; i < getTamanho(); i++) {
		if (obras[i].getCustoTotal() > c)
			o.push_back(obras[i]);
	}
	return o;
}

vector<Obra> Construtora::obrasDuracaoMaior(int d) const {
	vector<Obra> o;

	for (int i = 0; i < getTamanho(); i++) {
		if (obras[i].getDuracaoTotal() > d)
			o.push_back(obras[i]);
	}
	return o;
}

vector<Obra> Construtora::obrasAsfaltoMaior(int a) const {
	vector<Obra> o;

	for (int i = 0; i < getTamanho(); i++) {
		if (obras[i].getAsfaltoTotal() > a)
			o.push_back(obras[i]);
	}
	return o;
}

vector<Obra> Construtora::obrasBetaoMaior(int b) const {
	vector<Obra> o;

	for (int i = 0; i < getTamanho(); i++) {
		if (obras[i].getBetaoTotal() > b)
			o.push_back(obras[i]);
	}
	return o;
}

vector<Obra> Construtora::obrasCaboMaior(int c) const {
	vector<Obra> o;

	for (int i = 0; i < getTamanho(); i++) {
		if (obras[i].getCaboTotal() > c)
			o.push_back(obras[i]);
	}
	return o;
}

vector<Obra> Construtora::obrasMadeiraMaior(int m) const {
	vector<Obra> o;

	for (int i = 0; i < getTamanho(); i++) {
		if (obras[i].getMadeiraTotal() > m)
			o.push_back(obras[i]);
	}
	return o;
}


void Construtora::imprime() const {

	for(unsigned int i=0; i<obras.size(); i++) {
		obras[i].imprime();
		cout << endl;
	}
	cout << endl << endl;
}

void Construtora::lerFicheiroTrabalho(Obra& o1, ifstream& ficheiro_leitura) {

	string tmp;
	int tmpn[]={0,0,0,0};
	stringstream ss;

	for (int i = 0; i < 4; i++) {
		getline(ficheiro_leitura, tmp);
		ss << tmp;
		ss >> tmpn[i];
		ss.clear();
	}

	getline(ficheiro_leitura, tmp);

	switch (tmp[0]) {
	case 'A':
		getline(ficheiro_leitura, tmp);
		{Trabalho *t1 = new Arruamento(tmpn[0], tmpn[1], tmp, tmpn[2], tmpn[3]);
		o1.adicionaTrabalho(t1);}
		break;

	case 'S':
		getline(ficheiro_leitura, tmp);
		{Trabalho *t2 = new Saneamento(tmpn[0], tmpn[1], tmp, tmpn[2], tmpn[3]);
		o1.adicionaTrabalho(t2);}
		break;

	case 'T':
		getline(ficheiro_leitura, tmp);
		{Trabalho *t3 = new Trolha(tmpn[0], tmpn[1], tmp, tmpn[2], tmpn[3]);
		o1.adicionaTrabalho(t3);}
		break;

	case 'E':
		getline(ficheiro_leitura, tmp);
		{Trabalho * t4 = new Eletricista(tmpn[0], tmpn[1], tmp, tmpn[2], tmpn[3]);
		o1.adicionaTrabalho(t4);}
		break;

	case 'C':
		getline(ficheiro_leitura, tmp);
		{Trabalho *t5 = new Carpinteiro(tmpn[0], tmpn[1], tmp, tmpn[2], tmpn[3]);
		o1.adicionaTrabalho(t5);}
		break;
	}

	getline(ficheiro_leitura, tmp);

	if (tmp.length() == 0)
		lerFicheiroTrabalho(o1, ficheiro_leitura);
	else {
		getline(ficheiro_leitura, tmp);
		getline(ficheiro_leitura, tmp);
	}

}

void Construtora::lerFicheiro(ifstream& ficheiro_leitura) {

	if (!ficheiro_leitura)
		throw ErroFicheiro();
	else {

		string tmp;
		stringstream ss;

		getline(ficheiro_leitura, tmp);
		this->nome = tmp;

		getline(ficheiro_leitura, tmp);
		getline(ficheiro_leitura, tmp);

		while (!ficheiro_leitura.eof()) {
			Obra o1;
			lerFicheiroTrabalho(o1, ficheiro_leitura);

			adicionaObra(o1);
		}
	}

}

void Construtora::escreverFicheiro(ofstream& ficheiro_escrita) const {

	ficheiro_escrita << nome << endl;

	for (unsigned int i = 0; i < obras.size(); i++) {
		obras[i].imprimeFicheiro(ficheiro_escrita);

		if(i<obras.size()-1)
			ficheiro_escrita << "\n";
	}
}

Obra* Construtora::getObra(unsigned int nr) {

	for(vector<Obra>::iterator it=obras.begin(); it!=obras.end(); it++)
		if(it->getNr()==nr)
			return &(*it);

	throw ObraInexistente(nr);
}

void Construtora::procuraTipoTrabalho() {
	stringstream ss;
	int op;
	string str;
	tipoTrabalho t;
	vector<tipoTrabalho> vctr;
	//= {arruamento, saneamento, trolha, eletricista, carpinteiro};

	vctr.push_back(arruamento);
	vctr.push_back(saneamento);
	vctr.push_back(trolha);
	vctr.push_back(eletricista);
	vctr.push_back(carpinteiro);


	bool valid = false;

	cout << "Escolha um tipo de trabalho" << endl;
	cout << "1: Arruamento" << endl;
	cout << "2: Saneamento" << endl;
	cout << "3: Trolha" << endl;
	cout << "4: Eletricista" << endl;
	cout << "5: Carpinteiro" << endl;

	do {
		cin >> str;
		ss << str;
		ss >> op;

		if (op < 1 || op > 5) {
			cout << "Opcao invalida \n" << endl;
			break;
		}

		t = vctr[op - 1];
		valid = true;
	} while (!valid);


	for(int i = 0; i < getTamanho(); i++)
	{
		vector<Trabalho *> v;
		v = obras[i].trabalhosTipo(t);
		if(v.size() > 0)
		{
			cout << endl << "Obra: " << obras[i].getNr() << endl;
			for (unsigned int j = 0; j < v.size(); j++)
			{
				cout << "Trabalho numero: " << v[j]->getNum() << endl;
			}
			cout << endl;
		}
	}
}

void Construtora::procuraID() const {
	stringstream ss;
	int op, id;
	string str;
	tipoTrabalho t;
	vector<tipoTrabalho> vctr;
	//= {arruamento, saneamento, trolha, eletricista, carpinteiro};

	vctr.push_back(arruamento);
	vctr.push_back(saneamento);
	vctr.push_back(trolha);
	vctr.push_back(eletricista);
	vctr.push_back(carpinteiro);


	bool valid = false;

	cout << "Escolha um tipo de trabalho" << endl;
	cout << "1: Arruamento" << endl;
	cout << "2: Saneamento" << endl;
	cout << "3: Trolha" << endl;
	cout << "4: Eletricista" << endl;
	cout << "5: Carpinteiro" << endl;

	do {
		cin >> str;
		ss << str;
		ss >> op;
		ss.clear();

		if (op < 1 || op > 5) {
			cout << "Opcao invalida \n" << endl;
			break;
		}

		t = vctr[op - 1];
		valid = true;
	} while (!valid);

	if(t<2)
		cout << "Insira o ID da Rua: ";
	else cout << "Insira o ID da Habitacao: ";

	do {
		ss.clear();
		cin >> str;
		ss << str;
	} while(!(ss>>id));

	for(int i = 0; i < getTamanho(); i++)
	{
		vector<Trabalho *> v;
		if(t<2)
			v = obras[i].trabalhosRua(id);
		else v = obras[i].trabalhosHabitacao(id);


		if(v.size() > 0)
		{
			cout << endl << "Obra: " << obras[i].getNr() << endl;
			for (unsigned int j = 0; j < v.size(); j++)
			{
				cout << "Trabalho numero: " << v[j]->getNum() << endl;
			}
			cout << endl;
		} else throw idInexistente(id,t,obras[i].getNr());
	}
}

void Construtora::procuraEmpresa() const {
	stringstream ss;
	int op;
	string str;


	bool valid = false;

	cout << "Escolha o nome da empresa sub-contratada a procurar:" << endl;
	cin >> str;
	cout << endl;


	for(int i = 0; i < getTamanho(); i++)
	{
		vector<Trabalho *> v;
		v = obras[i].trabalhosEmpresa(str);


		if(v.size() > 0)
		{
			cout << endl << "Obra: " << obras[i].getNr() << endl;
			for (unsigned int j = 0; j < v.size(); j++)
			{
				cout << "Trabalho numero: " << v[j]->getNum() << endl;
			}
			cout << endl;
		} else throw EmpresaInexistente(str,obras[i].getNr());
	}
}

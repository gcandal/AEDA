#include "Empresa.h"

//class Empresa

Empresa::Empresa(string nome, int ano, int contacto):
	nome(nome), ultimoAnoContratacao(ano), contacto(contacto)
{}

string Empresa::getNome() const {return nome; }

int Empresa::getAno() const {return ultimoAnoContratacao;}

int Empresa::getContacto() const {return contacto;}

void Empresa::setNome(string novo_nome) { nome=novo_nome;}

void Empresa::setAno(int ano) {ultimoAnoContratacao=ano;}

void Empresa::setContacto(int novo_contacto) {contacto=novo_contacto;}


//class EmpresasGuardadas;

void EmpresasGuardadas::inserirEmpresa(Empresa &e1) {

	Tabela::iterator it=empresas.find(e1);

	if(it==empresas.end())
		empresas.insert(e1);
	else {
		empresas.erase(it);
		empresas.insert(e1);
	}
}

void EmpresasGuardadas::removerEmpresa(string nome) {

	Tabela::iterator it=empresas.begin();
	Empresa e1;

	while(it!=empresas.end()) {
		if(it->getNome()==nome)
			empresas.erase(it);
		it++;
	}
}

int EmpresasGuardadas::removerEmpresas(int anoMinimo) {

	int count=0;
	Tabela::iterator it=empresas.begin();
	Empresa e1;

	while(it!=empresas.end()) {
		if(it->getAno()<anoMinimo) {
			empresas.erase(it);
			count++;
		}
		it++;
	}
	return count;
}

void EmpresasGuardadas::alterarContacto(string nome, int contacto) {

	Empresa e1(nome);
	Tabela::iterator it=empresas.find(e1);

	if(it==empresas.end())
		throw EmpresaNaoExistente(nome);
	else {
		e1 = (*it);
		empresas.erase(it);
		e1.setContacto(contacto);
		empresas.insert(e1);
	}
}

void EmpresasGuardadas::alterarAno(string nome, int ano) {

	Empresa e1(nome);
	Tabela::iterator it=empresas.find(e1);

	if(it==empresas.end())
		throw EmpresaNaoExistente(nome);
	else {
		e1 = (*it);
		empresas.erase(it);
		e1.setAno(ano);
		empresas.insert(e1);
	}
}

void EmpresasGuardadas::consultaEmpresas() {

	Tabela::iterator it=empresas.begin();

	while(it!=empresas.end()) {
		cout<<"Empresa: "<<it->getNome()<<", Ultima Contratacao: "<<it->getAno()<<", Contacto: "<<it->getContacto()<<endl;
		it++;
	}
}

void EmpresasGuardadas::leFicheiro(ifstream& ficheiro_leitura) {

	if(!ficheiro_leitura)
		throw ErroNoFicheiro();
	else {
		string nome, temp1, temp2;
		int contacto, ultimoAno;

		while (!ficheiro_leitura.eof()) {

			getline(ficheiro_leitura, nome);
			getline(ficheiro_leitura, temp1);
			getline(ficheiro_leitura, temp2);

			contacto = atoi(temp1.c_str());
			ultimoAno = atoi(temp2.c_str());

			Empresa e1(nome, contacto, ultimoAno);
			inserirEmpresa(e1);
		}
	}
}

void EmpresasGuardadas::escreveFicheiro(ofstream& ficheiro_escrita) {

	Tabela::iterator it=empresas.begin();

	while(it!=empresas.end()) {
		ficheiro_escrita<<it->getNome()<<endl<<it->getAno()<<endl<<it->getContacto()<<endl;
		it++;
	}
}

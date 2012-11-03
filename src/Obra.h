#ifndef OBRA_H_
#define OBRA_H_
#include <vector>
#include <string>
#include <fstream>
#include <ctime>
#include <sstream>
#include "Domestico.h"
#include "InfraEstrutura.h"
#include "Trabalho.h"

using namespace std;

/*class Empresa {
 string nome;
 vector <Trabalho *> trab;
 public:
 void adicionaTrabalho(Trabalho *t1);
 void setNome(string nome);
 string getNome();
 };*/

class Obra {
	vector<Trabalho *> trabalhos;
	static unsigned int ultimoNr;
	unsigned int nr;
public:
	Obra();
	int getTamanho() const;
	static unsigned int getUltimoNr();
	void adicionaTrabalho(Trabalho *t1);
	//bool eliminaTrab(Trabalho *t1);
	bool eliminaTrab(unsigned int n);
	unsigned int getNr() const;
	int getCustoTotal() const;
	int getCustoTrab(tipoTrabalho t) const;
	int getDuracaoTrab(tipoTrabalho t) const;;
	int getDuracaoTotal() const;
	int getAsfaltoTotal() const;
	int getBetaoTotal() const;
	int getCaboTotal() const;
	int getMadeiraTotal() const;
	Trabalho &trabalhoMaisBarato();
	Trabalho &trabalhoMaisCaro();
	Trabalho &trabalhoMenorDuracao();
	Trabalho &trabalhoMaiorDuracao();
	string searchNum(int search);
	vector<Trabalho *> trabalhosCustoMenor(int c) const;
	vector<Trabalho *> trabalhosDuracaoMenor(int d) const;
	vector<Trabalho *> trabalhosAsfaltoMenor(int a) const;
	vector<Trabalho *> trabalhosBetaoMenor(int b) const;
	vector<Trabalho *> trabalhosCaboMenor(int c) const;
	vector<Trabalho *> trabalhosMadeiraMenor(int m) const;
	vector<Trabalho *> trabalhosCustoMaior(int c) const;
	vector<Trabalho *> trabalhosDuracaoMaior(int d) const;
	vector<Trabalho *> trabalhosAsfaltoMaior(int a) const;
	vector<Trabalho *> trabalhosBetaoMaior(int b) const;
	vector<Trabalho *> trabalhosCaboMaior(int c) const;
	vector<Trabalho *> trabalhosMadeiraMaior(int m) const;
	vector<Trabalho *> trabalhosEmpresa(string emp) const;
	vector<Trabalho *> trabalhosRua(int id) const;
	vector<Trabalho *> trabalhosHabitacao(int id) const;
	vector<Trabalho *> trabalhosTipo(tipoTrabalho tp);
	Trabalho& getTrabalho(unsigned int n);
	void imprime() const;
	void imprimeFicheiro(ofstream& ficheiro_escrita) const;

	class TrabalhoInexistente {
	public:
		int id;
		TrabalhoInexistente(int id): id(id) {}
	};
 };

class Construtora {
	string nome;
	vector<Obra> obras;
	void lerFicheiroTrabalho(Obra& o1, ifstream& ficheiro_leitura);
public:
	Construtora(string nome);
	Construtora();
	string getNome() const;
	int getTamanho() const;
	void adicionaObra(Obra o1);
	//bool eliminaObra(Obra o1);
	bool eliminaObra(unsigned int n);
	int getCustoTotal() const;
	int getDuracaoTotal() const;
	int getAsfaltoTotal() const;
	int getBetaoTotal() const;
	int getCaboTotal() const;
	int getMadeiraTotal() const;
	Obra &obraMaisBarato();
	Obra &obraMaisCaro();
	Obra &obraMenorDuracao();
	Obra &obraMaiorDuracao();
	vector<Obra> obrasCustoMenor(int c) const;
	vector<Obra> obrasDuracaoMenor(int d) const;
	vector<Obra> obrasAsfaltoMenor(int a) const;
	vector<Obra> obrasBetaoMenor(int b) const;
	vector<Obra> obrasCaboMenor(int c) const;
	vector<Obra> obrasMadeiraMenor(int m) const;
	vector<Obra> obrasCustoMaior(int c) const;
	vector<Obra> obrasDuracaoMaior(int d) const;
	vector<Obra> obrasAsfaltoMaior(int a) const;
	vector<Obra> obrasBetaoMaior(int b) const;
	vector<Obra> obrasCaboMaior(int c) const;
	vector<Obra> obrasMadeiraMaior(int m) const;
	void procuraTipoTrabalho();
	void imprime() const;
	void escreverFicheiro(ofstream& ficheiro_escrita) const;
	void lerFicheiro(ifstream& ficheiro_leitura);
	Obra& getObra(unsigned int nr);

	class ErroFicheiro {
	public:
		ErroFicheiro() {
		}
	};

	class ObraInexistente {
	public:
		int id;
		ObraInexistente(int id): id(id) {}
	};

};

#endif /*OBRA_H_*/

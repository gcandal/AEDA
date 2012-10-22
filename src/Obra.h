#ifndef OBRA_H_
#define OBRA_H_
#include <vector>
#include <string>
#include <fstream>
#include <ctime>
#include <sstream>
#include "Domestico.h"
#include "InfraEstrutura.h"

using namespace std;

const char NOME_FICHEIRO[] = "obras.txt";

enum tipoTrabalho{arruamento, saneamento, trolha, eletricista, carpinteiro};

class Trabalho {
	const unsigned int duracao, custo;
	string empresa;
public:
	Trabalho(int duracao, int custo, string empresa);
	virtual ~Trabalho() {}
	string getEmpresa() const;
	/*virtual*/ int getCusto() const /*= 0*/;
	/*virtual*/ int getDuracao() const /*= 0*/;
<<<<<<< .mine
	//virtual int getAsfalto() const = 0;
	//virtual int getBetao() const = 0;
	//virtual int getCabo() const = 0;
	//virtual int getMadeira() const = 0;
=======
	virtual int getAsfalto() const;
	virtual int getBetao() const;
	virtual int getCabo() const;
	virtual int getMadeira() const;
>>>>>>> .r10
	//virtual void imprimeEcra() const;
	//virtual void imprimeFicheiro() const;
};

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
public:
	int getTamanho() const;
	void adicionaTrabalho(Trabalho *t1);
	int getCustoTotal() const;
	int getDuracaoTotal() const;
	int getAsfaltoTotal() const;
	int getBetaoTotal() const;
	int getCaboTotal() const;
	int getMadeiraTotal() const;
	Trabalho &trabalhoMaisBarato();
	Trabalho &trabalhoMaisCaro();
	Trabalho &trabalhoMenorDuracao();
	Trabalho &trabalhoMaiorDuracao();
	vector<Trabalho *> trabalhosCustoMenor(int c);
	vector<Trabalho *> trabalhosDuracaoMenor(int d);
	vector<Trabalho *> trabalhosAsfaltoMenor(int a);
	vector<Trabalho *> trabalhosBetaoMenor(int b);
	vector<Trabalho *> trabalhosCaboMenor(int c);
	vector<Trabalho *> trabalhosMadeiraMenor(int m);
	vector<Trabalho *> trabalhosCustoMaior(int c);
	vector<Trabalho *> trabalhosDuracaoMaior(int d);
	vector<Trabalho *> trabalhosAsfaltoMaior(int a);
	vector<Trabalho *> trabalhosBetaoMaior(int b);
	vector<Trabalho *> trabalhosCaboMaior(int c);
	vector<Trabalho *> trabalhosMadeiraMaior(int m);
	vector<Trabalho *> trabalhosEmpresa(string emp);
};

class Construtora {
	string nome;
	vector<Obra> obras;
	void lerFicheiroTrabalho(Obra& o1, ifstream& ficheiro_leitura);
public:
	Construtora();
	string getNome() const;
	int getTamanho() const;
	void adicionaObra(Obra o1);
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
	vector<Obra> obrasCustoMenor(int c);
	vector<Obra> obrasDuracaoMenor(int d);
	vector<Obra> obrasAsfaltoMenor(int a);
	vector<Obra> obrasBetaoMenor(int b);
	vector<Obra> obrasCaboMenor(int c);
	vector<Obra> obrasMadeiraMenor(int m);
	vector<Obra> obrasCustoMaior(int c);
	vector<Obra> obrasDuracaoMaior(int d);
	vector<Obra> obrasAsfaltoMaior(int a);
	vector<Obra> obrasBetaoMaior(int b);
	vector<Obra> obrasCaboMaior(int c);
	vector<Obra> obrasMadeiraMaior(int m);
	void escreverFicheiro() const;
	void lerFicheiro();

	class ErroFicheiro {
		time_t tempo;
	public:
		ErroFicheiro(time_t tempo): tempo(tempo) {}
		time_t getTempo() {return tempo;};
	};
};

#endif /*OBRA_H_*/

#ifndef TROLHAS_H_
#define TROLHAS_H_
#include <vector>
#include <string>
#include <fstream>
#include <ctime>
#include <sstream>

using namespace std;

enum tipoTrabalho{arruamento, saneamento, trolha, eletricista, carpinteiro};

class Trabalho {
	const unsigned int duracao, custo;
	string empresa;
public:
	Trabalho(int duracao, int custo, string empresa);
	virtual ~Trabalho() {}
	string getEmpresa() const;
	/*virtual*/ int getCusto() const;
	/*virtual*/ int getDuracao() const;
	virtual int getAsfalto() const = 0;
	virtual int getBetao() const;
	virtual int getCabo() const;
	virtual int getMadeira() const;
	virtual void imprimeFicheiro(ofstream& ficheiro_escrita) const;
	virtual tipoTrabalho getTipoTrabalho() const;
	virtual int getId() const;
	virtual string info() const;
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
	static unsigned int nr;
public:
	Obra();
	int getTamanho() const;
	static unsigned int getNr();
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
	vector<Trabalho *> trabalhosRua(int id);
	vector<Trabalho *> trabalhosHabitacao(int id);
	void imprimeFicheiro(ofstream& ficheiro_escrita) const;
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
	//Remove Obra?
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
	void escreverFicheiro(ofstream& ficheiro_escrita) const;
	void lerFicheiro(ifstream& ficheiro_leitura);

	class ErroFicheiro {
		time_t tempo;
	public:
		ErroFicheiro(time_t tempo): tempo(tempo) {}
		time_t getTempo() {return tempo;}
	};
};

class InfraEstrutura: public Trabalho {
private:
	const unsigned int idRua;
public:
	InfraEstrutura(int duracao, int custo, string empresa, int idRua);
	int getIdRua() const;
	virtual int getAsfalto() const;
	virtual int getBetao() const;
	virtual int getCabo() const;
	virtual int getMadeira() const;
	//virtual int getCusto() const;
	//virtual int getDuracao() const;
	virtual tipoTrabalho getTipoTrabalho() const;
	virtual int getId() const {return idRua;}
	virtual string info() const;
};

class Arruamento: public InfraEstrutura {
	const unsigned int quantAsfalto;
	const static tipoTrabalho tipo = arruamento;
public:
	Arruamento(int duracao, int custo, string empresa, int idRua,
			int quantAsfalto);
	int getAsfalto() const;
	int getBetao() const;
	int getCabo() const;
	int getMadeira() const;
	//int getCusto() const;
	//int getDuracao() const;
	void imprimeFicheiro(ofstream& ficheiro_escrita) const;
	virtual tipoTrabalho getTipoTrabalho() const {return tipo;}
	virtual string info() const;
};

class Saneamento: public InfraEstrutura {
	const unsigned int quantBetao;
	const static tipoTrabalho tipo = saneamento;
public:
	Saneamento(int duracao, int custo, string empresa, int idRua,
			int quantBetao);
	int getBetao() const;
	int getAsfalto() const;
	int getCabo() const;
	int getMadeira() const;
	//int getCusto() const;
	//int getDuracao() const;
	void imprimeFicheiro(ofstream& ficheiro_escrita) const;
	virtual tipoTrabalho getTipoTrabalho() const {return tipo;}
	virtual string info() const;
};

/*
 * Classe virtual dos trabalhos domesticos
 *
 */
class Domestico: public Trabalho {
	const unsigned int idHabitacao;			/*<ID da habitacao na qual o trabalho esta a ser efetuado */
public:
	/* Construtor de Domestico
	 *
	 * @param duracao Tempo que o trabalho demorara a realizar
	 * @param custo Custo que o trabalho tera
	 * @param empresa Empresa a qual o trabalho esta entregue
	 * @param idHabitacao ID da habitacao na qual o trabalho sera efetuado
	 *
	 */
	Domestico(int duracao, int custo, string empresa, int idHabitacao);
	/*
	 * @return ID da habitacao na qual o trabalho esta a ser efetuado
	 */
	int getIdHabitacao() const;
	virtual int getAsfalto() const;
	virtual int getBetao() const;
	virtual int getCabo() const;
	virtual int getMadeira() const;
	//virtual int getCusto() const;
	//virtual int getDuracao() const;
	virtual tipoTrabalho getTipoTrabalho() const;
	virtual int getId() const {return idHabitacao;}
	virtual string info() const;
};

class Trolha: public Domestico {
	const unsigned int quantBetao;
	const static tipoTrabalho tipo = trolha;
public:
	Trolha(int duracao, int custo, string empresa, int idRua, int quantBetao);
	int getBetao() const;
	int getAsfalto() const;
	int getCabo() const;
	int getMadeira() const;
	//int getCusto() const;
	//int getDuracao() const;
	void imprimeFicheiro(ofstream& ficheiro_escrita) const;
	virtual tipoTrabalho getTipoTrabalho() const {return tipo;}
	virtual string info() const;
};

class Eletricista: public Domestico {
	const unsigned int compCabo;
	const static tipoTrabalho tipo = eletricista;
public:
	Eletricista(int duracao, int custo, string empresa, int idRua,
			int compCabo);
	int getCabo() const;
	int getBetao() const;
	int getAsfalto() const;
	int getMadeira() const;
	//int getCusto() const;
	//int getDuracao() const;
	void imprimeFicheiro(ofstream& ficheiro_escrita) const;
	virtual tipoTrabalho getTipoTrabalho() const {return tipo;}
	virtual string info() const;
};

class Carpinteiro: public Domestico {
	const unsigned int areaMadeira;
	const static tipoTrabalho tipo = carpinteiro;
public:
	Carpinteiro(int duracao, int custo, string empresa, int idRua,
			unsigned int areaMadeira);
	int getMadeira() const;
	//int getCusto() const;
	//int getDuracao() const;
	void imprimeFicheiro(ofstream& ficheiro_escrita) const;
	virtual tipoTrabalho getTipoTrabalho() const {return tipo;}
	virtual string info() const;
};


#endif /*TROLHAS_H_*/

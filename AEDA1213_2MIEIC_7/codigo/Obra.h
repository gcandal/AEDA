#ifndef OBRA_H_
#define OBRA_H_
#include <vector>
#include <string>
#include <fstream>
#include <ctime>
#include <sstream>
#include <queue>
#include "Domestico.h"
#include "InfraEstrutura.h"
#include "Trabalho.h"

using namespace std;

//Usado para conter comparador das filas de prioridade
struct ComparaTrabalhos : public std::binary_function<Trabalho*, Trabalho*, bool>
{
  bool operator()(const Trabalho* t1, const Trabalho* t2) const
  {
    return t1->getCusto() > t2->getCusto();
  }
};

class Obra {
	vector<Trabalho *> trabalhos;
	priority_queue<Trabalho *,vector<Trabalho *>,ComparaTrabalhos> fila_trabalhos;
	/*!
	 * \brief Adiciona um trabalho � fila de prioridade de pagamento
	 */
	void fila_adicionaTrabalho(Trabalho *t1);
	/*!
	 * \brief Elimina um trabalho da fila de prioridade de pagamento
	 * \param N�mero do trabalho a ser eliminado
	 */
	bool fila_eliminaTrab(unsigned int n);
	static unsigned int ultimoNr;
	unsigned int nr;
public:
	Obra();
	/*!
	 * \return Devolve o n�mero de trabalhos na obra
	 */
	int getTamanho() const;
	/*!
	 * \return Devolve o ultimo n�mero de identifica��o atribu�do a uma obra
	 */
	static unsigned int getUltimoNr();
	/*!
	 * \brief Adiciona um trabalho � obra
	 * \param Apontador para o trabalho a ser adicionado
	 */
	void adicionaTrabalho(Trabalho *t1);
	vector<Trabalho *> getTrabalhos() const;
	/*!
	 * \brief Elimina um trabalho
	 * \param N�mero do trabalho a ser eliminado
	 */
	bool eliminaTrab(unsigned int n);
	/*!
	 * \brief Atualiza o custo de um trabalho
	 * \param Trabalho que foi atualizado
	 */
	void fila_atualizaTrab(Trabalho* t1);
	/*!
	 * \return Devolve o proximo trabalho a ser pago
	 */
	Trabalho* fila_proximoAPagar() const;
	/*!
	 * \return Devolve o numero da obra
	 */
	unsigned int getNr() const;
	/*!
	 * \return Devolve o custo total da obra
	 */
	int getCustoTotal() const;
	/*!
	 * \brief Calcula o custo total de todos os trabalhos de um determinado tipo
	 * \param Tipo de trabalho
	 * \return Custo total dos trabalhos
	 */
	int getCustoTrab(tipoTrabalho t) const;
	/*!
	 * \brief Calcula a dura��o total de todos os trabalhos de um determinado tipo
	 * \param Tipo de trabalho
	 * \return Dura��o total dos trabalhos
	 */
	int getDuracaoTrab(tipoTrabalho t) const;
	/*!
	 * \return Devolve a dura��o total da obra
	 */
	int getDuracaoTotal() const;
	/*!
	 * \return Devolve o asfalto total na obra
	 */
	int getAsfaltoTotal() const;
	/*!
	 * \return Devolve o bet�o total na obra
	 */
	int getBetaoTotal() const;
	/*!
	 * \return Devolve o cabo total na obra
	 */
	int getCaboTotal() const;
	/*!
	 * \return Devolve a madeira total na obra
	 */
	int getMadeiraTotal() const;
	/*!
	 * \return Devolve o trabalho mais barato
	 */
	Trabalho &trabalhoMaisBarato();
	/*!
	 * \return Devolve o trabalho mais caro
	 */
	Trabalho &trabalhoMaisCaro();
	/*!
	 * \return Devolve o trabalho com menor dura��o
	 */
	Trabalho &trabalhoMenorDuracao();
	/*!
	 * \return Devolve o trabalho com maior dura��o
	 */
	Trabalho &trabalhoMaiorDuracao();
	/*!
	 * \brief Procura um trabalho pelo seu n�mero
	 * \param N�mero do trabalho
	 * \return Devolve o trabalho com o n�mero correspondente
	 */
	string searchNum(int search);
	/*!
	 * \param Valor do custo pretendido
	 * \result Devolve os trabalhos com custo inferior ao introduzido
	 */
	vector<Trabalho *> trabalhosCustoMenor(int c) const;
	/*!
	 * \param Valor da dura��o pretendida
	 * \result Devolve os trabalhos com dura��o inferior � introduzida
	 */
	vector<Trabalho *> trabalhosDuracaoMenor(int d) const;
	/*!
	 * \param Quandtidade de asfalto pretendida
	 * \result Devolve os trabalhos com quantidade de asfalto inferior � introduzida
	 */
	vector<Trabalho *> trabalhosAsfaltoMenor(int a) const;
	/*!
	 * \param Quandtidade de bet�o pretendida
	 * \result Devolve os trabalhos com quantidade de bet�o inferior � introduzida
	 */
	vector<Trabalho *> trabalhosBetaoMenor(int b) const;
	/*!
	 * \param Comprimento de cabo pretendido
	 * \result Devolve os trabalhos com comprimento de cabo inferior ao introduzido
	 */
	vector<Trabalho *> trabalhosCaboMenor(int c) const;
	/*!
	 * \param �rea de madeira pretendida
	 * \result Devolve os trabalhos com �rea de madeira inferior � introduzida
	 */
	vector<Trabalho *> trabalhosMadeiraMenor(int m) const;
	/*!
	 * \param Valor do custo pretendido
	 * \result Devolve os trabalhos com custo superior ao introduzido
	 */
	vector<Trabalho *> trabalhosCustoMaior(int c) const;
	/*!
	 * \param Dura��o pretendida
	 * \result Devolve os trabalhos com dura��o superior � introduzida
	 */
	vector<Trabalho *> trabalhosDuracaoMaior(int d) const;
	/*!
	 * \param Quandtidade de asfalto pretendida
	 * \result Devolve os trabalhos com quantidade de asfalto superior � introduzida
	 */
	vector<Trabalho *> trabalhosAsfaltoMaior(int a) const;
	/*!
	 * \param Quandtidade de asfalto pretendida
	 * \result Devolve os trabalhos com quantidade de bet�o superior � introduzida
	 */
	vector<Trabalho *> trabalhosBetaoMaior(int b) const;
	/*!
	 * \param Comprimento de cabo pretendido
	 * \result Devolve os trabalhos com comprimento de cabo superior ao introduzido
	 */
	vector<Trabalho *> trabalhosCaboMaior(int c) const;
	/*!
	 * \param �rea de madeira pretendida
	 * \result Devolve os trabalhos com �rea de madeira superior � introduzida
	 */
	vector<Trabalho *> trabalhosMadeiraMaior(int m) const;
	/*!
	 * \param Nome da empresa
	 * \return Devolve os trabalhos que pertencem a uma empresa
	 */
	vector<Trabalho *> trabalhosEmpresa(string emp) const;
	/*!
	 * \param ID da rua
	 * \return Devolve todos os trabalhos a serem feitos numa determinada rua
	 */
	vector<Trabalho *> trabalhosRua(int id) const;
	/*!
	 * \param ID da habita��o
	 * \return Devolve todos os trabalhos a serem feitos numa determinada habita��o
	 */
	vector<Trabalho *> trabalhosHabitacao(int id) const;
	/*!
	 * \param Tipo de trabalho
	 * \return Devolve todos os trabalhos de um tipo
	 */
	vector<Trabalho *> trabalhosTipo(tipoTrabalho tp);
	/*!
	 * \param N�mero do trabalho pretendido
	 * \return Devolve o trabalho com um determinado n�mero
	 */
	Trabalho* getTrabalho(unsigned int n);
	/*!
	 *  \brief Imprime na consola informa��es sobre a obra
	 */
	void imprime() const;
	/*!
	 *  \brief Imprime na consola informa��es sobre a ordem de pagamento da Tesouraria
	 */
	void fila_imprime() const;
	/*!
	 *  \brief Guarda no ficheiro de escrita informa��es sobre a obra
	 *  \param Ficheiro onde se pretende guardar as informa��es
	 */
	void imprimeFicheiro(ofstream& ficheiro_escrita) const;

	class TrabalhoInexistente {
	public:
		int id;
		TrabalhoInexistente(int id) :
				id(id) {
		}
	};

};

class Construtora {
	string nome;
	vector<Obra> obras;
	priority_queue<Trabalho *,vector<Trabalho *>,ComparaTrabalhos> fila_trabalhos_totais;
	void fila_adicionaTrabalho(Trabalho *t1);
	/*!
	 * \brief L� no ficheiro de texto as informa��es relativas a uma obra
	 * \param Obra pretendida, ficheiro de texto
	 */
	void lerFicheiroTrabalho(Obra& o1, ifstream& ficheiro_leitura);
public:
	/*!
	 * \brief Construtor da classe Construtora
	 * \param Nome da construtora
	 */
	Construtora(string nome);
	Construtora();
	/*!
	 * \return Devolve o nome da construtora
	 */
	string getNome() const;
	/*!
	 * \return Devolve o n�mero de obras da construtora
	 */
	int getTamanho() const;
	/*!
	 * \brief Adiciona uma obra
	 * \param Obra pretendida
	 */
	void adicionaObra(Obra o1);
	/*!
	 * \brief Elimina uma obra com um determinado n�mero
	 * \param N�mero da obra pretendida
	 */
	bool eliminaObra(unsigned int n);
	/*!
	 * \return Calcula o custo total da obra
	 */
	int getCustoTotal() const;
	/*!
	 * \return Calcula a dura��o total da obra
	 */
	int getDuracaoTotal() const;
	/*!
	 * \return Calcula o asfalto total da obra
	 */
	int getAsfaltoTotal() const;
	/*!
	 * \return Calcula o bet�o total da obra
	 */
	int getBetaoTotal() const;
	/*!
	 * \return Calcula o comprimento de cabo total da obra
	 */
	int getCaboTotal() const;
	/*!
	 * \return Calcula a �rea de madeira total da obra
	 */
	int getMadeiraTotal() const;
	/*!
	 * \return Devolve a obra mais barata
	 */
	Obra &obraMaisBarato();
	/*!
	 * \return Devolve a obra mais cara
	 */
	Obra &obraMaisCaro();
	/*!
	 * \return Devolve a obra com menor dura��o
	 */
	Obra &obraMenorDuracao();
	/*!
	 * \return Devolve a obra com maior dura��o
	 */
	Obra &obraMaiorDuracao();
	/*!
	 * \param Custo pretendido
	 * \return Devolve as obras com custo menor do que o pretendido
	 */
	vector<Obra> obrasCustoMenor(int c) const;
	/*!
	 * \param Dura��o pretendida
	 * \return Devolve as obras com dura��o menor do que a pretendida
	 */
	vector<Obra> obrasDuracaoMenor(int d) const;
	/*!
	 * \param Quantidade de asfalto pretendida
	 * \return Devolve as obras com quantidade de asfalto menor do que a pretendida
	 */
	vector<Obra> obrasAsfaltoMenor(int a) const;
	/*!
	 * \param Quantidade de bet�o pretendida
	 * \return Devolve as obras com quantidade de bet�o menor do que a pretendida
	 */
	vector<Obra> obrasBetaoMenor(int b) const;
	/*!
	 * \param Comprimento de cabo pretendido
	 * \return Devolve as obras com comprimento de cabo menor do que o pretendido
	 */
	vector<Obra> obrasCaboMenor(int c) const;
	/*!
	 * \param �rea de madeira pretendida
	 * \return Devolve as obras com �rea de madeira menor do que a pretendida
	 */
	vector<Obra> obrasMadeiraMenor(int m) const;
	/*!
	 * \param Custo pretendido
	 * \return Devolve as obras com custo maior do que o pretendido
	 */
	vector<Obra> obrasCustoMaior(int c) const;
	/*!
	 * \param Dura��o pretendida
	 * \return Devolve as obras com dura��o maior do que a pretendida
	 */
	vector<Obra> obrasDuracaoMaior(int d) const;
	/*!
	 * \param Quantidade de asfalto pretendida
	 * \return Devolve as obras com quantidade de asfalto maior do que a pretendida
	 */
	vector<Obra> obrasAsfaltoMaior(int a) const;
	/*!
	 * \param Quantidade de bet�o pretendida
	 * \return Devolve as obras com quantidade de bet�o maior do que a pretendida
	 */
	vector<Obra> obrasBetaoMaior(int b) const;
	/*!
	 * \param Comprimento de cabo pretendido
	 * \return Devolve as obras com comprimento de cabo maior do que o pretendido
	 */
	vector<Obra> obrasCaboMaior(int c) const;
	/*!
	 * \param �rea de madeira pretendida
	 * \return Devolve as obras com �rea de madeira maior do que a pretendida
	 */
	vector<Obra> obrasMadeiraMaior(int m) const;
	/*!
	 * \brief Pede um tipo de trabalho ao utilizador e imprime os ID's de todos os trabalhos desse tipo
	 */
	void procuraTipoTrabalho();
	/*!
	 * \brief Imprime na consola informa��es sobre a construtora
	 */
	void imprime() const;
	/*!
	 *  \brief Guarda no ficheiro de escrita informa��es sobre a construtora
	 *  \param Ficheiro onde se pretende guardar as informa��es
	 */
	void escreverFicheiro(ofstream& ficheiro_escrita) const;
	/*!
	 *  \brief Imprime na consola informa��es sobre a ordem de pagamento da Tesouraria
	 */
	void fila_imprime();
	/*!
	 *  \brief L� no ficheiro de escrita informa��es sobre a construtora
	 *  \param Ficheiro de onde se pretende ler as informa��es
	 */
	void lerFicheiro(ifstream& ficheiro_leitura);
	/*!
	 * \param N�mero da obra pretendida
	 * \result Devolve a obra com o n�mero pretendido
	 */
	Obra* getObra(unsigned int nr);

	void procuraID() const;
	void procuraEmpresa() const;

	class ErroFicheiro {
	public:
		ErroFicheiro() {
		}
	};

	class ObraInexistente {
	public:
		int id;
		ObraInexistente(int id) :
				id(id) {
		}
	};

	class EmpresaInexistente {
	public:
		string empresa;
		unsigned int num;
		EmpresaInexistente(string empresa,unsigned int num): empresa(empresa), num(num) {};
	};

	class idInexistente {
	public:
		int id;
		tipoTrabalho t;
		unsigned int num;
		idInexistente(int id, tipoTrabalho t, unsigned int num) :
			id(id), t(t), num(num) {
		}
	};

};

#endif /*OBRA_H_*/

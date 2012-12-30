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

/*!
 * \brief Estrutura usada para conter comparador das filas de prioridade
 */
struct ComparaTrabalhos : public std::binary_function<Trabalho*, Trabalho*, bool>
{
  bool operator()(const Trabalho* t1, const Trabalho* t2) const
  {
    return t1->getCusto() > t2->getCusto();
  }
};

/*!
 * \brief Classe que representa uma obra
 */
class Obra {
	vector<Trabalho *> trabalhos;
	priority_queue<Trabalho *,vector<Trabalho *>,ComparaTrabalhos> fila_trabalhos;
	/*!
	 * \brief Adiciona um trabalho a fila de prioridade de pagamento
	 */
	void fila_adicionaTrabalho(Trabalho *t1);
	/*!
	 * \brief Elimina um trabalho da fila de prioridade de pagamento
	 * \param Numero do trabalho a ser eliminado
	 */
	bool fila_eliminaTrab(unsigned int n);
	static unsigned int ultimoNr;
	unsigned int nr;
public:
	Obra();
	/*!
	 * \return Devolve o numero de trabalhos na obra
	 */
	int getTamanho() const;
	/*!
	 * \return Devolve o ultimo numero de identificacao atribuido a uma obra
	 */
	static unsigned int getUltimoNr();
	/*!
	 * \brief Adiciona um trabalho a obra
	 * \param Apontador para o trabalho a ser adicionado
	 */
	void adicionaTrabalho(Trabalho *t1);
	/*!
	 * \brief Devolve os trabalhos da obra
	 * \result Vector de trabalhos
	 */
	vector<Trabalho *> getTrabalhos() const;
	/*!
	 * \brief Elimina um trabalho
	 * \param Numero do trabalho a ser eliminado
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
	 * \brief Calcula a duracao total de todos os trabalhos de um determinado tipo
	 * \param Tipo de trabalho
	 * \return Duracao total dos trabalhos
	 */
	int getDuracaoTrab(tipoTrabalho t) const;
	/*!
	 * \return Devolve a duracao total da obra
	 */
	int getDuracaoTotal() const;
	/*!
	 * \return Devolve o asfalto total na obra
	 */
	int getAsfaltoTotal() const;
	/*!
	 * \return Devolve o betao total na obra
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
	 * \return Devolve o trabalho com menor duracao
	 */
	Trabalho &trabalhoMenorDuracao();
	/*!
	 * \return Devolve o trabalho com maior duracao
	 */
	Trabalho &trabalhoMaiorDuracao();
	/*!
	 * \brief Procura um trabalho pelo seu numero
	 * \param Numero do trabalho
	 * \return Devolve o trabalho com o numero correspondente
	 */
	string searchNum(int search);
	/*!
	 * \param Valor do custo pretendido
	 * \result Devolve os trabalhos com custo inferior ao introduzido
	 */
	vector<Trabalho *> trabalhosCustoMenor(int c) const;
	/*!
	 * \param Valor da duracao pretendida
	 * \result Devolve os trabalhos com duracao inferior a introduzida
	 */
	vector<Trabalho *> trabalhosDuracaoMenor(int d) const;
	/*!
	 * \param Quantidade de asfalto pretendida
	 * \result Devolve os trabalhos com quantidade de asfalto inferior a introduzida
	 */
	vector<Trabalho *> trabalhosAsfaltoMenor(int a) const;
	/*!
	 * \param Quandtidade de betao pretendida
	 * \result Devolve os trabalhos com quantidade de betao inferior a introduzida
	 */
	vector<Trabalho *> trabalhosBetaoMenor(int b) const;
	/*!
	 * \param Comprimento de cabo pretendido
	 * \result Devolve os trabalhos com comprimento de cabo inferior ao introduzido
	 */
	vector<Trabalho *> trabalhosCaboMenor(int c) const;
	/*!
	 * \param Area de madeira pretendida
	 * \result Devolve os trabalhos com area de madeira inferior a introduzida
	 */
	vector<Trabalho *> trabalhosMadeiraMenor(int m) const;
	/*!
	 * \param Valor do custo pretendido
	 * \result Devolve os trabalhos com custo superior ao introduzido
	 */
	vector<Trabalho *> trabalhosCustoMaior(int c) const;
	/*!
	 * \param Duracao pretendida
	 * \result Devolve os trabalhos com duracao superior a introduzida
	 */
	vector<Trabalho *> trabalhosDuracaoMaior(int d) const;
	/*!
	 * \param Quantidade de asfalto pretendida
	 * \result Devolve os trabalhos com quantidade de asfalto superior a introduzida
	 */
	vector<Trabalho *> trabalhosAsfaltoMaior(int a) const;
	/*!
	 * \param Quantidade de asfalto pretendida
	 * \result Devolve os trabalhos com quantidade de betao superior a introduzida
	 */
	vector<Trabalho *> trabalhosBetaoMaior(int b) const;
	/*!
	 * \param Comprimento de cabo pretendido
	 * \result Devolve os trabalhos com comprimento de cabo superior ao introduzido
	 */
	vector<Trabalho *> trabalhosCaboMaior(int c) const;
	/*!
	 * \param Area de madeira pretendida
	 * \result Devolve os trabalhos com area de madeira superior a introduzida
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
	 * \param ID da habitacao
	 * \return Devolve todos os trabalhos a serem feitos numa determinada habitacao
	 */
	vector<Trabalho *> trabalhosHabitacao(int id) const;
	/*!
	 * \param Tipo de trabalho
	 * \return Devolve todos os trabalhos de um tipo
	 */
	vector<Trabalho *> trabalhosTipo(tipoTrabalho tp);
	/*!
	 * \param Numero do trabalho pretendido
	 * \return Devolve o trabalho com um determinado numero
	 */
	Trabalho* getTrabalho(unsigned int n);
	/*!
	 *  \brief Imprime na consola informacoes sobre a obra
	 */
	void imprime() const;
	/*!
	 *  \brief Imprime na consola informacoes sobre a ordem de pagamento da Tesouraria
	 */
	void fila_imprime() const;
	/*!
	 *  \brief Guarda no ficheiro de escrita informacoes sobre a obra
	 *  \param Ficheiro onde se pretende guardar as informacoes
	 */
	void imprimeFicheiro(ofstream& ficheiro_escrita) const;
	/*!
	 *  \brief Classe que representa trabalhos inexistentes
	 */
	class TrabalhoInexistente {
	public:
		int id;
		TrabalhoInexistente(int id) :
				id(id) {
		}
	};

};

/*!
 *  \brief Classe que representa a construtora
 */
class Construtora {
	string nome;
	vector<Obra> obras;
	priority_queue<Trabalho *,vector<Trabalho *>,ComparaTrabalhos> fila_trabalhos_totais;
	void fila_adicionaTrabalho(Trabalho *t1);
	/*!
	 * \brief Lê no ficheiro de texto as informacoes relativas a uma obra
	 * \param Obra pretendida, ficheiro de texto
	 */
	void lerFicheiroTrabalho(Obra& o1, ifstream& ficheiro_leitura);
public:
	/*!
	 * \brief Construtor da classe Construtora
	 * \param Nome da construtora
	 */
	Construtora(string nome);
	/*!
	 * \brief Construtor da classe Construtora
	 */
	Construtora();
	/*!
	 * \return Devolve o nome da construtora
	 */
	string getNome() const;
	/*!
	 * \return Devolve o numero de obras da construtora
	 */
	int getTamanho() const;
	/*!
	 * \brief Adiciona uma obra
	 * \param Obra pretendida
	 */
	void adicionaObra(Obra o1);
	/*!
	 * \brief Elimina uma obra com um determinado numero
	 * \param Numero da obra pretendida
	 */
	bool eliminaObra(unsigned int n);
	/*!
	 * \return Calcula o custo total da obra
	 */
	int getCustoTotal() const;
	/*!
	 * \return Calcula a duracao total da obra
	 */
	int getDuracaoTotal() const;
	/*!
	 * \return Calcula o asfalto total da obra
	 */
	int getAsfaltoTotal() const;
	/*!
	 * \return Calcula o betao total da obra
	 */
	int getBetaoTotal() const;
	/*!
	 * \return Calcula o comprimento de cabo total da obra
	 */
	int getCaboTotal() const;
	/*!
	 * \return Calcula a area de madeira total da obra
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
	 * \return Devolve a obra com menor duracao
	 */
	Obra &obraMenorDuracao();
	/*!
	 * \return Devolve a obra com maior duracao
	 */
	Obra &obraMaiorDuracao();
	/*!
	 * \param Custo pretendido
	 * \return Devolve as obras com custo menor do que o pretendido
	 */
	vector<Obra> obrasCustoMenor(int c) const;
	/*!
	 * \param Duracao pretendida
	 * \return Devolve as obras com duracao menor do que a pretendida
	 */
	vector<Obra> obrasDuracaoMenor(int d) const;
	/*!
	 * \param Quantidade de asfalto pretendida
	 * \return Devolve as obras com quantidade de asfalto menor do que a pretendida
	 */
	vector<Obra> obrasAsfaltoMenor(int a) const;
	/*!
	 * \param Quantidade de betao pretendida
	 * \return Devolve as obras com quantidade de betao menor do que a pretendida
	 */
	vector<Obra> obrasBetaoMenor(int b) const;
	/*!
	 * \param Comprimento de cabo pretendido
	 * \return Devolve as obras com comprimento de cabo menor do que o pretendido
	 */
	vector<Obra> obrasCaboMenor(int c) const;
	/*!
	 * \param area de madeira pretendida
	 * \return Devolve as obras com area de madeira menor do que a pretendida
	 */
	vector<Obra> obrasMadeiraMenor(int m) const;
	/*!
	 * \param Custo pretendido
	 * \return Devolve as obras com custo maior do que o pretendido
	 */
	vector<Obra> obrasCustoMaior(int c) const;
	/*!
	 * \param Duracao pretendida
	 * \return Devolve as obras com duracao maior do que a pretendida
	 */
	vector<Obra> obrasDuracaoMaior(int d) const;
	/*!
	 * \param Quantidade de asfalto pretendida
	 * \return Devolve as obras com quantidade de asfalto maior do que a pretendida
	 */
	vector<Obra> obrasAsfaltoMaior(int a) const;
	/*!
	 * \param Quantidade de betao pretendida
	 * \return Devolve as obras com quantidade de betao maior do que a pretendida
	 */
	vector<Obra> obrasBetaoMaior(int b) const;
	/*!
	 * \param Comprimento de cabo pretendido
	 * \return Devolve as obras com comprimento de cabo maior do que o pretendido
	 */
	vector<Obra> obrasCaboMaior(int c) const;
	/*!
	 * \param area de madeira pretendida
	 * \return Devolve as obras com area de madeira maior do que a pretendida
	 */
	vector<Obra> obrasMadeiraMaior(int m) const;
	/*!
	 * \brief Pede um tipo de trabalho ao utilizador e imprime os ID's de todos os trabalhos desse tipo
	 */
	void procuraTipoTrabalho();
	/*!
	 * \brief Imprime na consola informacoes sobre a construtora
	 */
	void imprime() const;
	/*!
	 *  \brief Guarda no ficheiro de escrita informacoes sobre a construtora
	 *  \param Ficheiro onde se pretende guardar as informacoes
	 */
	void escreverFicheiro(ofstream& ficheiro_escrita) const;
	/*!
	 *  \brief Imprime na consola informacoes sobre a ordem de pagamento da Tesouraria
	 */
	void fila_imprime();
	/*!
	 *  \brief Le no ficheiro de escrita informacoes sobre a construtora
	 *  \param Ficheiro de onde se pretende ler as informacoes
	 */
	void lerFicheiro(ifstream& ficheiro_leitura);
	/*!
	 * \param Numero da obra pretendida
	 * \result Devolve a obra com o numero pretendido
	 */
	Obra* getObra(unsigned int nr);
	/*!
	 * \brief Menu que procura um determinado ID
	 */
	void procuraID() const;
	/*!
	 * \brief Menu que procura uma determinada empresa
	 */
	void procuraEmpresa() const;
	/*!
	 * \brief Classe que representa Erro no Ficheiro
	 */
	class ErroFicheiro {
	public:
		ErroFicheiro() {
		}
	};
	/*!
	 * \brief Classe que representa uma obra inexistente
	 */
	class ObraInexistente {
	public:
		int id;
		ObraInexistente(int id) :
				id(id) {
		}
	};
	/*!
	 * \brief Classe que representa uma empresa inexistente
	 */
	class EmpresaInexistente {
	public:
		string empresa;
		unsigned int num;
		EmpresaInexistente(string empresa,unsigned int num): empresa(empresa), num(num) {};
	};
	/*!
	 * \brief Classe que representa um id inexistente
	 */
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

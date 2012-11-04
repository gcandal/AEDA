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
	/*
	 * @return Devolve o número de trabalhos na obra
	 */
	int getTamanho() const;
	/*
	 * @return Devolve o ultimo número de identificação atribuído a uma obra
	 */
	static unsigned int getUltimoNr();
	/*
	 * @brief Adiciona um trabalho à obra
	 * @param Apontador para o trabalho a ser adicionado
	 */
	void adicionaTrabalho(Trabalho *t1);
	/*
	 * @brief Elimina um trabalho
	 * @param Número do trabalho a ser eliminado
	 */
	bool eliminaTrab(unsigned int n);
	/*
	 * @return Devolve o numero da obra
	 */
	unsigned int getNr() const;
	/*
	 * @return Devolve o custo total da obra
	 */
	int getCustoTotal() const;
	/*
	 * @brief Calcula o custo total de todos os trabalhos de um determinado tipo
	 * @param Tipo de trabalho
	 * @return Custo total dos trabalhos
	 */
	int getCustoTrab(tipoTrabalho t) const;
	/*
	 * @brief Calcula a duração total de todos os trabalhos de um determinado tipo
	 * @param Tipo de trabalho
	 * @return Duração total dos trabalhos
	 */
	int getDuracaoTrab(tipoTrabalho t) const;
	/*
	 * @return Devolve a duração total da obra
	 */
	int getDuracaoTotal() const;
	/*
	 * @return Devolve o asfalto total na obra
	 */
	int getAsfaltoTotal() const;
	/*
	 * @return Devolve o betão total na obra
	 */
	int getBetaoTotal() const;
	/*
	 * @return Devolve o cabo total na obra
	 */
	int getCaboTotal() const;
	/*
	 * @return Devolve a madeira total na obra
	 */
	int getMadeiraTotal() const;
	/*
	 * @return Devolve o trabalho mais barato
	 */
	Trabalho &trabalhoMaisBarato();
	/*
	 * @return Devolve o trabalho mais caro
	 */
	Trabalho &trabalhoMaisCaro();
	/*
	 * @return Devolve o trabalho com menor duração
	 */
	Trabalho &trabalhoMenorDuracao();
	/*
	 * @return Devolve o trabalho com maior duração
	 */
	Trabalho &trabalhoMaiorDuracao();
	/*
	 * @brief Procura um trabalho pelo seu número
	 * @param Número do trabalho
	 * @return Devolve o trabalho com o número correspondente
	 */
	string searchNum(int search);
	/*
	 * @param Valor do custo pretendido
	 * @result Devolve os trabalhos com custo inferior ao introduzido
	 */
	vector<Trabalho *> trabalhosCustoMenor(int c) const;
	/*
	 * @param Valor da duração pretendida
	 * @result Devolve os trabalhos com duração inferior à introduzida
	 */
	vector<Trabalho *> trabalhosDuracaoMenor(int d) const;
	/*
	 * @param Quandtidade de asfalto pretendida
	 * @result Devolve os trabalhos com quantidade de asfalto inferior à introduzida
	 */
	vector<Trabalho *> trabalhosAsfaltoMenor(int a) const;
	/*
	 * @param Quandtidade de betão pretendida
	 * @result Devolve os trabalhos com quantidade de betão inferior à introduzida
	 */
	vector<Trabalho *> trabalhosBetaoMenor(int b) const;
	/*
	 * @param Comprimento de cabo pretendido
	 * @result Devolve os trabalhos com comprimento de cabo inferior ao introduzido
	 */
	vector<Trabalho *> trabalhosCaboMenor(int c) const;
	/*
	 * @param Área de madeira pretendida
	 * @result Devolve os trabalhos com área de madeira inferior à introduzida
	 */
	vector<Trabalho *> trabalhosMadeiraMenor(int m) const;
	/*
	 * @param Valor do custo pretendido
	 * @result Devolve os trabalhos com custo superior ao introduzido
	 */
	vector<Trabalho *> trabalhosCustoMaior(int c) const;
	/*
	 * @param Duração pretendida
	 * @result Devolve os trabalhos com duração superior à introduzida
	 */
	vector<Trabalho *> trabalhosDuracaoMaior(int d) const;
	/*
	 * @param Quandtidade de asfalto pretendida
	 * @result Devolve os trabalhos com quantidade de asfalto superior à introduzida
	 */
	vector<Trabalho *> trabalhosAsfaltoMaior(int a) const;
	/*
	 * @param Quandtidade de asfalto pretendida
	 * @result Devolve os trabalhos com quantidade de betão superior à introduzida
	 */
	vector<Trabalho *> trabalhosBetaoMaior(int b) const;
	/*
	 * @param Comprimento de cabo pretendido
	 * @result Devolve os trabalhos com comprimento de cabo superior ao introduzido
	 */
	vector<Trabalho *> trabalhosCaboMaior(int c) const;
	/*
	 * @param Área de madeira pretendida
	 * @result Devolve os trabalhos com área de madeira superior à introduzida
	 */
	vector<Trabalho *> trabalhosMadeiraMaior(int m) const;
	/*
	 * @param Nome da empresa
	 * @return Devolve os trabalhos que pertencem a uma empresa
	 */
	vector<Trabalho *> trabalhosEmpresa(string emp) const;
	/*
	 * @param ID da rua
	 * @return Devolve todos os trabalhos a serem feitos numa determinada rua
	 */
	vector<Trabalho *> trabalhosRua(int id) const;
	/*
	 * @param ID da habitação
	 * @return Devolve todos os trabalhos a serem feitos numa determinada habitação
	 */
	vector<Trabalho *> trabalhosHabitacao(int id) const;
	/*
	 * @param Tipo de trabalho
	 * @return Devolve todos os trabalhos de um tipo
	 */
	vector<Trabalho *> trabalhosTipo(tipoTrabalho tp);
	/*
	 * @param Número do trabalho pretendido
	 * @return Devolve o trabalho com um determinado número
	 */
	Trabalho* getTrabalho(unsigned int n);
	/*
	 *  @brief Imprime na consola informações sobre a obra
	 */
	void imprime() const;
	/*
	 *  @brief Guarda no ficheiro de escrita informações sobre a obra
	 *  @param Ficheiro onde se pretende guardar as informações
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
	void lerFicheiroTrabalho(Obra& o1, ifstream& ficheiro_leitura);
public:
	Construtora(string nome);
	Construtora();
	string getNome() const;
	int getTamanho() const;
	void adicionaObra(Obra o1);
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
	Obra* getObra(unsigned int nr);

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

};

#endif /*OBRA_H_*/

/*
 * SubContratada.h
 *
 *  Created on: 16 de Dez de 2012
 *      Author: Jonz
 */

#ifndef SUBCONTRATADA_H_
#define SUBCONTRATADA_H_

#include <string>
#include "BST.h"

using namespace std;

enum tipo
{
	domestico, infraEstrutura, null
};
class SubContratada
{
	string nome;
	tipo tipoTrabalhos;
	int numEmpregados;
	double volumeMedio;
public:
	/*!
	 * /brief Construtor da classe SubContratada
	 * /param Nome, tipo de trabalhos que realiza, número de empregados e volume médio anual de negócios
	 */
	SubContratada(string n, tipo t, int nE, double vM) :
			nome(n), tipoTrabalhos(t), numEmpregados(nE), volumeMedio(vM)
	{

	}
	/*!
	 * /brief Devolve o nome da Sub-contratada
	 */
	string getNome()
	{
		return nome;
	}
	/*!
	 * /brief Devolve o tipo de trabalhos realizados pela empresa
	 */
	tipo getTipo()
	{
		return tipoTrabalhos;
	}
	/*!
	 * /brief Devolve o número de trabalhos da empresa
	 */
	int getNumEmpregados()
	{
		return numEmpregados;
	}
	/*!
	 * /brief Devolve o volume médio anual de negócios da empresa
	 */
	double getVolumeMedio()
	{
		return volumeMedio;
	}
	/*!
	 * /brief Altera o nome da Sub-contratada
	 */
	void setNome(string n)
	{
		nome = n;
	}
	/*!
	 * /brief Altera o tipo de trabalhos realizados pela empresa
	 */
	void setTipo(tipo t)
	{
		tipoTrabalhos = t;
	}
	/*!
	 * /brief Altera o número de trabalhos da empresa
	 */
	void setNumEmpregados(int n)
	{
		numEmpregados = n;
	}
	/*!
	 * /brief Altera o volume médio anual de negócios da empresa
	 */
	void setVolumeMedio(double v)
	{
		volumeMedio = v;
	}
	/*
	 *  /brief Operador '<' da classe SubContratada
	 *
	 */
	bool operator<(const SubContratada &sc) const;
	/*
	 *  /brief Operador '==' da classe SubContratada
	 *  /return Devolve True se o nome das sub-contratadas for igual
	 */
	bool operator==(SubContratada &sc) const;

	/*!
	 *  /Imprime na consola informações sobre a empresa
	 */
	friend ostream & operator<<(ostream & o, const SubContratada &sc)
	{
		o << "Nome: " << sc.nome << endl;
		o << "Tipo de trabalhos:";
		if (sc.tipoTrabalhos == domestico)
			o << "Domestico\n";
		else if (sc.tipoTrabalhos == infraEstrutura)
			o << "Infra-estrutura\n";
		else
			o << "Invalido \n";
		o << "Numero de empregados: " << sc.numEmpregados << endl;
		o << "Volume medio anual de negocios: " << sc.volumeMedio << endl;
		return o;
	}
};

class Empresas
{
	BST<SubContratada> arvoreEmpresas;
public:
	Empresas() :
			arvoreEmpresas(SubContratada("", null, 0, 0))
	{
	}
	;

	/*!
	 * /brief Devolve a árvore com as empresas passíveis de serem sub-contratadas
	 */
	BST<SubContratada> getEmpresas()
	{
		return arvoreEmpresas;
	}
	/*!
	 *  /brief Adiciona uma nova empresa passível de ser sub-contratada
	 */
	void adicionaEmpresa(const SubContratada &sc);
	/*!
	 *  /brief Remove uma nova empresa passível de ser sub-contratada
	 */
	void removeEmpresa(SubContratada sc);
	/*!
	 *  /brief Imprime, por ordem alfabética, as empresas contidas na árvore
	 */
	void imprime();

	/*!
	 *  /brief Altera o tipo de trabalhos realizados por uma empresa
	 *  /param Nome da empresa, novo tipo de trabalhos
	 *  /return True se a operação tiver sido realizada com sucesso
	 */
	bool alteraTipoTrabalho(string n, tipo t);

	/*!
	 *  /brief Altera o número de empregados numa empresa
	 *  /param Nome da empresa, novo número de trabalhadores
	 *  /return True se a operação tiver sido realizada com sucesso
	 */
	bool alteraNumEmpregados(string n, int x);

	/*!
	 *  /brief Altera o volume médio anual de negócios numa empresa
	 *  /param Nome da empresa, novo volume médio anual de negócios
	 *  /return True se a operação tiver sido realizada com sucesso
	 */
	bool alteraVolumeMedio(string n, double v);

	//LISTAGENS

	/*!
	 * /brief Imprime todos as emprsas que realizam trabalhos de um dado tipo
	 * /param Tipo de trabalho desejado
	 */
	void imprimeTipoTrabalho(tipo t);
	/*
	 *  /brief Imprime todos as empresas com um número de empregados superior ao introduzido
	 *  /param Número de trabalhadores pretendido
	 */
	void imprimeEmpregadosSup(int n);
	/*
	 *  /brief Imprime todos as empresas com um número de empregados inferior ao introduzido
	 *  /param Número de trabalhadores pretendido
	 */
	void imprimeEmpregadosInf(int n);
	/*
	 *  /brief Imprime todos as empresas com um volume médio anual de negócios superior ao introduzido
	 *  /param Volume médio anual de negócios pretendido
	 */
	void imprimeVolumeSup(double n);
	/*
	 *  /brief Imprime todos as empresas com um volume médio anual de negócios inferior ao introduzido
	 *  /param Volume médio anual de negócios pretendido
	 */
	void imprimeVolumeInf(double n);
};
#endif /* SUBCONTRATADA_H_ */

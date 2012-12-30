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

/*!
 * \brief Classe que representa uma empresa sub contratada
 */
class SubContratada
{
	string nome;
	tipo tipoTrabalhos;
	int numEmpregados;
	double volumeMedio;
public:
	/*!
	 * \brief Construtor da classe SubContratada
	 * \param Nome, tipo de trabalhos que realiza, numero de empregados e volume medio anual de negocios
	 */
	SubContratada(string n, tipo t, int nE, double vM) :
			nome(n), tipoTrabalhos(t), numEmpregados(nE), volumeMedio(vM)
	{

	}
	/*!
	 * \brief Devolve o nome da Sub-contratada
	 */
	string getNome()
	{
		return nome;
	}
	/*!
	 * \brief Devolve o tipo de trabalhos realizados pela empresa
	 */
	tipo getTipo()
	{
		return tipoTrabalhos;
	}
	/*!
	 * \brief Devolve o numero de trabalhos da empresa
	 */
	int getNumEmpregados()
	{
		return numEmpregados;
	}
	/*!
	 * \brief Devolve o volume medio anual de negocios da empresa
	 */
	double getVolumeMedio()
	{
		return volumeMedio;
	}
	/*!
	 * \brief Altera o nome da Sub-contratada
	 */
	void setNome(string n)
	{
		nome = n;
	}
	/*!
	 * \brief Altera o tipo de trabalhos realizados pela empresa
	 */
	void setTipo(tipo t)
	{
		tipoTrabalhos = t;
	}
	/*!
	 * \brief Altera o numero de trabalhos da empresa
	 */
	void setNumEmpregados(int n)
	{
		numEmpregados = n;
	}
	/*!
	 * \brief Altera o volume medio anual de negocios da empresa
	 */
	void setVolumeMedio(double v)
	{
		volumeMedio = v;
	}
	/*
	 *  \brief Operador '<' da classe SubContratada
	 *
	 */
	bool operator<(const SubContratada &sc) const;
	/*
	 *  \brief Operador '==' da classe SubContratada
	 *  \result Devolve True se o nome das sub-contratadas for igual
	 */
	bool operator==(SubContratada &sc) const;

	/*!
	 *  /Imprime na consola informacoes sobre a empresa
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

/*!
 * \brief Classe que representa as Empresas subcontratadas
 */
class Empresas
{
	BST<SubContratada> arvoreEmpresas;
public:
	/*!
	 * \brief Construtor classe empresas
	 */
	Empresas() :
			arvoreEmpresas(SubContratada("", null, 0, 0))
	{
	}
	;

	/*!
	 * \brief Devolve a arvore com as empresas passiveis de serem sub-contratadas
	 */
	BST<SubContratada> getEmpresas()
	{
		return arvoreEmpresas;
	}
	/*!
	 *  \brief Adiciona uma nova empresa passivel de ser sub-contratada
	 */
	void adicionaEmpresa(const SubContratada &sc);
	/*!
	 *  \brief Remove uma nova empresa passivel de ser sub-contratada
	 */
	void removeEmpresa(SubContratada sc);
	/*!
	 *  \brief Imprime, por ordem alfabetica, as empresas contidas na arvore
	 */
	void imprime();

	/*!
	 *  \brief Altera o tipo de trabalhos realizados por uma empresa
	 *  \param Nome da empresa, novo tipo de trabalhos
	 *  \result True se a operaçao tiver sido realizada com sucesso
	 */
	bool alteraTipoTrabalho(string n, tipo t);

	/*!
	 *  \brief Altera o numero de empregados numa empresa
	 *  \param Nome da empresa, novo numero de trabalhadores
	 *  \result True se a operaçao tiver sido realizada com sucesso
	 */
	bool alteraNumEmpregados(string n, int x);

	/*!
	 *  \brief Altera o volume medio anual de negocios numa empresa
	 *  \param Nome da empresa, novo volume medio anual de negocios
	 *  \result True se a operaçao tiver sido realizada com sucesso
	 */
	bool alteraVolumeMedio(string n, double v);

	//LISTAGENS

	/*!
	 * \brief Imprime todos as emprsas que realizam trabalhos de um dado tipo
	 * \param Tipo de trabalho desejado
	 */
	void imprimeTipoTrabalho(tipo t);
	/*
	 *  \brief Imprime todos as empresas com um numero de empregados superior ao introduzido
	 *  \param Numero de trabalhadores pretendido
	 */
	void imprimeEmpregadosSup(int n);
	/*
	 *  \brief Imprime todos as empresas com um numero de empregados inferior ao introduzido
	 *  \param Numero de trabalhadores pretendido
	 */
	void imprimeEmpregadosInf(int n);
	/*
	 *  \brief Imprime todos as empresas com um volume medio anual de negocios superior ao introduzido
	 *  \param Volume medio anual de negocios pretendido
	 */
	void imprimeVolumeSup(double n);
	/*
	 *  \brief Imprime todos as empresas com um volume medio anual de negocios inferior ao introduzido
	 *  \param Volume medio anual de negocios pretendido
	 */
	void imprimeVolumeInf(double n);
};
#endif /* SUBCONTRATADA_H_ */

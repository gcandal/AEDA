#ifndef Empresa_H_
#define Empresa_H_

#include <tr1/unordered_set>
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <cstdlib>

using namespace std;

class Empresa {
	string nome;
	int ultimoAnoContratacao;
	int contacto;
public:
	/*!
	 * /brief Construtor da classe Empresa
	 * /param nome, ultimo ano de contratacao e contacto da empresa
	 */
	Empresa(string nome="", int ano=2012, int contacto=-1);
	/*!
	 * /result Devolve o nome da empresa
	 */
	string getNome() const;
	/*!
	 * /result Devolve o ultimo ano de contratacao da empresa
	 */
	int getAno() const;
	/*!
	 * /result Devolve o contacto da empresa
	 */
	int getContacto() const;
	/*!
	 * /brief Altera o nome da empresa
	 * /param Novo nome
	 */
	void setNome(string nome);
	/*!
	 * /brief Altera o ultimo ano de contratacao da empresa
	 * /param Novo ultimo ano de contratacao
	 */
	void setAno(int ano);
	/*!
	 * /brief Altera o contacto da empresa
	 * /param Novo contacto
	 */
	void setContacto(int contacto);
	/*!
	 * /brief Operador == da classe empresa
	 * /param Empresa a comparar
	 * /result true/false resultante da comparacao
	 */
	bool operator==(const Empresa &e2) const {return nome==e2.getNome();}
};

class EmpresaNaoExistente {
	string nome;
public:
	/*!
	 * /brief Construtor da classe EmpresaNaoExistente
	 * /param nome da empresa
	 */
	EmpresaNaoExistente(string nome): nome(nome) {}
};

struct hash_empresas {
	int operator() (const Empresa & e1) const {
		return e1.getNome().size(); }

	bool operator() (const Empresa & e1, const Empresa & e2) const {
		return e1.getNome()==e2.getNome(); }

};

typedef tr1::unordered_set<Empresa, hash_empresas, hash_empresas> Tabela;

class EmpresasGuardadas {
	Tabela empresas;
public:
	/*!
	 * /brief Insere uma empresa na tabela empresas
	 * /param Empresa a inserir
	 */
	void inserirEmpresa(Empresa &e1);
	/*!
	 * /brief Remove uma empresa na tabela empresas
	 * /param Empresa a remover
	 */
	void removerEmpresa(string nome);
	/*!
	 * /brief Remove as empresas da tabela empresas com ultimo ano de contratacao menor que o parametro
	 * /param Ano Minimo para cada empresa
	 * /result Numero de empresas removidas
	 */
	int removerEmpresas(int anoMinimo);
	/*!
	 * /brief Altera o contacto da empresa o nome especificado nos parametros
	 * /param Nome da empresa, novo contacto
	 */
	void alterarContacto(string nome, int contacto);
	/*!
	 * /brief Altera o ultimo ano de contratacao da empresa o nome especificado nos parametros
	 * /param Nome da empresa, novo ultimo ano
	 */
	void alterarAno(string nome, int ano);
	/*!
	 * /brief Mostra os detalhes de cada empresa da tabela empresas
	 */
	void consultaEmpresas();
	/*!
	 * /brief Verifica se a empresa com nome especificado no parametro existe
	 * /param Nome a procurar
	 * /result true/false
	 */
	bool existeEmpresa(string nome);
	/*!
	 * /brief Le os dados de um ficheiro
	 * /param Ficheiro de leitura
	 */
	void leFicheiro(ifstream& ficheiro_leitura);
	/*!
	 * /brief Escreve os dados num ficheiro
	 * /param Ficheiro de escrita
	 */
	void escreveFicheiro(ofstream& ficheiro_escrita);

	class ErroNoFicheiro {
	public:
		/*!
		 * /brief Construtor da classe ErroNoFicheiro
		 */
		ErroNoFicheiro() {}
	};

};


#endif

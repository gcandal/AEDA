#ifndef MAIN_H_
#define MAIN_H_

#include "Obra.h"
#include "Empresa.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

bool debug=false;
EmpresasGuardadas empGuard;

class ValorInvalido {
public:
	int valor;
	ValorInvalido(int valor): valor(valor) {}
};

bool isNumber(string str);
int pedirValor();

bool lerTrabalho(int& a);
void novoTrabalho(Obra& o1);
Trabalho* inserirTrabalho();
void alterarTrabalho(Construtora& c1, Obra* o1);
void removerTrabalho(Construtora& c1, Obra* o1);
void consultarTrabalho(Construtora& c1, Obra& o1);
void imprimeVectorTrabalhos(vector<Trabalho*> vctr);

void novaObra(Construtora& c1);
void consultarObra(Construtora& c1);
void alterarObra(Construtora& c1);
void calcObras(Construtora& c1, Obra* o1);
void removerObra(Construtora& c1);
void imprimeVectorObras(vector<Obra> vctr);

void calConstrutora(Construtora& c1);
void efetuarAlteracao(Construtora& c1, Obra* o1, Trabalho& t1);

void menuPrinc(Construtora& c1);
void menuS(Construtora& c1, Obra* o1);

void menuEmp();
void adicionaEmp();
void alteraEmp();
void alteraContEmp(string nome);
void alteraAnoEmp(string nome);
void eliminaEmp();
void eliminAnoEmp();

#endif

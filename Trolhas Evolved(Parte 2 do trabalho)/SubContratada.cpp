/*
 * SubContratada.cpp
 *
 *  Created on: 16 de Dez de 2012
 *      Author: Jonz
 */

#include "SubContratada.h"

bool SubContratada::operator<(const SubContratada &sc) const
{
	return nome < sc.nome;
}

bool SubContratada::operator==(SubContratada &sc) const
{
	return nome == sc.nome;
}

void Empresas::adicionaEmpresa(const SubContratada &sc)
{
	arvoreEmpresas.insert(sc);
}

void Empresas::removeEmpresa(SubContratada sc)
{
	arvoreEmpresas.remove(sc);
}

void Empresas::imprime()
{
	arvoreEmpresas.printTree();
}

bool Empresas::alteraTipoTrabalho(string n, tipo t)
{
	BSTItrIn<SubContratada> itr(arvoreEmpresas);
	while (!itr.isAtEnd())
	{
		if (itr.retrieve().getNome() == n)
		{
			itr.retrieve().setTipo(t);
			return true;
		}
		itr.advance();
	}
	return false;
}

bool Empresas::alteraNumEmpregados(string n, int x)
{
	BSTItrIn<SubContratada> itr(arvoreEmpresas);
	while (!itr.isAtEnd())
	{
		if (itr.retrieve().getNome() == n)
		{
			itr.retrieve().setNumEmpregados(x);
			return true;
		}
		itr.advance();
	}
	return false;
}

bool Empresas::alteraVolumeMedio(string n, double v)
{
	BSTItrIn<SubContratada> itr(arvoreEmpresas);
	while (!itr.isAtEnd())
	{
		if (itr.retrieve().getNome() == n)
		{
			itr.retrieve().setVolumeMedio(v);
			return true;
		}
		itr.advance();
	}
	return false;
}

void Empresas::imprimeTipoTrabalho(tipo t){
	BSTItrIn<SubContratada> itr(arvoreEmpresas);
		while (!itr.isAtEnd())
		{
			if (itr.retrieve().getTipo() == t)
			{
				cout << itr.retrieve();
			}
			itr.advance();
		}
}

void Empresas::imprimeEmpregadosSup(int n)
{
	BSTItrIn<SubContratada> itr(arvoreEmpresas);
			while (!itr.isAtEnd())
			{
				if (itr.retrieve().getNumEmpregados() > n)
				{
					cout << itr.retrieve();
				}
				itr.advance();
			}
}

void Empresas::imprimeEmpregadosInf(int n)
{
	BSTItrIn<SubContratada> itr(arvoreEmpresas);
			while (!itr.isAtEnd())
			{
				if (itr.retrieve().getNumEmpregados() < n)
				{
					cout << itr.retrieve();
				}
				itr.advance();
			}
}

void Empresas::imprimeVolumeSup(double n)
{
	BSTItrIn<SubContratada> itr(arvoreEmpresas);
			while (!itr.isAtEnd())
			{
				if (itr.retrieve().getVolumeMedio() > n)
				{
					cout << itr.retrieve();
				}
				itr.advance();
			}
}

void Empresas::imprimeVolumeInf(double n)
{
	BSTItrIn<SubContratada> itr(arvoreEmpresas);
			while (!itr.isAtEnd())
			{
				if (itr.retrieve().getVolumeMedio() < n)
				{
					cout << itr.retrieve();
				}
				itr.advance();
			}
}

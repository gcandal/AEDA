#include "Obra.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

const char NOME_FICHEIRO[] = "obras.txt", NOME_FICHEIRO_TMP[]="obras_tmp.txt";

int pedirValor() {

	stringstream ss;
	string str;
	int res;

	cout << "Insira um limite: ";
	cin >> str;
	ss << str;
	ss >> res;

	return res;
}

void infoConstrutora(const Construtora& c1) {

	stringstream ss;
	int op;
	string str;
	int valor;

	//Erro de quê? -> depois de corrigir adicionar .size() no fim
	//Não usa ainda funcoes que retornam obra

	do {
		cout << "1. Tempo total ate terminarem todas as obras" << endl;
		cout << "2x. Material total necessario para todas as obras" << endl;
		cout << "3x. Material necessario menor do que..." << endl;
		cout << "4x. Material necessario maior do que..." << endl;
		cout << "5. Numero de obras a serem realizadas" << endl;
		cout << "6. Obras que vao demorar mais do que..." << endl;
		cout << "7. Obras que vao demorar menos do que..." << endl;
		cout << "8. Obras que vao custar mais do que..." << endl;
		cout << "9. Obras que vao custar menos do que..." << endl;
		cout << "40. Sair" << endl << endl;

		cout << "Valores de x:" << endl;
		cout << "1: Asfalto" << endl;
		cout << "2: Betao" << endl;
		cout << "3: Cabo" << endl;
		cout << "4: Madeira" << endl;

		cout << "\nEscolha opcao: ";
		cin >> str;
		ss << str;
		ss >> op;
		cout << "\n";

		switch (op) {
		case 1:
			c1.getDuracaoTotal();
			break;
		case 21:
			c1.getAsfaltoTotal();
			break;
		case 22:
			c1.getBetaoTotal();
			break;
		case 23:
			c1.getCaboTotal();
			break;
		case 24:
			c1.getMadeiraTotal();
			break;
		case 31:
			valor = pedirValor();
			//c1.obrasAsfaltoMenor(200);
			break;
		default:
			cout << "Opcao invalida.\n";
			break;
		}
		/*
		 if (op == "1")
		 c1.getDuracaoTotal();
		 else if (op == "21")
		 c1.getAsfaltoTotal();
		 else if (op == "22")
		 c1.getBetaoTotal();
		 else if (op == "23")
		 c1.getCaboTotal();
		 else if (op == "24")
		 c1.getMadeiraTotal();
		 else if (op == "31") {
		 valor = pedirValor();
		 c1.obrasAsfaltoMenor(valor);
		 } else if (op == "32") {
		 valor = pedirValor();
		 c1.obrasBetaoMenor(valor);
		 } else if (op == "33") {
		 valor = pedirValor();
		 c1.obrasCaboMenor(valor);
		 } else if (op == "34") {
		 valor = pedirValor();
		 c1.obrasMadeiraMenor(valor);
		 } else if (op == "41") {
		 valor = pedirValor();
		 c1.obrasAsfaltoMaior(valor);
		 } else if (op == "42") {
		 valor = pedirValor();
		 c1.obrasBetaoMaior(valor);
		 } else if (op == "43") {
		 valor = pedirValor();
		 c1.obrasCaboMaior(valor);
		 } else if (op == "44") {
		 valor = pedirValor();
		 c1.obrasMadeiraMaior(valor);
		 } else if (op == "5")
		 c1.getTamanho();
		 else if (op == "6") {
		 valor = pedirValor();
		 c1.obrasDuracaoMaior(valor);
		 } else if (op == "7") {
		 valor = pedirValor();
		 c1.obrasDuracaoMenor(valor);
		 } else if (op == "8") {
		 valor = pedirValor();
		 c1.obrasCustoMaior(valor);
		 } else if (op == "9") {
		 valor = pedirValor();
		 int a = c1.obrasCustoMenor(valor);
		 } else if (op == "40")
		 cout << endl;
		 else
		 cout << "Opcao invalida.\n";*/

	} while (op != 40);

}

bool lerTrabalho(int& a) {

	string str;
	stringstream ss;

	cin >> str;
	ss << str;

	return !(ss >> a);
}

Trabalho* novoTrabalho() {

	string op;
	int tmpn[4];
	string str;
	Trabalho* res;

	do {
		cout << "Duracao: ";
	} while (lerTrabalho(tmpn[0]));

	cout << endl;

	do {
		cout << "Custo: ";
	} while (lerTrabalho(tmpn[1]));

	cout << endl;

	cout << "Empresa: ";
	cin >> str;
	cout << endl;

	do {
		cout << "ID da Rua/Habitacao: ";
	} while (lerTrabalho(tmpn[2]));

	cout << endl;

	do {
		cout << "Quantidade de material: ";
	} while (lerTrabalho(tmpn[3]));

	cout << endl;

	cout << "Tipo: " << endl;
	cout << "1. Arruamento\n";
	cout << "2. Saneamento\n";
	cout << "3. Trolha\n";
	cout << "4. Eletricista\n";
	cout << "5. Carpinteiro\n";

	cout << "Opcao: ";

	cin >> op;

	while (true) {
		cout << "Opcao: ";
		cin >> op;
		cout << endl;

		if (op == "1") {
			res = new Arruamento(tmpn[0], tmpn[1], str, tmpn[2], tmpn[3]);
			return res;
		} else if (op == "2") {
			res = new Saneamento(tmpn[0], tmpn[1], str, tmpn[2], tmpn[3]);
			return res;
		} else if (op == "3") {
			res = new Trolha(tmpn[0], tmpn[1], str, tmpn[2], tmpn[3]);
			return res;
		} else if (op == "4") {
			res = new Eletricista(tmpn[0], tmpn[1], str, tmpn[2], tmpn[3]);
			return res;
		} else if (op == "5") {
			res = new Carpinteiro(tmpn[0], tmpn[1], str, tmpn[2], tmpn[3]);
			return res;
		}

		cout << "Opcao invalida.\n";
	}

}

void novaObra(Construtora& c1) {

	Obra o1;
	cout << "A criar Obra nr " << o1.getNr() << ":\n";

	string op;

	do {
		cout << "Quer adicionar um novo trabalho a obra? (s/n)";
		cin >> op;

		if (op == "s" || op == "S")
			o1.adicionaTrabalho(novoTrabalho());
		else if (op == "n" || op == "N")
			cout << endl;
		else
			cout << "Opcao invalida.\n";

	} while (op != "n" && op != "N");

	c1.adicionaObra(o1);
}

int main() {

	ifstream ficheiro_leitura(NOME_FICHEIRO);
	ofstream ficheiro_escrita(NOME_FICHEIRO_TMP);
	Construtora c1;
	string construtora;
	stringstream ss;
	int op;
	string str;

	try {
		c1.lerFicheiro(ficheiro_leitura);
	} catch (Construtora::ErroFicheiro &e) {
		cout << "Tentativa de abrir o ficheiro falhou ha "
				<< time(NULL) - e.getTempo() << " segundos atras.\n";
		cout << "Por favor insira o nome da construtora: ";

		cin >> construtora;
		Construtora* c2 = new Construtora(construtora);
		c1 = *c2;
		delete c2;

		cout << endl;
	}

	do {
		cout << "Construtora " << c1.getNome() << endl;
		cout << "1. Informacao sobre Construtora" << endl;
		cout << "2. Adicionar uma Obra" << endl;
		cout << "3. (...)" << endl;
		cout << "40. Sair" << endl;

		cout << "\nEscolha opcao: ";
		cin >> str;
		ss << str;
		ss >> op;
		cout << "\n";

		/*if (op == "1")
		 infoConstrutora(c1);
		 if (op == "")
		 novaObra(c1);
		 else if (op == "40")
		 cout << endl;
		 else
		 cout << "Opcao invalida.\n";*/

		switch (op) {
		case 1:
			infoConstrutora(c1);
			break;
		case 2:
			novaObra(c1);
			break;
		case 40:
			cout << endl;
			break;
		default:
			cout << "Opcao invalida.\n";
			break;
		}

		ss.clear();
	} while (op != 40);



	c1.escreverFicheiro(ficheiro_escrita);
	ficheiro_leitura.close();
	ficheiro_escrita.close();
	remove(NOME_FICHEIRO);
	rename(NOME_FICHEIRO_TMP,NOME_FICHEIRO);

	return 1;
}


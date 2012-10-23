#include "Obra.h"
#include "InfraEstrutura.h"
#include "Domestico.h"

#include <iostream>
#include <fstream>

using namespace std;

const char NOME_FICHEIRO[] = "obras.txt";

int main() {

	ifstream ficheiro_leitura(NOME_FICHEIRO);
	Construtora c1;

	try {
		c1.lerFicheiro(ficheiro_leitura);
	}
	catch(Construtora::ErroFicheiro &e) {
		cout << "Tentativa de abrir o ficheiro falhou.\n";
	}


	ficheiro_leitura.close();

	return 1;
}




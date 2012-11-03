#include "main.h"

int pedirValor() {

	stringstream ss;
	string str;
	int res;

	cout << "Insira um limite: ";
	cin >> str;
	ss << str;
	ss >> res;

	if(res<0)
		throw ValorInvalido(res);

	return res;
}

void imprimeVectorTrabalhos(vector<Trabalho *> vctr) {
	if (vctr.size() > 0) {
		for (unsigned int i = 0; i < vctr.size(); i++) {
			cout << vctr[i]->info();
		}
	}
}

void imprimeVectorObras(vector<Obra> vctr) {
	for (unsigned int i = 0; i < vctr.size(); i++) {
		cout << vctr[i].getNr() << endl;
	}
}

void infoConstrutora(Construtora& c1) {

	stringstream ss;
	int op;
	string str;
	int valor;

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
		cout << "10. Trabalhos de um determinado tipo..." << endl;
		cout << "11. Voltar ao menu anterior" << endl << endl;

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
			cout << c1.getDuracaoTotal() << endl;
			break;
		case 21:
			cout << c1.getAsfaltoTotal() << endl;
			break;
		case 22:
			cout << c1.getBetaoTotal() << endl;
			break;
		case 23:
			cout << c1.getCaboTotal() << endl;
			break;
		case 24:
			cout << c1.getMadeiraTotal() << endl;
			break;
		case 31:
			valor = pedirValor();
			imprimeVectorObras(c1.obrasAsfaltoMenor(valor)); //VER SE FUNCIONA E ADICIONAR AOS OUTROS
			break;
		case 32:
			valor = pedirValor();
			imprimeVectorObras(c1.obrasBetaoMenor(valor));
			break;
		case 33:
			valor = pedirValor();
			imprimeVectorObras(c1.obrasCaboMenor(valor));
			break;
		case 34:
			valor = pedirValor();
			imprimeVectorObras(c1.obrasMadeiraMenor(valor));
			break;
		case 41:
			valor = pedirValor();
			imprimeVectorObras(c1.obrasAsfaltoMaior(valor));
			break;
		case 42:
			valor = pedirValor();
			imprimeVectorObras(c1.obrasBetaoMaior(valor));
			break;
		case 43:
			valor = pedirValor();
			imprimeVectorObras(c1.obrasCaboMaior(valor));
			break;
		case 44:
			valor = pedirValor();
			imprimeVectorObras(c1.obrasMadeiraMaior(valor));
			break;
		case 5:
			cout << c1.getTamanho();
			break;
		case 6:
			valor = pedirValor();
			imprimeVectorObras(c1.obrasDuracaoMaior(valor));
			break;
		case 7:
			valor = pedirValor();
			imprimeVectorObras(c1.obrasDuracaoMenor(valor));
			break;
			break;
		case 8:
			valor = pedirValor();
			imprimeVectorObras(c1.obrasCustoMaior(valor));
			break;
			break;
		case 9:
			valor = pedirValor();
			imprimeVectorObras(c1.obrasCustoMenor(valor));
			break;
			break;
		case 10:
			c1.procuraTipoTrabalho();
			break;
		case 11:
			cout << endl;
			break;
		default:
			cout << "Opcao invalida.\n";
			break;
		}
		ss.clear();
	} while (op != 10);

}

bool lerTrabalho(int& a) {

	string str;
	stringstream ss;

	cin >> str;
	ss << str;

	return !(ss >> a);
}

Trabalho* inserirTrabalho() {

	string op;
	int tmpn[4];
	string str;
	Trabalho* res;

	do {
		cout << "Duracao: ";
	} while (lerTrabalho(tmpn[0]) || tmpn[0]<0);

	cout << endl;

	do {
		cout << "Custo: ";
	} while (lerTrabalho(tmpn[1]) || tmpn[1]<0);

	cout << endl;

	cout << "Empresa: ";
	cin >> str;
	cout << endl;

	do {
		cout << "ID da Rua/Habitacao: ";
	} while (lerTrabalho(tmpn[2]) || tmpn[2]<0);

	cout << endl;

	do {
		cout << "Quantidade de material: ";
	} while (lerTrabalho(tmpn[3]) || tmpn[3]<0);

	cout << endl;

	cout << "Tipo: " << endl;
	cout << "1. Arruamento\n";
	cout << "2. Saneamento\n";
	cout << "3. Trolha\n";
	cout << "4. Eletricista\n";
	cout << "5. Carpinteiro\n";

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

void novoTrabalho(Obra& o1) {

	string op;

	do {
		cout << "Quer adicionar um novo trabalho a obra? (s/n)";
		cin >> op;

		if(o1.getTamanho()==0 && op=="n") {
			cout << "A Obra tem que ter pelo menos um trabalho!\n";
			o1.adicionaTrabalho(inserirTrabalho());
		}
		else {
			if (op == "s")
				o1.adicionaTrabalho(inserirTrabalho());
			else if (op == "n")
				cout << endl;
			else
				cout << "Opcao invalida.\n";
		}

	} while ((op != "n") || o1.getTamanho()==0);

}

void novaObra(Construtora& c1) {

	Obra o1;
	cout << "A criar Obra nr " << o1.getNr() << ":\n";

	novoTrabalho(o1);

	c1.adicionaObra(o1);
}

void efetuarAlteracao(Trabalho& t1) {

	string str;
	stringstream ss;
	int op;
	unsigned int nr;
	ifstream a;

	cout << t1.info();

	do {
			cout << "1. Alterar Empresa" << endl;
			cout << "2. Alterar Duracao" << endl;
			cout << "3. Alterar Custo" << endl;
			cout << "4. Alterar Material" << endl;
			if(t1.getTipoTrabalho()==arruamento || t1.getTipoTrabalho()==saneamento)
				cout << "5. Alterar ID da Rua" << endl;
			else cout << "5. Alterar ID da Habitacao" << endl;
			cout << "40. Sair" << endl;

			cout << "\nEscolha opcao: ";
			cin >> str;
			ss << str;
			ss >> op;
			cout << "\n";
			ss.clear();

			switch (op) {
			case 1:
				cout << "Qual o nome da nova empresa?";
				cin >> str;
				cout << endl;
				t1.setEmpresa(str);
				break;
			case 2:
				cout << "Qual a nova duracao do trabalho?";
				do{
					cin >> str;
					ss << str;
				} while(!ss>>nr);
				ss.clear();
				t1.setDuracao(nr);
				break;
			case 3:
				cout << "Qual o novo custo do trabalho?";
				do{
					cin >> str;
					ss << str;
				} while(!ss>>nr);
				ss.clear();
				t1.setCusto(nr);
				break;
			case 4:
				cout << "Qual a nova quantidade de material que ira ser usada?";
				do{
					cin >> str;
					ss << str;
				} while(!ss>>nr);
				ss.clear();
				t1.setMaterial(nr);
				break;
			case 5:
				cout << "Qual o novo ID?";
				do{
					cin >> str;
					ss << str;
				} while(!ss>>nr);
				ss.clear();
				t1.setID(nr);
				break;
			case 40:
				cout << endl;
				break;
			default:
				cout << "Opcao invalida.\n";
				break;
			}

		} while (op != 40);

}

void alterarTrabalho(Obra& o1) {

	string str;
	stringstream ss;
	unsigned int nr;
	Trabalho* t1;
	bool valid=true;

	cout << "Insira o numero do trabalho que quer alterar: " << endl;

	do{
		cin >> str;
		ss << str;
	} while(!(ss>>nr));


	try {
		t1=&o1.getTrabalho(nr);
	} catch (Obra::TrabalhoInexistente& e) {
		valid=false;
		cout << "Nao existe nenhum trabalho com o ID " << e.id << endl;
	}

	if(valid)
		efetuarAlteracao(*t1);

}

void alterarObra(Construtora& c1) {

	string str;
	stringstream ss;
	unsigned int nr;
	Obra o1;
	bool valid=true;

	cout << "Insira o numero da obra que quer alterar: " << endl;

	do{
		cin >> str;
		ss << str;
	} while(!(ss>>nr));

	try {
		o1=c1.getObra(nr);
	} catch (Construtora::ObraInexistente& e) {
		valid=false;
		cout << "Nao existe nenhuma obra com o ID " << e.id << endl;
	}

	if(valid)
		alterarTrabalho(o1);

}

int main() {

	string NOME_FICHEIRO = "obras.txt", NOME_FICHEIRO_TMP = "obras_tmp.txt";
	Construtora c1;
	string construtora;
	stringstream ss;
	int op;
	string str;

/*
	cout << "Insira o numero da construtora sobre a qual quer trabalhar: ";
	cin >> str;
	cout << endl;
	NOME_FICHEIRO += (str + ".txt");
	NOME_FICHEIRO_TMP += (str + ".txt");*/

	ifstream ficheiro_leitura(NOME_FICHEIRO.c_str());
	ofstream ficheiro_escrita(NOME_FICHEIRO_TMP.c_str());

	try {
		c1.lerFicheiro(ficheiro_leitura);
	} catch (Construtora::ErroFicheiro &e) {
		cout << "Tentativa de abrir o ficheiro falhou.\n" << endl;
		cout
				<< "Por favor insira o nome para a construtora a ser criada no ficheiro "
				<< NOME_FICHEIRO << ":\n";

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
		cout << "3. Alterar uma Obra" << endl;
		cout << "40. Sair" << endl;

		cout << "\nEscolha opcao: ";
		cin >> str;
		ss << str;
		ss >> op;
		cout << "\n";

		switch (op) {
		case 1:
			infoConstrutora(c1);
			break;
		case 2:
			novaObra(c1);
			break;
		case 3:
			alterarObra(c1);
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
	remove(NOME_FICHEIRO.c_str());
	rename(NOME_FICHEIRO_TMP.c_str(), NOME_FICHEIRO.c_str());

	/*
	 * O info est� a imprimir as coisas duas vezes, j� procurei o motivo e n�o encontro -_-' - Est� aqui o test case
	 *
	Trabalho* t1=new Trolha(5, 3, "asd", 1, 4);
	cout<<t1->info();*/

	return 1;
}


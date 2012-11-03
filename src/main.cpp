#include "main.h"

void menuPrinc(Construtora& c1);

int pedirValor() {

	stringstream ss;
	string str;
	int res;

	try {
		cout << "Insira um limite: ";
		cin >> str;
		ss << str;
		ss >> res;

		if(res<0)
			throw ValorInvalido(res);
	} catch(ValorInvalido &v) {
		cout << "Valor invalido" << endl;
		pedirValor();
	}

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
		cout << "Obra numero " << vctr[i].getNr() << endl;
	}
}

void calConstrutora(Construtora& c1) {

	stringstream ss;
	int op;
	string str;
	int valor;

	do {
		cout << "1. Numero de obras" << endl;
		cout << "2. Duracao total das obras" << endl;
		cout << "3. Custo total das obras" << endl;
		cout << "4x. Material total das obras (escolha um valor para x, referente ao tipo de material)" << endl;
		cout << "5x. Obras com quantidade de material menor do que... (escolha um valor para x, referente ao tipo de material)" << endl;
		cout << "6x. Obras com quantidade de material maior do que... (escolha um valor para x, referente ao tipo de material)" << endl;
		cout << "7. Obras com duracao maior que..." << endl;
		cout << "8. Obras com duracao menor que..." << endl;
		cout << "9. Obras com custo maior que..." << endl;
		cout << "10. Obras com custo menor que..." << endl;
		cout << "11. Trabalhos de um determinado tipo" << endl;
		cout << "12. Voltar ao menu anterior" << endl << endl;

		cout << "Valores de x:" << endl;
		cout << "1 - Asfalto" << endl;
		cout << "2 - Betao" << endl;
		cout << "3 - Cabo" << endl;
		cout << "4 - Madeira" << endl;

		cout << "\nEscolha opcao: ";
		cin >> str;
		ss << str;
		ss >> op;
		cout << "\n";

		switch (op) {
		case 1:
			cout << "Numero de obras: " << c1.getTamanho() << endl << endl;
			break;
		case 2:
			cout << "Duracao total: " << c1.getDuracaoTotal() << " dias" << endl << endl;
			break;
		case 3:
			cout << "Custo total: " << c1.getCustoTotal() << " euros" << endl << endl;
			break;
		case 41:
			cout << "Asfalto total: " << c1.getAsfaltoTotal() << endl << endl;
			break;
		case 42:
			cout << "Betao total: " << c1.getBetaoTotal() << endl << endl;
			break;
		case 43:
			cout << "Cabo total: " << c1.getCaboTotal() << endl << endl;
			break;
		case 44:
			cout << "Madeira total: " << c1.getMadeiraTotal() << endl << endl;
			break;
		case 51:
			valor = pedirValor();
			imprimeVectorObras(c1.obrasAsfaltoMenor(valor)); //VER SE FUNCIONA E ADICIONAR AOS OUTROS
			break;
		case 52:
			valor = pedirValor();
			imprimeVectorObras(c1.obrasBetaoMenor(valor));
			break;
		case 53:
			valor = pedirValor();
			imprimeVectorObras(c1.obrasCaboMenor(valor));
			break;
		case 54:
			valor = pedirValor();
			imprimeVectorObras(c1.obrasMadeiraMenor(valor));
			break;
		case 61:
			valor = pedirValor();
			imprimeVectorObras(c1.obrasAsfaltoMaior(valor));
			break;
		case 62:
			valor = pedirValor();
			imprimeVectorObras(c1.obrasBetaoMaior(valor));
			break;
		case 63:
			valor = pedirValor();
			imprimeVectorObras(c1.obrasCaboMaior(valor));
			break;
		case 64:
			valor = pedirValor();
			imprimeVectorObras(c1.obrasMadeiraMaior(valor));
			break;
		case 7:
			valor = pedirValor();
			imprimeVectorObras(c1.obrasDuracaoMaior(valor));
			break;
		case 8:
			valor = pedirValor();
			imprimeVectorObras(c1.obrasDuracaoMenor(valor));
			break;
		case 9:
			valor = pedirValor();
			imprimeVectorObras(c1.obrasCustoMaior(valor));
			break;
		case 10:
			valor = pedirValor();
			imprimeVectorObras(c1.obrasCustoMenor(valor));
			break;
		case 11:
			c1.procuraTipoTrabalho();
			break;
		case 12:
			cout << endl;
			menuPrinc(c1);
			break;
		default:
			cout << "Opcao invalida.\n";
			break;
		}
		ss.clear();
	} while (op != 12);

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
		cout << "Duracao (em dias): ";
	} while (lerTrabalho(tmpn[0]) || tmpn[0]<0);

	cout << endl;

	do {
		cout << "Custo (em euros): ";
	} while (lerTrabalho(tmpn[1]) || tmpn[1]<0);

	cout << endl;

	cout << "Empresa associada: ";
	cin >> str;
	cout << endl;

	do {
		cout << "ID da Rua (p/infra-estruturas) ou Habitacao (para domesticos): ";
	} while (lerTrabalho(tmpn[2]) || tmpn[2]<0);

	cout << endl;

	do {
		cout << "Quantidade de material: ";
	} while (lerTrabalho(tmpn[3]) || tmpn[3]<0);

	cout << endl;

	cout << "Escolha um tipo de trabalho: " << endl;
	cout << "1. Infra-estruturas - Arruamento" << endl;
	cout << "2. Infra-estruturas - Saneamento" << endl;
	cout << "3. Domestico - Trolha" << endl;
	cout << "4. Domestico - Eletricista" << endl;
	cout << "5. Domestico - Carpinteiro" << endl;

	while (true) {
		//cout << "Opcao: ";
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
		cout << "Deseja adicionar um novo trabalho a obra? (s/n)";
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
	cout << "A criar Obra numero " << o1.getNr() << ":\n";

	novoTrabalho(o1);

	c1.adicionaObra(o1);
}

void efetuarAlteracao(Construtora& c1, Trabalho& t1) {

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
			cout << "6. Voltar ao menu anterior" << endl;

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
				try {
					t1.setDuracao(nr); }
				catch(Trabalho::ValorIncorrecto &val) {
					cout << "Valor invalido: " << val.v << endl;
				}
				break;
			case 3:
				cout << "Qual o novo custo do trabalho?";
				do{
					cin >> str;
					ss << str;
				} while(!ss>>nr);
				ss.clear();
				try {
					t1.setCusto(nr); }
				catch(Trabalho::ValorIncorrecto &val) {
					cout << "Valor invalido: " << val.v << endl;
				}
				break;
			case 4:
				cout << "Qual a nova quantidade de material que ira ser usada?";
				do{
					cin >> str;
					ss << str;
				} while(!ss>>nr);
				ss.clear();
				try {
					t1.setMaterial(nr); }
				catch(Trabalho::ValorIncorrecto &val) {
					cout << "Valor invalido: " << val.v << endl;
				}
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
			case 6:
				menuPrinc(c1);
				break;
			default:
				cout << "Opcao invalida.\n";
				break;
			}

		} while (op != 6);

}

void alterarTrabalho(Construtora& c1, Obra& o1) {

	string str;
	stringstream ss;
	unsigned int nr;
	Trabalho* t1;
	bool valid=true;

	cout << "Insira o numero do trabalho que pretende alterar: " << endl;

	do{
		cin >> str;
		ss << str;
	} while(!(ss>>nr));


	try {
		t1=&o1.getTrabalho(nr);
	} catch (Obra::TrabalhoInexistente& e) {
		valid=false;
		cout << "Nao existe nenhum trabalho com o numero: " << e.id << endl;
	}

	if(valid)
		efetuarAlteracao(c1, *t1);

}

void alterarObra(Construtora& c1) {

	string str;
	stringstream ss;
	unsigned int nr;
	Obra o1;
	bool valid=true;

	cout << "Insira o numero da obra que pretende alterar: " << endl;

	do{
		cin >> str;
		ss << str;
	} while(!(ss>>nr));

	try {
		o1=c1.getObra(nr);
	} catch (Construtora::ObraInexistente& e) {
		valid=false;
		cout << "Nao existe nenhuma obra com numero:  " << e.id << endl;
	}

	if(valid)
		alterarTrabalho(c1, o1);

}


void removerObra(Construtora& c1) {

}

void menuPrinc(Construtora& c1) {

	stringstream ss;
	int op;
	string str;

	do {

		cout << "1. Listagem das obras e trabalhos" << endl;
		cout << "2. Calculos sobre a construtora" << endl;
		cout << "3. Adicionar uma obra" << endl;
		cout << "4. Alterar uma Obra" << endl;
		cout << "5. Remover uma obra" << endl;
		cout << "6. Sair" << endl;

		cout << "\nEscolha uma opcao: ";
		cin >> str;
		ss << str;
		ss >> op;
		cout << "\n";


		switch (op) {
		case 1:
			c1.imprime();
			break;
		case 2:
			calConstrutora(c1);
			break;
		case 3:
			novaObra(c1);
			break;
		case 4:
			alterarObra(c1);
			break;
		case 5:
			removerObra(c1);
			break;
		case 6:
			cout << endl;
			break;
		default:
			cout << "Opcao invalida. Tente outra vez.\n";
			break;
		}

		ss.clear();
	} while (op != 6);
}

int main() {

	string NOME_FICHEIRO = "obras.txt", NOME_FICHEIRO_TMP = "obras_tmp.txt";
	Construtora c1;
	string construtora;
	//stringstream ss;
	//int op;
	//string str;

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
		cout << "Tentativa de abrir o ficheiro falhou.\n";
		cout << "Insira o nome para a construtora a ser criada: " << endl;
		cin >> construtora;
		Construtora* c2 = new Construtora(construtora);
		c1 = *c2;
		delete c2;

		cout << endl;
	}

	cout /*<< "Construtora "*/ << c1.getNome() << endl << endl;
	menuPrinc(c1);

	c1.escreverFicheiro(ficheiro_escrita);
	ficheiro_leitura.close();
	ficheiro_escrita.close();
	remove(NOME_FICHEIRO.c_str());
	rename(NOME_FICHEIRO_TMP.c_str(), NOME_FICHEIRO.c_str());

	/*
	 * O info está a imprimir as coisas duas vezes, já procurei o motivo e não encontro -_-' - Está aqui o test case
	 *
	Trabalho* t1=new Trolha(5, 3, "asd", 1, 4);
	cout<<t1->info();*/

	return 1;
}


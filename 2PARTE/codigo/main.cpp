#include "main.h"

using namespace std;

int main()
{

	string NOME_FICHEIRO = "obras.txt", NOME_FICHEIRO_TMP = "obras_tmp.txt";
	string NOME_F = "empresas.txt", NOME_F_TMP = "empresas_tmp.txt";
	Construtora c1;
	string construtora;

	ifstream ficheiro_leitura(NOME_FICHEIRO.c_str());
	ofstream ficheiro_escrita(NOME_FICHEIRO_TMP.c_str());
	ifstream f_leitura(NOME_F.c_str());
	ofstream f_escrita(NOME_F_TMP.c_str());

	try
	{
		c1.lerFicheiro(ficheiro_leitura);
	} catch (Construtora::ErroFicheiro &e)
	{
		cout << "Tentativa de abrir o ficheiro falhou.\n";
		cout << "Insira o nome para a construtora a ser criada: " << endl;
		cin >> construtora;
		Construtora* c2 = new Construtora(construtora);
		c1 = *c2;
		delete c2;

		cout << endl;
	}

	try
	{
		empGuard.leFicheiro(f_leitura);
	} catch (EmpresasGuardadas::ErroNoFicheiro &e1)
	{
		cout << endl;
	}

	cout << c1.getNome() << endl << endl;
	menuPrinc(c1);
	c1.escreverFicheiro(ficheiro_escrita);
	empGuard.escreveFicheiro(f_escrita);
	ficheiro_leitura.close();
	ficheiro_escrita.close();
	f_leitura.close();
	f_escrita.close();
	remove(NOME_FICHEIRO.c_str());
	rename(NOME_FICHEIRO_TMP.c_str(), NOME_FICHEIRO.c_str());
	remove(NOME_F.c_str());
	rename(NOME_F_TMP.c_str(), NOME_F.c_str());

	return 1;
}

bool isNumber(string str)
{
	bool ret = false;
	for (unsigned int i = 0; i < str.size(); i++)
	{
		if (isdigit(str[i]))
			ret = true;
		else
			return false;
	}
	return ret;
}

int pedirValor()
{

	stringstream ss;
	string str;
	int res;

	try
	{
		do
		{
			cout << "Insira um limite: ";
			cin >> str;
		} while (!isNumber(str));

		res = atoi(str.c_str());

		if (res < 0)
			throw ValorInvalido(res);
	} catch (ValorInvalido &v)
	{
		cout << "Valor invalido" << endl << endl;
		res = pedirValor();
	}
	return res;
}

void imprimeVectorTrabalhos(vector<Trabalho*> vctr)
{

	cout << endl;
	if (vctr.size() == 0)
		cout << "Nao ha nenhum trabalho com as condicoes pretendidas";
	else
	{
		for (unsigned int i = 0; i < vctr.size(); i++)
		{
			cout << "Trabalho numero: " << vctr[i]->getNum();
		}
		cout << endl;
	}
}

void imprimeVectorObras(vector<Obra> vctr)
{

	cout << endl;
	if (vctr.size() == 0)
		cout << "Nao ha nenhuma obra com as condicoes pretendidas." << endl;
	else
	{
		for (unsigned int i = 0; i < vctr.size(); i++)
		{
			cout << "Obra numero " << vctr[i].getNr() << endl;
		}
	}
	cout << endl;
}

void calConstrutora(Construtora& c1)
{

	bool menu = true;
	do
	{
		stringstream ss;
		int op;
		string str;
		int valor;

		cout << "1. Numero de obras" << endl;
		cout << "2. Duracao total das obras" << endl;
		cout << "3. Custo total das obras" << endl;
		cout
				<< "4x. Material total das obras (escolha um valor para x, referente ao tipo de material)"
				<< endl;
		cout
				<< "5x. Obras com quantidade de material menor do que... (escolha um valor para x, referente ao tipo de material)"
				<< endl;
		cout
				<< "6x. Obras com quantidade de material maior do que... (escolha um valor para x, referente ao tipo de material)"
				<< endl;
		cout << "7. Obras com duracao maior que..." << endl;
		cout << "8. Obras com duracao menor que..." << endl;
		cout << "9. Obras com custo maior que..." << endl;
		cout << "10. Obras com custo menor que..." << endl;
		cout << "11. Obra com maior duracao" << endl;
		cout << "12. Obra com menor duracao" << endl;
		cout << "13. Obra com maior custo" << endl;
		cout << "14. Obra com menor custo" << endl;
		cout << "15. Trabalhos de um determinado tipo" << endl;
		cout << "16. Trabalhos com um determinado ID" << endl;
		cout << "17. Trabalhos sub-contratados a uma determinada empresa"
				<< endl;
		cout << "18. Voltar ao menu anterior" << endl << endl;

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

		switch (op)
		{
		case 1:
			cout << "Numero de obras: " << c1.getTamanho() << endl << endl;
			break;
		case 2:
			cout << "Duracao total: " << c1.getDuracaoTotal() << " dias" << endl
					<< endl;
			break;
		case 3:
			cout << "Custo total: " << c1.getCustoTotal() << " euros" << endl
					<< endl;
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
			imprimeVectorObras(c1.obrasAsfaltoMenor(valor));
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
			cout << "Obra numero: " << (c1.obraMaiorDuracao()).getNr()
					<< ", duracao total: "
					<< (c1.obraMaiorDuracao()).getDuracaoTotal() << endl
					<< endl;
			break;
		case 12:
			cout << "Obra numero: " << (c1.obraMenorDuracao()).getNr()
					<< ", duracao total: "
					<< (c1.obraMenorDuracao()).getDuracaoTotal() << endl
					<< endl;
			break;
		case 13:
			cout << "Obra numero: " << (c1.obraMaisCaro()).getNr()
					<< ", custo total: "
					<< (c1.obraMaisCaro()).getDuracaoTotal() << endl << endl;
			break;
		case 14:
			cout << "Trabalho numero: " << (c1.obraMaisBarato()).getNr()
					<< ", custo total: "
					<< (c1.obraMaisBarato()).getDuracaoTotal() << endl << endl;
			break;
		case 15:
			c1.procuraTipoTrabalho();
			break;
		case 16:
			try
			{
				c1.procuraID();
			} catch (Construtora::idInexistente& e)
			{

				cout << "Nao ha nenhuma ";

				if (e.t == arruamento || e.t == saneamento)
					cout << "rua";
				else
					cout << "habitacao";

				cout << " com o ID: " << e.id << " na obra Nr" << e.num << ".\n"
						<< endl;

			}
			break;
		case 17:
			try
			{
				c1.procuraEmpresa();
			} catch (Construtora::EmpresaInexistente& e)
			{
				cout << "Nao existe nenhuma empresa " << e.empresa
						<< " na obra Nr" << e.num << ".\n" << endl;
			}
			break;
		case 18:
			cout << endl;
			menu = false;
			menuPrinc(c1);
			break;
		default:
			cout << "Opcao invalida.\n" << endl;
			break;
		}
	} while (menu);
}

bool lerTrabalho(int& a)
{

	string str;
	cin >> str;
	if (isNumber(str))
	{
		//cout << "<" << endl;
		a = atoi(str.c_str());
		return false;
	}
	else
		return true;
}

Trabalho* inserirTrabalho()
{

	string op;
	int tmpn[4];
	string str;
	Trabalho* res;

	do
	{
		cout << "Duracao (em dias): ";
	} while (lerTrabalho(tmpn[0]) || tmpn[0] < 0);
	cin.clear();
	cout << endl;

	do
	{
		cout << "Custo (em euros): ";
	} while (lerTrabalho(tmpn[1]) || tmpn[1] < 0);
	cin.clear();

	cout << endl;
	cout << "Empresa associada: ";
	cin >> str;
	cout << endl;
	cin.clear();

	do
	{
		cout
				<< "ID da Rua (p/infra-estruturas) ou Habitacao (para domesticos): ";
	} while (lerTrabalho(tmpn[2]) || tmpn[2] < 0);
	cin.clear();
	cout << endl;

	do
	{
		cout << "Quantidade de material: ";
	} while (lerTrabalho(tmpn[3]) || tmpn[3] < 0);
	cout << endl;

	cout << "Escolha um tipo de trabalho: " << endl;
	cout << "1. Infra-estruturas - Arruamento" << endl;
	cout << "2. Infra-estruturas - Saneamento" << endl;
	cout << "3. Domestico - Trolha" << endl;
	cout << "4. Domestico - Eletricista" << endl;
	cout << "5. Domestico - Carpinteiro" << endl;

	while (true)
	{
		string op1;
		cout << "Opcao: ";
		cin >> op1;
		cout << endl;

		if (op1 == "1")
		{
			res = new Arruamento(tmpn[0], tmpn[1], str, tmpn[2], tmpn[3]);
			return res;
		}
		else if (op1 == "2")
		{
			res = new Saneamento(tmpn[0], tmpn[1], str, tmpn[2], tmpn[3]);
			return res;
		}
		else if (op1 == "3")
		{
			res = new Trolha(tmpn[0], tmpn[1], str, tmpn[2], tmpn[3]);
			return res;
		}
		else if (op1 == "4")
		{
			res = new Eletricista(tmpn[0], tmpn[1], str, tmpn[2], tmpn[3]);
			return res;
		}
		else if (op1 == "5")
		{
			res = new Carpinteiro(tmpn[0], tmpn[1], str, tmpn[2], tmpn[3]);
			return res;
		}
		else
			cout << "Opcao invalida.\n" << endl;
	}
}

void novoTrabalho(Obra& o1)
{

	string op;

	do
	{
		cout << "Deseja adicionar um novo trabalho a obra? (s/n)";
		cin >> op;

		if (o1.getTamanho() == 0 && op == "n")
		{
			cout << "A Obra tem que ter pelo menos um trabalho!\n";
			o1.adicionaTrabalho(inserirTrabalho());
		}
		else
		{
			if (op == "s")
				o1.adicionaTrabalho(inserirTrabalho());
			else if (op == "n")
				cout << endl;
			else
				cout << "Opcao invalida.\n" << endl;
		}

	} while ((op != "n") || o1.getTamanho() == 0);
}

void novaObra(Construtora& c1)
{

	Obra o1;
	cout << "A criar Obra numero " << o1.getNr() << ":\n";

	novoTrabalho(o1);
	c1.adicionaObra(o1);
}

void efetuarAlteracao(Construtora& c1, Obra* o1, Trabalho& t1)
{

	t1.imprime();

	bool menu = true;
	do
	{
		string str, str1;
		stringstream ss, ss1;
		int op;
		int nr;
		ifstream a;

		cout << endl << "1. Alterar Empresa" << endl;
		cout << "2. Alterar Duracao" << endl;
		cout << "3. Alterar Custo" << endl;
		cout << "4. Alterar Material" << endl;
		if (t1.getTipoTrabalho() == arruamento
				|| t1.getTipoTrabalho() == saneamento)
			cout << "5. Alterar ID da Rua" << endl;
		else
			cout << "5. Alterar ID da Habitacao" << endl;
		cout << "6. Voltar ao menu anterior" << endl;

		cout << "\nEscolha opcao: ";
		cin >> str;
		ss << str;
		ss >> op;
		cout << "\n";
		ss.clear();

		switch (op)
		{
		case 1:
			cout << "Qual o nome da nova empresa?";
			cin >> str;
			t1.setEmpresa(str);
			cout << endl;
			break;
		case 2:
			do
			{
				cout << "Qual a nova duracao do trabalho?";
				cin >> str1;
			} while (!isNumber(str1));
			nr = atoi(str1.c_str());
			try
			{
				t1.setDuracao(nr);
			} catch (Trabalho::ValorIncorrecto &val)
			{
				cout << "Valor invalido: " << val.v << endl;
			}
			break;
		case 3:
			do
			{
				cout << "Qual o novo custo do trabalho?";
				cin >> str1;
			} while (!isNumber(str1));
			nr = atoi(str1.c_str());
			try
			{
				t1.setCusto(nr);
				o1->fila_atualizaTrab(&t1);
			} catch (Trabalho::ValorIncorrecto &val)
			{
				cout << "Valor invalido: " << val.v << endl;
			}
			break;
		case 4:
			do
			{
				cout << "Qual a nova quantidade de material que ira ser usada?";
				cin >> str1;
			} while (!isNumber(str1));
			nr = atoi(str1.c_str());
			try
			{
				t1.setMaterial(nr);
			} catch (Trabalho::ValorIncorrecto &val)
			{
				cout << "Valor invalido: " << val.v << endl;
			}
			break;
		case 5:
			do
			{
				cout << "Qual o novo ID?";
				cin >> str1;
			} while (!isNumber(str1));
			nr = atoi(str1.c_str());
			t1.setID(nr);
			break;
		case 6:
			menuPrinc(c1);
			menu = false;
			break;
		default:
			cout << "Opcao invalida.\n" << endl;
			break;
		}
	} while (menu);
}

void alterarTrabalho(Construtora& c1, Obra* o1)
{

	string str;
	stringstream ss;
	unsigned int nr;
	Trabalho* t1;
	bool valid = true;

	do
	{
		cout << "Insira o numero do trabalho que pretende alterar: " << endl;
		cin >> str;
	} while (!isNumber(str));
	nr = atoi(str.c_str());

	try
	{
		if (debug)
			cout << "Consultar trabalho numero " << nr << "!!!" << endl;
		t1 = o1->getTrabalho(nr);

		if (debug)
			t1->imprime();

	} catch (Obra::TrabalhoInexistente& e)
	{
		valid = false;
		cout << "Nao existe nenhum trabalho com o numero: " << e.id << endl;
	}

	if (valid)
		efetuarAlteracao(c1, o1, *t1);
}

void consultarObra(Construtora& c1)
{

	string str;
	stringstream ss;
	unsigned int nr;
	Obra* o1;
	bool valid = true;

	do
	{
		cout << "Insira o numero da obra que pretende consultar: " << endl;
		cin >> str;
	} while (!isNumber(str));

	nr = atoi(str.c_str());

	try
	{
		o1 = c1.getObra(nr);
	} catch (Construtora::ObraInexistente& e)
	{
		valid = false;
		cout << "Nao existe nenhuma obra com numero:  " << e.id << endl;
	}

	if (valid)
	{
		bool menu = true;

		do
		{
			stringstream ss;
			int op;
			string str;

			cout << "1. Imprimir trabalhos indiscriminadamente" << endl;
			cout << "2. Imprimir trabalhos por ordem de pagamento" << endl;
			cout << "3. Sair" << endl;

			cout << "\nEscolha opcao: ";
			cin >> str;
			ss << str;
			ss >> op;
			cout << "\n";

			switch (op)
			{
			case 1:
				o1->imprime();
				cout << endl << endl;
				break;
			case 2:
				o1->fila_imprime();
				cout << endl << endl;
				break;
			case 3:
				cout << endl;
				menu = false;
				menuPrinc(c1);
				break;
			default:
				cout << "Opcao invalida.\n" << endl;
				break;
			}
		} while (menu);
	}
}

void consultarTrabalho(Construtora& c1, Obra& o1)
{

	string str;
	stringstream ss;
	unsigned int nr;
	Trabalho *t1;
	bool valid = true;

	do
	{
		cout << "Insira o numero do trabalho que pretende consultar: " << endl;
		cin >> str;
	} while (!isNumber(str));

	nr = atoi(str.c_str());

	try
	{
		t1 = o1.getTrabalho(nr);

	} catch (Obra::TrabalhoInexistente& e)
	{
		valid = false;
		cout << "Nao existe nenhum trabalho  com numero:  " << e.id << endl;
	}
	if (valid)
		t1->imprime();
}

void removerTrabalho(Construtora& c1, Obra* o1)
{

	string str;
	stringstream ss;
	unsigned int nr;
	bool valid = true;

	do
	{
		cout << "Insira o numero do trabalho que pretende eliminar: " << endl;
		cin >> str;
	} while (!isNumber(str));

	nr = atoi(str.c_str());

	/*try {
	 if(debug)
	 cout << "Eliminando trabalho" << nr << " !!" <<endl;*/

	Trabalho *tb1;

	try
	{
		tb1 = o1->getTrabalho(nr);

	} catch (Obra::TrabalhoInexistente& e)
	{
		valid = false;
		cout << "Nao existe nenhum trabalho com o numero:  " << e.id
				<< " na Obra nr " << o1->getNr() << endl;
		return;
	}

	o1->eliminaTrab(nr);

	/*if(debug)
	 o1->imprime();

	 } catch (Obra::TrabalhoInexistente& e) {
	 valid=false;
	 cout << "Nao existe nenhum trabalho com o numero:  " << e.id << " na Obra nr " << o1->getNr() << endl;
	 return;
	 }*/

	//Trabalho * tb1 = o1->getTrabalho(nr);
	string empresa = tb1->getEmpresa();
	Empresa e1(empresa);
	empGuard.inserirEmpresa(e1);

	if (valid)
		o1->imprime();
}

void removerObra(Construtora& c1)
{

	string str;
	stringstream ss;
	unsigned int nr;
	Obra* o1;
	bool valid = true;

	do
	{
		cout << "Insira o numero da obra que pretende eliminar: " << endl;
		cin >> str;
	} while (!isNumber(str));

	nr = atoi(str.c_str());

	try
	{

		o1 = c1.getObra(nr);

		if (debug)
			o1->imprime();
	} catch (Construtora::ObraInexistente& e)
	{
		valid = false;
		cout << "Nao existe nenhuma obra com numero:  " << e.id << endl;
		return;
	}

	if (valid)
	{
		vector<Trabalho *> temp = o1->getTrabalhos();
		string nome;
		for (unsigned int i = 0; i < temp.size(); i++)
		{
			nome = temp[i]->getEmpresa();
			Empresa e1(nome);
			empGuard.inserirEmpresa(e1);
		}
		if (c1.eliminaObra(nr))
			cout << "Obra eliminada com sucesso";
	}
	return;
}

void calcObras(Construtora& c1, Obra* o1)
{

	bool menu = true;
	do
	{
		stringstream ss;
		int op;
		string str;
		int valor;

		cout << "1. Numero de trabalhos" << endl;
		cout << "2. Duracao total da obra" << endl;
		cout << "3. Custo total da obra" << endl;
		cout
				<< "4x. Material total da obra (escolha um valor para x, referente ao tipo de material)"
				<< endl;
		cout
				<< "5x. Trabalhos com quantidade de material menor do que... (escolha um valor para x, referente ao tipo de material)"
				<< endl;
		cout
				<< "6x. Trabalhos com quantidade de material maior do que... (escolha um valor para x, referente ao tipo de material)"
				<< endl;
		cout << "7. Trabalhos com duracao maior que..." << endl;
		cout << "8. Trabalhos com duracao menor que..." << endl;
		cout << "9. Trabalhos com custo maior que..." << endl;
		cout << "10. Trabalhos com custo menor que..." << endl;
		cout << "11. Trabalho com maior duracao" << endl;
		cout << "12. Trabalho com menor duracao" << endl;
		cout << "13. Trabalho mais barato" << endl;
		cout << "14. Trabalho mais caro" << endl;
		cout << "15. Voltar ao menu anterior" << endl << endl;

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

		switch (op)
		{
		case 1:
			cout << "Numero de trabalhos: " << o1->getTamanho() << endl << endl;
			break;
		case 2:
			cout << "Duracao total: " << o1->getDuracaoTotal() << " dias"
					<< endl << endl;
			break;
		case 3:
			cout << "Custo total: " << o1->getCustoTotal() << " euros" << endl
					<< endl;
			break;
		case 41:
			cout << "Asfalto total: " << o1->getAsfaltoTotal() << endl << endl;
			break;
		case 42:
			cout << "Betao total: " << o1->getBetaoTotal() << endl << endl;
			break;
		case 43:
			cout << "Cabo total: " << o1->getCaboTotal() << endl << endl;
			break;
		case 44:
			cout << "Madeira total: " << o1->getMadeiraTotal() << endl << endl;
			break;
		case 51:
			valor = pedirValor();
			imprimeVectorTrabalhos(o1->trabalhosAsfaltoMenor(valor));
			break;
		case 52:
			valor = pedirValor();
			imprimeVectorTrabalhos(o1->trabalhosBetaoMenor(valor));
			break;
		case 53:
			valor = pedirValor();
			imprimeVectorTrabalhos(o1->trabalhosCaboMenor(valor));
			break;
		case 54:
			valor = pedirValor();
			imprimeVectorTrabalhos(o1->trabalhosMadeiraMenor(valor));
			break;
		case 61:
			valor = pedirValor();
			imprimeVectorTrabalhos(o1->trabalhosAsfaltoMaior(valor));
			break;
		case 62:
			valor = pedirValor();
			imprimeVectorTrabalhos(o1->trabalhosBetaoMaior(valor));
			break;
		case 63:
			valor = pedirValor();
			imprimeVectorTrabalhos(o1->trabalhosCaboMaior(valor));
			break;
		case 64:
			valor = pedirValor();
			imprimeVectorTrabalhos(o1->trabalhosMadeiraMaior(valor));
			break;
		case 7:
			valor = pedirValor();
			imprimeVectorTrabalhos(o1->trabalhosDuracaoMaior(valor));
			break;
		case 8:
			valor = pedirValor();
			imprimeVectorTrabalhos(o1->trabalhosDuracaoMenor(valor));
			break;
		case 9:
			valor = pedirValor();
			imprimeVectorTrabalhos(o1->trabalhosCustoMaior(valor));
			break;
		case 10:
			valor = pedirValor();
			imprimeVectorTrabalhos(o1->trabalhosCustoMenor(valor));
			break;
		case 11:
			cout << "Trabalho numero: " << (o1->trabalhoMaiorDuracao()).getNum()
					<< ", duracao total: "
					<< (o1->trabalhoMaiorDuracao()).getDuracao() << endl
					<< endl;
			break;
		case 12:
			cout << "Trabalho numero: " << (o1->trabalhoMenorDuracao()).getNum()
					<< ", duracao total: "
					<< (o1->trabalhoMenorDuracao()).getDuracao() << endl
					<< endl;
			break;
		case 13:
			cout << "Trabalho numero: " << (o1->trabalhoMaisCaro()).getNum()
					<< ", custo total: "
					<< (o1->trabalhoMaisCaro()).getDuracao() << endl << endl;
			break;
		case 14:
			cout << "Trabalho numero: " << (o1->trabalhoMaisBarato()).getNum()
					<< ", custo total: "
					<< (o1->trabalhoMaisBarato()).getDuracao() << endl << endl;
			break;
		case 15:
			cout << endl;
			menu = false;
			menuS(c1, o1);
			break;
		default:
			cout << "Opcao invalida.\n" << endl;
			break;
		}
	} while (menu);
}

void menuS(Construtora& c1, Obra* o1)
{

	bool menu = true;
	do
	{
		stringstream ss;
		int op;
		string str;

		cout << endl << "1. Calculos sobre a obra" << endl;
		cout << "2. Adicionar um trabalho" << endl;
		cout << "3. Alterar um trabalho" << endl;
		cout << "4. Remover um trabalho" << endl;
		cout << "5. Voltar ao menu anterior" << endl;

		cout << "\nEscolha uma opcao: ";
		cin >> str;
		ss << str;
		ss >> op;
		cout << "\n";

		switch (op)
		{
		case 1:
			calcObras(c1, o1);
			break;
		case 2:
			o1->adicionaTrabalho(inserirTrabalho());
			break;
		case 3:
			alterarTrabalho(c1, o1);
			break;
		case 4:
			if (o1->getTamanho() < 2)
				cout
						<< "A obra apenas possui um trabalho, e no minimo tem que ter um. Remocao impossivel.\n";
			else
				removerTrabalho(c1, o1);
			break;
		case 5:
			menuPrinc(c1);
			menu = false;
			cout << endl;
			break;
		default:
			cout << "Opcao invalida. Tente outra vez.\n" << endl;
			break;
		}
	} while (menu);
}

void alterarObra(Construtora& c1)
{

	unsigned int nr;
	Obra* o1;
	bool valid = true;
	string str;
	stringstream ss;

	do
	{
		cout << "Insira o numero da obra que pretende alterar: " << endl;
		cin >> str;
	} while (!isNumber(str));

	nr = atoi(str.c_str());

	try
	{
		o1 = c1.getObra(nr);

		if (debug)
			o1->imprime();
	} catch (Construtora::ObraInexistente& e)
	{
		valid = false;
		cout << "Nao existe nenhuma obra com numero:  " << e.id << endl;
	}

	if (valid)
		menuS(c1, o1);
}

void adicionaEmp()
{

	string nome, tempc, tempa;
	int contacto, ano;

	cout << "Insira o nome da empresa: ";
	cin >> nome;

	do
	{
		cout << endl << "Insira o contacto da empresa: ";
		cin >> tempc;
	} while (!isNumber(tempc));

	contacto = atoi(tempc.c_str());

	do
	{
		cout << endl << "Insira o ultimo ano de contratacao da empresa: ";
		cin >> tempa;
	} while (!isNumber(tempa));

	ano = atoi(tempa.c_str());

	Empresa e1(nome, ano, contacto);
	empGuard.inserirEmpresa(e1);
}

void adicionaSub()
{

	string nome, nE, vM;
	tipo t;
	int numEmpregados;
	double volumeMedio;
	bool valid = false;
	string str;
	stringstream ss;
	int op;

	cout << "Insira o nome da empresa: ";
	cin >> nome;

	do
	{
		cout << "Insira o tipo de trabalhos realizados\n";
		cout << "1.Domestico\n";
		cout << "2.Infra-estruturas\n";
		cin >> str;
		ss << str;
		ss >> op;

		switch (op)
		{
		case 1:
			t = domestico;
			valid = true;
			break;
		case 2:
			t = infraEstrutura;
			valid = true;
			break;
		default:
			cout << "Opcao invalida\n";
			valid = false;
			break;
		}

	} while (!valid);

	do
	{
		cout << endl << "Insira o numero de empregados da empresa: ";
		cin >> nE;
	} while (!isNumber(nE));
	numEmpregados = atoi(nE.c_str());

	do
	{
		cout << endl << "Insira o volume medio anual de negocios da empresa: ";
		cin >> vM;
	} while (!isNumber(vM));
	volumeMedio = atoi(vM.c_str());

	SubContratada s1(nome, t, numEmpregados, volumeMedio);
	e1.adicionaEmpresa(s1);

}

void alteraContEmp(string nome)
{

	string temp;
	int cont;

	do
	{
		cout << endl << "Insira o novo contacto: ";
		cin >> temp;
		if (!isNumber(temp))
			cout << endl << "Valor invalido. Tente outra vez.";
	} while (!isNumber(temp));

	cont = atoi(temp.c_str());
	empGuard.alterarContacto(nome, cont);
}

void alteraAnoEmp(string nome)
{

	string temp;
	int ano;

	do
	{
		cout << endl << "Insira o novo contacto: ";
		cin >> temp;
		if (!isNumber(temp))
			cout << endl << "Valor invalido. Tente outra vez.";
	} while (!isNumber(temp));

	ano = atoi(temp.c_str());
	empGuard.alterarAno(nome, ano);
}

void alteraEmp()
{

	string nome, str;
	int op;
	stringstream ss;

	do
	{
		cout << "Insira o nome da empresa a alterar: ";
		cin >> nome;
		if (!empGuard.existeEmpresa(nome))
			cout << endl << "Nome invalido. Tente outra vez" << endl;
	} while (!empGuard.existeEmpresa(nome));

	cout << endl << "Pretende alterar" << endl;
	cout << "1. O contacto da empresa" << endl;
	cout << "2. O ultimo ano de contratacao da empresa" << endl;

	cout << "\nEscolha uma opcao: ";
	cin >> str;
	ss << str;
	ss >> op;
	cout << "\n";

	switch (op)
	{
	case 1: //alterar contacto
		alteraContEmp(nome);
		cout << endl;
		break;
	case 2: //alterar ano
		alteraAnoEmp(nome);
		cout << endl;
		break;
	default:
		cout << "Opcao invalida. Tente outra vez.\n" << endl;
		ss.clear();
		str.clear();
		alteraEmp();
	}
}

void alteraSub()
{

	string nome, str;
	int op;
	stringstream ss;

	cout << "Insira o nome da empresa a alterar: ";
	cin >> nome;

	cout << endl << "Pretende alterar" << endl;
	cout << "1. O tipo de trabalhos efectuados pela empresa" << endl;
	cout << "2. O numero de empregados da empresa" << endl;
	cout << "3. O volume medio anual de negocios da empresa" << endl;

	cout << "\nEscolha uma opcao: ";
	cin >> str;
	ss << str;
	ss >> op;
	cout << "\n";

	switch (op)
	{
	case 1:
		alteraTipoSub(nome);
		break;
	case 2:
		alteraNumSub(nome);
		cout << endl;
		break;
	case 3:
		alteraVolSub(nome);
		cout << endl;
		break;
	default:
		cout << "Opcao invalida. Tente outra vez.\n" << endl;
		ss.clear();
		str.clear();
		alteraSub();
		break;
	}
}

void alteraTipoSub(string nome)
{
	string str;
	int op;
	stringstream ss;
	bool valid = true;
	do
	{
		cout
				<< "A empresa passa a efectuar trabalhos domesticos (1) ou infra-estruturas(2)?";
		cout << "\nEscolha uma opcao: ";
		cin >> str;
		ss << str;
		ss >> op;
		cout << "\n";

		switch (op)
		{
		case 1:
			if (e1.alteraTipoTrabalho(nome, domestico))
			{
				cout << "Alteracao realizada com sucesso\n";
			}
			else
				cout << "Erro, alteracao nao realizada\n";
			break;
		case 2:
			if (e1.alteraTipoTrabalho(nome, infraEstrutura))
			{
				cout << "Alteracao realizada com sucesso\n";
			}
			else
			{
				cout << "Erro, alteracao nao realizada\n";
			}
			break;
		default:
			cout << "Opcao invalida\n";
			valid = false;
			break;
		}
	} while (!valid);
	cout << endl;
}

void alteraNumSub(string nome)
{
	string temp;
	int n;

	do
	{
		cout << endl << "Insira o novo numero de empregados: ";
		cin >> temp;
		if (!isNumber(temp))
			cout << endl << "Valor invalido. Tente outra vez.";
	} while (!isNumber(temp));

	n = atoi(temp.c_str());
	e1.alteraNumEmpregados(nome, n);
}

void alteraVolSub(string nome)
{
	string temp;
	double n;

	do
	{
		cout << endl << "Insira o novo volume medio anual de negocios: ";
		cin >> temp;
		if (!isNumber(temp))
			cout << endl << "Valor invalido. Tente outra vez.";
	} while (!isNumber(temp));

	n = atoi(temp.c_str());
	e1.alteraVolumeMedio(nome, n);
}

void listSub()
{
	stringstream ss, ss2;
	int op, op2, x;
	string str, str2;

	cout << "1.Imprimir empresas que realizam trabalhos de um determinado tipo"
			<< endl;
	cout
			<< "2.Imprimir empresas com numero de trabalhadores inferior a um valor"
			<< endl;
	cout
			<< "3.Imprimir empresas com numero de trabalhadores superior a um valor"
			<< endl;
	cout
			<< "4.Imprimir empresas com volume medio anual de negocios inferior a um valor"
			<< endl;
	cout
			<< "5.Imprimir empresas com volume medio anual de negocios superior a um valor"
			<< endl;
	cout << "6.Sair" << endl;

	cout << "\nEscolha uma opcao: ";
	cin >> str;
	ss << str;
	ss >> op;
	cout << "\n";

	switch (op)
	{
	case 1:
		cout << "Domesticos(1) ou Infra-estruturas(2)?";
		cin >> str2;
		ss2 << str2;
		ss2 >> op2;
		cout << endl;
		switch (op2)
		{
		case 1:
			e1.imprimeTipoTrabalho(domestico);
			break;
		case 2:
			e1.imprimeTipoTrabalho(infraEstrutura);
			break;
		default:
			cout << "Opcao invalida\n";
			break;
		}
		break;
	case 2:
		x = pedirValor();
		e1.imprimeEmpregadosInf(x);
		break;
	case 3:
		x = pedirValor();
		e1.imprimeEmpregadosSup(x);
		break;
	case 4:
		x = pedirValor();
		e1.imprimeVolumeInf(x);
		break;
	case 5:
		x = pedirValor();
		e1.imprimeVolumeSup(x);
		break;
	case 6:
		return;
	default:
		cout << "Opcao Invalida\n";
		break;

	}
	listSub();

}

void eliminaSub()
{
	string nome;
	cout << "Insira o nome da empresa a eliminar: ";
	cin >> nome;
	cout << endl;
	SubContratada s(nome, null, 0, 0);

	e1.removeEmpresa(s);

}
void eliminaEmp()
{

	string nome;

	do
	{
		cout << "Insira o nome da empresa a eliminar: ";
		cin >> nome;
		if (!empGuard.existeEmpresa(nome))
			cout << endl << "Nome invalido. Tente outra vez" << endl;
	} while (!empGuard.existeEmpresa(nome));

	empGuard.removerEmpresa(nome);
}

void eliminAnoEmp()
{

	string temp;
	int num, ano;

	do
	{
		cout << "Insira o ano minimo: ";
		cin >> temp;
		if (!isNumber(temp))
			cout << endl << "Valor invalido. Tente outra vez" << endl;
	} while (!isNumber(temp));

	ano = atoi(temp.c_str());
	num = empGuard.removerEmpresas(ano);

	cout << "Foram removidas " << num << " empresas." << endl;
}

void menuEmp()
{

	bool menu = true;
	do
	{
		stringstream ss;
		int op;
		string str;

		cout << endl << "1. Consultar empresas guardadas" << endl;
		cout << "2. Adicionar uma empresa" << endl;
		cout << "3. Alterar uma empresa" << endl;
		cout << "4. Eliminar uma empresa por nome" << endl;
		cout << "5. Eliminar empresas com ano menor que.." << endl;
		cout << "6. Sair" << endl;

		cout << "\nEscolha uma opcao: ";
		cin >> str;
		ss << str;
		ss >> op;
		cout << "\n";

		switch (op)
		{
		case 1:
			empGuard.consultaEmpresas();
			cout << endl << endl;
			break;
		case 2:
			adicionaEmp();
			cout << endl;
			break;
		case 3:
			alteraEmp();
			cout << endl;
			break;
		case 4:
			eliminaEmp();
			break;
		case 5:
			eliminAnoEmp();
			break;
		case 6:
			menu = false;
			cout << endl;
			return;
			break;
		default:
			cout << "Opcao invalida. Tente outra vez.\n" << endl;
			ss.clear();
			str.clear();
			break;
		}
		ss.clear();
	} while (menu);
}

void menuSub()
{

	bool menu = true;
	do
	{
		stringstream ss;
		int op;
		string str;

		cout << endl << "1. Consultar empresas" << endl; //DONE
		cout << "2. Adicionar uma empresa" << endl; //DONE
		cout << "3. Alterar uma empresa" << endl; //DONE
		cout << "4. Eliminar uma empresa por nome" << endl; //DONE
		cout << "5. Listagens" << endl;
		cout << "6. Sair" << endl;

		cout << "\nEscolha uma opcao: ";
		cin >> str;
		ss << str;
		ss >> op;
		cout << "\n";

		switch (op)
		{
		case 1:
			e1.imprime();
			cout << endl << endl;
			break;
		case 2:
			adicionaSub();
			cout << endl;
			break;
		case 3:
			alteraSub();
			cout << endl;
			break;
		case 4:
			eliminaSub();
			break;
		case 5:
			listSub();
			break;
		case 6:
			menu = false;
			cout << endl;
			return;
			break;
		default:
			cout << "Opcao invalida. Tente outra vez.\n" << endl;
			ss.clear();
			str.clear();
			break;
		}
		ss.clear();
	} while (menu);
}

void menuPrinc(Construtora& c1)
{

	bool menu = true;
	do
	{
		stringstream ss;
		int op;
		string str;

		cout << endl << "1. Listagem das obras e trabalhos" << endl;
		cout << "2. Calculos sobre a construtora" << endl;
		cout << "3. Adicionar uma obra" << endl;
		cout << "4. Alterar uma obra" << endl;
		cout << "5. Consultar uma obra" << endl;
		cout << "6. Remover uma obra" << endl;
		cout << "7. Listagem da ordem de pagamento de todas as obras" << endl;
		cout << "8. Empresas guardadas" << endl;
		cout << "9. Empresas passiveis de serem sub-contratadas" << endl;
		cout << "10. Sair" << endl;

		cout << "\nEscolha uma opcao: ";
		cin >> str;
		ss << str;
		ss >> op;
		cout << "\n";

		switch (op)
		{
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
			consultarObra(c1);
			break;
		case 6:
			removerObra(c1);
			break;
		case 7:
			c1.fila_imprime();
			break;
		case 8:
			menuEmp();
			break;
		case 9:
			menuSub();
			break;
		case 10:
			menu = false;
			cout << endl;
			return;
			break;
		default:
			cout << "Opcao invalida. Tente outra vez.\n" << endl;
			ss.clear();
			str.clear();
			break;
		}
		ss.clear();
	} while (menu);
}


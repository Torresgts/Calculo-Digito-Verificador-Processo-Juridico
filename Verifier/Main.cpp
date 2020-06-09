#include <iostream>
#include <sstream>
#include <string>

#include "Main.h"

void Verify()
{
	std::string userInput;
	long long int codigo = 0;
	std::cout << "Digite o codigo: ";
	std::cin >> userInput;

	if (userInput.length() < 18)
	{
		while (userInput.length() < 18)
		{
			userInput = "0" + userInput;
		}
		std::cout << "Zero(s) adicionado(s) no inicio do codigo." << std::endl;
	}
	else if (userInput.length() > 18)
	{
		std::cout << "TAMANHO DO CODIGO MAIOR QUE O REQUERIDO!" << std::endl;
		return;
	}

	std::stringstream num(userInput);

	num >> codigo;

	long long int DD; // Digito Verificador
	codigo = codigo * 100;
	codigo = codigo % 97;
	DD =  98 - codigo;
	std::cout << "Digito verificador: "<< DD << std::endl;
	

	const std::string Number = userInput;
	std::string NNNNNNN = Number.substr(0, 7); // Número sequencial do Processo
	std::string AAAA = Number.substr(7, 4); // Ano do ajuizamento do Processo
	std::string J = Number.substr(11, 1); // Órgão ou Segmento do Poder Judiciário
	std::string TR = Number.substr(12, 2); // Tribunal do respectivo Segmento do Poder Judiciário
	std::string OOOO = Number.substr(14, 4); // Unidade de origem do Processo (Varas)


	std::cout << "Formatado : " << NNNNNNN << "-" << DD << "." << AAAA <<"."<< J << "." << TR << "." << OOOO <<std::endl;
	std::cout << "Corrido : " << NNNNNNN << DD << AAAA << J << TR << OOOO << std::endl;
	std::cout << "" << std::endl;

	AskForNewVerification();
}

void AskForNewVerification()
{
	std::cout << "Deseja realizar novo processo? : 1-SIM 2-NAO" << std::endl;
	int answer;
	std::cin >> answer;
	if (answer == 1)
	{
		system("CLS");
		Verify();
	}
}

int main()
{
	Verify();

	system("PAUSE");
}
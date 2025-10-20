#pragma once

# include <iostream>  //| cout, cerr
# include <fstream>   //| ifstream
# include <cstdlib>   //| atof, atoi
# include <string>    //| string
# include <map>       //| map
# include <exception> //| exception

class BitcoinExchange
{
	public:
		BitcoinExchange();
		BitcoinExchange(const std::string &databaseFile);
		BitcoinExchange(const BitcoinExchange &other);
		~BitcoinExchange();
		
		BitcoinExchange &operator=(const BitcoinExchange &other);
		
		void parseCSV();
		void readInputFile();
		float getTargetValue(const std::string &targetDate);

		class OpenFileErrorException : public std::exception
		{
			public:
				virtual const char *what() const throw() { return ("Error: could not open file."); };
		};

	private:
		std::map<std::string, float> _data;
		std::ifstream _csvFile;
		std::ifstream _inputFile;
};

/*

 Exercício 00: Bitcoin Exchange

 Esta classe implementa um programa que calcula o valor de uma quantidade de bitcoins em uma data específica,
 usando uma base de dados histórica de preços do Bitcoin armazenada em um arquivo CSV.

 Funcionalidades principais:
 - parseCSV(): lê o arquivo data.csv e armazena os dados em um std::map
 - readInputFile(): lê o arquivo de entrada com as datas e quantidades a serem convertidas
 - getTargetValue(date): busca o valor do Bitcoin na data especificada, ou na data anterior mais próxima
 - Validação de datas (formato YYYY-MM-DD, anos bissextos, dias válidos por mês)
 - Validação de valores (entre 0 e 1000)
 - Tratamento de exceções para arquivos inválidos

 Características:
 - Usa std::map<std::string, float> para armazenar pares data-valor ordenados
 - Map permite busca eficiente e ordenação automática das datas
 - lower_bound() para encontrar a data mais próxima quando a data exata não existe
 - Suporte a arquivos CSV com formato: date,exchange_rate
 - Entrada no formato: date | value

 IMPORTANTE - Lista CPP09:
 Nesta lista (CPP09), cada exercício deve usar um tipo diferente de container STL.
 E, nesse exercício, foi usado o std::map para armazenar os dados do Bitcoin.

*/

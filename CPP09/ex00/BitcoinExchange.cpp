#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const std::string &filename)
{
	this->_csvFile.open("data.csv", std::ifstream::in);         //| Arquivo de dados do Bitcoin (CSV)
	this->_inputFile.open(filename.c_str(), std::ifstream::in); //| Arquivo de entrada (txt)
	if (!this->_csvFile.is_open() || !this->_inputFile.is_open())
		throw (BitcoinExchange::OpenFileErrorException());
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other) { *this = other; }

BitcoinExchange::~BitcoinExchange()
{
	this->_csvFile.close();   //| Fechando o arquivo de dados do Bitcoin
	this->_inputFile.close(); //| Fechando o arquivo de entrada
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other)
{
	if (this != &other)
		this->_data = other._data;
	return (*this);
}

void BitcoinExchange::parseCSV()
{
	std::string date, value, line;

	while (std::getline(this->_csvFile, line))
	{
		date = line.substr(0, 10);                    //| Data (YYYY-MM-DD)
		value = line.substr(11, -1);                  //| Valor (float)
		this->_data[date] = std::atof(value.c_str()); //| Adicionando a data e o valor ao map
	}
}

static bool isLeapYear(int year) { return (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0)); }

static bool isValidDate(const std::string &line)
{
	if (line.length() != 10) //| Se a data não estiver no formato YYYY-MM-DD, é inválida
		return (false);

	std::string date = line.substr(0, 10);
	if (date[4] != '-' || date[7] != '-') //| Se o separador não estiver no lugar correto, é inválida
		return (false);

	int year = std::atoi(date.substr(0, 4).c_str());
	int month = std::atoi(date.substr(5, 2).c_str());
	if (month < 1 || month > 12)
		return (false);
	int day = std::atoi(date.substr(8, 2).c_str());
	int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	if (isLeapYear(year)) //| Se o ano for bissexto, fevereiro tem 29 dias
		daysInMonth[1] = 29;
	if (day < 1 || day > daysInMonth[month - 1]) //| Se o dia não estiver no intervalo valido para o mes, é inválida
		return (false);
	return (true);
}

float BitcoinExchange::getTargetValue(const std::string &targetDate)
{
	std::map<std::string, float>::iterator it = this->_data.begin();
	for (; it != this->_data.end(); it++)
		if (it->first == targetDate)
			return (it->second);

	it = this->_data.lower_bound(targetDate); //| Encontrando a data mais proxima e maior que a data alvo
	if (it == this->_data.begin())            //| Se a data alvo for menor que a primeira data no map, retorna -1
		return (-1);
	it--;                                     //| Retornando a data mais proxima e menor que a data alvo
	return (it->second);
}

void BitcoinExchange::readInputFile()
{
	std::string line, date, str_value, delimiter;
	float value;
	char *s;

	getline(this->_inputFile, line);
	if (line != "date | value") //| Cabeçalho inválido
	{
		std::cerr << "Error: invalid input." << std::endl;
		return;
	}
	
	while (getline(this->_inputFile, line))
	{
		if (line.empty())
		{
			std::cerr << "Error: empty line." << std::endl;
			continue;
		}
		if (line.length() < 14) //| Linha inválida
		{
			std::cerr << "Error: bad input> " << line << std::endl;
			continue;
		}

		date = line.substr(0, 10);
		str_value = line.substr(13);
		value = std::strtof(str_value.c_str(), &s); //| Convertendo o valor para float
		delimiter = line.substr(10, 3);
		if (delimiter != " | " || !isValidDate(date) || *s != '\0')
			std::cerr << "Error: bad input> " << line << std::endl;
		else if (value < 0 || value > 1000)
			std::cerr << "Error: value out of range> " << line << ". The number must be between 0 and 1000" << std::endl;
		else
		{
			float targetValue = this->getTargetValue(date);
			if (targetValue == -1)
				std::cerr << "Error: date not found> " << date << std::endl;
			else
				std::cout << date << " => " << value << " = " << targetValue * value << std::endl;
		}
	}
}
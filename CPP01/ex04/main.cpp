#include "Replace.hpp" 

void err(const std::string error)
{
	//| 'cerr' é a saída de erro.
	std::cout << error << std::endl;
}

int main(int ac, char **av)
{
	if (ac != 4)
		return (err("Error! Usage: ./SedIsForLosers <filename> <string1> <string2>"), 1);
	if (!av[1][0] || !av[2][0] || !av[3][0])
		return (err("Error! Invalid Arguments."), 2);
	
	//| Abrindo o arquivo para leitura.
	std::ifstream ifs(av[1]);
	if (!ifs)
		return (err("Error! Invalid Input File."), 3);

	std::string input;
	std::string result;
	//| Lendo linha por linha do arquivo.
	while (std::getline(ifs, input))
	{
		//| Fazendo o replace de cada linha, se der.
		result += Replace::replace(input, av[2], av[3]);
		if (ifs.eof())
			result += "\n";
	}
	//| Fechando o arquivo lido.
	ifs.close()

	if (!result)
		return (err("<string1> does not have any match with <string2> in <filename>."), 3);

	//| Abrindo o arquivo para escrita.
	std::ofstream ofs(av[1] + ".replace");
	if (!ofs)
		return (err("Error! Invalid Output File."), 4);
	ofs << result;
	//| Fechando o arquivo escrito.
	ofs.close();

	return (0);
}

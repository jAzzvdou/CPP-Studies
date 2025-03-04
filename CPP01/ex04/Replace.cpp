#include "Replace.hpp"

std::string Replace::replace(const std::string &input, const std::string &s1, const std::string &s2)
{
	std::string result;

	//| Posição da primeira aparição de 's1' em 'input'.
	int foundPos = 0;
	//| Posição de onde começa a próxima parte de 'input'.
	int continuePos = 0;
	//| Tamanho de 's1' para atualizar a posição da procura.
	int addLen = s1.length();

	int len = input.length();
	for (int i = 0; i < len; i++)
	{
		//| Procurando 's1' em 'input'.
		foundPos = input.find(s1, foundPos);
		if (foundPos != -1)
		{
			//| Pega da posição inicial e copia até a parte que achou o match.
			result += input.substr(continuePos, foundPos - continuePos) + s2;
			//| Pula para a próxima parte a ser procurada.
			foundPos += addLen;
			continuePos = foundPos;
		}
		else
		{
			//| Caso não ache mais aparição mas ainda tenha conteúdo em 'input', copia o resto para o resultado.
			if (continuePos)
				result += input.substr(continuePos);
			break ;
		}
	}
	return (result);
}

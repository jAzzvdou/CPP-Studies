#include "Harl.hpp"

int	main(void)
{
	Harl harl;

	//| Testando cada reclamação.
	harl.complain("debug");
	harl.complain("info");
	harl.complain("warning");
	harl.complain("error");

	//| Testando uma reclamação inválida.
	harl.complain("invalid");

	return (0);
}

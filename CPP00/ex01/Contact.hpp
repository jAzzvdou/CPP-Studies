#ifndef CONTACT_HPP
# define CONTACT_HPP

#include <iomanip>
#include <string>

class Contact
{
	public:
		Contact(); //| Construtor

		Contact(std::string first_name,
			std::string last_name,
			std::string nickname,
			std::string phone_number,
			std::string darkest_secret);

		~Contact(); //| Destrutor

		//|----------| Métodos |----------|//
		display(void) const;

	private:
		std::string first_name;
		std::string last_name;
		std::string nickname;
		std::string phone_number;
		std::string darkest_secret;
};

#endif //| CONTACT_HPP

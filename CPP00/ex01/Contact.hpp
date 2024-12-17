#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <string>

class Contact
{
	public:
		Contact(); //| Construtor

		Contact(const std::string &first_name,
			const std::string &last_name,
			const std::string &nickname,
			const std::string &phone_number,
			const std::string &darkest_secret);

		//|----------| Método |----------|//
		void displayShort(void) const;
		void displayFull(void) const;

		~Contact(); //| Destrutor

	private:
		std::string _first_name;
		std::string _last_name;
		std::string _nickname;
		std::string _phone_number;
		std::string _darkest_secret;
};

#endif //| CONTACT_HPP

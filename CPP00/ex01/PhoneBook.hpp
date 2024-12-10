#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include <iostream>
#include <string>
#include "Contact.hpp"

class PhoneBook
{
        public:
                PhoneBook(); //| Construtor

                ~PhoneBook(); //| Destrutor

		//|----------| Métodos |----------|//
		void	addContact(void);
		void	searchContact(void); const;

        private:
		Contact	_contact[8];
		_contact[i].display();
};

#endif //| PHONEBOOK_HPP

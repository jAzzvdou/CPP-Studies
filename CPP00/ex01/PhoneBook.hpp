#pragma once

# include "Contact.hpp"

class PhoneBook
{
    public:
        PhoneBook(); //| Construtor
        ~PhoneBook(); //| Destrutor

		//|----------| Métodos |----------|//
		void addContact(void);
		void searchContact(void) const;
		void displayContacts(void) const;

    private:
		Contact _contacts[8];
};

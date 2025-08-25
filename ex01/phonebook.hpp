#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "contact.hpp"

class PhoneBook {
   private:
	Contact contacts[8];
	int contactIndex;

   public:
	PhoneBook();
	~PhoneBook();
	void addContact();
	void displayContacts() const;
	void searchContact() const;
};

#endif // PHONEBOOK_HPP

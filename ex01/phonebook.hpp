#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "contact.hpp"
#include <iomanip>
#include <cstdlib>

class PhoneBook {
   private:
	Contact contacts[8];
	int contactNumber;

   public:
	PhoneBook();
	~PhoneBook();

	bool addContact();

	void displayContacts() const;
	bool searchContact() const;
	void giveHelp() const;
};

#endif // PHONEBOOK_HPP

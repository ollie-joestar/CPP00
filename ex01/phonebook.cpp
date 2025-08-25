/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oohnivch <oohnivch@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 11:36:00 by oohnivch          #+#    #+#             */
/*   Updated: 2025/08/25 15:17:14 by oohnivch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"
#include <iomanip>

PhoneBook::PhoneBook() : contactIndex(0) {}

PhoneBook::~PhoneBook() {}

void	PhoneBook::giveHelp() const {
	std::cout << "ADD:\tAdd a new contact to the phone book." << std::endl;
	std::cout << "SEARCH:\tDisplay a list of contacts and view details of a specific contact." << std::endl;
	std::cout << "HELP:\tDisplay this help message." << std::endl;
	std::cout << "EXIT:\tExit the phone book application." << std::endl;
}

void	PhoneBook::addContact() {
	std::string fName, lName, nName, pNumber, dSecret;

	std::cout << "Enter First Name: ";
	// std::getline(std::cin, fName);
	std::cin >> fName;
	std::cout << "Enter Last Name: ";
	std::cin >> lName;
	std::cout << "Enter Nickname: ";
	std::cin >> nName;
	std::cout << "Enter Phone Number: ";
	std::cin >> pNumber;
	std::cout << "Enter Darkest Secret: ";
	std::cin >> dSecret;

	contacts[contactIndex].setContactInfo(fName, lName, nName, pNumber, dSecret);
	contactIndex++;
	if (contactIndex >= 8)
		contactIndex = 0;
}

void	PhoneBook::displayContacts() const {
	std::cout << "---------------------------------------------" << std::endl;
	std::cout << "|     Index|First Name| Last Name|  Nickname|" << std::endl;
	std::cout << "---------------------------------------------" << std::endl;
	for (int i = 0; i < (contactIndex < 8 ? contactIndex : 8); i++) {
		std::cout << "|" << std::setw(10) << i + 1 << "|"
		          << std::setw(10) << (contacts[i].getFirstName().length() > 10 ? contacts[i].getFirstName().substr(0, 9) + "." : contacts[i].getFirstName()) << "|"
		          << std::setw(10) << (contacts[i].getLastName().length() > 10 ? contacts[i].getLastName().substr(0, 9) + "." : contacts[i].getLastName()) << "|"
		          << std::setw(10) << (contacts[i].getNickname().length() > 10 ? contacts[i].getNickname().substr(0, 9) + "." : contacts[i].getNickname()) << "|" << std::endl;
	}
	std::cout << "---------------------------------------------" << std::endl;
}

void	PhoneBook::searchContact() const {
	int index;

	std::cout << "Enter the index of the contact to view details: ";
	std::cin >> index;
	if (std::cin.fail() || index < 1 || index > 8 || index > contactIndex) {
		std::cin.clear();
		std::cin.ignore(10000, '\n');
		std::cout << "Invalid index." << std::endl;
		return;
	}
	const Contact &contact = contacts[index - 1];
	std::cout << "First Name: " << contact.getFirstName() << std::endl;
	std::cout << "Last Name: " << contact.getLastName() << std::endl;
	std::cout << "Nickname: " << contact.getNickname() << std::endl;
	std::cout << "Phone Number: " << contact.getPhoneNumber() << std::endl;
	std::cout << "Darkest Secret: " << contact.getDarkestSecret() << std::endl;
}

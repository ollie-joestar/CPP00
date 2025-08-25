#include "phonebook.hpp"

int	main(void) {
	std::string command;
	PhoneBook phoneBook;

	std::cout << "Welcome to your PhoneBook!" << std::endl;
	std::cout << "Available commands: ADD, SEARCH, HELP, EXIT" << std::endl;
	std::cout << "Enter command: ";
	std::cin >> command;
	while (command != "EXIT") {
		if (command == "ADD") {
			phoneBook.addContact();
			std::cout << "Contact added successfully!" << std::endl;
		} else if (command == "SEARCH") {
			phoneBook.displayContacts();
			phoneBook.searchContact();
		} else if (command == "HELP") {
			std::cout << "Available commands: ADD, SEARCH, HELP, EXIT" << std::endl;
		} else {
			std::cout << "Invalid command. Please enter ADD, SEARCH, HELP or EXIT." << std::endl;
		}
		std::cout << "Enter command: ";
		std::cin >> command;
	}
	std::cout << "Exiting PhoneBook. Goodbye!" << std::endl;
	return 0;
}

#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <string>

class Contact {
   private:
	std::string firstName;
	std::string lastName;
	std::string nickname;
	std::string phoneNumber;
	std::string darkestSecret;

   public:
	Contact();
	~Contact();

	void setContactInfo(std::string fName, std::string lName,
	                    std::string nName, std::string pNumber,
	                    std::string dSecret);

	std::string getFirstName() const;
	std::string getLastName() const;
	std::string getNickname() const;
	std::string getPhoneNumber() const;
	std::string getDarkestSecret() const;
};

#endif // CONTACT_HPP

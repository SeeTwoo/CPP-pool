#ifndef CONTACT_HPP
# define CONTACT_HPP

#include <string>

class Contact {
	public:
//		Contact();
//		~Contact();
//		Contact(const Contact&);
//		Contact& operator=(const Contact&);
	private:
		std::string	_firstName;
		std::string	_lastName;
		std::string	_nickName;
		std::string _phoneNumber;
		std::string	_secret;
};

#endif

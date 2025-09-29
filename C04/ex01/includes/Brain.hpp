#ifndef BRAIN_HPP
# define BRAIN_HPP

class Brain {
	private :
		std::string	ideas[100];
	public :
		Brain();
		Brain(const Brain&);
		Brain &operator=(brain &);
		~Brain();
};

#endif

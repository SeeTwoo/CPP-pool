/* ************************************************************************** */
/*                                                                            */
/*                                                         :::     ::::::::   */
/*   Fixed.hpp                                           :+:     :+:    :+:   */
/*                                                     +:+ +:+        +:+     */
/*   By: SeeTwoo <waltibee@gmail.com>                +#+  +:+       +#+       */
/*                                                 +#+#+#+#+#+   +#+          */
/*   Created:                                           #+#    #+#            */
/*   Uptated:                                          ###   ########.fr      */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

class Fixed {
	private:
		int					Number;
		static int const	BinaryPointPosition = 8;
	public:
		Fixed();
		Fixed(const Fixed&);
		Fixed(const int);
		Fixed(const float);
		Fixed	&operator=(const Fixed &other);

		bool	operator==(const Fixed &other) const;
		bool	operator<=(const Fixed &other) const;
		bool	operator>=(const Fixed &other) const;
		bool	operator!=(const Fixed &other) const;
		bool	operator<(const Fixed &other) const;
		bool	operator>(const Fixed &other) const;

		Fixed	operator+(const Fixed &other) const;
		Fixed	operator-(const Fixed &other) const;
		Fixed	operator/(const Fixed &other) const;
		Fixed	operator*(const Fixed &other) const;

		Fixed	&operator++();
		Fixed	operator++(int);
		Fixed	&operator--();
		Fixed	operator--(int);

		static Fixed	&min(Fixed &a, Fixed &b);
		static Fixed	&max(Fixed &a, Fixed &b);
		static const Fixed	&min(const Fixed &a, const Fixed &b);
		static const Fixed	&max(const Fixed &a, const Fixed &b);

		~Fixed();
		int		getRawBits(void) const;
		void	setRawBits(int const raw);
		float	toFloat(void) const;
		int		toInt(void) const;
};

std::ostream& operator<<(std::ostream& os, const Fixed &other);

#endif

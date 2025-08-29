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
		Fixed& operator=(const Fixed&);
		~Fixed();
		int		getRawBits(void) const;
		void	setRawBits(int const raw);
};

#endif

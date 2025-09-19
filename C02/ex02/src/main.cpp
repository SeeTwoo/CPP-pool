/* ************************************************************************** */
/*                                                                            */
/*                                                         :::     ::::::::   */
/*   main.cpp                                            :+:     :+:    :+:   */
/*                                                     +:+ +:+        +:+     */
/*   By: SeeTwoo <waltibee@gmail.com>                +#+  +:+       +#+       */
/*                                                 +#+#+#+#+#+   +#+          */
/*   Created:                                           #+#    #+#            */
/*   Uptated:                                          ###   ########.fr      */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Fixed.hpp"

int	main(void) {
	Fixed a;
    Fixed b;
    Fixed const constA( 54);
    Fixed const constB( 42.42f );
    Fixed const d( b );
    a = Fixed( 10.5f );
    b = Fixed(10.2f);
    int result;

    std::cout << std::endl;
    std::cout << "min entre a = "<< a << " et b = "<< b << " " <<Fixed::min(a, b) << std::endl;
    std::cout << "max entre a = "<< a << " et b = "<< b << " " <<Fixed::max(a, b) << std::endl;
    std::cout << std::endl;
    std::cout << "min entre constA = "<< constA << " et constB = "<< constB << " " <<Fixed::min(constA, constB) << std::endl;
    std::cout << "max entre constA = "<< constA << " et constB = "<< constB << " " <<Fixed::max(constA, constB) << std::endl;
    std::cout << std::endl;
    std::cout << a << " + " << b << " = " << a + b << std::endl;
    std::cout << a << " - " << b << " = " << a - b << std::endl;
    std::cout << a << " * " << b << " = " << a * b << std::endl;
    std::cout << a << " / " << b << " = " << a / b << std::endl;
    std::cout << std::endl;
    std::cout << "a is " << a << std::endl;
    std::cout << "++a is " << ++a << std::endl;
    std::cout << "a++ is " << a++ << std::endl;
    std::cout << "a is " << a << std::endl;
    std::cout << "--a is " << --a << std::endl;
    std::cout << "a-- is " << a-- << std::endl;
    std::cout << "a is " << a << std::endl;
    std::cout << std::endl;
    result = a < b;
    std::cout << a << " < " << b << " = " << result << std::endl;
    result = a > b;
    std::cout << a << " > " << b << " = " << result << std::endl;
    result = a <= b;
    std::cout << a << " <= " << b << " = " << result << std::endl;
    result = a >= b;
    std::cout << a << " >= " << b << " = " << result << std::endl;
    result = a == b;
    std::cout << a << " == " << b << " = " << result << std::endl;
    result = a != b;
    std::cout << a << " != " << b << " = " << result << std::endl;
    std::cout << std::endl;
    std::cout << "a is " << a.toInt() << " as integer" << std::endl;
    std::cout << "b is " << b.toInt() << " as integer" << std::endl;
    std::cout << "d is " << d.toInt() << " as integer" << std::endl;
    return 0;
}

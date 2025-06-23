/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlewicki <nlewicki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 12:02:14 by nlewicki          #+#    #+#             */
/*   Updated: 2025/06/23 11:49:09 by nlewicki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <iostream>

// live time type polymorphism (type checking at runtime)

int main(void)
{
	Base *base1 = generate();
	Base *base2 = generate();
	Base *base3 = generate();

	std::cout << "Identifying base1:" << std::endl;
	identify(base1);
	identify(*base1);
	std::cout << "Identifying base2:" << std::endl;
	identify(base2);
	identify(*base2);
	std::cout << "Identifying base3:" << std::endl;
	identify(base3);
	identify(*base3);

	delete base1;
	delete base2;
	delete base3;
	return 0;
}

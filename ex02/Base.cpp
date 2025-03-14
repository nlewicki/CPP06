/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlewicki <nlewicki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 12:02:07 by nlewicki          #+#    #+#             */
/*   Updated: 2025/03/14 12:11:35 by nlewicki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <iostream>
#include <random>

Base::~Base()
{
}

Base *generate(void)
{
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<int> dis(0, 2);

	int random = dis(gen);

	std::cout << "Generated: " << (char)(random + 'A') << std::endl;
	switch (random)
	{
		case 0:
			return new A();
		case 1:
			return new B();
		default:
			return new C();
	}
}

void identify(Base *p)
{
	if (dynamic_cast<A *>(p))
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B *>(p))
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C *>(p))
		std::cout << "C" << std::endl;
}

void identify(Base &p)
{
	try
	{
		(void)dynamic_cast<A &>(p);
		std::cout << "A" << std::endl;
	}
	catch (std::bad_cast &e)
	{
		try
		{
			(void)dynamic_cast<B &>(p);
			std::cout << "B" << std::endl;
		}
		catch (std::bad_cast &e)
		{
			try
			{
				(void)dynamic_cast<C &>(p);
				std::cout << "C" << std::endl;
			}
			catch (std::bad_cast &e)
			{
				std::cout << "Unknown" << std::endl;
			}
		}
	}
}

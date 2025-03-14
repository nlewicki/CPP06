/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlewicki <nlewicki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 11:38:43 by nlewicki          #+#    #+#             */
/*   Updated: 2025/03/13 12:25:14 by nlewicki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int main(int argv, char **argc)
{
	if(argv != 2)
	{
		std::cout << "Usage: ./convert [string]" << std::endl;
		return 1;
	}
	ScalarConverter::convert(argc[1]);
	return 0;
}

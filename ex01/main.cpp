/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlewicki <nlewicki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 13:28:29 by nlewicki          #+#    #+#             */
/*   Updated: 2025/06/23 11:49:39 by nlewicki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

// serialization and deserialization of a Data structure (converting a pointer to uintptr_t and back)

int main(void)
{
	Data data;
	uintptr_t raw;

	data.s1 = "Hello";
	data.n = 42;
	std::cout << "Data address: " << &data << std::endl;
	std::cout << "Data values:" << std::endl;
	std::cout << data.s1 << std::endl;
	std::cout << data.n << std::endl;
	raw = Serializer::serialize(&data);
	std::cout << "Raw pointer value: " << raw << std::endl;
	Data *ptr = Serializer::deserialize(raw);
	std::cout << "Deserialized address: " << ptr << std::endl;
	std::cout << "Deserialized values:\n";
	std::cout << ptr->s1 << std::endl;
	std::cout << ptr->n << std::endl;
	return 0;
}

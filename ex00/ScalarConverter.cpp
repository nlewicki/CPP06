/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlewicki <nlewicki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 11:38:11 by nlewicki          #+#    #+#             */
/*   Updated: 2025/03/14 11:57:29 by nlewicki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{
}

ScalarConverter::ScalarConverter(ScalarConverter const & src)
{
	(void)src;
}

ScalarConverter::~ScalarConverter()
{
}

ScalarConverter &	ScalarConverter::operator=(ScalarConverter const & src)
{
	(void)src;
	return (*this);
}

void fromChar(char value)
{
	std::cout << "char: '" << value << "'" << std::endl;
	std::cout << "int: " << static_cast<int>(value) << std::endl;
	std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(value) << "f" << std::endl;
	std::cout << "double: " << std::fixed << std::setprecision(1) << static_cast<double>(value) << std::endl;
}

void fromInt(int value)
{
	// Check if char is displayable
	if (value >= 32 && value <= 126)
		std::cout << "char: '" << static_cast<char>(value) << "'" << std::endl;
	else if (value >= 0 && value <= 127)
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: impossible" << std::endl;

	std::cout << "int: " << value << std::endl;
	std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(value) << "f" << std::endl;
	std::cout << "double: " << std::fixed << std::setprecision(1) << static_cast<double>(value) << std::endl;
}

void fromFloat(float value)
{
	// Check if char is displayable
	if (std::isnan(value) || std::isinf(value))
		std::cout << "char: impossible" << std::endl;
	else if (value >= 32 && value <= 126)
		std::cout << "char: '" << static_cast<char>(value) << "'" << std::endl;
	else if (value >= 0 && value <= 127)
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: impossible" << std::endl;

	// Check if int conversion is possible
	if (std::isnan(value) || std::isinf(value) || value > INT_MAX || value < INT_MIN)
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << static_cast<int>(value) << std::endl;

	std::cout << "float: " << std::fixed << std::setprecision(1) << value << "f" << std::endl;
	std::cout << "double: " << std::fixed << std::setprecision(1) << static_cast<double>(value) << std::endl;
}

void fromDouble(double value)
{
	// Check if char is displayable
	if (std::isnan(value) || std::isinf(value))
		std::cout << "char: impossible" << std::endl;
	else if (value >= 32 && value <= 126)
		std::cout << "char: '" << static_cast<char>(value) << "'" << std::endl;
	else if (value >= 0 && value <= 127)
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: impossible" << std::endl;

	// Check if int conversion is possible
	if (std::isnan(value) || std::isinf(value) || value > INT_MAX || value < INT_MIN)
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << static_cast<int>(value) << std::endl;

	// Check if float conversion is possible (might lose precision)
	if (value > std::numeric_limits<float>::max() || value < -std::numeric_limits<float>::max())
		std::cout << "float: impossible" << std::endl;
	else
		std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(value) << "f" << std::endl;

	std::cout << "double: " << std::fixed << std::setprecision(1) << value << std::endl;
}

void ScalarConverter::convert(const std::string &str)
{
	// Check for special cases first
	if (str == "nan" || str == "nanf")
	{
		fromDouble(std::numeric_limits<double>::quiet_NaN());
		return;
	}
	else if (str == "+inf" || str == "+inff")
	{
		fromDouble(std::numeric_limits<double>::infinity());
		return;
	}
	else if (str == "-inf" || str == "-inff")
	{
		fromDouble(-std::numeric_limits<double>::infinity());
		return;
	}

	// Check for char
	if (str.length() == 3 && str[0] == '\'' && str[2] == '\'')
	{
		fromChar(str[1]);
		return;
	}

	// Try to convert to different types
	try
	{
		// Try as int first
		size_t pos;
		int i = std::stoi(str, &pos);
		if (pos == str.length())
		{
			fromInt(i);
			return;
		}

		// Try as float
		float f = std::stof(str, &pos);
		if (pos == str.length() || (pos == str.length() - 1 && str[str.length() - 1] == 'f'))
		{
			fromFloat(f);
			return;
		}

		// Try as double
		double d = std::stod(str, &pos);
		if (pos == str.length())
		{
			fromDouble(d);
			return;
		}

		// If we get here, couldn't match any type
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: impossible" << std::endl;
		std::cout << "double: impossible" << std::endl;
	}
	catch (const std::exception &)
	{
		// Conversion failed
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: impossible" << std::endl;
		std::cout << "double: impossible" << std::endl;
	}
}

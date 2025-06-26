/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlewicki <nlewicki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 11:38:11 by nlewicki          #+#    #+#             */
/*   Updated: 2025/06/26 11:33:05 by nlewicki         ###   ########.fr       */
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

enum Type
{
	TYPE_CHAR,
	TYPE_INT,
	TYPE_FLOAT,
	TYPE_DOUBLE,
	TYPE_INVALID
};

static Type detecttype(const std::string &str)
{
	if (str.empty())
		return TYPE_INVALID;
	if (str == "nan" || str == "+inf" || str == "-inf")
		return TYPE_DOUBLE;
	if (str == "nanf" || str == "+inff" || str == "-inff")
		return TYPE_FLOAT;
	if (str.length() == 3 && str[0] == '\'' && str[2] == '\'' && str[1] >= 32 && str[1] <= 126)
		return TYPE_CHAR;
	if (str.length() == 1 && str[0] >= 32 && str[0] <= 126 && !std::isdigit(str[0]))
		return TYPE_CHAR;
	if (str.length() > 1 && str[str.length() - 1] == 'f')
	{
		std::string without_f = str.substr(0, str.length() - 1);
		if (without_f.find('.') != std::string::npos)
		{
			try {
				std::stof(without_f);
				return TYPE_FLOAT;
			} catch (...) {
				return TYPE_INVALID;
			}
		}
		return TYPE_INVALID;
	}
	if (str.find('.') != std::string::npos)
	{
		try {
			std::stod(str);
			return TYPE_DOUBLE;
		} catch (...) {
			return TYPE_INVALID;
		}
	}
	size_t start = 0;
	if (str[0] == '+' || str[0] == '-')
		start = 1;
	if (start >= str.length())
		return TYPE_INVALID;
	for (size_t i = start; i < str.length(); i++)
	{
		if (!std::isdigit(str[i]))
			return TYPE_INVALID;
	}
	try {
		std::stoll(str);
		return TYPE_INT;
	} catch (...) {
		return TYPE_INVALID;
	}
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

static void fromFloat(float value)
{
	if (std::isnan(value) || std::isinf(value))
		std::cout << "char: impossible" << std::endl;
	else if (value >= 32 && value <= 126 && value == static_cast<int>(value))
		std::cout << "char: '" << static_cast<char>(value) << "'" << std::endl;
	else if (value >= 0 && value <= 127 && value == static_cast<int>(value))
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: impossible" << std::endl;
	if (std::isnan(value) || std::isinf(value) || value > INT_MAX || value < INT_MIN)
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << static_cast<int>(value) << std::endl;
	if (std::isnan(value))
		std::cout << "float: nanf" << std::endl;
	else if (std::isinf(value))
		std::cout << "float: " << (value > 0 ? "+inff" : "-inff") << std::endl;
	else
		std::cout << "float: " << std::fixed << std::setprecision(1) << value << "f" << std::endl;
	if (std::isnan(value))
		std::cout << "double: nan" << std::endl;
	else if (std::isinf(value))
		std::cout << "double: " << (value > 0 ? "+inf" : "-inf") << std::endl;
	else
		std::cout << "double: " << std::fixed << std::setprecision(1) << static_cast<double>(value) << std::endl;
}

static void fromDouble(double value)
{
	if (std::isnan(value) || std::isinf(value))
		std::cout << "char: impossible" << std::endl;
	else if (value >= 32 && value <= 126 && value == static_cast<int>(value))
		std::cout << "char: '" << static_cast<char>(value) << "'" << std::endl;
	else if (value >= 0 && value <= 127 && value == static_cast<int>(value))
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: impossible" << std::endl;

	if (std::isnan(value) || std::isinf(value) || value > INT_MAX || value < INT_MIN)
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << static_cast<int>(value) << std::endl;

	if (std::isnan(value))
		std::cout << "float: nanf" << std::endl;
	else if (std::isinf(value))
		std::cout << "float: " << (value > 0 ? "+inff" : "-inff") << std::endl;
	else if (value > std::numeric_limits<float>::max() || value < -std::numeric_limits<float>::max())
		std::cout << "float: impossible" << std::endl;
	else
		std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(value) << "f" << std::endl;

	if (std::isnan(value))
		std::cout << "double: nan" << std::endl;
	else if (std::isinf(value))
		std::cout << "double: " << (value > 0 ? "+inf" : "-inf") << std::endl;
	else
		std::cout << "double: " << std::fixed << std::setprecision(1) << value << std::endl;
}

void ScalarConverter::convert(const std::string &str)
{
	Type type = detecttype(str);

	std::cout << "Detected type: ";
	switch (type) {
		case TYPE_CHAR:
			std::cout << "char";
			break;
		case TYPE_INT:
			std::cout << "int";
			break;
		case TYPE_FLOAT:
			std::cout << "float";
			break;
		case TYPE_DOUBLE:
			std::cout << "double";
			break;
		case TYPE_INVALID:
			std::cout << "invalid";
			break;
	}
	std::cout << std::endl;

	if (type == TYPE_INVALID)
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: impossible" << std::endl;
		std::cout << "double: impossible" << std::endl;
		return;
	}

	try
	{
		switch (type)
		{
			case TYPE_CHAR:
			{
				char c = (str.length() == 1) ? str[0] : str[1];
				fromChar(c);
				break;
			}
			case TYPE_INT:
			{
				long long temp = std::stoll(str);
				if (temp > INT_MAX || temp < INT_MIN)
				{
					std::cout << "char: impossible" << std::endl;
					std::cout << "int: impossible" << std::endl;
					std::cout << "float: impossible" << std::endl;
					std::cout << "double: impossible" << std::endl;
					return;
				}
				int actualInt = static_cast<int>(temp);
				fromInt(actualInt);
				break;
			}
			case TYPE_FLOAT:
			{
				float actualFloat;
				if (str == "nanf")
					actualFloat = std::numeric_limits<float>::quiet_NaN();
				else if (str == "+inff")
					actualFloat = std::numeric_limits<float>::infinity();
				else if (str == "-inff")
					actualFloat = -std::numeric_limits<float>::infinity();
				else
					actualFloat = std::stof(str);
				fromFloat(actualFloat);
				break;
			}
			case TYPE_DOUBLE:
			{
				double actualDouble;
				if (str == "nan")
					actualDouble = std::numeric_limits<double>::quiet_NaN();
				else if (str == "+inf")
					actualDouble = std::numeric_limits<double>::infinity();
				else if (str == "-inf")
					actualDouble = -std::numeric_limits<double>::infinity();
				else
					actualDouble = std::stod(str);
				fromDouble(actualDouble);
				break;
			}
			default:
				std::cout << "char: impossible" << std::endl;
				std::cout << "int: impossible" << std::endl;
				std::cout << "float: impossible" << std::endl;
				std::cout << "double: impossible" << std::endl;
				break;
		}
	}
	catch (const std::exception &)
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: impossible" << std::endl;
		std::cout << "double: impossible" << std::endl;
	}
}

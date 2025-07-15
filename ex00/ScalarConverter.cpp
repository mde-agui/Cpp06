/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-agui <mde-agui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 22:05:01 by mde-agui          #+#    #+#             */
/*   Updated: 2025/06/09 16:10:32 by mde-agui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

bool	isChar(const std::string& literal)
{
	return (literal.length() == 1 && std::isprint(literal[0]) &&
			!std::isdigit(literal[0]));
}

bool	isInt(const std::string& literal)
{
	if (literal.empty() || literal == "-" || literal == "+")
		return (false);
	
	size_t	start = (literal[0] == '-' || literal[0] == '+') ? 1 : 0;
	if (start == literal.length() || !std::isdigit(literal[start]))
		return (false);
	for (size_t i = start + 1; i < literal.length(); ++i)
	{
		if (!std::isdigit(literal[i]))
			return (false);
	}
	
	std::istringstream	iss(literal);
	long long			i;
	iss >> i;
	if (iss.fail() || !iss.eof())
		return (false);
	return (i >= std::numeric_limits<int>::min() && i <= std::numeric_limits<int>::max());
}

bool	isFloat(const std::string& literal)
{
	if (literal == "-inff" || literal == "+inff" || literal == "nanf")
		return (true);
	if (literal.empty() || literal[literal.length() - 1] != 'f')
		return (false);
	std::istringstream	iss(literal.substr(0, literal.length() - 1));
	float				f;
	iss >> f;
	return (!iss.fail() && iss.eof());
}

bool	isDouble(const std::string& literal)
{
	if (literal == "-inf" || literal == "+inf" || literal == "nan")
		return (true);
	if (literal.empty() || literal == "-" || literal == "+")
		return (false);
	double	d = atof(literal.c_str());
	if (d == 0.0 && literal != "0" && literal != "-0" && literal != "+0")
		return (false);
	if (isInt(literal))
		return (false);
	return (literal.find("f") == std::string::npos);
}

static void	charHandler(const std::string& literal)
{
	char	c = literal[0];

	std::cout << "char: '" << c << "'" << std::endl;
	std::cout << "int: " << static_cast<int>(c) << std::endl;
	std::cout << "float: " << static_cast<float>(c) << "f" << std::endl;
	std::cout << "double: " << static_cast<double>(c) << std::endl;
	return ;
}

static void	intHandler(const std::string& literal)
{
	std::istringstream	iss(literal);
	long long			i;

	iss >> i;
	if (iss.fail() || !iss.eof())
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: impossible" << std::endl;
		std::cout << "double: impossible" << std::endl;
		return ;
	}
	int	value = static_cast<int>(i);
	if (value >= 0 && value <= 127 && std::isprint(value))
		std::cout << "char: '" << static_cast<char>(value) << "'" << std::endl;
	else
		std::cout << "char: Non displayable" << std::endl;
	std::cout << "int: " << value << std::endl;
	std::cout << "float " << static_cast<float>(value) << "f" << std::endl;
	std::cout << "double " << static_cast<double>(value) << std::endl;
	return ;
}

static void	floatHandler(const std::string& literal)
{
	float	f = atof(literal.c_str());

	if (literal == "nanf" || f != f)
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: nanf" << std::endl;
		std::cout << "double: nan" << std::endl;
	}
	else if (literal == "+inff" || literal == "-inff" ||
			f > std::numeric_limits<float>::max() || f < -std::numeric_limits<float>::max())
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: " << (literal == "+inff" ? "inff" : "-inff") << std::endl;
		std::cout << "double: " << (literal == "+inff" ? "inf" : "-inf") << std::endl;
	}
	else
	{
		if (f >= 0 && f <= 127 && std::isprint(static_cast<int>(f)))
			std::cout << "char: '" << static_cast<char>(f) << "'" << std::endl;
		else
			std::cout << "char: impossible" << std::endl;
		if (f > static_cast<float>(std::numeric_limits<int>::max()) ||
			f < static_cast<float>(std::numeric_limits<int>::min()))
			std::cout << "int: impossible" << std::endl;
		else
			std::cout << "int: " << static_cast<int>(f) << std::endl;
		std::cout << "float: " << f << "f" << std::endl;
		std::cout << "double: " << static_cast<double>(f) << std::endl;
	}
	return ;
}

static void	doubleHandler(const std::string& literal)
{
	double	d = atof(literal.c_str());

	if (literal == "nan" || d != d)
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: nanf" << std::endl;
		std::cout << "double: nan" << std::endl;
	}
	else if (literal == "+inf" || literal == "-inf" ||
			d > std::numeric_limits<double>::max() || d < -std::numeric_limits<double>::max())
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: " << (literal == "+inf" ? "inff" : "-inff") << std::endl;
		std::cout << "double: " << (literal == "+inf" ? "inf" : "-inf") << std::endl;
	}
	else
	{
		if (d >= 0 && d <= 127 && std::isprint(static_cast<int>(d)))
			std::cout << "char: '" << static_cast<char>(d) << "'" << std::endl;
		else
			std::cout << "char: impossible" << std::endl;
		if (d > static_cast<double>(std::numeric_limits<int>::max()) ||
			d < static_cast<double>(std::numeric_limits<int>::min()))
			std::cout << "int: impossible" << std::endl;
		else
			std::cout << "int: " << static_cast<int>(d) << std::endl;
		std::cout << "float: " << static_cast<float>(d) << "f" << std::endl;
		std::cout << "double: " << d << std::endl;
	}
	return ;
}

static void invalidHandler(const std::string& /* literal */)
{
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	std::cout << "float: impossible" << std::endl;
	std::cout << "double: impossible" << std::endl;
	return ;
}

void	ScalarConverter::convert(const std::string& literal)
{
	std::cout << std::fixed << std::setprecision(1);
	typedef void (*Handler)(const std::string&);

	Handler	handlers[] =
	{
		&intHandler,
		&charHandler,
		&floatHandler,
		&doubleHandler,
		&invalidHandler
	};

	bool	(*detectors[])(const std::string&) =
	{
		&isInt,
		&isChar,
		&isFloat,
		&isDouble,
		NULL
	};
	
	for (int i = 0; detectors[i]; ++i)
	{
		if (detectors[i](literal))
		{
			handlers[i](literal);
			return ;
		}
	}
	handlers[4](literal);
}

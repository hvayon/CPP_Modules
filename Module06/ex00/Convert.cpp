/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Convert.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvayon <hvayon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 19:41:03 by hvayon            #+#    #+#             */
/*   Updated: 2022/10/28 20:54:32 by hvayon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Convert.hpp"

Convert::Convert() : _err(false), _input(""), _val(0.0f) {
	return ;
}

Convert::Convert (const std::string &input) : _err(false), _input(input), _val(0.0f) {
	try {
		char *str = NULL;
		if (std::isprint(_input[0]) && !std::isdigit(_input[0]) && _input[1] == '\0') //string
			_val = _input[0];
		else {
			_val = std::strtod(_input.c_str(), &str); //convert to double //c_str() convert to string
			if (_val == 0.0f &&\
			(_input[0] != '+' && _input[0] != '-' && !std::isdigit(_input[0])))
				throw Convert::BadStrException();
			if (*str && std::strcmp(str, "f"))
				throw Convert::BadStrException();
		}
			
	}
	catch(const std::exception& e) {
		_err = true;
		std::cerr << e.what() << '\n';
	}
}

bool	Convert::getErr(void) const {
	return _err;
}

std::string	Convert::getInput(void) const {
	return _input;
}

double	Convert::getVal(void) const {
	return _val;
}

char	Convert::getChar(void) const
{
	return static_cast <char> (_val);
}

int		Convert::getInt(void) const
{
	return static_cast <int> (_val);
}

float	Convert::getFloat(void) const
{
	return static_cast <float> (_val);
}

double	Convert::getDouble(void) const
{
	return static_cast <double> (_val);
}

static void	printChar(std::ostream&	o, const Convert& c)
{
	o << "char: ";
	if (std::isnan(c.getVal()) || std::isinf(c.getVal()) || \
	c.getVal() > static_cast <double> (std::numeric_limits<char>::max()) || \
	c.getVal() < static_cast <double> (std::numeric_limits<char>::min()))
	{
		o << "impossible" << std::endl;
		return ;
	}
	if (!std::isprint(c.getChar()))
	{
		o << "Non displayable" << std::endl;
		return;
	}
	o << '\'' << c.getChar() << '\''<< std::endl;
}

// static void	printInt(std::ostream&	o, const Convert& c)
// static void	printFloat(std::ostream&	o, const Convert& c)
// static void	printDouble(std::ostream&	o, const Convert& c)
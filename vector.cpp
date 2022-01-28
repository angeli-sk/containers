/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   vector.cpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: akramp <akramp@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/26 11:49:16 by akramp        #+#    #+#                 */
/*   Updated: 2022/01/27 14:13:33 by akramp        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "vector.hpp"
#include <cstdio>

using namespace ft;

vector::vector(/* args */) {}

vector::vector(vector const & copy)
{
	*this = copy;
}

vector & vector::operator = (vector const & copy)
{
	this->_length = copy._length;
	return *this;
}

vector::~vector() {}

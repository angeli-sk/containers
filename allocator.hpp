/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   allocator.hpp                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: akramp <akramp@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/06/07 14:50:39 by akramp        #+#    #+#                 */
/*   Updated: 2022/06/07 14:55:03 by akramp        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef ALLOCATOR_HPP
# define ALLOCATOR_HPP
#include <memory>

namespace ft
{
	template <class T> class allocator;
	class My_Alloc : public std::iterator<std::input_iterator_tag, pOpReference>
	{

	}
}


#endif

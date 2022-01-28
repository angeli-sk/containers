/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   vector.hpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: akramp <akramp@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/26 11:59:32 by akramp        #+#    #+#                 */
/*   Updated: 2022/01/27 18:47:49 by akramp        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
# define VECTOR_HPP

namespace ft
{
	class vector
	{
		private:
			int	_length;
		public:
			vector();
			vector(vector const & copy);
			vector & operator = (vector const & copy);
			virtual ~vector();
	};
}

#endif

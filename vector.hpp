/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   vector.hpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: akramp <akramp@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/26 11:59:32 by akramp        #+#    #+#                 */
/*   Updated: 2022/06/07 17:26:18 by akramp        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
# define VECTOR_HPP
#include <memory> //alloc

namespace ft
{
	template < class T, class Allocator = std::allocator <T> >
	class vector
	{
		public:
			typedef Allocator								allocator_type;
			typedef std::allocator_traits<allocator_type>   alloc_traits;
			typedef typename alloc_traits::size_type       	size_type;

			explicit vector (const allocator_type& alloc = allocator_type()) : _alloc(alloc) {}
			// explicit vector (size_type n, const value_type& val = value_type(),
			// 	const allocator_type& alloc = allocator_type());
			// vector (InputIterator first, InputIterator last,
            //     const allocator_type& alloc = allocator_type());
			vector(const vector  & copy) { *this = copy; }
			vector & operator = (vector const & copy)
			{
				this->_length = copy._length;
				return *this;
			}
			virtual ~vector() {};

		private:
			T			_length;
			Allocator 	_alloc;

		protected:
			// template<typename T_>
			// struct is_same<T_,T_>
			// {
			// 	static const bool value = true;
			// };

			// template<bool> struct static_assert;
			// template<> struct static_assert<true> {};

			typedef T												value_type;
			typedef value_type&										reference;
			typedef const value_type&								const_reference;
			typedef typename 		alloc_traits::difference_type 	difference_type;
			typedef typename 		alloc_traits::pointer			pointer;
			typedef typename 		alloc_traits::const_pointer		const_pointer;
			typedef pointer											iterator;
			typedef const_pointer									const_iterator;
			typedef std::reverse_iterator<iterator>          		reverse_iterator;
			typedef std::reverse_iterator<const_iterator>    		const_reverse_iterator;


			// static_assert<is_same<typename allocator_type::value_type,value_type>::value>();
			//begin();
	};
}

#endif

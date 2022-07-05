/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   vector.hpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: akramp <akramp@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/26 11:59:32 by akramp        #+#    #+#                 */
/*   Updated: 2022/07/05 17:46:16 by akramp        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
# define VECTOR_HPP
#include <memory> //alloc
#include <iostream>
#include <cmath>

namespace ft
{
	template < class T, class Allocator = std::allocator <T> >
	class vector
	{
		public:
			typedef Allocator								allocator_type;
			typedef std::allocator_traits<allocator_type>   alloc_traits;
			typedef typename alloc_traits::size_type       	size_type;

		private:
			size_type	_size;
			size_type	_capacity;

			Allocator 	_alloc_type;


		protected:
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

		private:
			pointer										_begin;
			pointer										_end;

			// void	create_update_array()
			// {

			// }


		public:

			// template <class _Tp, class _Allocator>
			// void vector<_Tp, _Allocator>::__vallocate(size_type __n)
			// {
			// 	if (__n > max_size())
			// 		this->__throw_length_error();
			// 	this->__begin_ = this->__end_ = __alloc_traits::allocate(this->__alloc(), __n);
			// 	this->__end_cap() = this->__begin_ + __n;
			// 	__annotate_new(0);
			// }

			/*---------------------------------------------------------------*/
			explicit vector (const allocator_type& alloc = allocator_type()) : _size(0), \
				_capacity(0), _alloc_type(alloc)
			{
				std::cout << "constructor uwu!" << std::endl;
			}

			explicit vector (size_type n, const value_type& val = value_type(),
				const allocator_type& alloc = allocator_type()) : _size(n), _capacity(0), _alloc_type(alloc) //change data to null
			{
					// pushback asign
					//figure out the growth rate
					(void)val;
					std::cout << "constructor owo!" << std::endl;
					if (_size > _capacity)
					{
						for (int i = 0; _capacity < _size; i++)
						{
							_capacity = pow(2, i);
							std::cout << i << " & " << _capacity << std::endl;
						}
						std::cout << "cap = " << _capacity << std::endl;
					}

			}

			// template <class InputIterator>
			// 	vector (InputIterator first, InputIterator last,
			// 		const allocator_type& alloc = allocator_type());
			// // {

			// // }

			vector(const vector  & copy) { *this = copy; }
			vector & operator = (vector const & copy)
			{
				this->_length = copy._length;
				return *this;
			}

			virtual ~vector()
			{
			};


			template <class InputIterator>
			void assign (InputIterator first, InputIterator last);

			void assign (size_type n, const value_type& val);

			// static_assert<is_same<typename allocator_type::value_type,value_type>::value>();
			//begin();

	};
}

#endif

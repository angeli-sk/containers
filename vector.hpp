/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   vector.hpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: akramp <akramp@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/26 11:59:32 by akramp        #+#    #+#                 */
/*   Updated: 2022/07/06 20:26:22 by akramp        ########   odam.nl         */
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
			size_type	_old_size;
			size_type	_capacity;
			size_type	_old_cap;
			Allocator 	_alloc_type;
			T			*_array;


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
			value_type									_val;

			void	capacity_updater()
			{
				if (_size > _capacity)
				{
					_old_cap = _capacity;
					for (size_type i = 0; _capacity < _size; i++)
						_capacity = pow(2, i);
				}
			}

			T	*copy_array(T *array, size_type size_new_array)
			{
				T *temp = new T[size_new_array];

				for (size_type i = 0; i < size_new_array; i++)
					temp[i] = array[i];
				// if (size_new_array > _old_cap)
				// {
				// 	for (size_type i = _old_cap; i < size_new_array; i++)
				// 		temp[i] = (value_type) 0;
				// 		std::cout << "djjdkdj" << std::endl;
				// }
				return temp;
			}

			void	new_array()
			{
				_array = new T[_size];
			}

			void	array_updater()
			{
					T *temp = NULL;
					if (_old_size != 0)
					{
						temp = copy_array(_array, _size);
						delete [] _array;
						_array = temp;
					}
					else
						new_array();

			}

			void	array_filler(size_type start)
			{

				for (size_type i = start; i < _size; i++)
					_array[i] = _val;
					std::cout << "owo!" << std::endl;
			}

			void	array_deleter()
			{
				delete [] _array;
			}



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
				_capacity(0), _old_cap(0), _alloc_type(alloc)
			{
				std::cout << "constructor uwu!" << std::endl;
			}

			explicit vector (size_type n, const value_type& val = value_type(),
				const allocator_type& alloc = allocator_type()) : _size(n), _capacity(0), \
				_old_cap(0), _alloc_type(alloc) //change data to null
			{
					// pushback asign
					_val = val;
					std::cout << "constructor owo!" << std::endl;

					capacity_updater();
					if (_array == NULL)
						new_array();
					// else
					// 	array_updater();
					array_filler(0);
					// for (size_type i = 0; i < _capacity; i++)
					// {
					// 	std::cout << "arr = " << _array[i] << std::endl;
					// }
					_old_size = _size;

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

			reference operator[] (size_type n)
			{
				return _array[n];
			}

			const_reference operator[] (size_type n) const
			{
				return _array[n];
			}

			void push_back (const value_type& val)
			{
				_old_size = _size;
				_size++;
				_val = val;
				std::cout << val << std::endl;
				capacity_updater();
				array_updater();
				_array[_size-1] = val;
				// array_filler(0);
			}

			// static_assert<is_same<typename allocator_type::value_type,value_type>::value>();
			//begin();

	};
}

#endif

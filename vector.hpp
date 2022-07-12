/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   vector.hpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: akramp <akramp@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/26 11:59:32 by akramp        #+#    #+#                 */
/*   Updated: 2022/07/12 18:21:46 by akramp        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
# define VECTOR_HPP
#include <memory> //alloc
#include <iostream>
#include <cmath>
#include <iostream>       // std::cerr
#include <typeinfo>       // operator typeid
#include <exception>      // std::exception
#define RED		"\033[38;5;196m"
#define WHITE	"\033[0m"
#define TEST "\033[38;5;196m TEST!!! \033[0m"

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
			bool		_flag_allocated;


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
			// pointer										_begin;
			// pointer										_end;
			value_type									_val;

			void	value_of_capacity_changer()
			{
				if (_size != _capacity)
				{
					_old_cap = _capacity;
					for (size_type i = 0; _capacity < _size; i++)
						_capacity = pow(2, i);
				}
			}

			T	*copy_array(T *array, size_type size_new_array, size_type start)
			{
				// T *temp = new T[size_new_array];
				T *temp = _alloc_type.allocate(size_new_array);

				_flag_allocated = true;
				for (size_type i = start; i < size_new_array; i++)
					temp[i] = array[i];
				return temp;
			}

			void	new_array()
			{
				// _array = new T[_capacity];
				_array = _alloc_type.allocate(_capacity);
				_flag_allocated = true;
			}

			void	array_capacity_updater()
			{
					T *temp = NULL;
					if (_flag_allocated == false)
					{
						std::cout << TEST << std::endl;
						new_array();
					}
					else
					{
						temp = copy_array(_array, _size, 0);
						// delete [] _array;
						array_deleter();
						_array = temp;
					}
			}

			void	array_filler(size_type start, value_type val)
			{
				for (size_type i = start; i < _size; i++)
					_alloc_type.construct(&_array[i], val);// _array[i] = val;
			}

			void	array_deleter()
			{
				// delete [] _array;
				for (size_t i = 0; i < _size; i++)
					_alloc_type.destroy(&_array[i]);
				_alloc_type.deallocate(_array, 1);
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

			size_type max_size() const
			{
				// return (std::numeric_limits<size_type>::max()/sizeof(T));
				return _alloc_type.max_size();
			}

			explicit vector (const allocator_type& alloc = allocator_type()) : _size(0), \
				_capacity(0), _old_cap(0), _alloc_type(alloc), _flag_allocated(false)
			{
				std::cout << RED << "constructor uwu!" << WHITE << std::endl;
			}

			explicit vector (size_type n, const value_type& val = value_type(),
				const allocator_type& alloc = allocator_type()) : _size(n), _capacity(0), \
				_old_cap(0), _alloc_type(alloc), _flag_allocated(false)
			{
					_val = val;
					if (_size < 0 || _size > max_size())
						throw (std::length_error("ft::vector"));
					std::cout << RED << "constructor owo!" << WHITE << std::endl;

					value_of_capacity_changer();
					std::cout << TEST << std::endl;
					new_array();
					array_filler(0, _val);
					_old_size = _size;
			}

			// template <class InputIterator>
			// 	vector (InputIterator first, InputIterator last,
			// 	const allocator_type& alloc = allocator_type());

			vector(const vector  & copy) { *this = copy; }
			vector & operator = (vector const & copy)
			{
				this->_size = copy._size;
				this->_old_size = copy._old_size;;
				this->_capacity = copy._capacity;
				this->_old_cap = copy._old_cap;
				this->_alloc_type = copy._alloc_type;
				this->_array = copy._array;
				this->_flag_allocated = copy._flag_allocated;
				this->_val = copy._val;
				return *this;
			}

			virtual ~vector()
			{
				if (_flag_allocated == true)
					array_deleter();
			};

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
				std::cout << RED << val << WHITE << std::endl;
				value_of_capacity_changer();
				array_capacity_updater();
				_alloc_type.construct(&_array[_size - 1], val);
				// _array[_size - 1] = val;
			}

			size_type size() const
			{
				return _size;
			}

			size_type capacity() const
			{
				return _capacity;
			}

			bool empty() const
			{
				if (_size == 0)
					return true;
				else
					return false;
			}

			void resize (size_type n, value_type val = value_type())
			{
				if (n < 0 || n > max_size())
						throw (std::length_error("ft::vector"));
				_old_size = _size;
				_size = n;
				_val = val;
				value_of_capacity_changer();
				array_capacity_updater();
				if (_old_size < _size)
					array_filler(_old_size, _val);
			}

			void reserve (size_type n)
			{
				if (_capacity < n)
				{
					_capacity = n;
					value_of_capacity_changer();
					array_capacity_updater();
				}
			}

			// template <class InputIterator>
			// void assign (InputIterator first, InputIterator last);

			void assign (size_type n, const value_type& val)
			{
				_val = val;
				if (_capacity < n)
				{
					_capacity = n;
					_size = n;
					array_capacity_updater();
				}
				else
				{
					// delete [] _array;
					array_deleter();
					_size = n;
					new_array();
				}
				array_filler(0, _val);
			}

			reference at (size_type n)
			{
				if (n < 0 || n > max_size() || n > _size)
						throw (std::out_of_range("ft::vector"));
				return _array[n];
			}

			const_reference at (size_type n) const
			{
				if (n < 0 || n > max_size() || n > _size)
						throw (std::out_of_range("ft::vector"));
				return _array[n];
			}

			reference front()
			{
				return _array[0];
			}

			const_reference front() const
			{
				return _array[0];
			}

			reference back()
			{
				return _array[_size-1];
			}

			const_reference back() const
			{
				return _array[_size-1];
			}

			allocator_type get_allocator() const
			{
				return  _alloc_type;
			}

			void pop_back()
			{
				_alloc_type.destroy(&_array[_size-1]);
				_size--;
			}

			// void swap (vector& x)
			// {
			// 	vector<T> bin;

			// 	bin = *this;
			// 	*this = x;
			// 	x = bin;
			// }

			// iterator insert (iterator position, const value_type& val)
			// {
			// 	// _old_size = _size;
			// 	// _size = _size + position
			// 	// if (_size > _capacity)
			// 	// {
			// 	// 	value_of_capacity_changer();
			// 	// 	array_capacity_updater();
			// 	// }
			// }

			// void insert (iterator position, size_type n, const value_type& val);

			// template <class InputIterator>
			//     void insert (iterator position, InputIterator first, InputIterator last);


			//start with testing & read notion future log!

			// static_assert<is_same<typename allocator_type::value_type,value_type>::value>();
			//begin();

	};
}

#endif

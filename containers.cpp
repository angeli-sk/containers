/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   containers.cpp                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: akramp <akramp@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/20 15:48:31 by akramp        #+#    #+#                 */
/*   Updated: 2022/06/24 18:05:58 by akramp        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "vector.hpp"
#include <vector>
#include <iostream>

void	init_it_tests()
{
	int arr[] = { 10, 20, 30 };
	int n = sizeof(arr) / sizeof(arr[0]);
	std::vector<int> vect(arr, arr + n);
	for (std::vector<int>::iterator i = vect.begin(); i != vect.end(); ++i)
		std::cout << *i << " ";
	std::cout << '\n';
}

void	iterator_tests()
{
	std::cout << "\nITERATORS TESTS:\n\n";
	std::cout << "Iterators:\n";
	init_it_tests();
	std::vector<int> ints_with_value (4, 100);
	for (std::vector<int>::iterator i = ints_with_value.begin(); i != ints_with_value.end(); ++i)
		std::cout << *i << ' ';
		std::cout << '\n';
	std::vector<int> it_tru (ints_with_value.begin(), ints_with_value.end());
	std::vector<int> rit_tru (ints_with_value.rbegin(), ints_with_value.rend());
	std::vector<int> copy_of_it_tru (it_tru);
}

void	capacity_tests()
{
	std::cout << "\nCAPACITY TESTS:\n\n";
	std::vector<int> empty_vec;
	std::vector<int> vec_with_value (4, 100);
	std::cout << "Capacity:\n";
	std::cout << "size empty: " << empty_vec.size() << '\n';
	std::cout << "size: " << vec_with_value.size() << '\n';
	std::cout << "max size: " << empty_vec.max_size() << '\n';
	vec_with_value.resize(2);
	std::cout << "resize: " << vec_with_value.size() << '\n';
	std::cout << "capacity: " << vec_with_value.capacity() << '\n';
	vec_with_value.resize(6);
	std::cout << "resize: " << vec_with_value.size() << '\n';
	std::cout << "capacity: " << vec_with_value.capacity() << '\n';
	vec_with_value.resize(10);
	std::cout << "resize: " << vec_with_value.size() << '\n';
	std::cout << "capacity: " << vec_with_value.capacity() << '\n';
	vec_with_value.resize(20);
	std::cout << "resize: " << vec_with_value.size() << '\n';
	std::cout << "capacity: " << vec_with_value.capacity() << '\n';
	vec_with_value.resize(33);
	std::cout << "resize: " << vec_with_value.size() << '\n';
	std::cout << "capacity: " << vec_with_value.capacity() << '\n';
	std::cout << "empty: "<< empty_vec.empty()  << '\n';
	std::cout << "not empty: " << vec_with_value.empty()  << '\n';
	vec_with_value.reserve(30);
	std::cout << "smaller reserve: " << vec_with_value.size() << '\n';
	std::cout << "capacity: " << vec_with_value.capacity() << '\n';
	vec_with_value.reserve(65);
	std::cout << "bigger reserve: " << vec_with_value.size() << '\n';
	std::cout << "capacity: " << vec_with_value.capacity() << '\n';
}

void	element_access_tests()
{
	std::cout << "\nELEMENT ACCESS TESTS:\n\n";
	int arr[] = { 10, 20, 30 };
	int n = sizeof(arr) / sizeof(arr[0]);
	std::vector<int> myvector (10);
	for (unsigned i=0; i<myvector.size(); i++)
		myvector.at(i)=i;
	std::cout << "assigned values at:";
	for (unsigned i=0; i<myvector.size(); i++)
		std::cout << ' ' << myvector.at(i);
	std::cout << '\n';
	std::vector<int> vect(arr, arr + n);
	std::cout << "element access: " << vect[0] << " " << vect[1] << " " << vect[2] << " " << "\n";
	std::cout << "element access front back: " << vect.front() << " " << vect.back() << "\n";
}

void	modifiers_tests()
{
	std::vector<int> empty_vec;
	std::vector<std::string> letters;
	std::vector<std::string>::iterator it;
	std::vector<std::string> swapity;
	std::allocator<int> alloc;

	std::cout << "size empty: " << empty_vec.size() << '\n';
	empty_vec.assign(3, 8);
	std::cout << "size assigned: " << empty_vec.size() << '\n';
	std::cout << "content of assigned: " << empty_vec[0] << " " << empty_vec[1] << " " << empty_vec[2] << " " << "\n";

	swapity.push_back("its swappedddd omgg");
	letters.push_back("abc");
	letters.push_back("xyz");
	std::string s = "def";
	letters.push_back(std::move(s));

	std::cout << "push back: ";
	for (unsigned i=0; i<letters.size(); i++)
		std::cout << ' ' << letters.at(i);
	std::cout << '\n';

	std::cout << "pop back: ";
	letters.pop_back();
	for (unsigned i=0; i<letters.size(); i++)
		std::cout << ' ' << letters.at(i);
	std::cout << '\n';

	std::cout << "insert: ";
	it = letters.begin();
	letters.insert(it, "lolity");
	for (unsigned i=0; i<letters.size(); i++)
		std::cout << ' ' << letters.at(i);
	std::cout << '\n';

	std::cout << "erase: ";
	letters.erase(it);
	for (unsigned i=0; i<letters.size(); i++)
		std::cout << ' ' << letters.at(i);
	std::cout << '\n';

	std::cout << "swap: ";
	letters.swap(swapity);
	for (unsigned i=0; i<letters.size(); i++)
		std::cout << ' ' << letters.at(i);
	std::cout << '\n';

	std::cout << "clear: ";
	letters.clear();
	for (unsigned i=0; i<letters.size(); i++)
		std::cout << ' ' << letters.at(i);
	std::cout << '\n';

	alloc = letters.get_allocator();
}

int	main(void)
{
	//VECTOR
	ft::vector <int> my_empty_vec;
	std::vector <std::string> lol(5, "shrek");
	iterator_tests();
	capacity_tests();
	element_access_tests();
	modifiers_tests();

	int myints[] = {16,2,77,29};
	std::vector<int> fifth (myints, myints + sizeof(myints) / sizeof(int) );
	std::cout << "the contents of fifth are:";
	for (std::vector<int>::iterator it = fifth.begin(); it != fifth.end(); ++it)
		std::cout << ' ' << *it;
		std::cout << '\n';
	for (std::vector<std::string>::iterator it = lol.begin(); it != lol.end(); ++it)
	{
		std::cout << *it << std::endl;
	}
}

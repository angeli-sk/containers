/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   containers.cpp                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: akramp <akramp@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/20 15:48:31 by akramp        #+#    #+#                 */
/*   Updated: 2022/07/07 17:54:48 by akramp        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "./vector.hpp"
#include <vector>
#include <iostream>
#define ORANGE "\033[38;5;208m"
#define YELLOW "\033[38;5;221m"
#define WHITE	"\033[0m"
#define RED		"\033[38;5;196m"

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
	std::vector<int> vec_int;
	ft::vector<int> my_vec_int;
	std::vector<std::string> vec;
	ft::vector <std::string> my_vec;
	std::vector<float> vec_float;
	ft::vector <float> my_vec_float;
	std::vector<std::string>::iterator it;
	std::allocator<int> alloc;

	/*** EMPTY TESTS ***/
	std::cout << ORANGE << "\nEMPTY SIZE TESTS:" << WHITE << std::endl;
	std::cout << "size empty:	" << vec.size() << '\n';
	std::cout << "is vec empty?		";
	if (vec.empty() == true)
		std::cout << "yes!" << std::endl;
	else
		std::cout << "no!" << std::endl;
	std::cout << "is my_vec empty?	";
	if (my_vec.empty() == true)
		std::cout << "yes!" << std::endl;
	else
		std::cout << "no!" << std::endl;
	std::cout << YELLOW << "my size empty:	" << my_vec.size() << WHITE << '\n';
	std::cout << "size: 		" << vec.size() << '\n';
	std::cout << YELLOW << "my size:	" << my_vec.size() << WHITE << '\n';
	std::cout << "size empty:	" << vec_int.size() << '\n';
	std::cout << YELLOW << "my size empty: 	" << my_vec_int.size() << WHITE << '\n';
	std::cout << "size:		" << vec_int.size() << '\n';
	std::cout << YELLOW << "my size: 	" << my_vec_int.size() << WHITE << '\n';

	vec.push_back("abc");
	vec.push_back("xyz");
	vec.push_back("azula");
	my_vec.push_back("abc");
	my_vec.push_back("xyz");
	my_vec.push_back("azula");
	std::string s = "def";
	vec.push_back(std::move(s));
	my_vec.push_back(std::move(s));

	/*** PUSH_BACK TESTS ***/
	std::cout << ORANGE << "\nPUSH BACK TESTS:" << WHITE << std::endl;
	std::cout << "[";
	for (unsigned i=0; i<vec.size(); i++)
		std::cout << vec.at(i);
	std::cout << ']' << std::endl;
	std::cout << YELLOW << "[";
	for (unsigned i=0; i<my_vec.size(); i++)
		std::cout << my_vec[i];
	std::cout << "]" << WHITE << std::endl;
	std::cout << '\n';

	std::cout << "is vec empty?		";
	if (vec.empty() == true)
		std::cout << "yes!" << std::endl;
	else
		std::cout << "no!" << std::endl;
	std::cout << "is my_vec empty?	";
	if (my_vec.empty() == true)
		std::cout << "yes!" << std::endl;
	else
		std::cout << "no!" << std::endl;


	/*** ASSIGN TESTS ***/
	vec_int.assign(3, 8);
	std::cout << "\nsize assigned: " << vec_int.size() << '\n';
	std::cout << "content of assigned: " << vec_int[0] << " " << vec_int[1] << " " << vec_int[2] << " " << "\n";


	/*** SIZE TESTS ***/
	std::cout << ORANGE << "\nSIZE TESTS:" << WHITE << std::endl;
	std::cout << "size:		" << vec.size() << '\n';
	std::cout << YELLOW << "my size:	" << my_vec.size() << WHITE << '\n';
	std::cout << "size:		" << vec_int.size() << '\n';
	std::cout << YELLOW << "my size empty:	" << my_vec_int.size() << WHITE << '\n';
	std::cout << "max_size int:		" << vec_int.max_size() << '\n';
	std::cout << YELLOW << "my max_size int:	" << my_vec_int.max_size() << WHITE << '\n';
	std::cout << "max_size str:		" << vec.max_size() << '\n';
	std::cout << YELLOW << "my max_size str:	" << my_vec.max_size() << WHITE << '\n';
	std::cout << "max_size float:		" << vec_float.max_size() << '\n';
	std::cout << YELLOW << "my max_size float:	" << my_vec_float.max_size() << WHITE << '\n';

	/*** CAPACITY TESTS ***/
	std::cout << ORANGE << "\nCAPACITY TESTS:" << WHITE << std::endl;
	std::cout << "cap:		" << vec.capacity() << '\n';
	std::cout << YELLOW << "my cap:		" << my_vec.capacity() << WHITE << '\n';
	std::cout << "cap float:	" << vec_float.capacity() << '\n';
	std::cout << YELLOW << "my cap float:	" << my_vec_float.capacity() << WHITE << '\n';
	vec.push_back("abc"); //change this to resize later
	vec.push_back("xyz");
	vec.push_back("azula");
	my_vec.push_back("abc");
	my_vec.push_back("xyz");
	my_vec.push_back("azula");
	std::cout << "cap:		" << vec.capacity() << '\n';
	std::cout << YELLOW << "my cap:		" << my_vec.capacity() << WHITE << '\n';

	std::cout << "pop back: ";
	vec.pop_back();
	for (unsigned i=0; i<vec.size(); i++)
		std::cout << ' ' << vec.at(i);
	std::cout << '\n';

	std::cout << "insert: ";
	it = vec.begin();
	vec.insert(it, "lolity");
	for (unsigned i=0; i<vec.size(); i++)
		std::cout << ' ' << vec.at(i);
	std::cout << '\n';

	std::cout << "erase: ";
	vec.erase(it);
	for (unsigned i=0; i<vec.size(); i++)
		std::cout << ' ' << vec.at(i);
	std::cout << '\n';

	std::vector<std::string> swapity;
	swapity.push_back("omg its swapped!!??\n");
	std::cout << "swap: ";
	vec.swap(swapity);
	for (unsigned i=0; i<vec.size(); i++)
		std::cout << ' ' << vec.at(i);
	std::cout << '\n';

	std::cout << "clear: ";
	vec.clear();
	for (unsigned i=0; i<vec.size(); i++)
		std::cout << ' ' << vec.at(i);
	std::cout << '\n';

	alloc = vec.get_allocator();
}

int	main(void)
{
	//VECTOR
	std::vector <int> empty_vec;
	ft::vector <int> my_empty_vec;
	std::vector <int> num_vec(5, 7);
	ft::vector <int> my_num_vec(5, 7);
	std::vector <std::string> lol(5, "uwu");

	for (size_t i = 0; i < my_num_vec.size(); i++)
	{
		std::cout << YELLOW << my_num_vec[i] << WHITE << std::endl;
	}

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

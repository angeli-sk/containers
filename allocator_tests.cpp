#include <memory>
#include <iostream>
#include <string>

int main()
{
    std::allocator<std::string> myAllocator;

    std::string* str = myAllocator.allocate(3);										//AlLOCATE

    myAllocator.construct(str, "lemao ");											//CONSTRUCT
    myAllocator.construct(str + 1, "im the alloc ");
    myAllocator.construct(str + 2, "master\n");

    std::cout << str[0] << str[1] << str[2];
	std::cout << "my alloc address: " << myAllocator.address(*str) << std::endl;	//ADDRESS
	std::cout << "my max size is: " << myAllocator.max_size() << std::endl;			//MAXSIZE

    myAllocator.destroy(str);														//DESTROY
    myAllocator.destroy(str + 1);
    myAllocator.destroy(str + 2);

    myAllocator.deallocate(str, 3);													//DEALLOCATE



	return 0;
}



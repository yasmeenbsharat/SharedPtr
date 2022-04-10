#include <iostream>

#include "SharedPtr.h"

class Test {
public:
	void print() {
		std::cout << "Hello \n";
	}
	Test() {
		std::cout << "Test constructor\n";
	}~Test() {
		std::cout << "Test destructor\n";
	}
};

int main() {



	{ // allocate a Test (t) object and have it owned by ptr1
		Test* t = new Test;
		SharedPtr < Test > ptr1(t); {
			//make another SharedPtr pyr2 pointing to the Test(t) object
			SharedPtr < Test > ptr2 = ptr1; // create ptr2 using copy of ptr1 
			std::cout << "Killing ptr2 shared pointer\n";

		} // ptr2 goes out of scope here, and the allocated Test(t) is not destroyed
		std::cout << "Killing ptr1 shared pointer\n";

	} // ptr1 goes out of scope here, and the allocated Test(t) is destroyed

	std::cout << "----------------------------------------------------------------------------------------------------------\n";

	{ // allocate a Test (t1) object and have it owned by ptr1
		Test* t1 = new Test;
		SharedPtr < Test > ptr1(t1);
		SharedPtr < Test > ptr3 = ptr1;
		// make another SharedPtr ptr3 pointing to the Test (t1) object
		// Shared pointer reference counter (t1) should have increased now to 2
		Test* t2 = new Test; {

			SharedPtr < Test > ptr2(t2); // allocate a Test (t2) object and have it owned by ptr2
			ptr1 = ptr2;
			// make SharedPtr ptr2 pointing to the Test(t2) object
			// Shared pointer reference counter (t1) should have decreased now to 1
			// Shared pointer reference counter (t2) should have increased now to 2

			std::cout << "Killing ptr2 shared pointer\n";

		} // ptr2 goes out of scope here, and the allocated Test t2  is not destroyed

		std::cout << "Killing ptr1 shared pointer\n";
		std::cout << "Killing ptr3 shared pointer\n";
	}
	// ptr1 goes out of scope here, and the allocated Test(t2) is destroyed
	//ptr3 goes out of scope here, and the allocated Test(t1) is destroyed

	std::cout << "----------------------------------------------------------------------------------------------------------\n";

	// ptr1 pointing to an integer.
	int* t = new int(9);
	SharedPtr < int > ptr1(t);
	std::cout << " ptr1's value now: " << *ptr1 << std::endl;

	int* t2 = new int(100);
	ptr1 = t2; // ptr1 now pointing to t2 .
	std::cout << " ptr1's value now: " << *ptr1 << std::endl;

	if (ptr1) {
		std::cout << "Shared Pointer ptr1 is  not NULL " << std::endl;
	}
	else
		std::cout << "Shared Pointer ptr1 is NULL " << std::endl;

	return 0;
}
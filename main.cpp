#include "shared.hpp"

class Base 
{
	public:
	std::string name;
	Base(std::string n) : name(n) {};
};

int main() {

	 SharedPtr<int> a(new int{2});

	 SharedPtr<int> b(new int{5});

	 std::cout << "A adress -> " << a.get() << std::endl;
	 std::cout << "B adress -> " << b.get() << std::endl;

	 SharedPtr<int> c = a;

	 SharedPtr<int> d = b;

	 b.swap(a);

	 std::cout << "A adress -> " << a.get() << std::endl;
	 std::cout << "B adress -> " << b.get() << std::endl;

	 std::cout << "\n";
	 std::cout << a.get() << std::endl;

	 std::cout << a.user_count() << std::endl;
	 std::cout << "\n";

	 std::cout << b.get() << std::endl;

	 std::cout << b.user_count() << std::endl;
	 std::cout << "\n";

	 std::cout << c.get() << std::endl;

	 std::cout << c.user_count() << std::endl;
	 std::cout << "\n";

	 std::cout << d.get() << std::endl;

	 std::cout << d.user_count() << std::endl;
	 std::cout << "\n";

	 SharedPtr<Base> value(new Base("Hello World!"));

	 std::cout << value->name << std::endl;
	 std::cout << value.get() << "\n";
	 std::cout << value.user_count() << "\n\n";
}

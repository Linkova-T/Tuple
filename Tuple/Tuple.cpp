#include <iostream>
#include <tuple>

template < auto Index, auto Max, typename ... Types >
struct Tuple_Printer
{
	static void print(std::ostream& stream, const std::tuple < Types ... >& tuple)
	{
		stream << std::get <Index>(tuple) << (Index + 1 == Max ? "" : ", ");
		Tuple_Printer < Index + 1, Max, Types ... > ::print(stream, tuple);
	}
};

template < auto Max, typename ... Types >
struct Tuple_Printer < Max, Max, Types ... >
{
	static void print(std::ostream& stream, const std::tuple < Types ... >& tuple) {
	}
};

template < typename ... Types>
std::ostream& operator << (std::ostream& stream, const std::tuple < Types ... >& tuple)
{
	Tuple_Printer < 0, sizeof...(Types), Types ... > ::print(stream, tuple);

	return stream;
}

int main() {
	auto tuple = std::make_tuple("Alice", 2, "r", 343434);
	std::cout << "A little";
	return 0;
}

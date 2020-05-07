// weakPtr.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <cstdio>
#include <vector>
#include <functional>
#include <type_traits>

using void_fn_t = std::function<void()>;
using int_fn_t = std::function<void(int)>;
using int_float_fn_t = std::function<void(int, float)>;

template<typename FN_TYPE>
class FunctionComposite
{
public:
	static_assert(std::is_base_of<FN_TYPE, FN_TYPE>::value, "Only functions can be held with FunctionComposite.");
	
	void add(FN_TYPE callback)
	{
		fnList.emplace_back(callback);
	}
	
	template<typename... ARGS_TYPES>
	void operator()(ARGS_TYPES&&... args) const
	{
		for (const auto& fn : fnList)
			fn(std::forward<ARGS_TYPES>(args)...);
	}
protected:
	std::vector<FN_TYPE> fnList;
};

struct k
{};

struct Dispatcher
{
	FunctionComposite<k> non_fn;
	FunctionComposite<void_fn_t> fn_void;
	FunctionComposite<int_fn_t> fn_int;
	FunctionComposite<int_float_fn_t> fn_int_float;
};

int main()
{
	Dispatcher d;

	d.fn_void.add([](){ printf("fn_void callback\n"); });
	d.fn_int.add([](int i){ 	printf("fn_int callback: %d\n", i); });
	d.fn_int_float.add([](int i, float f){ printf("fn_int_float callback: %d, %f\n", i, f); });

	d.fn_void();
	d.fn_int(42);
	d.fn_int_float(1337, 3.1415f);
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file

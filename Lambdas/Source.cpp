#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

void ForEach(const std::vector<int>& values,  const std::function<void(int)>& func)
{
	for (int value : values)
		func(value);
}

int main()
{
	std::vector<int> values = { 1,5,4,2,4,3,45 };
	auto it =  std::find_if(values.begin(), values.end(), [](int value) {return value > 3; });
	std::cout << *it << std::endl;

	int a = 5;

	// auto lambda = [](int value) { std::cout << "Values = " << value << std::endl; };
	auto lambda = [=](int value) mutable { std::cout << "Values = " << a << std::endl; };

	ForEach(values, lambda);

	std::cin.get();
};
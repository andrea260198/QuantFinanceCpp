#include <iostream>
#include "include/DataFrame.h"


int main()
{
	std::vector<int> index = { 1, 2 };
	std::vector<std::string> columns = { "a", "b" };
	std::vector<std::vector<double>> data = { {1.0, 2.0},{3.0, 4.0} };


	DataFrame<int, std::string, double> df0(index, columns, data);

	DataFrame<int, std::string, double> df1({ 1, 2 }, { "first", "second" }, { {1.0, 2.0},{3.0, 4.0} });

	DataFrame<int, std::string, double> df2(df1);

	DataFrame<int, std::string, double> df3(df0);
	
    std::cout << df3.toString();

    df3.append(df0);

    std::cout << df3.toString();

	auto x = df2.iloc(1);

	printf("df2.iloc(1)\n");
	for (const auto& val : x)
	{
		std::cout << val << std::endl;
	}

    auto df4 = std::move(df3);

}

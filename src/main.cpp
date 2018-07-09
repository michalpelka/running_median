#include <iostream>
#include <stdlib.h>     /* abs */
#include <string>       /* stoi */
#include "running_median.hpp"
int main()
{

	std::string input("");
	RunningMedian runningMedian;
	do
	{
		std::cin >> input;
		try{
			int iinput = std::stoi(input);
			runningMedian.addElement(iinput);
			continue;
		}
		catch(std::invalid_argument& e){
		  // simply ignore
		}
		if (input.compare("m") ==0)
		{
			std::cout << runningMedian.getMedian() << " ";
		}
	}
	while (input.compare("q")!=0);
	std::cout << std::endl;

}

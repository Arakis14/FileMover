#include <iostream>
#include <string>
#include <filesystem>

std::string takeInput()
{
	std::string temp;
	std::cout << "Write a command, please." << std::endl;
	std::getline(std::cin, temp);
	return temp;
}

void fileMover()
{
	std::string temp;
	std::string fName;
	std::string source;
	std::string destinaton;

	while (source.empty())
	{
		if (std::filesystem::exists(temp = takeInput())) {
			source = temp;
			temp.clear();
			auto pos = source.find_last_of('\\');
			fName = source.substr(pos + 1);
			//debugg
			std::cout << "File name is:" << fName << "\n";
			std::cout << "Path & file exists." << "\n";
		}
		else
			std::cout << "Path or file doesn't exists." << "\n";
	}

	while (destinaton.empty())
	{
		if (std::filesystem::exists(temp = takeInput())) {
			destinaton = temp;
			temp.clear();
			std::cout << "Path exists." << "\n";
		}
		else
			std::cout << "Path doesn't exists." << "\n";
	}
	std::cout << "Would you like to move?\n";
	destinaton.rfind('\\\\') == (destinaton.size() - 1) ? destinaton += fName : destinaton = destinaton + "\\\\" + fName;
	
	//debugg
	std::cout << "Destination name is: " << destinaton << "\n";
	std::filesystem::rename(source, destinaton);
}

int main()
{
	std::cout << "Current path is " << std::filesystem::current_path() << '\n'; // (1)
	fileMover();
	std::cout << "Move succesfull!";
};
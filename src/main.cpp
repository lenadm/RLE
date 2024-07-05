#include <iostream>
#include <string>
#include <vector>


std::vector<std::string> deconstructor(std::string input);
std::string reconstructor(std::vector<std::string> text);

int main(void) {
	std::string input = "aaaaabbcd";
	std::vector<std::string> text = deconstructor(input);

	if (reconstructor(text) == input) {
		std::cout << "True";
	}
}

std::vector<std::string> deconstructor(std::string input) {
	std::vector<std::string> output;
	int counter = 1;
	
	for (int i = 1; i < input.size() + 1; ++i) {
	  	if (input[i] == input[i - 1]) {
			++counter;
		} else {
			std::string message = std::to_string(counter) + input[i - 1];
			output.push_back(message);
			counter = 1;
	  	}
	}
	return output;
}

std::string reconstructor(std::vector<std::string> text) {
	std::string output;

	for (int i = 0; i < text.size(); ++i) {
		std::string count;
		char character = text[i].back();

		for (int j = 0; j < text[i].size() - 1; ++j) {
			count.push_back(text[i][j]);
		}

		for (int j = 0; j < std::stoi(count); ++j) {
			output.push_back(character);
		}
	}
	
	return output;
}

		

﻿#include <string>
#include <vector>
#include <charconv>

/*
This file will only have things related with any kind of manipulation to std::string
*/
namespace P23 {
	
	/*
		Splits str in a std::string vector, delimiting each str by separator, and at max with maxplit sections.

		Ejemplo: str = "Hola mundo bla bla bla"
		split(str," ") -> {"Hola", "mundo", "bla", "bla", "bla"}
		split(str,"bla") -> {"Hola mundo ", " ", " ", ""}
		split(str," ", 3) -> {"Hola", "mundo", "bla bla bla"}
	*/
	std::vector<std::string> split(const std::string& str, const std::string& separator,const size_t& maxplit = std::string::npos){
		std::vector<std::string> ret;
		if(maxplit != std::string::npos) ret.reserve(maxplit);

		size_t curOffset = 0;
		size_t curPos = 0;
		while (ret.size() < maxplit-1 && (curPos=str.find(separator, curOffset)) != std::string::npos) {
			ret.push_back(str.substr(curOffset, curPos - curOffset));
			curOffset = curPos + separator.size();
		}
		ret.push_back(str.substr(curOffset));
		return ret;
	}

	/*
		Converts a vector of strings which contains numbers to a vector of numbers.

		Ejemplo: vec = {"1", "2", "3", "4"}
		from_string_vec_to_int_vec(vec) -> {1, 2, 3, 4}
	*/
	std::vector<int> from_string_vec_to_int_vec(std::vector<std::string> vec) {
		std::vector<int> ret;
		for (const auto& str : vec) {
			int num;
			std::from_chars(str.data(), str.data() + str.size(), num);
			ret.push_back(num);
		}
		return ret;
	}
}
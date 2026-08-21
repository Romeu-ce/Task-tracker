#include<iostream>
#include<fstream>
#include <nlohmann/json.hpp>


int main(void) {

	std::ifstream jsonFileStream("./test.json");    //reading the json
	nlohmann::json jsonData = nlohmann::json::parse(jsonFileStream);
	jsonData["data"] = 4;




	std::ofstream jsonFileStram("./test.json");   //modifying json
	jsonFileStram << jsonData.dump(4);
	std::cout << std::setw(4) << jsonData;

	jsonFileStream.close();
	return 0;

}
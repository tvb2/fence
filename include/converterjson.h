#pragma once

#include "nlohmann/json.hpp"

#include <vector>
#include <string>
#include <stdexcept>
#include <iostream>
#include <vector>

class ConverterJSON{
private:
	nlohmann::json data = nlohmann::json::array();
	std::vector<std::vector<int>> forest;
	std::vector<int> tree{0,0};
public:
	ConverterJSON(const std::string &filename);

	/**
	 * read data from config.json
	 * @return contents of config.json of json datatype
	 */
	void getData(const std::string &filename );

	std::vector<std::vector<int>> getForest();

	void addtree(std::vector<int> const &t);

	void updateJSON();

};
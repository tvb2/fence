#pragma once

#include "nlohmann/json.hpp"

#include <vector>
#include <string>
#include <stdexcept>
#include <iostream>
#include <vector>

class ConverterJSON{
private:
	nlohmann::json data;
	std::vector<std::vector<int>> forest;
	std::vector<int> tree;
public:
	ConverterJSON();

	/**
	 * read data from config.json
	 * @return contents of config.json of json datatype
	 */
	nlohmann::json getData();

	std::vector<std::vector<int>> getForest();



};
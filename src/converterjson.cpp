#include "converterjson.h"

#include <filesystem>
#include <map>
#include <fstream>
#include <thread>
#include <stdexcept>

//#define DEBUG_GETEXTDOCUMENTS


class ConfigMissingException : public std::exception {
public:
	const char *what() const noexcept override {
		return "config file is missing!\n";
	}
};
class WrongVersionException : public std::exception {
public:
	const char *what() const noexcept override {
		return "config.json has incorrect file version!\n";
	}
};
class FileNotValidException : public std::exception {
public:
	const char *what() const noexcept override {
		return "file not found or read error: ";
	}
};

	ConverterJSON::ConverterJSON () {
		//get data from config.json
		this->getData();
	}

	/**
	 * read data from config.json
	 * @return contents of config.json of json datatype
	 */
	nlohmann::json ConverterJSON::getData(){

			std::ifstream input;

			//throw error if config.json file is missing
			try {
				input.open("config.json");
				if (!input.is_open())
					throw ConfigMissingException();
			}
			catch(ConfigMissingException &x) {
				std::cerr << x.what();
			}
			input >> this->data;
			input.close();
			return data;
		}

	std::vector<std::vector<int>> ConverterJSON::getForest(){
		int x, y;
		for (auto item:data){
			this->tree[0] = item["x"];
			this->tree[1] = item["y"];
			this->forest.emplace_back(tree);
		}
		return forest;
	}
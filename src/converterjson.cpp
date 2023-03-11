#include "converterjson.h"

#include <filesystem>
#include <map>
#include <fstream>
#include <thread>
#include <stdexcept>
#include <string>

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

	ConverterJSON::ConverterJSON (const std::string &filename) {
		//get data from config.json
		this->getData(filename);
		this->getForest();
	}

	/**
	 * read data from config.json
	 * @return contents of config.json of json datatype
	 */
	void ConverterJSON::getData(const std::string &filename){
			std::ifstream input;
			//throw error if config.json file is missing
			try {
				input.open(filename);
				if (!input.is_open())
					throw ConfigMissingException();
			}
			catch(ConfigMissingException &x) {
				std::cerr << x.what();
			}
			input >> this->data;
			input.close();
			//update forest
			this->forest.clear();
			for (auto item:data){
			this->tree[0] = item["x"];
			this->tree[1] = item["y"];
			this->forest.emplace_back(tree);
		}
		tree[0] = 0; tree[1] = 0;
		}

	std::vector<std::vector<int>> ConverterJSON::getForest(){
		return this->forest;
	}

	void ConverterJSON::addtree(std::vector<int> const &t){
		this->forest.emplace_back(t);
		std::string name = "t"+std::to_string(forest.size());
		this->data[name]["x"] = t[0];
		this->data[name]["y"] = t[1];
		this->updateJSON();
	}

	void ConverterJSON::updateJSON(){
		std::ofstream update("config.json");
		update << std::setw(4) << std::fixed << std::setprecision(4) << data;
		update.close();
	}	

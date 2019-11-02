//
// Created by Dad on 11/1/19.
//

#include "KeyDefinitions.h"
#include <fstream>

static const char* valid_key_characters = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";

bool KeyDefinitions::load(const std::string &fileName) {
	keys.clear();
	std::ifstream in(fileName, std::ifstream::in);
	if (!in.is_open()) {
		return false;
	} else {
		std::string key;
		while (getline(in, key)) {
			if (key.length() < 1) {
				return false;
			} else if (key.find_first_not_of(valid_key_characters) != std::string::npos) {
				return false;
			} else {
				keys.push_back(key);
			}
		}
		in.close();
		return true;
	}
}

bool KeyDefinitions::isValidKey(const std::string &key) const {
	return std::find(keys.begin(), keys.end(), key) != keys.end();
}

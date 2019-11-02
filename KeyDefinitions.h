//
// Created by Dad on 11/1/19.
//

#ifndef CS253HW5_KEYDEFINITIONS_H
#define CS253HW5_KEYDEFINITIONS_H

#include <string>
#include <vector>

class KeyDefinitions {
public:
	bool load(const std::string& fileName);
	bool isValidKey(const std::string& key) const;

private:
	std::vector<std::string> keys;
};

#endif //CS253HW5_KEYDEFINITIONS_H

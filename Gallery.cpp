//
// Created by Dad on 11/1/19.
//

#include "Gallery.h"
#include "KeyDefinitions.h"

#include <stdexcept>

Gallery::Gallery(const string &s1, const string &s2)
: Gallery(std::vector<std::string>{ s1, s2 })
{

}

Gallery::Gallery(const string &s1, const string &s2, const string &s3)
: Gallery(std::vector<std::string>{ s1, s2, s3 })
{

}

Gallery::Gallery(const string &s1, const string &s2, const string &s3, const string &s4)
: Gallery(std::vector<std::string>{ s1, s2, s3, s4 })
{

}

Gallery::Gallery(const string &s1, const string &s2, const string &s3, const string &s4, const string &s5)
: Gallery(std::vector<std::string>{ s1, s2, s3, s4, s5 })
{

}

Gallery::Gallery(const string &s1, const string &s2, const string &s3, const string &s4, const string &s5, const string &s6)
: Gallery(std::vector<std::string>{ s1, s2, s3, s4, s5, s6 })
{

}

Gallery::Gallery(std::vector<std::string> files) {
	KeyDefinitions keys;
	for (size_t i = 0; i < files.size(); i++) {
		if (keys.load(files[i])) {
			files.erase(files.begin() + i, files.begin() + i + 1);
			//keys loaded, now load enemies


			return;
		}
	}
	throw std::runtime_error("Missing key file.");
}

Gallery::Gallery(const Gallery &other) {

}

Gallery &Gallery::operator=(const Gallery &other) {
	if (&other != this) {
		enemies = other.enemies;
	}
	return *this;
}

Gallery::~Gallery() {
}

void Gallery::read(const string &filename, const string &keyfilename) {
}

void Gallery::add(const Enemy &enemy) {

}

void Gallery::clear() {

}

void Gallery::size() const {

}

bool Gallery::empty() const {
	return false;
}

const Enemy* Gallery::get(size_t n) const {
	return nullptr;
}

Enemy* Gallery::get(size_t n) {
	return nullptr;
}

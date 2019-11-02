//
// Created by Dad on 11/1/19.
//

#include "Gallery.h"
#include <stdexcept>
#include <fstream>

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
	for (size_t i = 0; i < files.size(); i++) {
		try {
			std::string keyFileName = files[i];
			Enemy e(keyFileName);
			//if we got here, we found a key file.  We only get here at most once.
			//remove key file from the file list so the remaining list is just enemies
			files.erase(files.begin() + i, files.begin() + i + 1);
			//now load enemies files
			for (size_t j = 0; j < files.size(); j++) {
				read(files[i], keyFileName);
			}
			return;	// exit the outer for loop and constructor
		} catch (std::runtime_error& err) {
			// not a key file, so keep going.
		}
	}
	//we checked all the files and did not find a key file.  Kaboom!
	throw std::runtime_error("Missing key file.");
}

void Gallery::read(const string &filename, const string &keyfilename) {
	Enemy e(keyfilename);	//throws std::runtime_error if can't load key file
	std::ifstream enemyStream(filename);
	if(enemyStream.fail()){
		throw std::runtime_error("Gallery: Could not find file: " + filename + '\n');
	}
	bool enemyRead = e.read(enemyStream);
	while (enemyRead) {
		add(e);
		enemyRead = e.read(enemyStream);
	}
	enemyStream.close();
}

void Gallery::add(const Enemy& enemy) {
	Enemy localEnemy(enemy);
	localEnemy.setGallery(this);
	enemies.push_back(localEnemy);
}

void Gallery::clear() {
	enemies.clear();
}

size_t Gallery::size() const {
	return enemies.size();
}

bool Gallery::empty() const {
	return enemies.empty();
}

const Enemy* Gallery::get(size_t n) const {
	return &enemies[n];
}

Enemy* Gallery::get(size_t n) {
	return &enemies[n];
}


std::ostream& operator<<( std::ostream &os, const Gallery &gallery ) {
	for (size_t i = 0; i < gallery.size(); i++) {
		gallery.get(i)->write(os);
		os << '\n';
	}
	return os;
}

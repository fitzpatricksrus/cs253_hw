#include "Gallery.h"
#include <cassert>
#include <iostream>
#include <string>

using namespace std;

void show(const Enemy &e) {
	for (size_t i = 0; i < e.size(); i++) {
		pair<string, string> p = e[i];
		assert(e[p.first] == p.second);
		cout << p.first << ": " << p.second << '\n';
	}
}

void show(const Gallery &g) {
	for (size_t i = 0; i < g.size(); i++) {
		if (i > 0)
			cout << '\n';
		show(g[i]);
	}
}

int main() {
	Gallery vacant("pokékeys", "/dev/null");
	const Gallery monsters("pokémon", "pokékeys");

	assert(!vacant);
	assert(monsters);

	assert(vacant == vacant);
	assert(monsters == monsters);
	assert(!(monsters == vacant));
	assert(!(vacant == monsters));

	assert(!(vacant != vacant));
	assert(!(monsters != monsters));
	assert(monsters != vacant);
	assert(vacant != monsters);

	show(vacant);
	show(monsters);

	return 0;
}
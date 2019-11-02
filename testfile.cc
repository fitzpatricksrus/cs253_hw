//
// Created by Evan on 10/19/2019.
//
#include <iostream>
#include <fstream>
#include "Enemy.h"

using namespace std;

int main(int argc, char* argv[]) {
    Enemy e,f;
    std::ifstream keyStream("in1");
    e.read(keyStream);
    std::cout << e;
}

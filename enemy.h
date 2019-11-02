//
// Created by Evan on 10/19/2019.
//
#include <vector>

class enemy{
private:
    std::vector<std::string> keys, values, allowedkeys;
    bool nameflag = true, otherflag = true, linkflag = true;
public:
    enemy() = default;
    ~enemy() = default;
    enemy(std::string keyfile);
    bool read(std::istream &in);
    void write(std::ostream &out);
    void write(std::string filename);
    std::string field(std::string key);
    void show_name(bool b);
    void show_other(bool b);
    void show_link(bool b);
    void clear();
    size_t size();
    bool empty();

};
std::ostream &operator<<(std::ostream &out, enemy e);
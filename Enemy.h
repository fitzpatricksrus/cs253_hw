//
// Created by Evan on 10/19/2019.
//
#include <vector>

class Enemy {
private:
    std::vector<std::string> keys, values, allowedkeys;
    bool nameflag = true, otherflag = true, linkflag = true;
public:
    Enemy() = default;
    ~Enemy() = default;
    Enemy(std::string keyfile);
    bool read(std::istream &in);
    void write(std::ostream &out) const;
    void write(std::string filename) const;
    std::string field(std::string key) const;
    void show_name(bool b);
    void show_other(bool b);
    void show_link(bool b);
    void clear();
    size_t size() const;
    bool empty() const;

};
std::ostream &operator<<(std::ostream &out, Enemy e);
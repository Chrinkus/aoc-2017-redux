#ifndef TOWER_H
#define TOWER_H

#include <iostream>
#include <vector>
#include <unordered_map>
#include <string_view>

#include <program.h>

class Tower {
public:
    Tower() = delete;
    explicit Tower(size_t size) { tower.reserve(size); }

    Program* add_program(Program_data& data);
    Program* add_program(std::string& n, Program* p);
    Program* get_base() const { return base; }
    void set_base();

    size_t tower_size() const { return tower.size(); }
private:

    std::vector<Program> tower;
    Program* base = nullptr;
};

class Tower_factory {
public:
    explicit Tower_factory(std::istream& is);

    Tower create_tower();
    size_t data_size() const { return data_tbl.size(); }
private:
    Program* fetch_program(std::string_view name);

    std::vector<Program_data> data_tbl;
    std::unordered_map<std::string_view,Program*> location_tbl;
};

#endif // TOWER_H
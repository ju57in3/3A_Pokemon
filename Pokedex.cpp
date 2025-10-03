//
// Created by justine on 03/10/2025.
//

#include "Pokedex.h"
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <algorithm>

Pokedex& Pokedex::instance() {
    static Pokedex inst;
    return inst;
}

void Pokedex::loadFromCSV(const std::string& path) {
    std::ifstream f(path);
    if (!f) throw std::runtime_error("Cannot open pokedex CSV: " + path);

    std::string line; std::getline(f, line); // header
    while (std::getline(f, line)) {
        if (line.empty()) continue;
        std::stringstream ss(line);
        std::string cell;

        auto next = [&](std::string& out) {
            if (!std::getline(ss, out, ',')) out.clear();
        };

        std::string idStr, name, t1, t2, total, hp, atk, def_, spA, spD, spd, gen, leg;
        next(idStr); next(name); next(t1); next(t2); next(total); next(hp);
        next(atk); next(def_); next(spA); next(spD); next(spd); next(gen); next(leg);

        int id = std::stoi(idStr);
        auto p = std::make_unique<Pokemon>(
            id, name, t1, t2,
            std::stoi(hp), std::stoi(atk), std::stoi(def_),
            std::stoi(spA), std::stoi(spD), std::stoi(spd),
            std::stoi(gen),
            (leg == "True" || leg == "true" || leg == "1")
        );
        baseById[id] = std::move(p);
        idByName[name] = id;
        ids.push_back(id);
    }
}

std::unique_ptr<Pokemon> Pokedex::cloneById(int id) const {
    auto it = baseById.find(id);
    if (it == baseById.end()) return nullptr;
    return it->second->clone();
}

std::unique_ptr<Pokemon> Pokedex::cloneByName(const std::string& name) const {
    auto it = idByName.find(name);
    if (it == idByName.end()) return nullptr;
    return cloneById(it->second);
}
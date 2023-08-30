//
// Created by Oznak Banshee on 8/25/23.
//

#include "parser.h"
#include <fstream>
#include <iostream>
#include <sstream>

void Parser::ParseFile(const std::string& file_name) {

    std::ifstream input_file(file_name);
    std::string file_line;

    if (!input_file.is_open()) throw std::logic_error ("НЕ ОТКРЫЛ ФАЙЛ");

    while (std::getline(input_file, file_line)) {
        std::istringstream iss(file_line);
        std::string str_type;
        iss >> str_type;
        if (str_type == "v") {
            double x, y, z;
            if (iss >> x >> y >> z) {
                obj_info_.vertices.push_back(x);
                obj_info_.vertices.push_back(y);
                obj_info_.vertices.push_back(z);
            }
        } else if (str_type == "f") {
            std::string index;
            std::vector<int> f_line;
            while (iss >> index) {
                f_line.push_back(std::stoi(index));
            }
            for (size_t i = 0; i < f_line.size(); ++i) {
                obj_info_.facets.push_back(f_line[i] - 1);
                obj_info_.facets.push_back(f_line[(i + 1) % f_line.size()] - 1);
            }
            obj_info_.num_facets++;
        }
    }
    obj_info_.num_vertexes = static_cast<int> (obj_info_.vertices.size() / 3);
}

void Parser::PrintV() {
    for (size_t i = 0; i < obj_info_.vertices.size(); ++i) {
        std::cout << obj_info_.vertices[i] << " ";
        if (i % 3 == 2) std::cout << std::endl;
    }
}

void Parser::set_obj_info(const ObjData& obj) {
    obj_info_ = obj;
}

void Parser::set_new_vertices(const std::vector<double> &new_vertices) {
    obj_info_.vertices = new_vertices;
}

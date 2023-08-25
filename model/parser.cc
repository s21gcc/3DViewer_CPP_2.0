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
                obj_info_.vertexes.push_back(x);
                obj_info_.vertexes.push_back(y);
                obj_info_.vertexes.push_back(z);
            }
        } else if (str_type == "f") {
            int index;
            std::vector<int> f_line;
            while (iss >> index) {
                f_line.push_back(index);
            }
            for (size_t i = 0; i < f_line.size(); ++i) {
                obj_info_.facets.push_back(f_line[i]);
                obj_info_.facets.push_back(f_line[(i + 1) % f_line.size()]);
            }
            obj_info_.num_facets++;
        }
    }
    obj_info_.num_vertexes = static_cast<int> (obj_info_.vertexes.size() / 3);
}

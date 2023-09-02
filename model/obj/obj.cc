//
// Created by Oznak Banshee on 8/25/23.
//

#include "obj.h"
#include <fstream>
#include <iostream>
#include <sstream>

void Obj::ParseFile(const std::string& file_name) {
    
    obj_model_data_.vertices.clear();
    obj_model_data_.facets.clear();
    obj_model_data_.num_facets = 0;
    obj_model_data_.num_vertexes = 0;

    std::ifstream input_file(file_name);
    std::string file_line;

    if (!input_file.is_open()) return; // здесь был эксепшн на неоткрытый файл

    while (std::getline(input_file, file_line)) {
        std::istringstream iss(file_line);
        std::string str_type;
        iss >> str_type;
        if (str_type == "v") {
            double x, y, z;
            if (iss >> x >> y >> z) {
                obj_model_data_.vertices.push_back(x);
                obj_model_data_.vertices.push_back(y);
                obj_model_data_.vertices.push_back(z);
            }
        } else if (str_type == "f") {
            std::string index;
            std::vector<int> f_line;
            while (iss >> index) {
                f_line.push_back(std::stoi(index));
            }
            for (size_t i = 0; i < f_line.size(); ++i) {
                obj_model_data_.facets.push_back(f_line[i] - 1);
                obj_model_data_.facets.push_back(f_line[(i + 1) % f_line.size()] - 1);
            }
            obj_model_data_.num_facets++;
        }
    }
    obj_model_data_.num_vertexes = static_cast<int> (obj_model_data_.vertices.size() / 3);
}

void Obj::PrintV() {
    for (size_t i = 0; i < obj_model_data_.vertices.size(); ++i) {
        std::cout << obj_model_data_.vertices[i] << " ";
        if (i % 3 == 2) std::cout << std::endl;
    }
}

void Obj::set_obj_model_data(const ObjInfo& obj) {
    obj_model_data_ = obj;
}

void Obj::set_new_vertices(const std::vector<double> &new_vertices) {
    obj_model_data_.vertices = new_vertices;
}

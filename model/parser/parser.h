//
// Created by Oznak Banshee on 8/25/23.
//

#ifndef INC_3DVIEWER_CPP_2_0_PARSER_H
#define INC_3DVIEWER_CPP_2_0_PARSER_H

#include <vector>

struct ObjData {
    int num_vertexes;
    int num_facets;
    std::vector<double> vertices;
    std::vector<int> facets;
};

class Parser {
public:
    Parser () : obj_info_({0, 0, {}, {}}) {}
    void ParseFile(const std::string& file_name);
    ObjData GetInfo() {return obj_info_;}
    void PrintV();
    void set_obj_info(const ObjData& obj);
    void set_new_vertices(const std::vector<double>& new_vertices);

private:
    ObjData obj_info_;
};


#endif //INC_3DVIEWER_CPP_2_0_PARSER_H

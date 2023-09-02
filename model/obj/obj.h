//
// Created by Oznak Banshee on 8/25/23.
//

#ifndef INC_3DVIEWER_CPP_2_0_OBJ_H
#define INC_3DVIEWER_CPP_2_0_OBJ_H

#include <vector>

struct ObjInfo {
    int num_vertexes;
    int num_facets;
    std::vector<double> vertices;
    std::vector<int> facets;
};

class Obj {
public:
    Obj () : obj_model_data_({0, 0, {}, {}}) {}
    void ParseFile(const std::string& file_name);


    ObjInfo get_obj_model_data() {return obj_model_data_;}
    void PrintV();
    void set_obj_model_data(const ObjInfo& obj);
    void set_new_vertices(const std::vector<double>& new_vertices);

private:
    ObjInfo obj_model_data_;
};


#endif //INC_3DVIEWER_CPP_2_0_OBJ_H

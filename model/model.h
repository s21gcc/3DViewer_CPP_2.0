//
// Created by Oznak Banshee on 9/1/23.
//

#ifndef INC_3DVIEWER_CPP_2_0_MODEL_H
#define INC_3DVIEWER_CPP_2_0_MODEL_H

#include <memory>
#include "obj/obj.h"
#include "transformer/affine_transformer.h"

class Model {
public:
    Model();
    void ParseObj(const std::string& file_name);
    void Scale(double size);

    void RotateX(double angle);
    void RotateY(double angle);
    void RotateZ(double angle);

    void MoveX(double offset);
    void MoveY(double offset);
    void MoveZ(double offset);


    ObjInfo GetObjData() {return obj_ -> get_obj_model_data();}
    void PrintV() {obj_->PrintV();}

private:
    std::unique_ptr<Obj> obj_;
    std::unique_ptr<AffineTransformer> transformer_;
    void ApplyTransformation(const std::function<void(AffineTransformer&)>& transformation);

};


#endif //INC_3DVIEWER_CPP_2_0_MODEL_H

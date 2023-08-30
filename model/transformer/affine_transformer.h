//
// Created by Oznak Banshee on 8/29/23.
//

#ifndef INC_3DVIEWER_CPP_2_0_AFFINE_TRANSFORMER_H
#define INC_3DVIEWER_CPP_2_0_AFFINE_TRANSFORMER_H

#include <vector>

class AffineTransformer {
public:
    AffineTransformer() : transformed_vertices_() {};

    void Scale(double size);

    void RotateX(double angle);
    void RotateY(double angle);
    void RotateZ(double angle);

    void MoveX(double offset);
    void MoveY(double offset);
    void MoveZ(double offset);

    void set_transformed_vertices(const std::vector<double>& vertices);
    const std::vector<double>& get_transformed_vertices() {return transformed_vertices_;}
private:
    std::vector<double> transformed_vertices_;
};


#endif //INC_3DVIEWER_CPP_2_0_AFFINE_TRANSFORMER_H

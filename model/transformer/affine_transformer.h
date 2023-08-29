//
// Created by Oznak Banshee on 8/29/23.
//

#ifndef INC_3DVIEWER_CPP_2_0_AFFINE_TRANSFORMER_H
#define INC_3DVIEWER_CPP_2_0_AFFINE_TRANSFORMER_H

#include <vector>

class AffineTransformer {
public:
    void RotateX(double angle);
    void RotateY(double angle);
    void RotateZ(double angle);

    void Scale(double size);

    void MoveX(double offset);
    void MoveY(double offset);
    void MoveZ(double offset);
private:
    std::vector<int> trasformed_vertexies_;
};


#endif //INC_3DVIEWER_CPP_2_0_AFFINE_TRANSFORMER_H

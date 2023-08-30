//
// Created by Oznak Banshee on 8/29/23.
//

#include "affine_transformer.h"
#include <cmath>

void AffineTransformer::Scale(double size) {
    if (size != 0) {
        for (size_t i = 0; i < transformed_vertices_.size(); ++i) {
            transformed_vertices_[i] *= size;
        }
    }
}

void AffineTransformer::RotateX(double angle) {
    angle = angle * M_PI / 180;
    for (size_t i = 0; i < transformed_vertices_.size(); i += 3) {
        double x = transformed_vertices_[i];
        double y = transformed_vertices_[i + 1];
        transformed_vertices_[i] = x * std::cos(angle) + y * std::sin(angle);
        transformed_vertices_[i + 1] = -x * std::sin(angle) + y * std::cos(angle);
    }
}

void AffineTransformer::RotateY(double angle) {
    angle = angle * M_PI / 180;
    for (size_t i = 0; i < transformed_vertices_.size(); i += 3) {
        double x = transformed_vertices_[i];
        double y = transformed_vertices_[i + 1];
        transformed_vertices_[i] = x * std::cos(angle) + y * std::sin(angle);
        transformed_vertices_[i + 1] = -x * std::sin(angle) + y * std::cos(angle);
    }
}

void AffineTransformer::RotateZ(double angle) {
    angle = angle * M_PI / 180;
    for (size_t i = 0; i < transformed_vertices_.size(); i += 3) {
        double x = transformed_vertices_[i];
        double y = transformed_vertices_[i + 1];
        transformed_vertices_[i] = x * std::cos(angle) + y * std::sin(angle);
        transformed_vertices_[i + 1] = -x * std::sin(angle) + y * std::cos(angle);
    }
}

void AffineTransformer::MoveX(double offset) {
    for (size_t i = 0; i < transformed_vertices_.size(); i += 3) {
        transformed_vertices_[i] += offset;
    }
}

void AffineTransformer::MoveY(double offset) {
    for (size_t i = 1; i < transformed_vertices_.size(); i += 3) {
        transformed_vertices_[i] += offset;
    }
}

void AffineTransformer::MoveZ(double offset) {
    for (size_t i = 2; i < transformed_vertices_.size(); i += 3) {
        transformed_vertices_[i] += offset;
    }
}

void AffineTransformer::set_transformed_vertices(const std::vector<double>& vertices) {
    transformed_vertices_ = vertices;
}
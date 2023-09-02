//
// Created by Oznak Banshee on 9/1/23.
//

#include "model.h"

Model::Model() : obj_(std::make_unique<Obj>()), transformer_(std::make_unique<AffineTransformer>()) {
    // Ничего не нужно делать здесь, все уже проинициализировано
}

void Model::ParseObj(const std::string& file_name) {
    obj_->ParseFile(file_name);
}

void Model::ApplyTransformation(const std::function<void(AffineTransformer&)>& transformation) {
    transformer_->set_transformed_vertices(obj_->get_obj_model_data().vertices);
    transformation(*transformer_);
    obj_->set_new_vertices(transformer_->get_transformed_vertices());
}

void Model::Scale(double size) {
    ApplyTransformation([size](AffineTransformer& transformer) {
        transformer.Scale(size);
    });
}

void Model::RotateX(double angle) {
    ApplyTransformation([angle](AffineTransformer& transformer) {
        transformer.RotateX(angle);
    });
}

void Model::RotateY(double angle) {
    ApplyTransformation([angle](AffineTransformer& transformer) {
        transformer.RotateY(angle);
    });
}

void Model::RotateZ(double angle) {
    ApplyTransformation([angle](AffineTransformer& transformer) {
        transformer.RotateZ(angle);
    });
}

void Model::MoveX(double offset) {
    ApplyTransformation([offset](AffineTransformer& transformer) {
        transformer.MoveX(offset);
    });
}

void Model::MoveY(double offset) {
    ApplyTransformation([offset](AffineTransformer& transformer) {
        transformer.MoveY(offset);
    });
}

void Model::MoveZ(double offset) {
    ApplyTransformation([offset](AffineTransformer& transformer) {
        transformer.MoveZ(offset);
    });
}




//void Model::Scale(double size) {
//    transformer_->set_transformed_vertices(obj_->get_obj_model_data().vertices);
//    transformer_->Scale(size);
//    obj_->set_new_vertices(transformer_->get_transformed_vertices());
//}
//
//void Model::RotateX(double angle) {
//    transformer_->set_transformed_vertices(obj_->get_obj_model_data().vertices);
//    transformer_->RotateX(angle);
//    obj_->set_new_vertices(transformer_->get_transformed_vertices());
//}
//
//void Model::RotateY(double angle) {
//    transformer_->set_transformed_vertices(obj_->get_obj_model_data().vertices);
//    transformer_->RotateY(angle);
//    obj_->set_new_vertices(transformer_->get_transformed_vertices());
//}
//
//void Model::RotateZ(double angle) {
//    transformer_->set_transformed_vertices(obj_->get_obj_model_data().vertices);
//    transformer_->RotateZ(angle);
//    obj_->set_new_vertices(transformer_->get_transformed_vertices());
//}
//
//void Model::MoveX(double offset) {
//    transformer_->set_transformed_vertices(obj_->get_obj_model_data().vertices);
//    transformer_->MoveX(offset);
//    obj_->set_new_vertices(transformer_->get_transformed_vertices());
//}
//
//void Model::MoveY(double offset) {
//    transformer_->set_transformed_vertices(obj_->get_obj_model_data().vertices);
//    transformer_->MoveY(offset);
//    obj_->set_new_vertices(transformer_->get_transformed_vertices());
//}
//
//void Model::MoveZ(double offset) {
//    transformer_->set_transformed_vertices(obj_->get_obj_model_data().vertices);
//    transformer_->MoveZ(offset);
//    obj_->set_new_vertices(transformer_->get_transformed_vertices());
//}

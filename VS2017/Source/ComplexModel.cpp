#pragma once

#include "ComplexModel.h"


ComplexModel::ComplexModel(Shader const &shader)
    : m_Shader(shader),
    m_BaseTranslation(glm::mat4(1.0f)),
    m_BaseRotation(glm::mat4(1.0f)),
    m_BaseScale(glm::mat4(1.0f)),
    m_ModelMatrix(glm::mat4(1.0f))
{

}

ComplexModel::~ComplexModel()
{
    for (auto model : m_Models) {
        delete model;
    }
}

void ComplexModel::setTranslation(glm::vec3 translation)
{
    m_BaseTranslation = glm::translate(glm::mat4(1.0f), translation);
}

void ComplexModel::setRotation(float angle, glm::vec3 rotation)
{
    m_BaseRotation = glm::rotate(glm::mat4(1.0f), glm::radians(angle), rotation);
}

void ComplexModel::setScale(glm::vec3 scale)
{
    m_BaseScale = glm::scale(glm::mat4(1.0f), scale);
}

void ComplexModel::setTransforms(glm::vec3 Translation, float angle, glm::vec3 rotation, glm::vec3 scale) 
{
    setTranslation(Translation);
    setRotation(angle, rotation);
    setScale(scale);
    computeModelMatrix();
}

void ComplexModel::computeModelMatrix()
{
    m_ModelMatrix = m_BaseTranslation * m_BaseRotation * m_BaseScale;
}


void ComplexModel::draw()
{
    draw(m_Shader);
}

void ComplexModel::draw(Shader &shader) {
    shader.Bind();
    for (auto model : m_Models) {
        model->draw(shader, m_ModelMatrix);
    }
    for (auto complexModel : m_ComplexModels) {
        complexModel->draw(shader);
    }
}

void ComplexModel::addModel(Model* model)
{
    m_Models.push_back(model);
}

void ComplexModel::addComplexModel(ComplexModel* complexModel)
{
    m_ComplexModels.push_back(complexModel);
}

#include "../freeglut.3.0.0.v140.1.0.2/sources/GL/glut.h"

#include "model/drawers/drawer.h"


namespace model{

void Drawer::setColor(const utils::Color& color){
    this->color = color;
}

utils::Color Drawer::getColor() const{
    return color;
}

void Drawer::draw(const utils::Vector3& position, const utils::Quaternion& orientation) const{
    glShadeModel(GL_FLAT);
    glMaterialfv (GL_FRONT, GL_AMBIENT_AND_DIFFUSE, color.data());

    
    glBegin(GL_TRIANGLES);
    
    const auto& order = getOrder();                // Precomputed vertex order for drawing
    const auto& staticNormals = getStaticNormals(); // Precomputed face normals

    // Iterate through faces, using the static normal for each face
    for (size_t i = 0; i < order.size(); i += 3) {
        int faceIndex = i / 3;  // Assuming each face is represented by a triangle

        // Retrieve and rotate the precomputed normal
        utils::Vector3 rotatedNormal = orientation.rotate(staticNormals[faceIndex]);

        // Set the rotated normal for OpenGL
        glNormal3f(rotatedNormal.x, rotatedNormal.y, rotatedNormal.z);

        // Draw each vertex of the face
        for (int j = 0; j < 3; ++j) {
            const utils::Vector3& vertex = orientation.rotate(vertices[order[i + j]]);

            glVertex3f(vertex.x + position.x, vertex.y + position.y, vertex.z + position.z);
        }
    }
    glEnd();
}

};
#include <vector>

#include "../freeglut.3.0.0.v140.1.0.2/sources/GL/glut.h"
#include "model/drawers/axisDrawer.h"

namespace model{

const std::vector<int> AxisDrawer::order = {
    0, 1
};

const std::vector<int>& AxisDrawer::getOrder() const{
    return order;
}

const std::vector<utils::Vector3>& AxisDrawer::getStaticNormals() const {
    static const std::vector<utils::Vector3> empty_normals;
    return empty_normals;
}

AxisDrawer::AxisDrawer(utils::Vector3 axis, float length) : length(length){
    axis = axis.normalize();
    vertices.push_back(axis);
}

void AxisDrawer::draw(const utils::Vector3& position, const utils::Quaternion& orientation) const {
    // Disable lighting for drawing
    glDisable(GL_LIGHTING);

    // Calculate the endpoint of the line
    utils::Vector3 endPoint = position + orientation.rotate(vertices[0]) * length;

    glBegin(GL_LINES);
    {
        // Set the line color
        glColor4f(color.rgba[0], color.rgba[1], color.rgba[2], color.rgba[3]);

        // Draw the line from the starting position to the endpoint
        glVertex3f(position.x, position.y, position.z);
        glVertex3f(endPoint.x, endPoint.y, endPoint.z);
    }
    glEnd();

    // Re-enable lighting
    glEnable(GL_LIGHTING);
}


};
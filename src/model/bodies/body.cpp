
#include "../freeglut.3.0.0.v140.1.0.2/sources/GL/glut.h"
#include "model/bodies/body.h"
#include "utils/utils.h"
#include "utils/quaternion.h"


namespace model{

utils::Vector3 Body::getPosition() const{
    return position;
}

void Body::setPosition(const utils::Vector3& p) {
    position = p;
}

utils::Quaternion Body::getOrientation() const{
    return orientation;
}

void Body::setOrientation(const utils::Quaternion& o) {
    orientation = o;
}



}; // namespace model

// model::Body::Body(utils::Vector3 position){
//     this->position = position;
//     side = 1;
// }

// void model::Body::draw(){
//     glPushMatrix(); // Save the current transformation matrix

//     // Translate to the body's position
//     glTranslatef(position.x, position.y, position.z);

//     glBegin(GL_QUADS);
//     {
//         // X POSITIVO
//         auto aux = triangleNormal(utils::Vector3(side, 0, side), 
//                                 utils::Vector3(side, 0, 0), 
//                                 utils::Vector3(side, side, 0));
//         glNormal3f(aux.x, aux.y, aux.z);
//         glVertex3f(side, 0, 0);
//         glVertex3f(side, side, 0);
//         glVertex3f(side, side, side);
//         glVertex3f(side, 0, side);

//         // Y POSITIVO
//         glNormal3f(0, 1, 0);
//         glVertex3f(0, side, 0);
//         glVertex3f(0, side, side);
//         glVertex3f(side, side, side);
//         glVertex3f(side, side, 0);

//         // Z POSITIVO
//         glNormal3f(0, 0, 1);
//         glVertex3f(0, 0, side);
//         glVertex3f(side, 0, side);
//         glVertex3f(side, side, side);
//         glVertex3f(0, side, side);

//         // X 0
//         glNormal3f(-1, 0, 0);
//         glVertex3f(0, 0, 0);
//         glVertex3f(0, 0, side);
//         glVertex3f(0, side, side);
//         glVertex3f(0, side, 0);

//         // Y 0
//         glNormal3f(0, -1, 0);
//         glVertex3f(0, 0, 0);
//         glVertex3f(side, 0, 0);
//         glVertex3f(side, 0, side);
//         glVertex3f(0, 0, side);

//         // Z 0
//         glNormal3f(0, 0, -1);
//         glVertex3f(0, 0, 0);
//         glVertex3f(0, side, 0);
//         glVertex3f(side, side, 0);
//         glVertex3f(side, 0, 0);
//     }
//     glEnd();

//     glPopMatrix(); // Save the current transformation matrix

// }




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


};
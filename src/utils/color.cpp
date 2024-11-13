#include "utils/color.h"
#include <string>

utils::Color::Color() : rgba{0, 0, 0, 1} {}

utils::Color::Color(float r, float g, float b, float a) {
    this->rgba[0] = r;
    this->rgba[1] = g;
    this->rgba[2] = b;
    this->rgba[3] = a;
}

utils::Color::Color(int r, int g, int b, float a){
    if (r + g + b > 3){
        this->rgba[0] = rgba[0] / 255.0f;
        this->rgba[1] = rgba[1] / 255.0f;
        this->rgba[2] = rgba[2] / 255.0f;

    } else {
        this->rgba[0] = r;
        this->rgba[1] = g;
        this->rgba[2] = b;
    }
    this->rgba[3] = a;
}

utils::Color::Color(const std::string& hexValue, float a){
    this->rgba[0] = std::stoi(hexValue.substr(1, 2), nullptr, 16) / 255.0f;
    this->rgba[1] = std::stoi(hexValue.substr(3, 2), nullptr, 16) / 255.0f;
    this->rgba[2] = std::stoi(hexValue.substr(5, 2), nullptr, 16) / 255.0f;
    this->rgba[3] = a;
}

utils::Color::Color(const Color& other){
    this->rgba[0] = other.rgba[0];
    this->rgba[1] = other.rgba[1];
    this->rgba[2] = other.rgba[2];
    this->rgba[3] = other.rgba[3];
}

const GLfloat* utils::Color::data() const{
    return rgba;
}
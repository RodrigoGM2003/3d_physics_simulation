#include "utils/color.h"
#include <string>

utils::Color::Color() : r(0), g(0), b(0), a(1) {}

utils::Color::Color(float r, float g, float b, float a) {
    this->r = static_cast<float>(r);
    this->g = static_cast<float>(g);
    this->b = static_cast<float>(b);
    this->a = static_cast<float>(a);
}

utils::Color::Color(int r, int g, int b, float a){
    if (r + g + b > 3){
        this->r = r / 255.0;
        this->g = g / 255.0;
        this->b = b / 255.0;
    } else {
        this->r = r;
        this->g = g;
        this->b = b;
    }
    this->a = a;
}

utils::Color::Color(const std::string& hexValue, float a){
    this->r = std::stoi(hexValue.substr(1, 2), nullptr, 16) / 255.0f;
    this->g = std::stoi(hexValue.substr(3, 2), nullptr, 16) / 255.0f;
    this->b = std::stoi(hexValue.substr(5, 2), nullptr, 16) / 255.0f;
    this->a = a;
}

utils::Color::Color(const Color& other){
    this->r = other.r;
    this->g = other.g;
    this->b = other.b;
    this->a = other.a;
}
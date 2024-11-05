#ifndef COLOR_H
#define COLOR_H

#include <string>


namespace utils{
    /**
     * @brief A class representing a 3D vector
     */
    class Color {
    public:
        /**
         * @brief The x, y and z components of the vector
         */
        float r, g, b, a;

        /**
         * @brief Default constructor
         */
        Color();

        /**
         * @brief Creates a color with rgba values between 0 and 1
         * @param r The red value of the color
         * @param g The green value of the color
         * @param b The blue value of the color
         * @param a The alpha value of the color
         */
        Color(float r, float g, float b, float a = 1);

        /**
         * @brief Creates a color given the rgb values between 0 and 255
         * @param r The red value of the color
         * @param g The green value of the color
         * @param b The blue value of the color
         * @param a The alpha value of the color
         */
        Color(int r, int g, int b, float a = 1);

        /**
         * @brief Creates a color given a hex value
         * @param color The hex value of the color
         * @param a The alpha value of the color
         */
        Color(const std::string& color, float a = 1);

        /**
         * @brief Copy constructor
         * @param other The color to copy
         */
        Color(const Color& other);
    };
}


#endif
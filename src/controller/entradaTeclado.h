
#ifndef ENTRADA_TECLADO_H
#define ENTRADA_TECLADO_H

/**
 * @brief Funcion de captura de eventos pulsacion de tecla correspondiente a caracter alfanumerico
 * @param k codigo ascii del caracter
 * @param x posicion del cursor en coordenadas de pantalla cuando se pulso la tecla
 * @param y posicion del cursor en coordenadas de pantalla cuando se pulso la tecla
 * @return void
 * 
 * Esta funcion es llamada por el sistema cuando se pulsa una tecla normal
 */
void letra (unsigned char k, int x, int y);


/**
 * @brief Funcion de captura de eventos pulsacion de caracteres especiales y de control
 * @param k codigo ascii del caracter
 * @param x posicion del cursor en coordenadas de pantalla cuando se pulso la tecla
 * @param y posicion del cursor en coordenadas de pantalla cuando se pulso la tecla
 * @return void
 * 
 * Esta funcion es llamada por el sistema cuando se pulsa una tecla especial
 */
void especial (int k, int x, int y);

#endif
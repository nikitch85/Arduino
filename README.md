# Arduino
The code which counts the number of buttons pushed was only tested on Arduini Uno (clone) with 1 digit 7 segment display (with dot)
with common anode (+).
Please note the pin connections.
The file 1_digit segment_hex.xlsx contans the pin mapping to the leds and also decimal to binary and to hex which are used in my code.

 *       E
 *    -------
 *  F |     |
 *    |  G  | D
 *    -------
 *    |     |
 *  A |     | C
 *    -------
 *        B   * DT
 *     For mapping open the file 1_digit segment_hex.xlsx


 *      The following is the scematic of pin mapping.
 *      6
 *    -------
 *  7 |     |
 *    |  8  | 5
 *    -------
 *    |     |
 *  2 |     | 4
 *    -------
 *        3   * 9
 *     

#include "./BinaryFace.h"
#include "Watchy_GSR.h" // for font

#include <bitset>

String BinaryFace::name(){
    return "Binary";
};

void BinaryFace::draw(uint8_t hour, uint8_t minute, GxEPD2_BW<GxEPD2_154_D67, GxEPD2_154_D67::HEIGHT>& display){

    // Zeichne das Grid
    display.fillScreen(GxEPD_WHITE); // Hintergrund weiß
    display.setFont(&aAntiCorona11pt7b);

    int cellSize = 33; // Breite der Zellen
    int cellHeight = 50; // Höhe der Zellen

    int rownumber = 0;
    int valuesRow1[6] = {0, 16, 8, 4, 2, 1};
    for (int j = 1; j < 6; ++j) {
        // Berechne die Position
        int x = j * cellSize;
        if (valuesRow1[j]<10) x += 10;
        int y = rownumber * cellHeight + cellHeight/2;

        // Zeichne den Wert in der Zelle
        display.setCursor(x, y); // Position für den Text
        display.print(valuesRow1[j]);
    }

    rownumber++;
    // Hours in binary
    for (int j = 1; j < 6; ++j) {
        int bit = (hour >> (4 - (j-1))) & 1; // hole das 4-j. bit
        
        display.drawRect(j * cellSize, rownumber*cellHeight, cellSize, cellSize, GxEPD_BLACK); // Rechteck zeichnen
        if (bit) {
            display.fillRect(j * cellSize, rownumber*cellHeight, cellSize, cellSize, GxEPD_BLACK); // Fülle das Rechteck, wenn das Bit 1 ist
        }
    }

    rownumber++;
    int valuesRow3[6] = {32, 16, 8, 4, 2, 1};
    for (int j = 0; j < 6; ++j) {
        // Berechne die Position
        int x = j * cellSize;
        if (valuesRow3[j]<10) x += 10;
        int y = rownumber * cellHeight + cellHeight/2;
        // Zeichne Wert in die Zelle
        display.setCursor(x, y); // Position für den Text
        display.print(valuesRow3[j]);
    }

    // Minutes in binary
    rownumber++;
    for (int j = 0; j < 6; ++j) {
        int bit = (minute >> (5 - j)) & 1; // Hole das j-te Bit der Minuten
        display.drawRect(j * cellSize, rownumber*cellHeight, cellSize, cellSize, GxEPD_BLACK); // Rechteck zeichnen
        if (bit) {
            display.fillRect(j * cellSize, rownumber*cellHeight, cellSize, cellSize, GxEPD_BLACK); // Fülle das Rechteck, wenn das Bit 1 ist
        }
    }
};

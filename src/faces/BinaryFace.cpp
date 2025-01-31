#include "./BinaryFace.h"
#include "Watchy_GSR.h" // for font

String BinaryFace::name(){
    return "Binary";
};

void BinaryFace::draw(uint8_t hour, uint8_t minute, GxEPD2_BW<GxEPD2_154_D67, GxEPD2_154_D67::HEIGHT>& display){

    // Zeichne das Grid
    display.fillScreen(GxEPD_WHITE); // Hintergrund weiß
    display.setFont(&aAntiCorona11pt7b);

    int cellSize = 30; // Breite der Zellen
    int cellHeight = 50; // Höhe der Zellen

    // Zeile 1:
    int i = 0;
    int valuesRow1[6] = {0, 16, 8, 4, 2, 1};
    for (int j = 1; j < 6; ++j) {
        // Berechne die Position
        int x = j * cellSize;
        if (valuesRow1[j]<10) x += 10;
        int y = i * cellHeight + cellHeight/2;

        // Zeichne den Wert in der Zelle
        display.setCursor(x, y); // Position für den Text
        display.print(valuesRow1[j]);
    }

    i++;
    // Zeile 2: Stunden in binärer Form (4 Zellen, ganz links leer)
    for (int j = 1; j < 6; ++j) {
        int bit = (hour >> (3 - j)) & 1; // Hole das j-te Bit der Stunden
        display.drawRect(j * cellSize, i*cellHeight, cellSize, cellSize, GxEPD_BLACK); // Rechteck zeichnen
        if (bit) {
            display.fillRect(j * cellSize, i*cellHeight, cellSize, cellSize, GxEPD_BLACK); // Fülle das Rechteck, wenn das Bit 1 ist
        }
    }

    // Zeile 3: 
    i++;
    int valuesRow3[6] = {32, 16, 8, 4, 2, 1};
    for (int j = 0; j < 6; ++j) {
        // Berechne die Position
        int x = j * cellSize;
        if (valuesRow3[j]<10) x += 10;
        int y = i * cellHeight + cellHeight/2;
        // Zeichne Wert in die Zelle
        display.setCursor(x, y); // Position für den Text
        display.print(valuesRow3[j]);
    }

    // Zeile 4: Minuten in binärer Form (6 Zellen)
    i++;
    for (int j = 0; j < 6; ++j) {
        int bit = (minute >> (5 - j)) & 1; // Hole das j-te Bit der Minuten
        display.drawRect(j * cellSize, i*cellHeight, cellSize, cellSize, GxEPD_BLACK); // Rechteck zeichnen
        if (bit) {
            display.fillRect(j * cellSize, i*cellHeight, cellSize, cellSize, GxEPD_BLACK); // Fülle das Rechteck, wenn das Bit 1 ist
        }
    }
};

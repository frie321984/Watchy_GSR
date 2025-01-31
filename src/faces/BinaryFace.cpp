#include "./BinaryFace.h"

String BinaryFace::name(){
    return "Binary";
};

void BinaryFace::draw(uint8_t hour, uint8_t minute, GxEPD2_BW<GxEPD2_154_D67, GxEPD2_154_D67::HEIGHT>& display){

    // Zeichne das Grid
    display.fillScreen(GxEPD_WHITE); // Hintergrund weiß

    int cellSize = 30; // Breite der Zellen

    // Zeile 1:
    int i = 0;
    for (int j = 0; j < 4; ++j) {
        // Berechne die Position
        int x = j * cellSize;
        int y = i * cellSize;

        display.drawRect(j * cellSize, i, cellSize, cellSize, GxEPD_BLACK); // Rechteck zeichnen
        // Zeichne den Wert in der Zelle
        display.setCursor(x + 10, y + 30); // Position für den Text
        display.print(j);
    }

    i++;
    // Zeile 2: Stunden in binärer Form (4 Zellen, ganz links leer)
    for (int j = 0; j < 4; ++j) {
        int bit = (hour >> (3 - j)) & 1; // Hole das j-te Bit der Stunden
        display.drawRect((j + 1) * cellSize, i*50, cellSize, cellSize, GxEPD_BLACK); // Rechteck zeichnen
        if (bit) {
            display.fillRect((j + 1) * cellSize, i*50, cellSize, cellSize, GxEPD_BLACK); // Fülle das Rechteck, wenn das Bit 1 ist
        }
    }

    // Zeile 3: 
    i++;
    for (int j = 0; j < 6; ++j) {
        // Berechne die Position
        int x = j * cellSize;
        int y = i * cellSize;
        display.drawRect(j * cellSize, i*50, cellSize, cellSize, GxEPD_BLACK); // Rechteck zeichnen
        // Zeichne Wert in die Zelle
        display.setCursor(x + 10, y + 30); // Position für den Text
        display.print(j);
    }

    // Zeile 4: Minuten in binärer Form (6 Zellen)
    i++;
    for (int j = 0; j < 6; ++j) {
        int bit = (minute >> (5 - j)) & 1; // Hole das j-te Bit der Minuten
        display.drawRect(j * cellSize, i*50, cellSize, cellSize, GxEPD_BLACK); // Rechteck zeichnen
        if (bit) {
            display.fillRect(j * cellSize, i*50, cellSize, cellSize, GxEPD_BLACK); // Fülle das Rechteck, wenn das Bit 1 ist
        }
    }
};

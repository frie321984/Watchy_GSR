# Bild 200x200 größe
# gimp bearbeiten: Bild->Modus->reduzierte Farben (1)
# kontrast hochdrehen
# export als jpg
# dann mit diesem script in c umwandeln: python3 convert-to-c.py > out.c

from PIL import Image

# Bild öffnen
image = Image.open('antique-simple-kontrast.jpg')

# Bild auf 200x200 skalieren (falls nötig)
image = image.resize((200, 200))

# In Schwarz-Weiß umwandeln
image = image.convert('1')  # 1-Bit Schwarz-Weiß

# Pixelwerte in ein C-Array umwandeln
pixels = list(image.getdata())
c_array = "const unsigned char image_data[] = {\n"
count = 0

for i in range(0, len(pixels), 8):
    byte = 0
    for j in range(8):
        if i + j < len(pixels):
            byte = (byte << 1) | (1 if pixels[i + j] == 0 else 0)  # 0 für Schwarz, 1 für Weiß
    c_array += f"0x{byte:02X}, "
    count += 1

    # Zeilenumbruch nach 100 Werten
    if count % 100 == 0:
        c_array += "\n"

c_array += "\n};"

print(c_array)

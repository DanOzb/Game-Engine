INSTRUKTION

Förutsättningar:
- g++ med stöd för C++23
- SDL3, SDL3_image, SDL3_ttf installerade

Bygga och köra:
1. öppna Makefile och avkommentera rätt INCLUDE_PATHS, LIBRARY_PATHS och LINKER_FLAGS för din plattform (Mac/Windows/Linux)
2. kör: make
3. kör: ./build/debug/play

Resursfiler:
- sökväg definierad i include/Constants.h: "./resources/"
- typsnitt: resources/fonts/ARIAL.TTF
- bilder: resources/images/


TESTBESKRIVNING

[TODO: Beskriv spelets syfte]

Kontroller:
- W / Pil upp: rör spelaren uppåt
- S / Pil ner: rör spelaren nedåt
- A / Pil vänster: rör spelaren vänster
- D / Pil höger: rör spelaren höger

[TODO: Beskriv hur spelaren får poäng, vad som händer vid kollision, osv.]

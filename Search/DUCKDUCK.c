#include "duckduck.h"
#include <stdio.h>
#include <stdlib.h>
#include "../MemoryV/v.h"
#include "../MemoryVS/vs.h"

void SF() {
    char TC[1003];
    sprintf(TC, "curl -s -A \"Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/122.0.0.0 Safari/537.36\" \"https://html.duckduckgo.com/html/?q=%s\" > temp.txt", Search);
    system(TC);

    FILE * TB = fopen("temp.txt", "r");
    if (TB == NULL) {
        printf("[!] Erro: Falha ao abrir os dados baixados.\n");
        return;
    }

    int bytes_lidos = fread(Import, sizeof(char), 4999, TB);
    Import[bytes_lidos] = '\0';
    fclose(TB);

}

#include <stdio.h>

int main() {
    FILE *fp;
    char store;

    fp = fopen("a.out", "rb+");
    if (!fp) {
        perror("fopen");
        return 1;
    }

    fseek(fp, 0, SEEK_SET);

    unsigned char val = 0x7F;
    fwrite(&val, 1, 1, fp);

    fseek(fp, 0, SEEK_SET);
    store = fgetc(fp);
    printf("%x\n", store);

    fclose(fp);
    return 0;
}

#include <stdio.h>
#include <stdlib.h>

void delete_section_header(__uint16_t entries, __uint16_t header_size, __uint64_t start, FILE *fp) {
    fseek(fp, start, SEEK_SET);
    unsigned char *rubbish = calloc(header_size, sizeof(unsigned char));

    for (int i = 1; i <= entries; i++) {
        fwrite(rubbish, sizeof(unsigned char), header_size, fp);
        fseek(fp, header_size, SEEK_CUR);
    }

    printf("Successfully nullified section headers\n");
}

int main() {
    FILE *fp;
    unsigned char *section_header_start = malloc(8);
    unsigned char *section_header_size = malloc(2);
    unsigned char *section_header_number = malloc(2);

    __uint16_t no_of_entries, header_size;
    __uint64_t start;

    fp = fopen("a.out", "rb+");
    if (!fp) {
        perror("fopen");
        return 1;
    }

    fseek(fp, 0x28, SEEK_SET);
    fread(section_header_start, 1, 8, fp);

    fseek(fp, 0x3A, SEEK_SET);
    fread(section_header_size, 1, 2, fp);

    fseek(fp, 0x3C, SEEK_SET);
    fread(section_header_number, 1, 2, fp);

    no_of_entries = section_header_number[0] | (section_header_number[1] << 8);
    header_size = section_header_size[0] | (section_header_size[1] << 8);

    start = (section_header_start[0]) |
    (section_header_start[1] << 8) |
    (section_header_start[2] << 16) |
    (section_header_start[3] << 24) |
    (section_header_start[4] << 32) |
    (section_header_start[5] << 40) |
    (section_header_start[6] << 48) |
    (section_header_start[7] << 56);

    free(section_header_number);
    free(section_header_size);
    free(section_header_start);

    printf("Start: %lx\n", start);
    printf("Header size: %x\n", header_size);
    printf("No: of entries: %u\n", no_of_entries);

    delete_section_header(no_of_entries, header_size, start, fp);

    fclose(fp);

    return 0;
}

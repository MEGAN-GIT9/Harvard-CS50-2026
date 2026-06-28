#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int main(int argc, char *argv[])
{
    // Accept a single command-line argument
    if (argc != 2)
    {
        printf("Usage: ./recover FILE\n");
        return 1;
    }

    // Open the memory card
    FILE *raw_file = fopen(argv[1], "r");
    if (raw_file == NULL)
    {
        return 1;
    }

    // Create a buffer for a block of data
    uint8_t buffer[512];
    int count = 0;
    char filename[8];
    FILE *img = NULL;

    // While there's still data left to read from the memory card
    while (fread(buffer, 1, 512, raw_file) == 512)
    {
        // Create JPEGs from the data
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            if (img != NULL)
            {
                fclose(img);
            }

            sprintf(filename, "%03i.jpg", count);
            img = fopen(filename, "w");
            count++;
        }

        if (img != NULL)
        {
            fwrite(buffer, 1, 512, img);
        }
    }

    // Close remaining files
    if (img != NULL)
    {
        fclose(img);
    }
    fclose(raw_file);

    return 0;
}

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

typedef uint8_t BYTE;
const int block_size = 512;

int main(int argc, char *argv[])
{
    // Ensure proper usage
    if (argc != 2)
    {
        printf("Usage: ./recover IMAGE\n");
        return 1;
    }

    // Open image for reading
    FILE *input = fopen(argv[1], "r");
    if (input == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }

    BYTE buffer[block_size];
    int n = 0;
    char filename[8 * sizeof(char)];
    FILE *output = NULL;

    while (fread(buffer, 1, block_size, input) == block_size)
    {
        if (buffer[0] == 0xff &&
            buffer[1] == 0xd8 &&
            buffer[2] == 0xff &&
            buffer[3] >= 0xe0 && buffer[3] <= 0xef)
        {

            // Close the last opened file
            if (n > 0)
            {
                fclose(output);
            }

            // Make name for the nth file
            sprintf(filename, "%03d.jpg", n);

            // Open the nth file
            output = fopen(filename, "w");
            if (output == NULL)
            {
                printf("Could not open file.\n");
                return 1;
            }
            n++;
        }

        if (output != NULL)
        {
            fwrite(buffer, 1, block_size, output);
        }
    }
    fclose(output);
    fclose(input);

    return 0;
}
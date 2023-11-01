#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int average = round((image[i][j].rgbtBlue + image[i][j].rgbtGreen + image[i][j].rgbtRed) / (float)3);
            image[i][j].rgbtBlue = average;
            image[i][j].rgbtGreen = average;
            image[i][j].rgbtRed = average;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE temp[height][width];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width / 2; j++)
        {
            temp[i][j] = image[i][j];
            image[i][j] = image[i][width - (j + 1)];
            image[i][width - (j + 1)] = temp[i][j];
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE temp[height][width];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            temp[i][j] = image[i][j];
        }
    }
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            float sum_blue = 0;
            float sum_green = 0;
            float sum_red = 0;
            int counter = 0;

            //Deal with the 3*3 box
            for (int r = -1; r < 2; r++)
            {
                for (int c = -1; c < 2; c++)
                {
                    if (i + r < 0 || i + r >= height)
                    {
                        continue;
                    }
                    if (j + c < 0 || j + c >= width)
                    {
                        continue;
                    }
                    sum_blue += temp[i + r][j + c].rgbtBlue;
                    sum_green += temp[i + r][j + c].rgbtGreen;
                    sum_red += temp[i + r][j + c].rgbtRed;
                    counter++;
                }
            }

            // Calculate the average value
            image[i][j].rgbtBlue = round(sum_blue / counter);
            image[i][j].rgbtGreen = round(sum_green / counter);
            image[i][j].rgbtRed = round(sum_red / counter);
        }
    }
    return;
}

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE temp[height][width];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            temp[i][j] = image[i][j];
        }
    }

    int Gx[3][3] = {{-1, 0, 1}, {-2, 0, 2}, {-1, 0, 1}};
    int Gy[3][3] = {{-1, -2, -1}, {0, 0, 0}, {1, 2, 1}};

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            float Gx_blue = 0;
            float Gx_green = 0;
            float Gx_red = 0;
            float Gy_blue = 0;
            float Gy_green = 0;
            float Gy_red = 0;

            //Deal with the 3*3 box
            for (int r = -1; r < 2; r++)
            {
                for (int c = -1; c < 2; c++)
                {
                    if (i + r < 0 || i + r >= height)
                    {
                        continue;
                    }
                    if (j + c < 0 || j + c >= width)
                    {
                        continue;
                    }
                    Gx_blue += temp[i + r][j + c].rgbtBlue * Gx[1 + r][1 + c];
                    Gx_green += temp[i + r][j + c].rgbtGreen * Gx[1 + r][1 + c];
                    Gx_red += temp[i + r][j + c].rgbtRed * Gx[1 + r][1 + c];
                    Gy_blue += temp[i + r][j + c].rgbtBlue * Gy[1 + r][1 + c];
                    Gy_green += temp[i + r][j + c].rgbtGreen * Gy[1 + r][1 + c];
                    Gy_red += temp[i + r][j + c].rgbtRed * Gy[1 + r][1 + c];
                }
            }

            // Calculate the new values of pixels
            int blue = round(sqrt(Gx_blue * Gx_blue + Gy_blue * Gy_blue));
            int green = round(sqrt(Gx_green * Gx_green + Gy_green * Gy_green));
            int red = round(sqrt(Gx_red * Gx_red + Gy_red * Gy_red));
            if (blue > 255)
            {
                blue = 255;
            }
            if (green > 255)
            {
                green = 255;
            }
            if (red > 255)
            {
                red = 255;
            }

            image[i][j].rgbtBlue = blue;
            image[i][j].rgbtGreen = green;
            image[i][j].rgbtRed = red;
        }
    }
    return;
}
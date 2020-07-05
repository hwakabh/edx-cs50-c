#include "helpers.h"
#include <math.h>
#include <string.h>


// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    // Calcurate average of RGM of each pixel and set each RGB value to them
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            float rgb_average = ((float) image[i][j].rgbtRed + (float) image[i][j].rgbtGreen + (float) image[i][j].rgbtBlue) / 3;
            image[i][j].rgbtRed = round(rgb_average);
            image[i][j].rgbtGreen = round(rgb_average);
            image[i][j].rgbtBlue = round(rgb_average);
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            // Calcurate filtered value for each pixel
            float sepia_red = image[i][j].rgbtRed * 0.393 + image[i][j].rgbtGreen * 0.769 + image[i][j].rgbtBlue * 0.189;
            float sepia_green = image[i][j].rgbtRed * 0.349 + image[i][j].rgbtGreen * 0.686 + image[i][j].rgbtBlue * 0.168;
            float sepia_blue = image[i][j].rgbtRed * 0.272 + image[i][j].rgbtGreen * 0.534 + image[i][j].rgbtBlue * 0.131;

            // Validate each RGB exceeded the int range or not
            if (round(sepia_red) >= 255) {
                sepia_red = 255;
            }
            if (round(sepia_green) >= 255) {
                sepia_green = 255;
            }
            if (round(sepia_blue) >= 255) {
                sepia_blue = 255;
            }

            // Update RBGs for each pixel
            image[i][j].rgbtRed = round(sepia_red);
            image[i][j].rgbtGreen = round(sepia_green);
            image[i][j].rgbtBlue = round(sepia_blue);
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++) {
        for (int j = 0, w = width / 2; j < w; j++) {
            RGBTRIPLE copy = image[i][j];
            image[i][j] = image[i][width - 1 - j];
            image[i][width - 1 - j] = copy;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE pixel[height][width];
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            pixel[i][j] = image[i][j];
        }
    }

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            int counter = 0;
            int red = 0;
            int green = 0;
            int blue = 0;

            red += pixel[i][j].rgbtRed;
            green += pixel[i][j].rgbtGreen;
            blue += pixel[i][j].rgbtBlue;
            counter++;

            if (i - 1 >= 0 && j - 1 >= 0) {
                red += pixel[i - 1][j - 1].rgbtRed;
                green += pixel[i - 1][j - 1].rgbtGreen;
                blue += pixel[i - 1][j - 1].rgbtBlue;
                counter++;
            }
            if (i - 1 >= 0 && j >= 0) {
                red += pixel[i - 1][j].rgbtRed;
                green += pixel[i - 1][j].rgbtGreen;
                blue += pixel[i - 1][j].rgbtBlue;
                counter++;
            }
            if (i - 1 >= 0 && j + 1 < width) {
                red += pixel[i - 1][j + 1].rgbtRed;
                green += pixel[i - 1][j + 1].rgbtGreen;
                blue += pixel[i - 1][j + 1].rgbtBlue;
                counter++;
            }
            if (j - 1 >= 0) {
                red += pixel[i][j - 1].rgbtRed;
                green += pixel[i][j - 1].rgbtGreen;
                blue += pixel[i][j - 1].rgbtBlue;
                counter++;
            }
            if (j + 1 < width) {
                red += pixel[i][j + 1].rgbtRed;
                green += pixel[i][j + 1].rgbtGreen;
                blue += pixel[i][j + 1].rgbtBlue;
                counter++;
            }
            if (i + 1 < height && j - 1 >= 0) {
                red += pixel[i + 1][j - 1].rgbtRed;
                green += pixel[i + 1][j - 1].rgbtGreen;
                blue += pixel[i + 1][j - 1].rgbtBlue;
                counter++;
            }
            if (i + 1 < height && j >= 0) {
                red += pixel[i + 1][j].rgbtRed;
                green += pixel[i + 1][j].rgbtGreen;
                blue += pixel[i + 1][j].rgbtBlue;
                counter++;
            }
            if (i + 1 < height && j + 1 < width) {
                red += pixel[i + 1][j + 1].rgbtRed;
                green += pixel[i + 1][j + 1].rgbtGreen;
                blue += pixel[i + 1][j + 1].rgbtBlue;
                counter++;
            }

            image[i][j].rgbtRed = round(red / (counter * 1.0));
            image[i][j].rgbtGreen = round(green / (counter * 1.0));
            image[i][j].rgbtBlue = round(blue / (counter * 1.0));
        }
    }
    return;
}

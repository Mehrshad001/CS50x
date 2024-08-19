#include "helpers.h"
#include <math.h>
// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int aver =
                (int) ((image[i][j].rgbtRed + image[i][j].rgbtGreen + image[i][j].rgbtBlue) / 3.0 +
                       0.5);

            image[i][j].rgbtRed = aver;
            image[i][j].rgbtGreen = aver;
            image[i][j].rgbtBlue = aver;
        }
    }
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    // int originalRed, originalGreen, originalBlue;
    // int sepiaRed, sepiaGreen, sepiaBlue;
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int originalRed = image[i][j].rgbtRed;
            int originalGreen = image[i][j].rgbtGreen;
            int originalBlue = image[i][j].rgbtBlue;

            // sepiaRed = .393 * originalRed + .769 * originalGreen + .189 * originalBlue;
            image[i][j].rgbtRed = fmin(255, (int) (0.393 * originalRed + 0.769 * originalGreen +
                                                   0.189 * originalBlue + 0.5));
            image[i][j].rgbtGreen = fmin(255, (int) (0.349 * originalRed + 0.686 * originalGreen +
                                                     0.168 * originalBlue + 0.5));
            image[i][j].rgbtBlue = fmin(255, (int) (0.272 * originalRed + 0.534 * originalGreen +
                                                    0.131 * originalBlue + 0.5));
        }
    }
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width / 2; j++)
        {
            RGBTRIPLE temp = image[i][j];
            image[i][j] = image[i][width - 1 - j];
            image[i][width - 1 - j] = temp;
        }
    }
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
            int bluesum = 0, redsum = 0, greensum = 0;
            float counter = 0.00;

            for (int k = -1; k < 2; k++)
            {
                for (int l = -1; l < 2; l++)
                {
                    int currentk = i + k;
                    int currentl = j + l;

                    if (currentk < 0 || currentk > (height - 1) || currentl < 0 ||
                        currentl > (width - 1))
                    {
                        continue;
                    }

                    redsum += image[currentk][currentl].rgbtRed;
                    greensum += image[currentk][currentl].rgbtGreen;
                    bluesum += image[currentk][currentl].rgbtBlue;

                    counter++;
                }
            }

            temp[i][j].rgbtRed = round(redsum / counter);
            temp[i][j].rgbtGreen = round(greensum / counter);
            temp[i][j].rgbtBlue = round(bluesum / counter);
        }
    }
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < height; j++)
        {
            image[i][j] = temp[i][j];
        }
    }
    return;
}

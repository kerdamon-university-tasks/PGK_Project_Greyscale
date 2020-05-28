#include "../inc/ImageConversion.h"
#include "inc/ImageConversion.h"

#include <wx/log.h>

namespace GreyscaleConverter
{
    void ImageConversion::ConvertToBichrome(wxImage& image, wxColour& colour)
    {
        float red{ static_cast<float>(colour.Red()) };
        float green{ static_cast<float>(colour.Green()) };
        float blue{ static_cast<float>(colour.Blue()) };

        float hue, saturation, lightness;
        RGBtoHSL(hue, saturation, lightness, red, green, blue);

        unsigned char* imgData{ image.GetData() };
        const auto imgDataSize{ image.GetWidth() * image.GetHeight() * 3 };

        lightness = lightness * 2.f - 1.f;
        //wxLogError("H = %f\nS = %f\nL = %f",hue,saturation,lightness);
        //wxLogError("R = %f\nG = %f\nB = %f", red, green, blue);
    	
        for (int i = 0; i < imgDataSize; i += 3)
        {
            float pixelHue, pixelSaturation, pixelLightness;
            float pixelRed{ static_cast<float>(imgData[i]) };
            float pixelGreen{ static_cast<float>(imgData[i + 1]) };
            float pixelBlue{ static_cast<float>(imgData[i + 2]) };

            RGBtoHSL(pixelHue, pixelSaturation, pixelLightness, pixelRed, pixelGreen, pixelBlue);

            pixelHue = hue;
            pixelSaturation = saturation + 1.1 * pixelLightness;
            if (pixelSaturation > 1)
                pixelSaturation = 1;
            if (pixelSaturation < 0)
                pixelSaturation = 0;
            pixelLightness = lightness + 1.1 * pixelLightness;
            if (pixelLightness > 1)
                pixelLightness = 1;
            if (pixelLightness < 0)
                pixelLightness = 0;
        	
            HSLtoRGB(pixelRed, pixelGreen, pixelBlue, pixelHue, pixelSaturation, pixelLightness);

            imgData[i] = static_cast<char>(pixelRed);
            imgData[i + 1] = static_cast<char>(pixelGreen);
            imgData[i + 2] = static_cast<char>(pixelBlue);
        }
    }

    void ImageConversion::ConvertToGreyScale(wxImage& image, int chRed, int chGreen, int chBlue, bool keepHue = false)
    {
        unsigned char* imgData{ image.GetData() };
        const auto imgDataSize{ image.GetWidth() * image.GetHeight() * 3 };

        const float chRedFloat { static_cast<float>(chRed) / 100.f };
        const float chGreenFloat{ static_cast<float>(chGreen) / 100.f };
        const float chBlueFloat{ static_cast<float>(chBlue) / 100.f };

        for (int i = 0; i < imgDataSize; i+=3)
        {
        	
            float y, u, v;
            float r{ static_cast<float>(imgData[i]) * chRedFloat };
            float g{ static_cast<float>(imgData[i + 1]) * chGreenFloat };
        	float b{ static_cast<float>(imgData[i + 2]) * chBlueFloat };
            RGBtoYUV(y, u, v, r, g, b);
            YUVtoRGB(r, g, b, y, u, v);
            float gr{ (r + g + b) / 3.f };
            gr = gr > 255 ? 255 : gr;
            gr = gr < 0 ? 0 :gr;
            imgData[i] = imgData[i+1] = imgData[i+2] = static_cast<unsigned char>(gr);
        }
    }

    void RGBtoYUV(float& Y, float& U, float& V, const float R, const float G, const float B)
    {
        Y = 0.257f * R + 0.504f * G + 0.098f * B + 16;
        U = -0.148f * R - 0.291f * G + 0.439f * B + 128;
        V = 0.439f * R - 0.368f * G - 0.071f * B + 128;
    }

    void YUVtoRGB(float& R, float& G, float& B, float Y, float U, float V)
    {
        Y -= 16;
        U -= 128;
        V -= 128;
        R = 1.164f * Y + 1.596f * V;
        G = 1.164f * Y - 0.392f * U - 0.813f * V;
        B = 1.164f * Y + 2.017f * U;
    }

	float minColour(float r, float g, float b)
    {
        float min{ r };
        if (g < min)
            min = g;
        if (b < min)
            min = b;
        return min;
    }

    float maxColour(float r, float g, float b)
    {
        float max{ r };
        if (g > max)
            max = g;
        if (b > max)
            max = b;
        return max;
    }

    void RGBtoHSL(float& H, float& S, float& L, const float R, const float G, const float B)
    {
    	// [0, 1]
        float red{ R / 255.f };
        float green{ G / 255.f };
        float blue{ B / 255.f };

        float min{ minColour(red,green,blue) };
        float max{ maxColour(red,green,blue) };

    	// luminance
        L = (min + max) / 2;

    	// saturation
        if (min == max)
            S = 0;
        else if (L < 0.5f)
            S = (max - min / (max + min));
        else if (L >= 0.5f)
            S = (max - min) / (2.f - max - min);

    	// hue
        if (max == red)
            H = (green - blue) / (max - min);
        else if (max == green)
            H = 2.f + (blue - red) / (max - min);
        else if (max == blue)
            H = 4.f + (red - green) / (max - min);
        else
            H = 0;

        if (H > 6)
            H -= 6;
        if (H < 0)
            H += 6;
    	
        H *= 60;
    }

	float HueToRGB(float temp1, float temp2, float tempColour)
    {
        if (6 * tempColour < 1)
            return temp2 + (temp1 - temp2) * 6 * tempColour;
        if (2 * tempColour < 1)
            return temp1;
        if (3 * tempColour < 1)
            return temp2 + (temp1 - temp2) * (0.67f - tempColour) * 6;
        return temp2;
    }

    void HSLtoRGB(float& R, float& G, float& B, const float H, const float S, const float L)
    {
        if (S == 0)
            R = G = B = L * 255;
        else
        {
            float temp1;
            if (L < 0.5f)
                temp1 = L * (1 + S);
            else
                temp1 = L + S - L * S;
            float temp2 = 2 * L - temp1;
            float hue = H / 360;
            float tempR = hue + 0.33f;
            float tempG = hue;
            float tempB = hue - 0.33f;

            if (tempR > 1) 
                tempR -= 1;
            if (tempB < 0) 
                tempB += 1;

            R = HueToRGB(temp1, temp2, tempR) * 255;
            G = HueToRGB(temp1, temp2, tempG) * 255;
            B = HueToRGB(temp1, temp2, tempB) * 255;
        }
    }
}

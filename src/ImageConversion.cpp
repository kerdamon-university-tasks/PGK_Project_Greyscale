#include "inc/ImageConversion.h"
#include <wx/log.h>
#include <wx/translation.h>

namespace GreyscaleConverter
{
    void RGBtoYUV(float& Y, float& U, float& V, const float R, const float G, const float B);
    void YUVtoRGB(float& R, float& G, float& B, float Y, float U, float V);
	
    void ImageConversion::ConvertToBichrome(wxImage& image)
    {
        /// TODO bichromia
    }

    void ImageConversion::ConvertToGreyScale(wxImage& imgTo, int chRed, int chGreen, int chBlue)
    {
    	/*if(redChannel + greenChannel + blueChannel > 1)
    	{
            double adjustment{ (redChannel + greenChannel + blueChannel) };
            redChannel /= adjustment;
            greenChannel /= adjustment;
            blueChannel /= adjustment;
    	}*/

        //imgTo = imgTo.ConvertToGreyscale(redChannel, greenChannel, blueChannel);
        
        //int factor{ chRed + chGreen + chBlue };
    	
        unsigned char* imgData = imgTo.GetData();
        const auto imgDataSize = imgTo.GetWidth() * imgTo.GetHeight() * 3;

        float chRedFloat = chRed / 100.;
        float chGreenFloat = chGreen / 100.;
        float chBlueFloat = chBlue / 100.;

        for (int i = 0; i < imgDataSize; i+=3)
        {
            float y, u, v;
            RGBtoYUV(y, u, v, imgData[i] * chRedFloat, imgData[i + 1] * chGreenFloat, imgData[i + 2] * chBlueFloat);
            float r, g, b;
            YUVtoRGB(r, g, b, y, u, v);
            float gr = (r + g + b) / 3.;
            gr = gr > 255 ? 255 : gr;
            gr = gr < 0 ? 0 :gr;
            imgData[i] = imgData[i+1] = imgData[i+2] =static_cast<unsigned char>(gr);
        }
        
    }

    void RGBtoYUV(float& Y, float& U, float& V, const float R, const float G, const float B)
    {
        Y = 0.257 * R + 0.504 * G + 0.098 * B + 16;
        U = -0.148 * R - 0.291 * G + 0.439 * B + 128;
        V = 0.439 * R - 0.368 * G - 0.071 * B + 128;
    }

    void YUVtoRGB(float& R, float& G, float& B, float Y, float U, float V)
    {
        Y -= 16;
        U -= 128;
        V -= 128;
        R = 1.164 * Y + 1.596 * V;
        G = 1.164 * Y - 0.392 * U - 0.813 * V;
        B = 1.164 * Y + 2.017 * U;
    }

}

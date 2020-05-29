#pragma once
#include <wx/image.h>
#include <wx/colour.h>

namespace GreyscaleConverter
{

    class ImageConversion
    {
    public:
        static void ConvertToBichrome(wxImage&, wxColour&, bool, int, int);
        static void ConvertToGreyScale(wxImage&, int, int, int, bool, int, int);
    	
    };
    void RGBtoYUV(float& Y, float& U, float& V, const float R, const float G, const float B);
    void YUVtoRGB(float& R, float& G, float& B, float Y, float U, float V);

    void RGBtoHSL(float& H, float& S, float& L, const float R, const float G, const float B);
    void HSLtoRGB(float& R, float& G, float& B, const float  H, const float S, const float L);
}


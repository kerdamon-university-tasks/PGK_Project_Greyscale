#pragma once
#include <wx/image.h>

namespace GreyscaleConverter
{

    class ImageConversion
    {
    public:
        static void ConvertToBichrome(wxImage&);
        static void ConvertToGreyScale(wxImage& orgImage, wxImage& copyImage, int chRed, int chGreen, int chBlue);
    };

}
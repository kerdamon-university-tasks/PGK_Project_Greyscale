#pragma once
#include <wx/image.h>

namespace GrayscaleConverter
{

    class ImageConversion
    {
    public:
        static void ConvertToBichrome(wxImage&);
        static void ConvertToGreyScale(wxImage&);
    };

}
#pragma once
#include <wx/image.h>

namespace GrayscaleConverter
{

    class ImageConversion
    {
    public:
        static wxImage ConvertToDuechrome(wxImage&);
        static wxImage ConvertToGreyScale(wxImage&);
    };

}
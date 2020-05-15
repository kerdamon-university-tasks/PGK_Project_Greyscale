#include "inc/ImageConversion.h"

namespace GreyscaleConverter
{

    void ImageConversion::ConvertToBichrome(wxImage& image)
    {
        /// TODO bichromia
    }

    void ImageConversion::ConvertToGreyScale(wxImage& orgImage, wxImage& copyImage, int chRed, int chGreen, int chBlue)
    {
        copyImage = orgImage.ConvertToGreyscale(chRed / 200., chGreen / 200., chBlue / 200.);
    }

}
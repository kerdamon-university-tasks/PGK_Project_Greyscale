#include "inc/ImageConversion.h"
#include <wx/log.h>
#include <wx/translation.h>

namespace GreyscaleConverter
{

    void ImageConversion::ConvertToBichrome(wxImage& image)
    {
        /// TODO bichromia
    }

    void ImageConversion::ConvertToGreyScale(wxImage& orgImage, wxImage& copyImage, int chRed, int chGreen, int chBlue)
    {
        double redChannel = chRed/400. + 0.5;
        double greenChannel = chGreen/400. + 0.5;
        double blueChannel = chBlue/400. + 0.5;

    	if(redChannel + greenChannel + blueChannel > 1)
    	{
            double adjustment{ (redChannel + greenChannel + blueChannel) };
            redChannel /= adjustment;
            greenChannel /= adjustment;
            blueChannel /= adjustment;
    	}

        copyImage = orgImage.ConvertToGreyscale(redChannel, greenChannel, blueChannel);
    }

}

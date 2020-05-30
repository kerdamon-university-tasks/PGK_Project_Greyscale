#pragma once
#include <wx/image.h>
#include <wx/colour.h>

namespace GreyscaleConverter
{
		///  Class handles two image convertions:
		///  - bichrome
		///  - greyscale
		///
		///  Other functions converts one color system to another:
		///  - RGB => YUV
    ///  - YUV => RGB
    ///  - RGB => HSL
		///  - HSL => RGB
    class ImageConversion
    {
    public:
    	
    		/// Converts image to bichrome
    		///
    		/// @param image iamge that will be converted
    		/// @param color color which will be kept
    		/// @param keepHue flag determining if hue should be kept
    		/// @param hueToKeep value of the hue to keep
    		/// @param tolerance tolerance of kept hue
    		/// @see ConvertToGreyScale()
    		/// @note Function proceed convrtion in place! (on image passed by reference)
        static void ConvertToBichrome(wxImage& image, wxColour& color, bool, int, int);

        /// Converts image to greyscale
        ///
        /// @param image iamge that will be converted
        /// @param chRed red channel value
        /// @param chGreen green channel value
        /// @param chBlue blue channel value
        /// @param keepHue flag determining if hue should be kept
        /// @param hueToKeep value of the hue to keep
        /// @param tolerance tolerance of kept hue
        /// @see ConvertToBichrome()
        /// @note Function proceed convrtion in place! (on image passed by reference)
        static void ConvertToGreyScale(wxImage&, int, int, int, bool, int, int);
    	
    };

		///@{
		/// @name Color convertions
    void RGBtoYUV(float& Y, float& U, float& V, const float R, const float G, const float B);
    void YUVtoRGB(float& R, float& G, float& B, float Y, float U, float V);

    void RGBtoHSL(float& H, float& S, float& L, const float R, const float G, const float B);
    void HSLtoRGB(float& R, float& G, float& B, const float  H, const float S, const float L);
    ///@}
}


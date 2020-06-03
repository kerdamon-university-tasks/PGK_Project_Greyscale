#pragma once
#include <wx/image.h>
#include <wx/colour.h>

namespace GreyscaleConverter
{
		///  Class performs two crucial for the program image conversions:
		///  - bichrome
		///  - greyscale
		///
		///  Rest of the methods converts one color system to another forward/backward - RGB -> YUV, RGB -> HSL
    class ImageConversion
    {
    public:
    	
    		/// Converts image to doutone
    		///
    		/// @param image iamge that will be converted
    		/// @param color color which will be kept
    		/// @param keepHue flag determining if hue should be kept
    		/// @param hueToKeep value of the hue to keep
    		/// @param tolerance tolerance of kept hue
    		/// @see ConvertToGreyScale()
    		/// @note Function proceeds conversion in place! (on image passed by reference)
        static void ConvertToBichrome(wxImage& image, wxColour& color, bool keepHue, int hueToKeep, int tolerance);

        /// Converts image to greyscale
        ///
        /// @param image image that will be converted
        /// @param chRed red channel value
        /// @param chGreen green channel value
        /// @param chBlue blue channel value
        /// @param keepHue flag determining if hue should be kept
        /// @param hueToKeep value of the hue to keep
        /// @param tolerance tolerance of kept hue
        /// @see ConvertToBichrome()
        /// @note Function proceeds conversion in place! (on image passed by reference)
        static void ConvertToGreyScale(wxImage& image, int chRed, int chGreen, int chBlue, bool keepHue, int hueToKeep, int tolerance);

    private:

        static void RGBtoHSL(double& H, double& S, double& L, const double R, const double G, const double B);

        /// Converts HSL color system to RGB
				/// @see RGBtoHSL()
        static void HSLtoRGB(double& R, double& G, double& B, const double  H, const double S, const double L);

        static double HueToRGB(double, double, double);
        ///@}

    		/// Finds minimum value from 3 basic colors
    		///
    		/// @returns minimum value of color channels
        static double MinColour(double r, double g, double b);

        /// Finds maximum value from 3 basic colors
				///
				/// @returns maximum value of color channels
        static double MaxColour(double r, double g, double b);
    };
}


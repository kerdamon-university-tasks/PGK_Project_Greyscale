#pragma once
#include <wx/image.h>
#include <wx/colour.h>
#include <cmath>

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

    private:
				///@{
				/// @name Color convertions
        static void RGBtoYUV(double& Y, double& U, double& V, const double R, const double G, const double B);
        static void YUVtoRGB(double& R, double& G, double& B, double Y, double U, double V);

        static void RGBtoHSL(double& H, double& S, double& L, const double R, const double G, const double B);
        static void HSLtoRGB(double& R, double& G, double& B, const double  H, const double S, const double L);

        static double HueToRGB(double, double, double);
        static double MinColour(double, double, double);
        static double MaxColour(double, double, double);
        ///@}
    };
}


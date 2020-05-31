#pragma once
#include <wx/image.h>
#include <wx/colour.h>
#include <cmath>

namespace GreyscaleConverter
{

    class ImageConversion
    {
    public:
        static void ConvertToBichrome(wxImage&, wxColour&, bool, int, int);
        static void ConvertToGreyScale(wxImage&, int, int, int, bool, int, int);
    private:
        static void RGBtoYUV(double& Y, double& U, double& V, const double R, const double G, const double B);
        static void YUVtoRGB(double& R, double& G, double& B, double Y, double U, double V);

        static void RGBtoHSL(double& H, double& S, double& L, const double R, const double G, const double B);
        static void HSLtoRGB(double& R, double& G, double& B, const double  H, const double S, const double L);

        static double HueToRGB(double, double, double);
        static double MinColour(double, double, double);
        static double MaxColour(double, double, double);
    };
    
}


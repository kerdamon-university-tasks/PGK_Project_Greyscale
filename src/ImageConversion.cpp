#include "../inc/ImageConversion.h"
#include "inc/ImageConversion.h"

namespace GreyscaleConverter
{
	void ImageConversion::ConvertToBichrome(wxImage& image, wxColour& colour, bool keepHue, int hueToKeep,
	                                        int tolerance)
	{
		const wxImage imageCopy = image.Copy();
		unsigned char* imageData{image.GetData()};
		unsigned char* copyData{imageCopy.GetData()};
		const auto imgDataSize{image.GetWidth() * image.GetHeight() * 3};

		const double red{static_cast<double>(colour.Red())};
		const double green{static_cast<double>(colour.Green())};
		const double blue{static_cast<double>(colour.Blue())};

		double hue, saturation, lightness;
		RGBtoHSL(hue, saturation, lightness, red, green, blue);

		lightness = lightness * 2.f - 1.f;

		// for each pixel
		for (int i = 0; i < imgDataSize; i += 3)
		{
			double pixelRed{static_cast<double>(imageData[i])};
			double pixelGreen{static_cast<double>(imageData[i + 1])};
			double pixelBlue{static_cast<double>(imageData[i + 2])};

			// mask
			double h, s, l;
			RGBtoHSL(h, s, l, pixelRed, pixelGreen, pixelBlue);
			
			int hueDistance{static_cast<int>(abs(h - hueToKeep))};

			// weight = 0 - full bichrome, 1 - full original
			double weight{1};
			if (keepHue)
			{
				if (tolerance == 0)
					weight = hueDistance == 0 ? 0 : 1;
				else
				{
					double toleratedHue{tolerance * 3.6f};
					weight = abs(h - hueToKeep) / toleratedHue;

					if (hueToKeep - toleratedHue < 0)
						weight = abs(-1 * abs((h - hueToKeep - 180) / toleratedHue) + 180.f / toleratedHue);

					if (hueToKeep + toleratedHue > 359)
						weight = abs(-1 * abs((h - hueToKeep + 180) / toleratedHue) + 180.f / toleratedHue);

					weight = weight > 1 ? 1 : weight;
					weight = weight < 0 ? 0 : weight;
				}
			}

			// apply colours
			h = hue;

			s = saturation + 1.1f * s;
			s = s >= 1 ? 1 : s;
			s = s <= 0 ? 0 : s;

			l = lightness + 1.05f * l;
			l = l >= 1 ? 1 : l;
			l = l <= 0 ? 0 : l;

			HSLtoRGB(pixelRed, pixelGreen, pixelBlue, h, s, l);
			pixelRed = weight * pixelRed + (1 - weight) * static_cast<double>(copyData[i]);
			pixelGreen = weight * pixelGreen + (1 - weight) * static_cast<double>(copyData[i + 1]);
			pixelBlue = weight * pixelBlue + (1 - weight) * static_cast<double>(copyData[i + 2]);

			imageData[i] = static_cast<unsigned char>(pixelRed);
			imageData[i + 1] = static_cast<unsigned char>(pixelGreen);
			imageData[i + 2] = static_cast<unsigned char>(pixelBlue);
		}
	}

	void ImageConversion::ConvertToGreyScale(wxImage& image, int chRed, int chGreen, int chBlue, bool keepHue,
	                                         int hueToKeep, int tolerance)
	{
		wxImage imageCopy = image.Copy();
		unsigned char* imageData{image.GetData()};
		unsigned char* copyData{imageCopy.GetData()};
		const auto imgDataSize{image.GetWidth() * image.GetHeight() * 3};

		const double channelReddouble{static_cast<double>(chRed) / 100.f};
		const double channelGreendouble{static_cast<double>(chGreen) / 100.f};
		const double channelBluedouble{static_cast<double>(chBlue) / 100.f};

		//for each pixel
		for (int i = 0; i < imgDataSize; i += 3)
		{
			double pixelRed{static_cast<double>(imageData[i])};
			double pixelGreen{static_cast<double>(imageData[i + 1])};
			double pixelBlue{static_cast<double>(imageData[i + 2])};

			// mask
			double h, s, l;
			RGBtoHSL(h, s, l, pixelRed, pixelGreen, pixelBlue);

			int hueDistance{static_cast<int>(abs(h - hueToKeep))};

			// weight = 0 - full grey, 1 - full original
			double weight{1};
			if (keepHue)
			{
				if (tolerance == 0)
					weight = hueDistance == 0 ? 0 : 1;
				else
				{
					double toleratedHue{tolerance * 1.8f};

					weight = abs(h - hueToKeep) / toleratedHue;
					
					if (hueToKeep - toleratedHue < 0)
						weight = abs(-1 * abs((h - hueToKeep - 180) / toleratedHue) + 180.f / toleratedHue);

					if (hueToKeep + toleratedHue > 359)
						weight = abs(-1 * abs((h - hueToKeep + 180) / toleratedHue) + 180.f / toleratedHue);
					
					weight = weight > 1 ? 1 : weight;
					weight = weight < 0 ? 0 : weight;
				}
			}
			pixelRed *= channelReddouble;
			pixelGreen *= channelGreendouble;
			pixelBlue *= channelBluedouble;

			// applying colours
			double pixelGrey{(pixelRed + pixelGreen + pixelBlue) / 3};
			pixelGrey = pixelGrey > 255 ? 255 : pixelGrey;
			pixelGrey = pixelGrey < 0 ? 0 : pixelGrey;

			pixelRed = weight * pixelGrey + (1 - weight) * static_cast<double>(copyData[i]);
			pixelGreen = weight * pixelGrey + (1 - weight) * static_cast<double>(copyData[i + 1]);
			pixelBlue = weight * pixelGrey + (1 - weight) * static_cast<double>(copyData[i + 2]);

			imageData[i] = static_cast<unsigned char>(pixelRed);
			imageData[i + 1] = static_cast<unsigned char>(pixelGreen);
			imageData[i + 2] = static_cast<unsigned char>(pixelBlue);
		}
	}

	void ImageConversion::RGBtoHSL(double& H, double& S, double& L, const double R, const double G, const double B)
	{
		// [0, 1]
		double red{R / 255.f};
		double green{G / 255.f};
		double blue{B / 255.f};

		double min{MinColour(red, green, blue)};
		double max{MaxColour(red, green, blue)};

		// luminance
		L = (min + max) / 2;

		// saturation
		if (min == max)
			S = 0;
		else if (L < 0.5f)
			S = (max - min / (max + min));
		else if (L >= 0.5f)
			S = (max - min) / (2.f - max - min);

		// hue
		if (max == red)
			H = (green - blue) / (max - min);
		else if (max == green)
			H = 2.f + (blue - red) / (max - min);
		else if (max == blue)
			H = 4.f + (red - green) / (max - min);
		else
			H = 0;

		if (H > 6)
			H -= 6;
		if (H < 0)
			H += 6;

		H *= 60;
	}

	double ImageConversion::HueToRGB(double temp1, double temp2, double tempColour)
	{
		if (6 * tempColour < 1)
			return temp2 + (temp1 - temp2) * 6 * tempColour;
		if (2 * tempColour < 1)
			return temp1;
		if (3 * tempColour < 1)
			return temp2 + (temp1 - temp2) * (0.67f - tempColour) * 6;
		return temp2;
	}

	void ImageConversion::HSLtoRGB(double& R, double& G, double& B, const double H, const double S, const double L)
	{
		if (S == 0)
			R = G = B = L * 255;
		else
		{
			double temp1;
			if (L < 0.5f)
				temp1 = L * (1 + S);
			else
				temp1 = L + S - L * S;
			double temp2 = 2 * L - temp1;
			double hue = H / 360;
			double tempR = hue + 0.33f;
			double tempG = hue;
			double tempB = hue - 0.33f;

			if (tempR > 1)
				tempR -= 1;
			if (tempB < 0)
				tempB += 1;

			R = HueToRGB(temp1, temp2, tempR) * 255;
			G = HueToRGB(temp1, temp2, tempG) * 255;
			B = HueToRGB(temp1, temp2, tempB) * 255;
		}
	}

	double ImageConversion::MinColour(double r, double g, double b)
	{
		double min{r};
		if (g < min)
			min = g;
		if (b < min)
			min = b;
		return min;
	}

	double ImageConversion::MaxColour(double r, double g, double b)
	{
		double max{r};
		if (g > max)
			max = g;
		if (b > max)
			max = b;
		return max;
	}
}

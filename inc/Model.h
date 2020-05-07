#pragma once
#include <wx/frame.h>
#include <wx/image.h>

#include "inc/ImageConversion.h"

namespace GrayscaleConverter
{
	class Model
	{
	public:

		Model();

		/// image thumbnail getter
		const wxImage& GetImageThumbnail() const;

		/// member fields setters
		void SetFixedColor();
		void SetColorTolerance(float newColorTolerance) { m_colorTolerance = newColorTolerance; }
		void SetRedChannel(int);
		void SetBlueChannel(int);
		void SetGreenChannel(int);
		void SetIsFixedColor(bool);

		void LoadImageFromFile(const wxString& filePath);
		void SaveImageToFile() const;
		void ConvertToDuechrome();
		void ConvertToGreyScale();

		/// EASTERKURWA EGG
		void EasterEgg();

	private:

		void AdjustImageThumbnail();
		
		wxImage m_originalImage;
		wxImage* m_imageThumbnail;

		const int m_maxImageThumbnailSize = 500;
		
		int m_redChannel = 0;
		int m_blueChannel = 0;
		int m_greenChannel = 0;

		wxColour m_keptHue;
		int m_colorTolerance = 0;
		
		bool m_isKeepHueChecked = false;
	};
}

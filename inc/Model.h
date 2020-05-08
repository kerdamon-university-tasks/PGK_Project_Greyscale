#pragma once
#include <wx/frame.h>
#include <wx/image.h>
#include <wx/wfstream.h>
#include <wx/log.h>

#include "inc/ImageConversion.h"

namespace GrayscaleConverter
{
	
	class Model
	{
	public:
		enum class WorkMode { BICHROME, GREYSCALE, NONE };
		
		Model();
		/// image thumbnail getter
		const wxImage& GetImageThumbnail() const;

		/// member fields setters
		void SetColorTolerance(double tolerance) { m_colorTolerance = tolerance; }
		void SetRedChannel(int value) { m_redChannel = value;}
		void SetBlueChannel(int value) { m_blueChannel = value; }
		void SetGreenChannel(int value) { m_greenChannel = value; }
		void SetKeptHue(float value) { m_keptHue = wxColor(128, 128, 128); };
		void SetWorkMode(WorkMode mode) { m_mode = mode; }
		void SetIsKeptHue(bool flag) { m_isKeptHue = flag; }
		
		void LoadImageFromFile(const wxString& filePath);
		void SaveImageToFile(const wxString& filename);
		void ApplyParametersToImage();

		/// EASTERKURWA EGG
		void EasterEgg();

	private:

		void AdjustImageThumbnail();
		
		wxImage* m_originalImage;
		wxImage m_originalImageCopy;
		wxImage m_imageThumbnail;
		wxImage m_imageThumbnailCopy;

		wxColour m_keptHue;
		WorkMode m_mode{ WorkMode::NONE };

		double m_colorTolerance{ 0 };
		
		const int m_maxImageThumbnailSize{ 500 };
		
		int m_redChannel{ 0 };
		int m_blueChannel{ 0 };
		int m_greenChannel{ 0 };
		
		bool m_isKeptHue{ false };
		bool m_isResultSaved{ false };
		bool m_isConfigSave{ false };
	};
}

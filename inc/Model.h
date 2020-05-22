#pragma once
#include <wx/frame.h>
#include <wx/image.h>
#include <wx/bitmap.h>
#include <wx/wfstream.h>
#include <wx/log.h>

namespace GreyscaleConverter
{
	
	class Model
	{
	public:
		
		enum class WorkMode { BICHROME, GREYSCALE, ORIGINAL, NONE, };
		
		Model();
		
		void LoadImageFromFile(const wxString& filePath);
		void LoadConfigFromFile(const wxString& filePath);
		void SaveImageToFile(const wxString& filename);
		void SaveConfigToFile(const wxString& filePath) const;
		
		void ApplyParametersToThumbnail();

		//getters
		const wxImage& GetImageThumbnail() const { return m_imageThumbnailCopy; }
		bool IsResultImageSaved() const { return m_isResultSaved; }
		bool IsConfigSaved() const { return m_isConfigSaved; }
		bool IsImageLoaded() const { return m_isImageLoaded; }

		//setters
		void SetColorTolerance(double tolerance) { m_colorTolerance = tolerance; }
		void SetRedChannel(int value) { m_redChannel = value; }
		void SetBlueChannel(int value) { m_blueChannel = value; }
		void SetGreenChannel(int value) { m_greenChannel = value; }
		void SetKeptHue(float value) { m_keptHue = wxColor{ 128, 128, 128 }; }
		void SetWorkMode(WorkMode mode) { m_mode = mode; }
		void SetIsKeptHue(bool flag) { m_isKeptHue = flag; }
		void SetBichromeColour(const wxColour colour) { m_bichromeColour = colour; }
		void IsImageLoaded(bool isLoaded) { m_isImageLoaded = isLoaded; }

		void EasterEgg();

	private:

		void AdjustImageThumbnail();
		
		wxImage m_originalImage;
		wxImage m_originalImageCopy;
		wxImage m_imageThumbnail;
		wxImage m_imageThumbnailCopy;

		wxColour m_keptHue;
		wxColour m_bichromeColour;
		WorkMode m_mode{ WorkMode::NONE };

		double m_colorTolerance{ 0 };
		
		const int m_maxImageThumbnailSize{ 500 };
		
		int m_redChannel{ 0 };
		int m_blueChannel{ 0 };
		int m_greenChannel{ 0 };
		
		bool m_isKeptHue{ false };
		bool m_isResultSaved{ true };
		bool m_isConfigSaved{ true };
		bool m_isImageLoaded{ false };

	};
}

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
		
		enum class WorkMode { BICHROME, GREYSCALE, ORIGINAL, NOT_LOADED, };
		
		Model();
		
		void LoadImageFromFile(const wxString& filePath);
		void LoadConfigFromFile(const wxString& filePath);
		void SaveImageToFile(const wxString& filename);
		void SaveConfigToFile(const wxString& filePath) const;
		
		void ApplyParametersToThumbnail();

		//getters
		const wxImage& GetImageThumbnail() const { return m_imageThumbnailMixed; }
		bool IsResultImageSaved() const { return m_isResultSaved; }
		bool IsConfigSaved() const { return m_isConfigSaved; }
		WorkMode GetWorkMode() const { return m_mode; }
		wxColour GetBichromeColour() const { return m_bichromeColour; }
		int GetKeptHue() const { return m_keptHue; }
		int GetKeptHueIntensivity() const { return m_keptHueIntensivity; }
		int GetRedChannel() const { return m_redChannel; }
		int GetGreenChannel() const { return m_greenChannel; }
		int GetBlueChannel() const { return m_blueChannel; }
		bool IsHueKept() const { return m_isHueKept; }
		int GetMixingFactor() const { return m_mixingFactor; }

		//setters
		void SetKeptHueIntensivity(int intensivity) { m_keptHueIntensivity = intensivity; }
		void SetRedChannel(int value) { m_redChannel = value; }
		void SetBlueChannel(int value) { m_blueChannel = value; }
		void SetGreenChannel(int value) { m_greenChannel = value; }
		void SetKeptHue(int value) { m_keptHue = value; }
		void SetWorkMode(WorkMode mode) { m_mode = mode; }
		void SetIsKeptHue(bool flag) { m_isHueKept = flag; }
		void SetBichromeColour(const wxColour colour) { m_bichromeColour = colour; }
		void SetMixingFactor(const int mixingFactor) { m_mixingFactor = mixingFactor; }
		void IsResultImageSaved(const bool isSaved) { m_isResultSaved = isSaved; }

		void EasterEgg();
		void MixConvertedWithOriginal();

	private:

		void AdjustImageThumbnail();
		
		wxImage m_originalImage;
		wxImage m_originalImageCopy;
		wxImage m_imageThumbnail;
		wxImage m_imageThumbnailCopy;
		wxImage m_imageThumbnailMixed;

		int m_keptHue{ 180 };

		wxColour m_bichromeColour{ wxColour{"Red"} };
		WorkMode m_mode{ WorkMode::NOT_LOADED };

		int m_keptHueIntensivity{ 80 };
		
		const int m_maxImageThumbnailSize{ 500 };
		
		int m_redChannel{ 0 };
		int m_blueChannel{ 0 };
		int m_greenChannel{ 0 };
		
		bool m_isHueKept{ false };
		bool m_isResultSaved{ true };
		bool m_isConfigSaved{ true };

		int m_mixingFactor{ 0 };

	};
}

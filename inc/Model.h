#pragma once

#include <wx/image.h>

#include "inc/ImageConversion.h"


namespace GreyscaleConverter
{
	/// Class representing Model in MVC pattern
	///
	/// Model holds all user input parameters and image with it's copies and thumbnails.
	///
	/// Model is used by Controller @see ControllerFrame
	class Model
	{
	public:

		/// Enum class containing available work modes:
		/// - BICHROME
		/// - GREYSCALE
		/// - ORIGINAL => original image is shown
		/// - NOT_LOADED => no image has been loaded to a program
		enum class WorkMode { BICHROME, GREYSCALE, ORIGINAL, NOT_LOADED, };
		
		Model();

		/// @{ 
		/// @name Save & Load methods
	
		/// Loads image from a file
		///	
		/// @param filePath path to file which we want to load image from
		/// @see SaveImageToFile()
		/// @note Handles all popular image formats
		void LoadImageFromFile(const wxString& filePath);

		/// Loads parameters configuration from a file
		///	
		/// @param filePath path to file which we want to load config from
		/// @see SaveConfigToFile()
		void LoadConfigFromFile(const wxString& filePath);

		/// Saves image to a file
		///	
		/// @param filename Name under which converted image will be saved
		/// @see LoadImageFromFile()
		/// @note Handles all popular image formats
		void SaveImageToFile(const wxString& filename);

		/// Saves user's configuration to a file
		///	
		/// @param filePath Name under which configuration will be saved
		/// @see LoadConfigFromFile()
		void SaveConfigToFile(const wxString& filePath) const;
		/// @}
		/// 

		
		/// @{ 
		/// @name Getters


		/// Returns image thumbnail
	const wxImage & GetImageThumbnail() const { return m_imageThumbnailMixed; }

		/// Returns current work mode
		///
		/// @see WorkMode SetWorkMode()
		WorkMode GetWorkMode() const { return m_mode; }

		/// Returns Color which will be kept in bichrome
		///
		/// @see SetBichromeColour()
		wxColour GetBichromeColour() const { return m_bichromeColour; }

		/// Returns factor by which original image is mixed with converted image
		///
		/// @see SetMixingFactor()
		int GetMixingFactor() const { return m_mixingFactor; }

		/// Returns value of kept hue
		///
		/// @see SetKeptHue()
		int GetKeptHue() const { return m_keptHue; }

		/// Returns intensivity value of kept hue
		///
		/// @see SetKeptHueTolerance()
		int GetKeptHueTolerance() const { return m_keptHueTolerance; }

		/// Returns value of red color channel
		///
		/// @see SetRedChannel()
		int GetRedChannel() const { return m_redChannel; }

		/// Returns value of green color channel
		///
		/// @see SetGreenChannel()
		int GetGreenChannel() const { return m_greenChannel; }

		/// Returns value of blue color channel
		///
		/// @see SetBlueChannel()
		int GetBlueChannel() const { return m_blueChannel; }
		
		/// Returns true if result image has already been saved, false otherwise
		/// 
		/// @see SaveImageToFile()
		bool IsResultImageSaved() const { return m_isResultSaved; }

		/// Returns true if config is saved, false otherwise
		/// 
		/// @see SaveConfigToFile()
		bool IsConfigSaved() const { return m_isConfigSaved; }

		/// Returns true if specific hue have to be kept, false otherwise
		/// 
		/// @see GetKeptHue() SetKeptHue()
		bool IsHueKept() const { return m_isHueKept; }

		///@}
		
		/// @{
		/// @name Setters

		/// Sets tolerance value of kept hue
		///	
		/// @param tolerance
		/// @see GetKeptHueTolerance()
		void SetKeptHueTolerance(int tolerance) { m_keptHueTolerance = tolerance; }

		/// Sets red channel value
		///	
		/// @param value red channel
		/// @see GetRedChannel()
		void SetRedChannel(int value) { m_redChannel = value; }

		/// Sets blue channel value
		///	
		/// @param value blue channel
		/// @see GetBlueChannel()
		void SetBlueChannel(int value) { m_blueChannel = value; }

		/// Sets green channel value
		///	
		/// @param value green channel
		/// @see GetGreenChannel()
		void SetGreenChannel(int value) { m_greenChannel = value; }

		/// Sets kept hue value
		///	
		/// @param value kept hue
		/// @see GetRedChannel()
		void SetKeptHue(int value) { m_keptHue = value; }

		/// Sets work mode
		///	
		/// @param mode work mode
		/// @see WorkMode GetWorkMode()
		void SetWorkMode(WorkMode mode) { m_mode = mode; }

		/// Sets boolean flag of kept hue
		///	
		/// @param flag flag
		/// @see IsHueKept()
		void IsKeptHue(bool flag) { m_isHueKept = flag; }

		/// Sets color for bichrome
		///	
		/// @param colour bichrome colour
		/// @see GetBichromeColour()
		void SetBichromeColour(const wxColour colour) { m_bichromeColour = colour; }

		/// Sets factor representing proportion between original and converted images
		///
		/// @param mixingFactor factor value
		/// @see GetMixingFactor() MixConvertedWithOriginal()
		void SetMixingFactor(const int mixingFactor) { m_mixingFactor = mixingFactor; }
		///@}


		/// Applies user's parameters to image thumbnail that is displayed in a live preview	
		void ApplyParametersToThumbnail();

		/// Combines original image with its converted version
		///
		/// Proportion between original image and converted one is kept as a parameter m_mixingFactor
		/// It is accesible with:
		/// @see GetMixingFactor() SetMixingFactor()
		void MixConvertedWithOriginal();

		/// Sets state of ResultImage (saved / not saved) as boolean flag
		///
		/// @param isSaved flag value
		/// @see IsResultImageSaved()
		void IsResultImageSaved(const bool isSaved) { m_isResultSaved = isSaved; }

	private:

		void AdjustImageThumbnail();

		wxImage m_originalImage;
		wxImage m_originalImageCopy;
		wxImage m_imageThumbnail;
		wxImage m_imageThumbnailCopy;
		wxImage m_imageThumbnailMixed;

		wxColour m_bichromeColour{ wxColour{"Red"} };
		WorkMode m_mode{ WorkMode::NOT_LOADED };

		const int m_maxImageThumbnailSize{ 500 };
		
		int m_keptHue{ 180 };
		int m_keptHueTolerance{ 20 };
		
		int m_redChannel{ 100 };
		int m_blueChannel{ 100 };
		int m_greenChannel{ 100 };
		
		bool m_isHueKept{ false };
		bool m_isResultSaved{ true };
		bool m_isConfigSaved{ true };

		int m_mixingFactor{ 0 };
	};
}

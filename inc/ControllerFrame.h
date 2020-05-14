#ifndef __ControllerFrame__
#define __ControllerFrame__

/**
@file
Subclass of Frame, which is generated by wxFormBuilder.
*/

#include "MainFrame.h"

//// end generated include

/** Implementing Frame */

namespace GrayscaleConverter
{

	class ControllerFrame : public Frame
	{
	protected:
		// Handlers for Frame events.
		void OnButtonClick_ConvertToGrayscale(wxCommandEvent& event);
		void OnButtonClick_Bichrome(wxCommandEvent& event);
		void OnButtonClick_PickColour(wxCommandEvent& event);
		void OnCheckBox_KeepOneHue(wxCommandEvent& event);
		void OnScrollThumbTrack_HueIntesivity(wxScrollEvent& event);
		void OnText_ChangeHueIntensivity(wxCommandEvent& event);
		void OnButtonClick_RaspberriesButton(wxCommandEvent& event);
		void OnScrollThumbTrack_ChangeRedChannel(wxScrollEvent& event);
		void OnText_ChangeRedChannel(wxCommandEvent& event);
		void OnScrollThumbTrack_ChangeGreenChannel(wxScrollEvent& event);
		void OnText_ChangeGreenChannel(wxCommandEvent& event);
		void OnScrollThumbTrack_ChangeBlueChannel(wxScrollEvent& event);
		void OnText_ChangeBlueChannel(wxCommandEvent& event);
		void OnMenuSelection_LoadImage(wxCommandEvent& event);
		void OnMenuSelection_LoadConfig(wxCommandEvent& event);
		void OnMenuSelection_SaveImage(wxCommandEvent& event);
		void OnMenuSelection_SaveConfig(wxCommandEvent& event);
		void OnMenuSelection_Exit(wxCommandEvent& event);
		void OnMenuSelection_GoFullscreen(wxCommandEvent& event);
		void OnUpdateUI(wxUpdateUIEvent& event);

		void OnPaint_RefreshImage(wxPaintEvent& event) override;

		//void WarningIfNotSaved(bool isResultImageSaved, bool isConfigSaved);
	public:
	//	/** Constructor */
		ControllerFrame(wxWindow* parent);
	//	//// end generated class members
	//	///
	private:

		bool IsResultImageSaved() { return true; }
		bool IsConfigSaved() { return true; }

		bool m_isImageLoaded = false;
		
	};


}
#endif // __ControllerFrame__

#pragma once

#include "MainFrame.h"

namespace GreyscaleConverter
{
	class ControllerFrame : public Frame
	{
	public:

		ControllerFrame(wxWindow* parent);
		
	protected:
		// Handlers for Frame events.
		void OnClose_Frame(wxCloseEvent& event);
		void OnButtonClick_ConvertToGrayscale(wxCommandEvent& event);
		void OnButtonClick_Bichrome(wxCommandEvent& event);
		void OnColourChanged_PickBichromeColour(wxColourPickerEvent& event);
		void OnButtonClick_KeepOneHue(wxCommandEvent& event);
		void OnScrollThumbTrack_HueIntesivity(wxScrollEvent& event);
		void OnText_ChangeHueIntensivity(wxCommandEvent& event);
		void OnScrollThumbTrack_HueKept(wxScrollEvent& event);
		void OnText_HueKept(wxCommandEvent& event);
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
		void OnMenuSelection_QualityPreview(wxCommandEvent& event);

		void OnPaint_RefreshImage(wxPaintEvent& event) override;
		
	private:

		int WarningIfImageNotSaved();
		
		void AlternateConversionButtons(Model::WorkMode pressedButton);
		void ClearImagePreview();
		void UpdatePreview();
		void UpdateControls();

	};
}

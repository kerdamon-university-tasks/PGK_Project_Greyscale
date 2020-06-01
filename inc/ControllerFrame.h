#pragma once

#include "MainFrame.h"

namespace GreyscaleConverter
{
	/// Class representing Controller in MVC design pattern
	///
	/// It reacts on different events that occure in View (Button click, slider move etc)
	/// by ordering model to proceed specific action. It also asks model for various information that is displayed on View
	class ControllerFrame : public Frame
	{
	public:

		ControllerFrame(wxWindow* parent);
		
	protected:

		/// Handles window exit event
		void OnClose_Frame(wxCloseEvent& event) override;

		/// Handles Grayscale convertion button click
		///
		/// Toggles button state, disables appropriate controls.
		/// Forces View to refresh (with latest parameters and work mode)
		void OnButtonClick_ConvertToGrayscale(wxCommandEvent& event) override;

		/// Handles Duotone button click
		///
		/// Toggles button state, disables appropriate controls.
		/// Forces View to refresh (with latest parameters and work mode)
		void OnButtonClick_Bichrome(wxCommandEvent& event) override;


		/// Handles color pick via color dialog
		///
		/// Forces View to refresh (with latest parameters and work mode)		
		void OnColourChanged_PickBichromeColour(wxColourPickerEvent& event) override;


		/// Handles Keep hue button click
		///
		/// Toggles button state and sets flag specifying if any hue should be kept.
		/// Forces View to refresh (with latest parameters and work mode)
		void OnButtonClick_KeepOneHue(wxCommandEvent& event) override;

		/// Handles hue tolerance slider interaction
		///
		/// Updates text showing next to slider and sets appropriate flag in model.
		void OnScrollThumbTrack_HueIntesivity(wxScrollEvent& event) override;


		/// Handles Hue tolerance value change from keyboard
		///
		/// Updates text showing next to slider and sets appropriate hue tolerance value in model.
		void OnText_ChangeHueIntensivity(wxCommandEvent& event) override;


		/// Handles hue value slider interaction
		///
		/// Updates text showing next to slider and sets appropriate hue value in model.
		void OnScrollThumbTrack_HueKept(wxScrollEvent& event) override;


		/// Handles hue value change from keyboard via text input
		///
		/// Updates text showing next to slider and sets appropriate hue value in model.
		void OnText_HueKept(wxCommandEvent& event) override;


		/// Handles some mystery button click
		///
		/// No one knows what it does.
		void OnButtonClick_RaspberriesButton(wxCommandEvent& event) override;


		/// Handles Hue tolerance value change from keyboard
		///
		/// Updates text showing next to slider and sets appropriate red channel value in model.
		void OnScrollThumbTrack_ChangeRedChannel(wxScrollEvent& event) override;

		/// Handles red channel value change via text input
		///
		/// Updates text showing next to slider and sets appropriate red channel value in model.
		void OnText_ChangeRedChannel(wxCommandEvent& event) override;


		/// Handles green channel value change via slider
		///
		/// Updates text showing next to slider and sets appropriate green channel value in model.
		void OnScrollThumbTrack_ChangeGreenChannel(wxScrollEvent& event) override;

		/// Handles green channel value change via text input
		///
		/// Updates text showing next to slider and sets appropriate green channel value in model.
		void OnText_ChangeGreenChannel(wxCommandEvent& event) override;


		/// Handles blue channel value change via slider
		///
		/// Updates text showing next to slider and sets appropriate blue channel value in model.
		void OnScrollThumbTrack_ChangeBlueChannel(wxScrollEvent& event) override;

		/// Handles blue channel value change via text input
		///
		/// Updates text showing next to slider and sets appropriate blue channel value in model.
		void OnText_ChangeBlueChannel(wxCommandEvent& event) override;

		/// Handles mix proportion value change via slider
		///
		/// Updates text showing next to slider and sets appropriate mixing factor value in model.
		void OnScrollThumbTrack_MixOriginalWithConverted(wxScrollEvent& event) override;


		/// Handles mix proportion value change via text input
		///
		/// Updates text showing next to slider and sets appropriate mixing factor value in model.
		void OnText_MixOriginalWithConverted(wxCommandEvent& event) override;

		/// Handles load image menu selection
		///
		/// Displays warning if there are some unsaved changes.
		/// Opens file dialog and tells model to load image from specific path.
		/// @see Model::LoadImageFromFile() Model::SaveImageToFile()
		void OnMenuSelection_LoadImage(wxCommandEvent& event) override;


		/// Handles load config file menu selection
		///
		/// Displays warning if there are some unsaved changes.
		/// Opens file dialog and tells model to load config file from specific path.
		/// @see Model::LoadConfigFromFile() Model::SaveConfigToFile()
		void OnMenuSelection_LoadConfig(wxCommandEvent& event) override;

		/// Handles save image menu selection
		///
		/// Opens file dialog and orders model to save current result image under given path.
		/// @see Model::SaveImageToFile() Model::LoadImageFromFile()
		void OnMenuSelection_SaveImage(wxCommandEvent& event) override;

		/// Handles save config menu selection
		///
		/// Opens file dialog and orders model to save current configurations under given path.
		/// @see Model::SaveConfigToFile() Model::LoadConfigFromFile()
		void OnMenuSelection_SaveConfig(wxCommandEvent& event) override;

		/// Handles exit menu selection
		void OnMenuSelection_Exit(wxCommandEvent& event) override;

		/// Handles full screen menu selection
		///
		/// Displays program in full screen mode
		void OnMenuSelection_GoFullscreen(wxCommandEvent& event) override;

		/// Handles preview quality change
		///
		/// Toggles flag determining if preview should be displayed in high quality.
		void OnMenuSelection_QualityPreview(wxCommandEvent& event) override;

		///
		void OnPaint_RefreshImage(wxPaintEvent& event) override;

	private:


		/// Shows warning in message box if results are not saved and user tries to load new image or config
		int WarningIfImageNotSaved();

		/// Toggles appropriate buttons
		void AlternateConversionButtons(Model::WorkMode pressedButton);

		/// Sets appropriate flags based on current work mode
		void ClearImagePreview();

		/// Updates live preview
		/// 
		/// Gives model order to apply current parameters to image thumbnail.
		/// Forces ImageView to update.
		void UpdatePreview();

		void UpdateControls();

		/// Disables color channels controls
		void DisableChannelControls();

		/// Enables color channels controls
		void EnableChannelControls();

	};
}

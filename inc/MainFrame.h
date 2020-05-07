///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Oct 26 2018)
// http://www.wxformbuilder.org/
//
// PLEASE DO *NOT* EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#pragma once

#include <wx/artprov.h>
#include <wx/xrc/xmlres.h>
#include <wx/string.h>
#include <wx/bitmap.h>
#include <wx/image.h>
#include <wx/icon.h>
#include <wx/gdicmn.h>
#include <wx/button.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/statline.h>
#include <wx/sizer.h>
#include <wx/checkbox.h>
#include <wx/slider.h>
#include <wx/textctrl.h>
#include <wx/bmpbuttn.h>
#include <wx/statbox.h>
#include <wx/panel.h>
#include <wx/menu.h>
#include <wx/frame.h>

#include "ImageView.h"
#include "Model.h"
#include "ImageView.h"

///////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
/// Class Frame
///////////////////////////////////////////////////////////////////////////////
///

namespace GrayscaleConverter
{

	class Frame : public wxFrame
	{
	private:

	protected:
		wxButton* m_grayscaleButton;
		wxStaticLine* m_staticline1;
		wxButton* m_duotoneButton;
		wxButton* m_pickColourButton;
		wxStaticLine* m_staticline2;
		wxCheckBox* m_keepHueCheckBox;
		wxSlider* m_hueSlider;
		wxTextCtrl* m_hueSliderText;
		wxBitmapButton* m_raspberriesButton;
		wxSlider* m_redChannelSlider;
		wxTextCtrl* m_redChannelText;
		wxSlider* m_greenChannelSlider;
		wxTextCtrl* m_greenChannelText;
		wxSlider* m_blueChannelSlider;
		wxTextCtrl* m_blueChannelText;
		wxMenuBar* m_menubar;
		wxMenu* fileMenu;
		wxMenu* m_menu3;

		ImageView* m_view;
		Model& m_model;

		// Virtual event handlers, overide them in your derived class
		virtual void OnButtonClick_ConvertToGrayscale(wxCommandEvent& event) { event.Skip(); }
		virtual void OnButtonClick_Duotone(wxCommandEvent& event) { event.Skip(); }
		virtual void OnButtonClick_PickColour(wxCommandEvent& event) { event.Skip(); }
		virtual void OnCheckBox_KeepOneHue(wxCommandEvent& event) { event.Skip(); }
		//virtual void OnScrollChanged_HueIntesivity( wxScrollEvent& event ) { event.Skip(); }
		virtual void OnScrollThumbTrack_HueIntesivity(wxScrollEvent& event) { event.Skip(); }
		virtual void OnText_ChangeHueIntensivity(wxCommandEvent& event) { event.Skip(); }
		virtual void OnButtonClick_RaspberriesButton(wxCommandEvent& event) { event.Skip(); }
		//virtual void OnScrollChanged_ChangeRedChannel( wxScrollEvent& event ) { event.Skip(); }
		virtual void OnScrollThumbTrack_ChangeRedChannel(wxScrollEvent& event) { event.Skip(); }
		virtual void OnText_ChangeRedChannel(wxCommandEvent& event) { event.Skip(); }
		//virtual void OnScrollChanged_ChangeGreenChannel( wxScrollEvent& event ) { event.Skip(); }
		virtual void OnScrollThumbTrack_ChangeGreenChannel(wxScrollEvent& event) { event.Skip(); }
		virtual void OnText_ChangeGreenChannel(wxCommandEvent& event) { event.Skip(); }
		//virtual void OnScrollChanged_ChangeBlueChannel( wxScrollEvent& event ) { event.Skip(); }
		virtual void OnScrollThumbTrack_ChangeBlueChannel(wxScrollEvent& event) { event.Skip(); }
		virtual void OnText_ChangeBlueChannel(wxCommandEvent& event) { event.Skip(); }
		virtual void OnMenuSelection_LoadImage(wxCommandEvent& event) { event.Skip(); }
		virtual void OnMenuSelection_LoadConfig(wxCommandEvent& event) { event.Skip(); }
		virtual void OnMenuSelection_SaveImage(wxCommandEvent& event) { event.Skip(); }
		virtual void OnMenuSelection_SaveConfig(wxCommandEvent& event) { event.Skip(); }
		virtual void OnMenuSelection_Exit(wxCommandEvent& event) { event.Skip(); }
		virtual void OnMenuSelection_GoFullscreen(wxCommandEvent& event) { event.Skip(); }


	public:

		Frame(wxWindow* parent, Model& newModel, wxWindowID id = wxID_ANY, const wxString& title = wxT("Conversion to grayscale - project"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize(1002, 692), long style = wxDEFAULT_FRAME_STYLE | wxTAB_TRAVERSAL);

		~Frame();

	};

}
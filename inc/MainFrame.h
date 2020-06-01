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
#include <wx/colour.h>
#include <wx/statline.h>
#include <wx/sizer.h>
#include <wx/slider.h>
#include <wx/textctrl.h>
#include <wx/bmpbuttn.h>
#include <wx/menu.h>
#include <wx/frame.h>
#include <wx/tglbtn.h>
#include <wx/clrpicker.h>
#include <wx/statbox.h>

#include "ImageView.h"
#include "Model.h"

///////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
/// Class Frame
///////////////////////////////////////////////////////////////////////////////
///

namespace GreyscaleConverter
{

	class Frame : public wxFrame
	{
	private:

	protected:
		wxToggleButton* m_grayscaleButton;
		wxStaticLine* m_staticline1;
		wxToggleButton* m_duotoneButton;
		wxColourPickerCtrl* m_pickDuotoneColourButton;
		wxStaticLine* m_staticline2;
		wxToggleButton* m_keepHueButton;
		wxSlider* m_hueSlider;
		wxTextCtrl* m_hueSliderText;
		wxSlider* m_toleranceSlider;
		wxTextCtrl* m_toleranceText;
		wxStaticLine* m_staticline3;
		wxBitmapButton* m_raspberriesButton;
		wxSlider* m_redChannelSlider;
		wxTextCtrl* m_redChannelText;
		wxSlider* m_greenChannelSlider;
		wxTextCtrl* m_greenChannelText;
		wxSlider* m_blueChannelSlider;
		wxTextCtrl* m_blueChannelText;
		wxSlider* m_mixedFactorSlider;
		wxTextCtrl* m_mixedFactorText;
		wxMenuBar* m_menubar;
		wxMenu* fileMenu;
		wxMenu* m_viewMenu;
		wxMenuItem* m_menuItemQualityPreview;

		ImageView* m_view;
		Model m_model;

		 //Virtual event handlers, overide them in your derived class
		virtual void OnClose_Frame(wxCloseEvent& event) { event.Skip(); }
		virtual void OnUpdateUI(wxUpdateUIEvent& event) { event.Skip(); }
		virtual void OnButtonClick_ConvertToGrayscale(wxCommandEvent& event) { event.Skip(); }
		virtual void OnButtonClick_Duotone(wxCommandEvent& event) { event.Skip(); }
		virtual void OnColourChanged_PickDuotoneColour(wxColourPickerEvent& event) { event.Skip(); }
		virtual void OnButtonClick_KeepOneHue(wxCommandEvent& event) { event.Skip(); }
		virtual void OnScrollThumbTrack_HueKept(wxScrollEvent& event) { event.Skip(); }
		virtual void OnText_HueKept(wxCommandEvent& event) { event.Skip(); }
		virtual void OnScrollThumbTrack_HueTolerance(wxScrollEvent& event) { event.Skip(); }
		virtual void OnText_ChangeHueTolerance(wxCommandEvent& event) { event.Skip(); }
		virtual void OnButtonClick_RaspberriesButton(wxCommandEvent& event) { event.Skip(); }
		virtual void OnScrollThumbTrack_ChangeRedChannel(wxScrollEvent& event) { event.Skip(); }
		virtual void OnText_ChangeRedChannel(wxCommandEvent& event) { event.Skip(); }
		virtual void OnScrollThumbTrack_ChangeGreenChannel(wxScrollEvent& event) { event.Skip(); }
		virtual void OnText_ChangeGreenChannel(wxCommandEvent& event) { event.Skip(); }
		virtual void OnScrollThumbTrack_ChangeBlueChannel(wxScrollEvent& event) { event.Skip(); }
		virtual void OnText_ChangeBlueChannel(wxCommandEvent& event) { event.Skip(); }
		virtual void OnScrollThumbTrack_MixOriginalWithConverted(wxScrollEvent& event) { event.Skip(); }
		virtual void OnText_MixOriginalWithConverted(wxCommandEvent& event) { event.Skip(); }
		virtual void OnMenuSelection_LoadImage(wxCommandEvent& event) { event.Skip(); }
		virtual void OnMenuSelection_LoadConfig(wxCommandEvent& event) { event.Skip(); }
		virtual void OnMenuSelection_SaveImage(wxCommandEvent& event) { event.Skip(); }
		virtual void OnMenuSelection_SaveConfig(wxCommandEvent& event) { event.Skip(); }
		virtual void OnMenuSelection_Exit(wxCommandEvent& event) { event.Skip(); }
		virtual void OnMenuSelection_GoFullscreen(wxCommandEvent& event) { event.Skip(); }
		virtual void OnMenuSelection_QualityPreview(wxCommandEvent& event) { event.Skip(); }
		
		virtual void OnPaint_RefreshImage(wxPaintEvent& event) { event.Skip(); }

	public:

		Frame(wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("Conversion to grayscale - project"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize(1100, 810), long style = wxDEFAULT_FRAME_STYLE | wxTAB_TRAVERSAL);

		~Frame();

	};

}
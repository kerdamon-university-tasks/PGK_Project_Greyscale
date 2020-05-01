#include "inc/ControllerFrame.h"

#include <wx/log.h>

ControllerFrame::ControllerFrame( wxWindow* parent, Model& newModel )
	:
	Frame( parent, newModel )
{
	m_raspberriesButton->Hide();
}

void ControllerFrame::OnButtonClick_ConvertToGrayscale( wxCommandEvent& event )
{
// TODO: Implement OnButtonClick_ConvertToGrayscale
	wxLogDebug("OnButtonClick_ConvertToGrayscale");
}

void ControllerFrame::OnButtonClick_Duotone( wxCommandEvent& event )
{
// TODO: Implement OnButtonClick_Duotone
	wxLogDebug("OnButtonClick_Duotone");
}

void ControllerFrame::OnButtonClick_PickColour( wxCommandEvent& event )
{
// TODO: Implement OnButtonClick_PickColour
	wxLogDebug("OnButtonClick_PickColour");
}

void ControllerFrame::OnCheckBox_KeepOneHue( wxCommandEvent& event )
{
	wxLogDebug("OnCheckBox_KeepOneHue");
}

void ControllerFrame::OnScrollThumbTrack_HueIntesivity(wxScrollEvent& event)
{
	wxLogDebug("OnScrollThumbTrack_HueIntesivity");
}

//void ControllerFrame::OnScrollChanged_HueIntesivity( wxScrollEvent& event )
//{
//	wxLogDebug("OnScrollChanged_HueIntesivity");
//}

void ControllerFrame::OnText_ChangeHueIntensivity( wxCommandEvent& event )
{
	wxLogDebug("OnText_ChangeHueIntensivity");
}

void ControllerFrame::OnButtonClick_RaspberriesButton( wxCommandEvent& event )
{
	wxLogDebug("OnButtonClick_RaspberriesButton");
}

void ControllerFrame::OnScrollThumbTrack_ChangeRedChannel(wxScrollEvent& event)
{
	wxLogDebug("OnScrollThumbTrack_ChangeRedChannel");

}

//void ControllerFrame::OnScrollChanged_ChangeRedChannel( wxScrollEvent& event )
//{
//// TODO: Implement OnScrollChanged_ChangeRedChannel
//	wxLogDebug("OnScrollChanged_ChangeRedChannel");
//}

void ControllerFrame::OnText_ChangeRedChannel( wxCommandEvent& event )
{
// TODO: Implement OnText_ChangeRedChannel
	wxLogDebug("OnText_ChangeRedChannel");
}

void ControllerFrame::OnScrollThumbTrack_ChangeGreenChannel(wxScrollEvent& event)
{
	wxLogDebug("OnScrollThumbTrack_ChangeGreenChannel");
}

//void ControllerFrame::OnScrollChanged_ChangeGreenChannel( wxScrollEvent& event )
//{
//// TODO: Implement OnScrollChanged_ChangeGreenChannel
//	wxLogDebug("OnScrollChanged_ChangeGreenChannel");
//}

void ControllerFrame::OnText_ChangeGreenChannel( wxCommandEvent& event )
{
// TODO: Implement OnText_ChangeGreenChannel
	wxLogDebug("OnText_ChangeGreenChannel");
}

void ControllerFrame::OnScrollThumbTrack_ChangeBlueChannel(wxScrollEvent& event)
{
	wxLogDebug("OnScrollThumbTrack_ChangeBlueChannel");
}

//void ControllerFrame::OnScrollChanged_ChangeBlueChannel( wxScrollEvent& event )
//{
//// TODO: Implement OnScrollChanged_ChangeBlueChannel
//	wxLogDebug("OnScrollChanged_ChangeBlueChannel");
//}

void ControllerFrame::OnText_ChangeBlueChannel( wxCommandEvent& event )
{
// TODO: Implement OnText_ChangeBlueChannel
	wxLogDebug("OnText_ChangeBlueChannel");
}

void ControllerFrame::OnMenuSelection_LoadImage( wxCommandEvent& event )
{
// TODO: Implement OnMenuSelection_LoadImage
	wxLogDebug("OnMenuSelection_LoadImage");
}

void ControllerFrame::OnMenuSelection_LoadConfig( wxCommandEvent& event )
{
// TODO: Implement OnMenuSelection_LoadConfig
	wxLogDebug("OnMenuSelection_LoadConfig");
}

void ControllerFrame::OnMenuSelection_SaveImage( wxCommandEvent& event )
{
// TODO: Implement OnMenuSelection_SaveImage
	wxLogDebug("OnMenuSelection_SaveImage");
}

void ControllerFrame::OnMenuSelection_SaveConfig( wxCommandEvent& event )
{
// TODO: Implement OnMenuSelection_SaveConfig
	wxLogDebug("OnMenuSelection_SaveConfig");
}

void ControllerFrame::OnMenuSelection_Exit( wxCommandEvent& event )
{
// TODO: Implement OnMenuSelection_Exit
	wxLogDebug("OnMenuSelection_Exit");
}

void ControllerFrame::OnMenuSelection_GoFullscreen( wxCommandEvent& event )
{
// TODO: Implement OnMenuSelection_GoFullscreen
	wxLogDebug("OnMenuSelection_GoFullscreen");
}

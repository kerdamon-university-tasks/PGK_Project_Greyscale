#include "inc/ControllerFrame.h"

#include <wx/msgdlg.h>
#include <wx/filedlg.h>
#include <wx/log.h>
#include <wx/wfstream.h>

namespace GrayscaleConverter
{
	ControllerFrame::ControllerFrame(wxWindow* parent, Model& newModel)
		:
		Frame(parent, newModel)
	{
		m_raspberriesButton->Hide();
	}

	void ControllerFrame::OnButtonClick_ConvertToGrayscale(wxCommandEvent& event)
	{
		// TODO: Implement OnButtonClick_ConvertToGrayscale
	}

	void ControllerFrame::OnButtonClick_Duotone(wxCommandEvent& event)
	{
		// TODO: Implement OnButtonClick_Duotone
	}

	void ControllerFrame::OnButtonClick_PickColour(wxCommandEvent& event)
	{
		// TODO: Implement OnButtonClick_PickColour
	}

	void ControllerFrame::OnCheckBox_KeepOneHue(wxCommandEvent& event)
	{
	}

	void ControllerFrame::OnScrollThumbTrack_HueIntesivity(wxScrollEvent& event)
	{
	}

	void ControllerFrame::OnText_ChangeHueIntensivity(wxCommandEvent& event)
	{
	}

	void ControllerFrame::OnButtonClick_RaspberriesButton(wxCommandEvent& event)
	{
	}

	void ControllerFrame::OnScrollThumbTrack_ChangeRedChannel(wxScrollEvent& event)
	{
	}

	void ControllerFrame::OnText_ChangeRedChannel(wxCommandEvent& event)
	{
		// TODO: Implement OnText_ChangeRedChannel
	}

	void ControllerFrame::OnScrollThumbTrack_ChangeGreenChannel(wxScrollEvent& event)
	{
		
	}

	void ControllerFrame::OnText_ChangeGreenChannel(wxCommandEvent& event)
	{
		// TODO: Implement OnText_ChangeGreenChannel
	}

	void ControllerFrame::OnScrollThumbTrack_ChangeBlueChannel(wxScrollEvent& event)
	{
	}

	void ControllerFrame::OnText_ChangeBlueChannel(wxCommandEvent& event)
	{
		// TODO: Implement OnText_ChangeBlueChannel
	}

	void ControllerFrame::OnMenuSelection_LoadImage(wxCommandEvent& event)
	{
		if (true /*...current content has not been saved...*/)
		{
			if (wxMessageBox(_("Current content has not been saved! Proceed?"), _("Please confirm"),
				wxICON_QUESTION | wxYES_NO, this) == wxNO)
				return;
			//else: proceed asking to the user the new file to open
		}

		wxFileDialog openFileDialog(this, _("Wybierz zdj\u0119cie"), "", "", "JPG files (*.jpg)|*.jpg", wxFD_OPEN | wxFD_FILE_MUST_EXIST);
		
		if (openFileDialog.ShowModal() == wxID_CANCEL)
			return;     // the user changed idea...

		// proceed loading the file chosen by the user;
		// this can be done with e.g. wxWidgets input streams:
		const wxFileInputStream inputStream(openFileDialog.GetPath());
		if (!inputStream.IsOk())
		{
			wxLogError("Cannot open file '%s'.", openFileDialog.GetPath());
			return;
		}

		m_model.LoadImageFromFile(openFileDialog.GetPath());
		m_view->Update();
	}

	void ControllerFrame::OnMenuSelection_LoadConfig(wxCommandEvent& event)
	{
		// TODO: Implement OnMenuSelection_LoadConfig
	}

	void ControllerFrame::OnMenuSelection_SaveImage(wxCommandEvent& event)
	{
		// TODO: Implement OnMenuSelection_SaveImage
	}

	void ControllerFrame::OnMenuSelection_SaveConfig(wxCommandEvent& event)
	{
		// TODO: Implement OnMenuSelection_SaveConfig
	}

	void ControllerFrame::OnMenuSelection_Exit(wxCommandEvent& event)
	{
		// TODO: Implement OnMenuSelection_Exit
	}

	void ControllerFrame::OnMenuSelection_GoFullscreen(wxCommandEvent& event)
	{
		// TODO: Implement OnMenuSelection_GoFullscreen
	}

	void ControllerFrame::OnUpdateUI(wxUpdateUIEvent& event)
	{
		//m_view->Update();
	}
}

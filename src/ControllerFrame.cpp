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

	/**
	 * \brief Metoda obslugujaca event do konwersji do odcieni szarosci.
	 * \param event test
	 */
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
		wxString warningNotSavedMessage;
		if (/*m_model.IsResultImageSaved()*/ true)
			warningNotSavedMessage.Append("Current image has not been saved!");
		if (!warningNotSavedMessage.IsEmpty())
		{
			warningNotSavedMessage.Append(" Proceed?");
			if (wxMessageBox(warningNotSavedMessage, _("Please confirm"),
				wxICON_QUESTION | wxYES_NO, this) == wxNO)
				return;
		}

		wxFileDialog openFileDialog(this, _("Choose photo"), "", "", "JPG files (*.jpg)|*.jpg", wxFD_OPEN | wxFD_FILE_MUST_EXIST);
		
		if (openFileDialog.ShowModal() == wxID_CANCEL)	//nothing selected
			return;

		const wxFileInputStream inputStream(openFileDialog.GetPath());	//checking if ok
		
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
		wxString warningNotSavedMessage;
		if (/*m_model.IsConfigSaved()*/ true)
			warningNotSavedMessage.Append("Current config has not been saved!");
		if (!warningNotSavedMessage.IsEmpty())
		{
			warningNotSavedMessage.Append(" Proceed?");
			if (wxMessageBox(warningNotSavedMessage, _("Please confirm"),
				wxICON_QUESTION | wxYES_NO, this) == wxNO)
				return;
		}
		
		wxFileDialog openFileDialog(this, _("Choose config file"), "", "", "JPG files (*.jpg)|*.jpg", wxFD_OPEN | wxFD_FILE_MUST_EXIST);

		if (openFileDialog.ShowModal() == wxID_CANCEL)	//nothing selected
			return;

		const wxFileInputStream inputStream(openFileDialog.GetPath());	//checking if ok
		if (!inputStream.IsOk())
		{
			wxLogError("Cannot open file '%s'.", openFileDialog.GetPath());
			return;
		}

		//m_model.LoadConfigFromFile(openFileDialog.GetPath());
		m_view->Update();
	}

	void ControllerFrame::OnMenuSelection_SaveImage(wxCommandEvent& event)
	{
		wxFileDialog saveFileDialog(this, _("Save image to file"), "", "",
				"JPG files (*.jpg)|*.jpg", wxFD_SAVE | wxFD_OVERWRITE_PROMPT);

		if (saveFileDialog.ShowModal() == wxID_CANCEL)
			return;     // the user changed idea...

		const wxFileOutputStream output_stream(saveFileDialog.GetPath());
		if (!output_stream.IsOk())
		{
			wxLogError("Cannot save current contents in file '%s'.", saveFileDialog.GetPath());
			return;
		}

		//m_model.SaveImageToFile(saveFileDialog.GetPath());
	}

	void ControllerFrame::OnMenuSelection_SaveConfig(wxCommandEvent& event)
	{
		wxFileDialog saveFileDialog(this, _("Save config to file"), "", "",
			"JPG files (*.jpg)|*.jpg", wxFD_SAVE | wxFD_OVERWRITE_PROMPT);

		if (saveFileDialog.ShowModal() == wxID_CANCEL)
			return;     // the user changed idea...

		const wxFileOutputStream output_stream(saveFileDialog.GetPath());
		if (!output_stream.IsOk())
		{
			wxLogError("Cannot save current contents in file '%s'.", saveFileDialog.GetPath());
			return;
		}

		//m_model.SaveConfigToFile(saveFileDialog.GetPath());
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
		//if(m_imageIsLoaded)
		//	m_view->Update();
	}

	//void ControllerFrame::WarningIfNotSaved(const bool isResultImageSaved, const bool isConfigSaved)
	//{
	//	wxString warningNotSavedMessage;
	//	if (isResultImageSaved)
	//		warningNotSavedMessage.Append("Current image has not been saved!\n");
	//	if (isConfigSaved)
	//		warningNotSavedMessage.Append("Current config has not been saved!\n");

	//	if (!warningNotSavedMessage.IsEmpty())
	//	{
	//		warningNotSavedMessage.Append(" Proceed?");
	//		if (wxMessageBox(warningNotSavedMessage, _("Please confirm"),
	//			wxICON_QUESTION | wxYES_NO, this) == wxNO)
	//			return;
	//	}
	//}
}

#include "inc/ControllerFrame.h"

#include <wx/msgdlg.h>
#include <wx/filedlg.h>
#include <wx/log.h>
#include <wx/wfstream.h>
#include <wx/colordlg.h>

namespace GreyscaleConverter
{
	ControllerFrame::ControllerFrame(wxWindow* parent)
		:
		Frame(parent)
	{
		m_raspberriesButton->Hide();
	}

	void ControllerFrame::OnButtonClick_ConvertToGrayscale(wxCommandEvent& event)
	{
		if (m_bichromeButton->GetValue())
			m_bichromeButton->SetValue(false);
		
		if (m_grayscaleButton->GetValue())
			m_model.SetWorkMode(Model::WorkMode::GREYSCALE);
		else
			m_model.SetWorkMode(Model::WorkMode::ORIGINAL);
		
		m_model.ApplyParametersToThumbnail();
		m_view->UpdateImage();
	}

	void ControllerFrame::OnButtonClick_Bichrome(wxCommandEvent& event)
	{
		//if (m_grayscaleButton->GetValue())
		//	m_grayscaleButton->SetValue(false);
		////m_model.SetWorkMode(Model::WorkMode::BICHROME);
		//m_model.ApplyParametersToThumbnail();
		//
		m_view->Update();
	}

	void ControllerFrame::OnColourChanged_PickColour(wxColourPickerEvent& event)
	{
		m_model.SetBichromeColour(m_pickColourButton->GetColour());
		m_model.ApplyParametersToThumbnail();
	}

	void ControllerFrame::OnButtonClick_KeepOneHue(wxCommandEvent& event)
	{
		if (m_keepHueButton->GetValue())
			m_model.SetIsKeptHue(true);
		else;
			m_model.SetIsKeptHue(false);
	}

	void ControllerFrame::OnScrollThumbTrack_HueIntesivity(wxScrollEvent& event)
	{
		wxString newText;
		newText << m_intensivitySlider->GetValue();
		m_intensivityText->SetValue(newText);
		
		double value;
		if (!m_intensivityText->GetValue().ToDouble(&value))
			return;
		
		m_model.SetColorTolerance(value);
	}

	void ControllerFrame::OnText_ChangeHueIntensivity(wxCommandEvent& event)
	{
		long value;
		if (!m_intensivityText->GetValue().ToLong(&value))
			return;

		m_intensivitySlider->SetValue(value);

		m_model.SetColorTolerance(value);
	}

	void ControllerFrame::OnScrollThumbTrack_HueKept(wxScrollEvent& event)
	{
		wxString newText;
		newText << m_hueSlider->GetValue();
		m_hueSliderText->SetValue(newText);

		double value;
		if (!m_hueSliderText->GetValue().ToDouble(&value))
			return;

		m_model.SetColorTolerance(value);
	}

	void ControllerFrame::OnText_HueKept(wxCommandEvent& event)
	{
		long value;
		if (!m_hueSliderText->GetValue().ToLong(&value))
			return;

		if(value > m_hueSlider->GetMax())
		{
			value = m_hueSlider->GetMax();
			wxString newText;
			newText << value;
			m_hueSliderText->SetValue(newText);
		}
		else if(value < m_hueSlider->GetMin())
		{
			value = m_hueSlider->GetMin();
			wxString newText;
			newText << value;
			m_hueSliderText->SetValue(newText);
		}
		
		m_hueSlider->SetValue(value);

		m_model.SetColorTolerance(value);
	}

	void ControllerFrame::OnButtonClick_RaspberriesButton(wxCommandEvent& event)
	{
		//TODO zaimplementowac
	}

	void ControllerFrame::OnScrollThumbTrack_ChangeRedChannel(wxScrollEvent& event)
	{
		wxString newText;
		newText << m_redChannelSlider->GetValue();
		m_redChannelText->SetValue(newText);

		double value;
		if (!m_redChannelText->GetValue().ToDouble(&value))
			return;

		m_model.SetRedChannel(value);
		m_model.ApplyParametersToThumbnail();
		m_view->UpdateImage();
	}

	void ControllerFrame::OnText_ChangeRedChannel(wxCommandEvent& event)
	{
		long value;
		if (!m_redChannelText->GetValue().ToLong(&value))
			return;

		if (value > m_redChannelSlider->GetMax())
		{
			value = m_redChannelSlider->GetMax();
			wxString newText;
			newText << value;
			m_redChannelText->SetValue(newText);
		}
		else if (value < m_redChannelSlider->GetMin())
		{
			value = m_redChannelSlider->GetMin();
			wxString newText;
			newText << value;
			m_redChannelText->SetValue(newText);
		}
		
		m_redChannelSlider->SetValue(value);

		m_model.SetRedChannel(value);
		m_view->UpdateImage();
	}

	void ControllerFrame::OnScrollThumbTrack_ChangeGreenChannel(wxScrollEvent& event)
	{
		wxString newText;
		newText << m_greenChannelSlider->GetValue();
		m_greenChannelText->SetValue(newText);

		double value;
		if (!m_greenChannelText->GetValue().ToDouble(&value))
			return;

		m_model.SetGreenChannel(value);
		m_model.ApplyParametersToThumbnail();
		m_view->UpdateImage();
	}

	void ControllerFrame::OnText_ChangeGreenChannel(wxCommandEvent& event)
	{
		long value;
		if (!m_greenChannelText->GetValue().ToLong(&value))
			return;

		if (value > m_greenChannelSlider->GetMax())
		{
			value = m_greenChannelSlider->GetMax();
			wxString newText;
			newText << value;
			m_greenChannelText->SetValue(newText);
		}
		else if (value < m_greenChannelSlider->GetMin())
		{
			value = m_greenChannelSlider->GetMin();
			wxString newText;
			newText << value;
			m_greenChannelText->SetValue(newText);
		}
		
		m_greenChannelSlider->SetValue(value);

		m_model.SetGreenChannel(value);
		m_view->UpdateImage();
	}

	void ControllerFrame::OnScrollThumbTrack_ChangeBlueChannel(wxScrollEvent& event)
	{
		wxString newText;
		newText << m_blueChannelSlider->GetValue();
		m_blueChannelText->SetValue(newText);

		double value;
		if (!m_blueChannelText->GetValue().ToDouble(&value))
			return;

		m_model.SetBlueChannel(value);
		m_model.ApplyParametersToThumbnail();
		m_view->UpdateImage();
	}

	void ControllerFrame::OnText_ChangeBlueChannel(wxCommandEvent& event)
	{
		long value;
		if (!m_blueChannelText->GetValue().ToLong(&value))
			return;

		if (value > m_blueChannelSlider->GetMax())
		{
			value = m_blueChannelSlider->GetMax();
			wxString newText;
			newText << value;
			m_blueChannelText->SetValue(newText);
		}
		else if (value < m_blueChannelSlider->GetMin())
		{
			value = m_blueChannelSlider->GetMin();
			wxString newText;
			newText << value;
			m_blueChannelText->SetValue(newText);
		}
		
		m_blueChannelSlider->SetValue(value);

		m_model.SetBlueChannel(value);
		m_view->UpdateImage();
	}

	void ControllerFrame::OnMenuSelection_LoadImage(wxCommandEvent& event)
	{
		//wxString warningNotSavedMessage;
		//if (/*m_model.IsResultImageSaved()*/ true)
		//	warningNotSavedMessage.Append("Current image has not been saved!");
		//if (!warningNotSavedMessage.IsEmpty())
		//{
		//	warningNotSavedMessage.Append(" Proceed?");
		//	if (wxMessageBox(warningNotSavedMessage, _("Please confirm"),
		//		wxICON_QUESTION | wxYES_NO, this) == wxNO)
		//		return;
		//}

		////wxFileDialog openFileDialog(this, _("Choose photo"), "", "", "JPG files (*.jpg)|*.jpg", wxFD_OPEN | wxFD_FILE_MUST_EXIST);
		//std::shared_ptr<wxFileDialog> openFileDialog{ new wxFileDialog{this, _("Choose photo"), "", "", "JPG files (*.jpg)|*.jpg", wxFD_OPEN | wxFD_FILE_MUST_EXIST } };

		//if (openFileDialog->ShowModal() == wxID_CANCEL)	//nothing selected
		//	return;

		//const wxFileInputStream inputStream(openFileDialog->GetPath());	//checking if ok
		//
		//if (!inputStream.IsOk())
		//{
		//	wxLogError("Cannot open file '%s'.", openFileDialog->GetPath());
		//	return;
		//}

		//m_model.LoadImageFromFile(openFileDialog->GetPath());
		////m_view->Update();
		///
		std::shared_ptr<wxFileDialog> WxOpenFileDialog1(new wxFileDialog(this,
			_("Choose a file"), _(""),
			_(""), _("JPEG files (*.jpg)|*.jpg|PNG files (*.png)|*.png"),
			wxFD_OPEN));

		if (WxOpenFileDialog1->ShowModal() == wxID_OK)
		{
			m_model.LoadImageFromFile(WxOpenFileDialog1->GetPath());
			m_isImageLoaded = true;
			m_view->UpdateImage();
		}

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

		wxFileDialog saveFileDialog(this,
			_("Choose a folder"), "",
			"", "JPEG files (*.jpg)|*.jpg|PNG files (*.png)|*.png",
			wxFD_SAVE | wxFD_OVERWRITE_PROMPT);
		
		if (saveFileDialog.ShowModal() == wxID_CANCEL)	//nothing selected
			return;

		const wxFileOutputStream output_stream(saveFileDialog.GetPath());	//checking if ok
		if (!output_stream.IsOk())
		{
			wxLogError("Cannot save current contents in file '%s'.", saveFileDialog.GetPath());
			return;
		}

		m_model.SaveImageToFile(saveFileDialog.GetPath());
	}

	void ControllerFrame::OnMenuSelection_SaveConfig(wxCommandEvent& event)
	{
		wxFileDialog saveFileDialog(this, _("Save config to file"), "", "",
			"JPG files (*.jpg)|*.jpg", wxFD_SAVE | wxFD_OVERWRITE_PROMPT);

		if (saveFileDialog.ShowModal() == wxID_CANCEL)	//nothing selected
			return;

		const wxFileOutputStream output_stream(saveFileDialog.GetPath());	//checking if ok
		if (!output_stream.IsOk())
		{
			wxLogError("Cannot save current contents in file '%s'.", saveFileDialog.GetPath());
			return;
		}

		//m_model.SaveConfigToFile(saveFileDialog.GetPath());
	}

	void ControllerFrame::OnMenuSelection_Exit(wxCommandEvent& event)
	{
		Close();
	}

	void ControllerFrame::OnMenuSelection_GoFullscreen(wxCommandEvent& event)
	{
		ShowFullScreen(true);
	}

	void ControllerFrame::OnUpdateUI(wxUpdateUIEvent& event)
	{
		//if(m_isImageLoaded)
		//	m_view->UpdateImage();
	}

	void ControllerFrame::OnPaint_RefreshImage(wxPaintEvent& event)
	{
		if (m_isImageLoaded)
			m_view->UpdateImage();
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

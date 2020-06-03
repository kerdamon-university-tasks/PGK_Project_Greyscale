#include "inc/ControllerFrame.h"
#include <wx/msgdlg.h>
#include <wx/filedlg.h>
#include <wx/log.h>
#include <wx/sound.h>

namespace GreyscaleConverter
{
	ControllerFrame::ControllerFrame(wxWindow* parent)
		:
		Frame(parent)
	{
		m_totallyNotSuspiciousLookingButton->Hide();
		m_totallyNotSuspiciousLookingAnimationCtrl->Hide();
		DisableChannelControls();
	}

	void ControllerFrame::OnClose_Frame(wxCloseEvent& event)
	{
		if (WarningIfImageNotSaved() == wxNO)
			return;
		Destroy();
	}

	void ControllerFrame::OnButtonClick_ConvertToGrayscale(wxCommandEvent& event)
	{
		if (m_grayscaleButton->GetValue())
			AlternateConversionButtons(Model::WorkMode::GREYSCALE);
		else
		{
			DisableChannelControls();
			ClearImagePreview();
		}
	}

	void ControllerFrame::OnButtonClick_Bichrome(wxCommandEvent& event)
	{
		if (m_bichromeButton->GetValue())
			AlternateConversionButtons(Model::WorkMode::BICHROME);
		else
			ClearImagePreview();
	}

	void ControllerFrame::OnColourChanged_PickBichromeColour(wxColourPickerEvent& event)
	{
		m_model.SetBichromeColour(m_pickBichromeColourButton->GetColour());
		GenerateThumbnail();
		UpdatePreview();
	}

	void ControllerFrame::OnButtonClick_KeepOneHue(wxCommandEvent& event)
	{
		if(m_model.GetWorkMode() == Model::WorkMode::NOT_LOADED)
		{
			m_keepHueButton->SetValue(false);
			return;
		}
		
		if (m_keepHueButton->GetValue())
			m_model.SetIsKeptHue(true);
		else
			m_model.SetIsKeptHue(false);

		UpdatePreview();
	}

	void ControllerFrame::OnScrollThumbTrack_HueTolerance(wxScrollEvent& event)
	{
		wxString newText;
		newText << m_toleranceSlider->GetValue();
		m_toleranceText->SetValue(newText);

		long value;
		if (!m_toleranceText->GetValue().ToLong(&value))
			return;

		m_model.SetKeptHueTolerance(value);

		UpdatePreview();
	}

	void ControllerFrame::OnText_ChangeHueTolerance(wxCommandEvent& event)
	{
		long value;
		if (!m_toleranceText->GetValue().ToLong(&value))
			return;

		if (value > m_toleranceSlider->GetMax())
		{
			value = m_toleranceSlider->GetMax();
			wxString newText;
			newText << value;
			m_toleranceText->SetValue(newText);
		}
		else if (value < m_toleranceSlider->GetMin())
		{
			value = m_toleranceSlider->GetMin();
			wxString newText;
			newText << value;
			m_toleranceText->SetValue(newText);
		}

		m_toleranceSlider->SetValue(value);

		m_model.SetKeptHueTolerance(value);

		UpdatePreview();
	}

	void ControllerFrame::OnScrollThumbTrack_HueKept(wxScrollEvent& event)
	{
		wxString newText;
		newText << m_hueSlider->GetValue();
		m_hueSliderText->SetValue(newText);

		long value;
		if (!m_hueSliderText->GetValue().ToLong(&value))
			return;

		m_model.SetKeptHue(value);

		UpdatePreview();
	}

	void ControllerFrame::OnText_HueKept(wxCommandEvent& event)
	{
		long value;
		if (!m_hueSliderText->GetValue().ToLong(&value))
			return;

		if (value > m_hueSlider->GetMax())
		{
			value = m_hueSlider->GetMax();
			wxString newText;
			newText << value;
			m_hueSliderText->SetValue(newText);
		}
		else if (value < m_hueSlider->GetMin())
		{
			value = m_hueSlider->GetMin();
			wxString newText;
			newText << value;
			m_hueSliderText->SetValue(newText);
		}

		m_hueSlider->SetValue(value);

		m_model.SetKeptHue(value);

		UpdatePreview();
	}

	void ControllerFrame::OnButtonClick_TotallyNotSuspiciousLookingButton(wxCommandEvent& event)
	{
		static bool pressed = false;
		static wxSound totallyNotSuspiciousLookingSound{ "res/totallyNotSuspiciousLookingMusic.wav" };
		
		if(!pressed)
		{
			totallyNotSuspiciousLookingSound.Play(wxSOUND_ASYNC | wxSOUND_LOOP);
			m_view->Hide();
			m_totallyNotSuspiciousLookingAnimationCtrl->Show();
			m_totallyNotSuspiciousLookingAnimationCtrl->Play();

			//refreshing window so that raspberry shows in the center (without it it initially shows on the bottom)
			SetSize(GetSize().GetWidth() - 1, GetSize().GetHeight() - 1);
			SetSize(GetSize().GetWidth() + 1, GetSize().GetHeight() + 1);

			DisableAllControls();
			pressed = true;
		}
		else
		{
			totallyNotSuspiciousLookingSound.Stop();
			m_totallyNotSuspiciousLookingAnimationCtrl->Stop();
			m_totallyNotSuspiciousLookingAnimationCtrl->Hide();
			m_view->Show();
			EnableAllControls();
			pressed = false;
		}
	}

	void ControllerFrame::OnScrollThumbTrack_ChangeRedChannel(wxScrollEvent& event)
	{
		wxString newText;
		newText << m_redChannelSlider->GetValue();
		m_redChannelText->SetValue(newText);

		long value;
		if (!m_redChannelText->GetValue().ToLong(&value))
			return;

		m_model.SetRedChannel(value);

		UpdatePreview();
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

		UpdatePreview();
	}

	void ControllerFrame::OnScrollThumbTrack_ChangeGreenChannel(wxScrollEvent& event)
	{
		wxString newText;
		newText << m_greenChannelSlider->GetValue();
		m_greenChannelText->SetValue(newText);

		long value;
		if (!m_greenChannelText->GetValue().ToLong(&value))
			return;

		m_model.SetGreenChannel(value);

		UpdatePreview();
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
		
		UpdatePreview();
	}

	void ControllerFrame::OnScrollThumbTrack_ChangeBlueChannel(wxScrollEvent& event)
	{
		wxString newText;
		newText << m_blueChannelSlider->GetValue();
		m_blueChannelText->SetValue(newText);

		long value;
		if (!m_blueChannelText->GetValue().ToLong(&value))
			return;

		m_model.SetBlueChannel(value);
		
		GenerateThumbnail();
		UpdatePreview();
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

		m_model.SetBlueChannel(value);
		m_blueChannelSlider->SetValue(value);

		UpdatePreview();
	}

	void ControllerFrame::OnScrollThumbTrack_MixOriginalWithConverted(wxScrollEvent& event)
	{
		wxString newText;
		newText << m_mixedFactorSlider->GetValue();
		m_mixedFactorText->SetValue(newText);

		long factor;
		if (!m_mixedFactorText->GetValue().ToLong(&factor))
			return;

		m_model.SetMixingFactor(factor);
		m_model.MixConvertedWithOriginal();
		
		UpdatePreview();
	}

	void ControllerFrame::OnText_MixOriginalWithConverted(wxCommandEvent& event)
	{
		long factor;
		if (!m_mixedFactorText->GetValue().ToLong(&factor))
			return;

		if (factor > m_mixedFactorSlider->GetMax())
		{
			factor = m_mixedFactorSlider->GetMax();
			wxString newText;
			newText << factor;
			m_mixedFactorText->SetValue(newText);
		}
		else if (factor < m_mixedFactorSlider->GetMin())
		{
			factor = m_mixedFactorSlider->GetMin();
			wxString newText;
			newText << factor;
			m_mixedFactorText->SetValue(newText);
		}

		m_mixedFactorSlider->SetValue(factor);

		m_model.SetMixingFactor(factor);
		m_model.MixConvertedWithOriginal();

		UpdatePreview();
	}

	void ControllerFrame::OnMenuSelection_LoadImage(wxCommandEvent& event)
	{
		if (WarningIfImageNotSaved() == wxNO)
			return;

		wxFileDialog openFileDialog{
			this, _("Choose a file"), _(""), _(""),
			_("JPEG files (*.jpg)|*.jpg|PNG files (*.png)|*.png|GIF files (*.gif)|*.gif|BMP files(*.bmp)|*.bmp|All files (*.*)|*.*"),
			wxFD_OPEN | wxFD_FILE_MUST_EXIST
		};

		const auto showResult = openFileDialog.ShowModal();

		if (showResult == wxID_CANCEL) //nothing selected
			return;

		if (showResult == wxID_OK)
		{
			m_model.LoadImageFromFile(openFileDialog.GetPath());
			m_model.SetWorkMode(Model::WorkMode::ORIGINAL);
			m_view->UpdateImage(m_menuItemQualityPreview->IsChecked());
		}
	}

	void ControllerFrame::OnMenuSelection_LoadConfig(wxCommandEvent& event)
	{
		if(m_model.GetWorkMode() == Model::WorkMode::NOT_LOADED)
		{
			wxMessageBox(_("Load image first"), _(""), wxICON_QUESTION, this);
			return;
		}

		if (WarningIfImageNotSaved() == wxNO)
			return;
		
		wxFileDialog openFileDialog{
			this, _("Choose a file"), _(""), _(""),
			_("Config files (*.cfg)|*.cfg"),
			wxFD_OPEN | wxFD_FILE_MUST_EXIST
		};

		const auto showResult = openFileDialog.ShowModal();

		if (showResult == wxID_CANCEL) //nothing selected
			return;

		if (showResult == wxID_OK)
		{
			m_model.LoadConfigFromFile(openFileDialog.GetPath());
			UpdateControls();
		}

		UpdatePreview();
	}

	void ControllerFrame::OnMenuSelection_SaveImage(wxCommandEvent& event)
	{
		if (m_model.GetWorkMode() == Model::WorkMode::NOT_LOADED)
			return;
		
		wxFileDialog saveFileDialog{
			this,
			_("Choose a folder"), "", "",
			_("JPEG files (*.jpg)|*.jpg|PNG files (*.png)|*.png|GIF files (*.gif)|*.gif|BMP files(*.bmp)|*.bmp|All files (*.*)|*.*"),
			wxFD_SAVE | wxFD_OVERWRITE_PROMPT
		};

		const auto showResult = saveFileDialog.ShowModal();

		if (showResult == wxID_CANCEL) //nothing selected
			return;

		if (showResult == wxID_OK)
		{
			m_model.SaveImageToFile(saveFileDialog.GetPath());
			m_model.IsResultImageSaved(true);
		}
		else
			wxLogError("Cannot save current contents in file '%s'.", saveFileDialog.GetPath());
	}

	void ControllerFrame::OnMenuSelection_SaveConfig(wxCommandEvent& event)
	{
		wxFileDialog saveFileDialog{
			this,
			_("Choose a folder"), "", "",
			_("Config files (*.cfg)|*.cfg"),
			wxFD_SAVE | wxFD_OVERWRITE_PROMPT
		};

		const auto showResult = saveFileDialog.ShowModal();

		if (showResult == wxID_CANCEL) //nothing selected
			return;

		if (showResult == wxID_OK)
		{
			m_model.SaveConfigToFile(saveFileDialog.GetPath());
		}
		else
			wxLogError("Cannot save current contents in file '%s'.", saveFileDialog.GetPath());
	}

	void ControllerFrame::OnMenuSelection_Exit(wxCommandEvent& event)
	{
		Close();
	}

	void ControllerFrame::OnMenuSelection_GoFullscreen(wxCommandEvent& event)
	{
		static auto fullscreened = false;
		if (fullscreened)
		{
			ShowFullScreen(false, wxFULLSCREEN_NOBORDER);
			fullscreened = !fullscreened;
		}
		else
		{
			ShowFullScreen(true, wxFULLSCREEN_NOBORDER);
			fullscreened = !fullscreened;
		}
	}

	void ControllerFrame::OnMenuSelection_QualityPreview(wxCommandEvent& event)
	{
		UpdatePreview();
	}

	void ControllerFrame::OnPaint_RefreshImage(wxPaintEvent& event)
	{
		if (m_model.GetWorkMode() != Model::WorkMode::NOT_LOADED)
			m_view->UpdateImage(m_menuItemQualityPreview->IsChecked());
	}

	int ControllerFrame::WarningIfImageNotSaved()
	{
		wxString warningNotSavedMessage;
		if (!m_model.IsResultImageSaved())
			warningNotSavedMessage.Append("Current image has not been saved! Proceed?");
		if (!warningNotSavedMessage.IsEmpty())
		{
			const auto result = wxMessageBox(warningNotSavedMessage, _("Please confirm"), wxICON_QUESTION | wxYES_NO,
			                                 this);
			if (result == wxNO)
				return result;
		}
		return -1;
	}

	void ControllerFrame::AlternateConversionButtons(Model::WorkMode pressedButton)
	{
		m_grayscaleButton->SetValue(false);
		m_bichromeButton->SetValue(false);

		DisableChannelControls();

		if (m_model.GetWorkMode() == Model::WorkMode::NOT_LOADED)
			return;

		ClearImagePreview();

		switch (pressedButton)
		{
		case Model::WorkMode::BICHROME:
			m_bichromeButton->SetValue(true);
			m_model.SetWorkMode(Model::WorkMode::BICHROME);
			break;
		case Model::WorkMode::GREYSCALE:
			m_grayscaleButton->SetValue(true);
			m_model.SetWorkMode(Model::WorkMode::GREYSCALE);
			EnableChannelControls();
			break;
		default: ;
		}

		UpdatePreview();
	}

	void ControllerFrame::DisableChannelControls()
	{
		m_redChannelSlider->Disable();
		m_redChannelText->Disable();
		m_greenChannelSlider->Disable();
		m_greenChannelText->Disable();
		m_blueChannelSlider->Disable();
		m_blueChannelText->Disable();
	}

	void ControllerFrame::EnableChannelControls()
	{
		m_redChannelSlider->Enable();
		m_redChannelText->Enable();
		m_greenChannelSlider->Enable();
		m_greenChannelText->Enable();
		m_blueChannelSlider->Enable();
		m_blueChannelText->Enable();
	}

	void ControllerFrame::DisableAllControls()
	{
		DisableChannelControls();
		m_hueSlider->Disable();
		m_hueSliderText->Disable();
		m_toleranceSlider->Disable();
		m_toleranceText->Disable();
		m_mixedFactorSlider->Disable();
		m_mixedFactorText->Disable();
		m_bichromeButton->Disable();
		m_grayscaleButton->Disable();
		m_keepHueButton->Disable();
		m_pickBichromeColourButton->Disable();
		m_menuItemLoadConfig->Enable(false);
		m_menuItemQualityPreview->Enable(false);
		m_menuItemLoadImage->Enable(false);
		m_menuItemSaveConfig->Enable(false);
		m_menuItemSaveImage->Enable(false);
	}

	void ControllerFrame::EnableAllControls()
	{
		EnableChannelControls();
		m_hueSlider->Enable();
		m_hueSliderText->Enable();
		m_toleranceSlider->Enable();
		m_toleranceText->Enable();
		m_mixedFactorSlider->Enable();
		m_mixedFactorText->Enable();
		m_bichromeButton->Enable();
		m_grayscaleButton->Enable();
		m_keepHueButton->Enable();
		m_pickBichromeColourButton->Enable();
		m_menuItemLoadConfig->Enable(true);
		m_menuItemQualityPreview->Enable(true);
		m_menuItemLoadImage->Enable(true);
		m_menuItemSaveConfig->Enable(true);
		m_menuItemSaveImage->Enable(true);
	}

	void ControllerFrame::ClearImagePreview()
	{
		if (m_model.GetWorkMode() == Model::WorkMode::NOT_LOADED)
			return;
		
		m_model.SetWorkMode(Model::WorkMode::ORIGINAL);
		UpdatePreview();
	}

	void ControllerFrame::UpdatePreview()
	{
		GenerateThumbnail();
		m_view->UpdateImage(m_menuItemQualityPreview->IsChecked());
	}

	void ControllerFrame::UpdateControls()
	{
		m_bichromeButton->SetValue(false);
		m_grayscaleButton->SetValue(false);
		DisableChannelControls();
		
		switch (m_model.GetWorkMode())
		{
		case Model::WorkMode::BICHROME:
			m_bichromeButton->SetValue(true);
			break;
		case Model::WorkMode::GREYSCALE:
			m_grayscaleButton->SetValue(true);
			EnableChannelControls();
			break;
		default:
			break;
		}

		m_keepHueButton->SetValue(false);
		if (m_model.IsHueKept())
			m_keepHueButton->SetValue(true);
		
		m_pickBichromeColourButton->SetColour(m_model.GetBichromeColour());
		
		m_hueSlider->SetValue(m_model.GetKeptHue());
		wxString tempText;
		tempText << m_model.GetKeptHue();
		m_hueSliderText->SetValue(tempText);
		
		m_toleranceSlider->SetValue(m_model.GetKeptHueTolerance());
		wxString tempText2;
		tempText2 << m_model.GetKeptHueTolerance();
		m_toleranceText->SetValue(tempText2);

		m_redChannelSlider->SetValue(m_model.GetRedChannel());
		wxString tempTextR;
		tempTextR << m_model.GetRedChannel();
		m_redChannelText->SetValue(tempTextR);

		m_greenChannelSlider->SetValue(m_model.GetGreenChannel());
		wxString tempTextG;
		tempTextG << m_model.GetGreenChannel();
		m_greenChannelText->SetValue(tempTextG);

		m_blueChannelSlider->SetValue(m_model.GetBlueChannel());
		wxString tempTextB;
		tempTextB << m_model.GetBlueChannel();
		m_blueChannelText->SetValue(tempTextB);
		
		m_mixedFactorSlider->SetValue(m_model.GetMixingFactor());
		wxString tempTextMix;
		tempTextMix << m_model.GetMixingFactor();
		m_mixedFactorText->SetValue(tempTextMix);
	}

	void ControllerFrame::GenerateThumbnail()
	{
		m_model.ApplyParametersToThumbnail();
		TotallyNotSuspiciousLookingFunction();
	}
	
	void ControllerFrame::TotallyNotSuspiciousLookingFunction()
	{
		if (m_model.GetRedChannel()			== 'J' && 
			m_model.GetGreenChannel()		== 'A' && 
			m_model.GetBlueChannel()		== 'N' && 
			m_model.GetKeptHue()			== 'U' && 
			m_model.GetKeptHueTolerance()	== 'S' && 
			m_model.GetMixingFactor()		== 'Z')

			m_totallyNotSuspiciousLookingButton->Show();
		else
			m_totallyNotSuspiciousLookingButton->Hide();
	}
}

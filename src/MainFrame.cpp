#include <wx/statbox.h>

#include "inc/MainFrame.h"

namespace GreyscaleConverter
{

	Frame::Frame(wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style)
		:
		wxFrame(parent, id, title, pos, size, style)
	{
		this->SetSizeHints(wxDefaultSize, wxDefaultSize);


		auto* mainSizer = new wxBoxSizer(wxHORIZONTAL);
		auto* barSizer = new wxBoxSizer(wxVERTICAL);
		
		m_grayscaleButton = new wxToggleButton{ this, wxID_ANY, wxT("Convert to grayscale"), wxDefaultPosition, wxDefaultSize, 0 };
		barSizer->Add(m_grayscaleButton, 0, wxALL | wxEXPAND, 8);

		
		auto* redChannelSizer = new wxStaticBoxSizer(new wxStaticBox(this, wxID_ANY, wxT("Red")), wxHORIZONTAL);
		
		m_redChannelSlider = new wxSlider(redChannelSizer->GetStaticBox(), wxID_ANY, 0, -200, 200, wxDefaultPosition, wxDefaultSize, wxSL_HORIZONTAL);
		m_redChannelSlider->SetMinSize(wxSize(200, -1));

		redChannelSizer->Add(m_redChannelSlider, 1, wxALL | wxALIGN_CENTER_VERTICAL, 5);

		m_redChannelText = new wxTextCtrl(redChannelSizer->GetStaticBox(), wxID_ANY, wxT("0"), wxDefaultPosition, wxSize(40, -1), 0);
		m_redChannelText->SetMaxLength(4);

		redChannelSizer->Add(m_redChannelText, 0, wxALL | wxALIGN_CENTER_VERTICAL, 5);
		
		barSizer->Add(redChannelSizer, 0, wxALIGN_BOTTOM | wxALL | wxEXPAND, 5);

		
		auto* greenChannelSizer = new wxStaticBoxSizer(new wxStaticBox(this, wxID_ANY, wxT("Green")), wxHORIZONTAL);

		m_greenChannelSlider = new wxSlider(greenChannelSizer->GetStaticBox(), wxID_ANY, 0, -200, 200, wxDefaultPosition, wxDefaultSize, wxSL_HORIZONTAL);
		m_greenChannelSlider->SetMinSize(wxSize(200, -1));

		greenChannelSizer->Add(m_greenChannelSlider, 1, wxALL | wxALIGN_CENTER_VERTICAL, 5);

		m_greenChannelText = new wxTextCtrl(greenChannelSizer->GetStaticBox(), wxID_ANY, wxT("0"), wxDefaultPosition, wxSize(40, -1), 0);
		m_greenChannelText->SetMaxLength(4);

		greenChannelSizer->Add(m_greenChannelText, 0, wxALIGN_CENTER_VERTICAL | wxALL, 5);

		barSizer->Add(greenChannelSizer, 0, wxALIGN_BOTTOM | wxALL | wxEXPAND, 5);

		
		auto* blueChannelSizer = new wxStaticBoxSizer(new wxStaticBox(this, wxID_ANY, wxT("Blue")), wxHORIZONTAL);

		m_blueChannelSlider = new wxSlider(blueChannelSizer->GetStaticBox(), wxID_ANY, 0, -200, 200, wxDefaultPosition, wxDefaultSize, wxSL_HORIZONTAL);
		m_blueChannelSlider->SetMinSize(wxSize(200, -1));

		blueChannelSizer->Add(m_blueChannelSlider, 1, wxALL | wxALIGN_CENTER_VERTICAL, 5);

		m_blueChannelText = new wxTextCtrl(blueChannelSizer->GetStaticBox(), wxID_ANY, wxT("0"), wxDefaultPosition, wxSize(40, -1), 0);
		m_blueChannelText->SetMaxLength(4);

		blueChannelSizer->Add(m_blueChannelText, 0, wxALIGN_CENTER_VERTICAL | wxALL, 5);

		barSizer->Add(blueChannelSizer, 0, wxALIGN_BOTTOM | wxALL | wxEXPAND, 5);

		m_staticline1 = new wxStaticLine(this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL);
		barSizer->Add(m_staticline1, 0, wxEXPAND | wxALL, 5);


		auto* bichromeSizer = new wxBoxSizer(wxVERTICAL);

		m_bichromeButton = new wxToggleButton(this, wxID_ANY, wxT("Convert to bichrome"), wxDefaultPosition, wxDefaultSize, 0);
		bichromeSizer->Add(m_bichromeButton, 1, wxALL | wxEXPAND, 8);

		m_pickBichromeColourButton = new wxColourPickerCtrl(this, wxID_ANY, wxColour(243, 40, 12), wxDefaultPosition, wxDefaultSize, wxCLRP_DEFAULT_STYLE);
		bichromeSizer->Add(m_pickBichromeColourButton, 1, wxALIGN_CENTER_HORIZONTAL | wxALL, 8);

		barSizer->Add(bichromeSizer, 0, wxEXPAND, 5);

		m_staticline2 = new wxStaticLine(this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL);
		barSizer->Add(m_staticline2, 0, wxEXPAND | wxALL, 5);

		m_keepHueButton = new wxToggleButton(this, wxID_ANY, wxT("Keep hue"), wxDefaultPosition, wxDefaultSize, 0);
		barSizer->Add(m_keepHueButton, 0, wxALL | wxEXPAND, 8);

		
		auto* hueSliderSizer = new wxStaticBoxSizer(new wxStaticBox(this, wxID_ANY, wxT("Hue")), wxHORIZONTAL);

		m_hueSlider = new wxSlider(hueSliderSizer->GetStaticBox(), wxID_ANY, 180, 0, 359, wxDefaultPosition, wxDefaultSize, wxSL_HORIZONTAL);
		m_hueSlider->SetMinSize(wxSize(200, -1));

		hueSliderSizer->Add(m_hueSlider, 1, wxALL | wxALIGN_CENTER_VERTICAL, 5);

		m_hueSliderText = new wxTextCtrl(hueSliderSizer->GetStaticBox(), wxID_ANY, wxT("180"), wxDefaultPosition, wxSize(40, -1), 0);
		m_hueSliderText->SetMaxLength(3);

		hueSliderSizer->Add(m_hueSliderText, 0, wxALL | wxALIGN_CENTER_VERTICAL, 5);

		barSizer->Add(hueSliderSizer, 0, wxALL | wxEXPAND, 5);
		

		auto* m_HUEToleranceSizer = new wxStaticBoxSizer(new wxStaticBox(this, wxID_ANY, wxT("HUE Tolerance")), wxHORIZONTAL);

		m_toleranceSlider = new wxSlider(m_HUEToleranceSizer->GetStaticBox(), wxID_ANY, 20, 0, 100, wxDefaultPosition, wxDefaultSize, wxSL_HORIZONTAL);
		m_toleranceSlider->SetMinSize(wxSize(200, -1));

		m_HUEToleranceSizer->Add(m_toleranceSlider, 1, wxALL | wxALIGN_CENTER_VERTICAL, 5);

		m_toleranceText = new wxTextCtrl(m_HUEToleranceSizer->GetStaticBox(), wxID_ANY, wxT("20"), wxDefaultPosition, wxSize(40, -1), 0);
		m_toleranceText->SetMaxLength(3);

		m_HUEToleranceSizer->Add(m_toleranceText, 0, wxALL | wxALIGN_CENTER_VERTICAL, 5);

		barSizer->Add(m_HUEToleranceSizer, 0, wxALL | wxEXPAND, 5);

		m_staticline3 = new wxStaticLine(this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL);
		barSizer->Add(m_staticline3, 0, wxEXPAND | wxALL, 5);


		auto mixedFactorSizer = new wxStaticBoxSizer(new wxStaticBox(this, wxID_ANY, wxT("Mixing factor")), wxHORIZONTAL);

		m_mixedFactorSlider = new wxSlider(mixedFactorSizer->GetStaticBox(), wxID_ANY, 0, 0, 100, wxDefaultPosition, wxDefaultSize, wxSL_HORIZONTAL);
		m_mixedFactorSlider->SetMinSize(wxSize(200, -1));

		mixedFactorSizer->Add(m_mixedFactorSlider, 1, wxALL | wxALIGN_CENTER_VERTICAL, 5);

		m_mixedFactorText = new wxTextCtrl(mixedFactorSizer->GetStaticBox(), wxID_ANY, wxT("0"), wxDefaultPosition, wxSize(40, -1), 0);
		m_mixedFactorText->SetMaxLength(4);

		mixedFactorSizer->Add(m_mixedFactorText, 0, wxALL | wxALIGN_CENTER_VERTICAL, 5);

		barSizer->Add(mixedFactorSizer, 0, wxALIGN_BOTTOM | wxALL | wxEXPAND, 5);

		auto* m_staticline4 = new wxStaticLine(this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL);
		barSizer->Add(m_staticline4, 0, wxEXPAND | wxALL, 5);
		

		auto* totallyNotSuspiciousLookingSizer = new wxBoxSizer(wxVERTICAL);

		m_totallyNotSuspiciousLookingButton = new wxBitmapButton(this, wxID_ANY, wxNullBitmap, wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW | 0);

		wxImage::AddHandler(new wxPNGHandler);
		m_totallyNotSuspiciousLookingButton->SetBitmap(wxBitmap(wxT("res/buttonRaspberries.png"), wxBITMAP_TYPE_ANY));
		m_totallyNotSuspiciousLookingButton->SetBitmapPressed(wxBitmap(wxT("res/buttonRaspberriesClicked.png"), wxBITMAP_TYPE_ANY));
		m_totallyNotSuspiciousLookingButton->SetBitmapCurrent(wxBitmap(wxT("res/buttonRaspberriesHover.png"), wxBITMAP_TYPE_ANY));
		m_totallyNotSuspiciousLookingButton->SetMaxSize(wxSize(100, 100));

		totallyNotSuspiciousLookingSizer->Add(m_totallyNotSuspiciousLookingButton, 0, wxALIGN_CENTER | wxALL | wxSHAPED | wxEXPAND, 5);

		barSizer->Add(totallyNotSuspiciousLookingSizer, 1, wxEXPAND|wxRESERVE_SPACE_EVEN_IF_HIDDEN, 5);

		mainSizer->Add(barSizer, 0, wxEXPAND, 5);


		auto* drawAreaSizer = new wxBoxSizer(wxVERTICAL);


		m_view = new ImageView(this, m_model, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL);
		m_view->SetForegroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_WINDOW));
		m_view->SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_HIGHLIGHTTEXT));
		
		drawAreaSizer->Add(m_view, 1, wxEXPAND | wxALL, 0);

		m_totallyNotSuspiciousLookingAnimationCtrl = new wxAnimationCtrl{ this, wxID_ANY, wxAnimation{ "res/raspberry_thumbnail.gif" } };
		m_totallyNotSuspiciousLookingAnimationCtrl->SetBackgroundColour(wxColour{ "White" });

		auto* m_totallyNotSuspiciousLookingSizer = new wxBoxSizer(wxHORIZONTAL);
		m_totallyNotSuspiciousLookingSizer->Add(m_totallyNotSuspiciousLookingAnimationCtrl, 0, wxALIGN_CENTER, 5);
		drawAreaSizer->Add(m_totallyNotSuspiciousLookingSizer, 1, wxALIGN_CENTER, 5);

		
		mainSizer->Add(drawAreaSizer, 1, wxEXPAND, 5);

		
		this->SetSizer(mainSizer);
		this->wxWindowBase::Layout();
		m_menubar = new wxMenuBar(0);
		m_fileMenu = new wxMenu();

		m_menuItemLoadImage = new wxMenuItem(m_fileMenu, wxID_ANY, wxString(wxT("Load Image...")), wxEmptyString, wxITEM_NORMAL);
		m_fileMenu->Append(m_menuItemLoadImage);

		m_menuItemSaveImage = new wxMenuItem(m_fileMenu, wxID_ANY, wxString(wxT("Save Image...")), wxEmptyString, wxITEM_NORMAL);
		m_fileMenu->Append(m_menuItemSaveImage);

		m_fileMenu->AppendSeparator();

		m_menuItemLoadConfig = new wxMenuItem(m_fileMenu, wxID_ANY, wxString(wxT("Load Config...")), wxEmptyString, wxITEM_NORMAL);
		m_fileMenu->Append(m_menuItemLoadConfig);
		
		m_menuItemSaveConfig = new wxMenuItem(m_fileMenu, wxID_ANY, wxString(wxT("Save Config...")), wxEmptyString, wxITEM_NORMAL);
		m_fileMenu->Append(m_menuItemSaveConfig);
		
		m_fileMenu->AppendSeparator();

		auto* m_exit = new wxMenuItem(m_fileMenu, wxID_ANY, wxString(wxT("Exit")) + wxT('\t') + wxT("Alt+F4"), wxEmptyString, wxITEM_NORMAL);
		
		m_fileMenu->Append(m_exit);
		m_menubar->Append(m_fileMenu, wxT("File"));

		m_viewMenu = new wxMenu();

		auto* m_fullscreen = new wxMenuItem(m_viewMenu, wxID_ANY, wxString(wxT("Fullscreen")) + wxT('\t') + wxT("F12"), wxEmptyString, wxITEM_NORMAL);
		m_viewMenu->Append(m_fullscreen);


		m_menuItemQualityPreview = new wxMenuItem(m_fileMenu, wxID_ANY, wxString(wxT("Render high quality preview")), wxEmptyString, wxITEM_CHECK);
		m_viewMenu->Append(m_menuItemQualityPreview);

		m_menubar->Append(m_viewMenu, wxT("View"));

		this->wxFrameBase::SetMenuBar(m_menubar);

		this->Centre(wxBOTH);

		
		this->Connect(wxEVT_CLOSE_WINDOW, wxCloseEventHandler(Frame::OnClose_Frame));
		this->Connect(wxEVT_UPDATE_UI, wxUpdateUIEventHandler(Frame::OnUpdateUI));
		m_grayscaleButton->Connect(wxEVT_COMMAND_TOGGLEBUTTON_CLICKED, wxCommandEventHandler(Frame::OnButtonClick_ConvertToGrayscale), NULL, this);
		m_bichromeButton->Connect(wxEVT_COMMAND_TOGGLEBUTTON_CLICKED, wxCommandEventHandler(Frame::OnButtonClick_Bichrome), NULL, this);
		m_pickBichromeColourButton->Connect(wxEVT_COMMAND_COLOURPICKER_CHANGED, wxColourPickerEventHandler(Frame::OnColourChanged_PickBichromeColour), NULL, this);
		m_keepHueButton->Connect(wxEVT_COMMAND_TOGGLEBUTTON_CLICKED, wxCommandEventHandler(Frame::OnButtonClick_KeepOneHue), NULL, this);
		m_toleranceSlider->Connect(wxEVT_SCROLL_CHANGED, wxScrollEventHandler(Frame::OnScrollThumbTrack_HueTolerance), NULL, this);
		m_toleranceSlider->Connect(wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler(Frame::OnScrollThumbTrack_HueTolerance), NULL, this);
		m_toleranceText->Connect(wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler(Frame::OnText_ChangeHueTolerance), NULL, this);
		m_hueSlider->Connect(wxEVT_SCROLL_CHANGED, wxScrollEventHandler(Frame::OnScrollThumbTrack_HueKept), NULL, this);
		m_hueSlider->Connect(wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler(Frame::OnScrollThumbTrack_HueKept), NULL, this);
		m_hueSliderText->Connect(wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler(Frame::OnText_HueKept), NULL, this);
		m_totallyNotSuspiciousLookingButton->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(Frame::OnButtonClick_TotallyNotSuspiciousLookingButton), NULL, this);
		m_redChannelSlider->Connect(wxEVT_SCROLL_CHANGED, wxScrollEventHandler(Frame::OnScrollThumbTrack_ChangeRedChannel), NULL, this);
		m_redChannelSlider->Connect(wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler(Frame::OnScrollThumbTrack_ChangeRedChannel), NULL, this);
		m_redChannelText->Connect(wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler(Frame::OnText_ChangeRedChannel), NULL, this);
		m_greenChannelSlider->Connect(wxEVT_SCROLL_CHANGED, wxScrollEventHandler(Frame::OnScrollThumbTrack_ChangeGreenChannel), NULL, this);
		m_greenChannelSlider->Connect(wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler(Frame::OnScrollThumbTrack_ChangeGreenChannel), NULL, this);
		m_greenChannelText->Connect(wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler(Frame::OnText_ChangeGreenChannel), NULL, this);
		m_blueChannelSlider->Connect(wxEVT_SCROLL_CHANGED, wxScrollEventHandler(Frame::OnScrollThumbTrack_ChangeBlueChannel), NULL, this);
		m_blueChannelSlider->Connect(wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler(Frame::OnScrollThumbTrack_ChangeBlueChannel), NULL, this);
		m_blueChannelText->Connect(wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler(Frame::OnText_ChangeBlueChannel), NULL, this);
		m_mixedFactorSlider->Connect(wxEVT_SCROLL_CHANGED, wxScrollEventHandler(Frame::OnScrollThumbTrack_MixOriginalWithConverted), NULL, this);
		m_mixedFactorSlider->Connect(wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler(Frame::OnScrollThumbTrack_MixOriginalWithConverted), NULL, this);
		m_mixedFactorText->Connect(wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler(Frame::OnText_MixOriginalWithConverted), NULL, this);
		m_fileMenu->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler(Frame::OnMenuSelection_LoadImage), this, m_menuItemLoadImage->GetId());
		m_fileMenu->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler(Frame::OnMenuSelection_LoadConfig), this, m_menuItemLoadConfig->GetId());
		m_fileMenu->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler(Frame::OnMenuSelection_SaveImage), this, m_menuItemSaveImage->GetId());
		m_fileMenu->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler(Frame::OnMenuSelection_SaveConfig), this, m_menuItemSaveConfig->GetId());
		m_fileMenu->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler(Frame::OnMenuSelection_Exit), this, m_exit->GetId());
		m_viewMenu->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler(Frame::OnMenuSelection_GoFullscreen), this, m_fullscreen->GetId());
		m_viewMenu->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler(Frame::OnMenuSelection_QualityPreview), this, m_menuItemQualityPreview->GetId());
		Bind(wxEVT_PAINT, wxPaintEventHandler(Frame::OnPaint_RefreshImage), this);
	}

	Frame::~Frame()
	{
		this->Disconnect(wxEVT_CLOSE_WINDOW, wxCloseEventHandler(Frame::OnClose_Frame));
		this->Disconnect(wxEVT_UPDATE_UI, wxUpdateUIEventHandler(Frame::OnUpdateUI));
		m_grayscaleButton->Disconnect(wxEVT_COMMAND_TOGGLEBUTTON_CLICKED, wxCommandEventHandler(Frame::OnButtonClick_ConvertToGrayscale), NULL, this);
		m_bichromeButton->Disconnect(wxEVT_COMMAND_TOGGLEBUTTON_CLICKED, wxCommandEventHandler(Frame::OnButtonClick_Bichrome), NULL, this);
		m_pickBichromeColourButton->Disconnect(wxEVT_COMMAND_COLOURPICKER_CHANGED, wxColourPickerEventHandler(Frame::OnColourChanged_PickBichromeColour), NULL, this);
		m_keepHueButton->Disconnect(wxEVT_COMMAND_TOGGLEBUTTON_CLICKED, wxCommandEventHandler(Frame::OnButtonClick_KeepOneHue), NULL, this);
		m_hueSlider->Disconnect( wxEVT_SCROLL_CHANGED, wxScrollEventHandler( Frame::OnScrollThumbTrack_HueTolerance), NULL, this );
		m_toleranceSlider->Disconnect(wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler(Frame::OnScrollThumbTrack_HueTolerance), NULL, this);
		m_toleranceText->Disconnect(wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler(Frame::OnText_ChangeHueTolerance), NULL, this);
		m_hueSlider->Disconnect(wxEVT_SCROLL_CHANGED, wxScrollEventHandler(Frame::OnScrollThumbTrack_HueKept), NULL, this);
		m_hueSlider->Disconnect(wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler(Frame::OnScrollThumbTrack_HueKept), NULL, this);
		m_hueSliderText->Disconnect(wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler(Frame::OnText_HueKept), NULL, this);
		m_totallyNotSuspiciousLookingButton->Disconnect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(Frame::OnButtonClick_TotallyNotSuspiciousLookingButton), NULL, this);
		m_redChannelSlider->Disconnect(wxEVT_SCROLL_CHANGED, wxScrollEventHandler(Frame::OnScrollThumbTrack_ChangeRedChannel), NULL, this);
		m_redChannelSlider->Disconnect(wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler(Frame::OnScrollThumbTrack_ChangeRedChannel), NULL, this);
		m_redChannelText->Disconnect(wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler(Frame::OnText_ChangeRedChannel), NULL, this);
		m_greenChannelSlider->Disconnect(wxEVT_SCROLL_CHANGED, wxScrollEventHandler(Frame::OnScrollThumbTrack_ChangeGreenChannel), NULL, this);
		m_greenChannelSlider->Disconnect(wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler(Frame::OnScrollThumbTrack_ChangeGreenChannel), NULL, this);
		m_greenChannelText->Disconnect(wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler(Frame::OnText_ChangeGreenChannel), NULL, this);
		m_blueChannelSlider->Disconnect(wxEVT_SCROLL_CHANGED, wxScrollEventHandler(Frame::OnScrollThumbTrack_ChangeBlueChannel), NULL, this);
		m_blueChannelSlider->Disconnect(wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler(Frame::OnScrollThumbTrack_ChangeBlueChannel), NULL, this);
		m_blueChannelText->Disconnect(wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler(Frame::OnText_ChangeBlueChannel), NULL, this);
		m_mixedFactorSlider->Disconnect(wxEVT_SCROLL_CHANGED, wxScrollEventHandler(Frame::OnScrollThumbTrack_MixOriginalWithConverted), NULL, this);
		m_mixedFactorSlider->Disconnect(wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler(Frame::OnScrollThumbTrack_MixOriginalWithConverted), NULL, this);
		m_mixedFactorText->Disconnect(wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler(Frame::OnText_MixOriginalWithConverted), NULL, this);

	}

}
///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Oct 26 2018)
// http://www.wxformbuilder.org/
//
// PLEASE DO *NOT* EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "inc/MainFrame.h"

///////////////////////////////////////////////////////////////////////////

namespace GrayscaleConverter
{

	Frame::Frame(wxWindow* parent, Model& newModel, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style)
		:
		wxFrame(parent, id, title, pos, size, style),
		m_model{ newModel }
	{
		this->SetSizeHints(wxDefaultSize, wxDefaultSize);

		wxBoxSizer* mainSizer;
		mainSizer = new wxBoxSizer(wxHORIZONTAL);

		wxBoxSizer* barSizer;
		barSizer = new wxBoxSizer(wxVERTICAL);

		
		m_grayscaleButton = new wxToggleButton{ this, wxID_ANY, wxT("Convert to grayscale"), wxDefaultPosition, wxDefaultSize, 0 };
		//m_grayscaleButton = new wxButton(this, wxID_ANY, wxT("Convert to grayscale"), wxDefaultPosition, wxDefaultSize, 0);
		barSizer->Add(m_grayscaleButton, 0, wxALL | wxEXPAND, 8);

		m_staticline1 = new wxStaticLine(this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL);
		barSizer->Add(m_staticline1, 0, wxEXPAND | wxALL, 5);

		wxBoxSizer* duotoneSizer;
		duotoneSizer = new wxBoxSizer(wxHORIZONTAL);

		m_bichromeButton = new wxToggleButton(this, wxID_ANY, wxT("Convert to bichrome"), wxDefaultPosition, wxDefaultSize, 0);
		//m_bichromeButton = new wxButton(this, wxID_ANY, wxT("Convert to bichrome"), wxDefaultPosition, wxDefaultSize, 0);
		duotoneSizer->Add(m_bichromeButton, 1, wxALL | wxEXPAND, 8);

		m_pickColourButton = new wxButton(this, wxID_ANY, wxT("Colour"), wxDefaultPosition, wxDefaultSize, 0);
		duotoneSizer->Add(m_pickColourButton, 1, wxALIGN_CENTER | wxALL, 8);


		barSizer->Add(duotoneSizer, 0, wxEXPAND, 5);

		m_staticline2 = new wxStaticLine(this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL);
		barSizer->Add(m_staticline2, 0, wxEXPAND | wxALL, 5);

		m_keepHueCheckBox = new wxCheckBox(this, wxID_ANY, wxT("Keep one hue"), wxDefaultPosition, wxDefaultSize, 0);
		barSizer->Add(m_keepHueCheckBox, 0, wxALIGN_CENTER | wxALL, 8);

		wxBoxSizer* hueSliderSizer;
		hueSliderSizer = new wxBoxSizer(wxHORIZONTAL);

		m_hueSlider = new wxSlider(this, wxID_ANY, 50, 0, 100, wxDefaultPosition, wxDefaultSize, wxSL_HORIZONTAL);
		m_hueSlider->SetMinSize(wxSize(200, -1));

		hueSliderSizer->Add(m_hueSlider, 1, wxALIGN_CENTER_VERTICAL | wxALL, 10);

		m_hueSliderText = new wxTextCtrl(this, wxID_ANY, wxT("0"), wxDefaultPosition, wxSize(40, -1), 0);
#ifdef __WXGTK__
		if (!m_hueSliderText->HasFlag(wxTE_MULTILINE))
		{
			m_hueSliderText->SetMaxLength(3);
		}
#else
		m_hueSliderText->SetMaxLength(3);
#endif
		hueSliderSizer->Add(m_hueSliderText, 0, wxALL | wxALIGN_CENTER_VERTICAL, 5);


		barSizer->Add(hueSliderSizer, 0, wxEXPAND, 5);

		wxBoxSizer* raspberriesSizer;
		raspberriesSizer = new wxBoxSizer(wxVERTICAL);

		m_raspberriesButton = new wxBitmapButton(this, wxID_ANY, wxNullBitmap, wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW | 0);

		wxImage::AddHandler(new wxPNGHandler);
		m_raspberriesButton->SetBitmap(wxBitmap(wxT("res/buttonRaspberries.png"), wxBITMAP_TYPE_ANY));
		m_raspberriesButton->SetBitmapPressed(wxBitmap(wxT("res/buttonRaspberriesClicked.png"), wxBITMAP_TYPE_ANY));
		m_raspberriesButton->SetBitmapCurrent(wxBitmap(wxT("res/buttonRaspberriesHover.png"), wxBITMAP_TYPE_ANY));
		m_raspberriesButton->SetMaxSize(wxSize(100, 100));

		raspberriesSizer->Add(m_raspberriesButton, 0, wxALIGN_CENTER | wxALL | wxSHAPED | wxEXPAND, 5);


		barSizer->Add(raspberriesSizer, 1, wxEXPAND, 5);

		wxBoxSizer* channelsSizer;
		channelsSizer = new wxBoxSizer(wxVERTICAL);

		wxStaticBoxSizer* redChannelSizer;
		redChannelSizer = new wxStaticBoxSizer(new wxStaticBox(this, wxID_ANY, wxT("Red")), wxHORIZONTAL);

		m_redChannelSlider = new wxSlider(redChannelSizer->GetStaticBox(), wxID_ANY, 0, -200, 200, wxDefaultPosition, wxDefaultSize, wxSL_HORIZONTAL);
		m_redChannelSlider->SetMinSize(wxSize(200, -1));

		redChannelSizer->Add(m_redChannelSlider, 1, wxALL | wxALIGN_CENTER_VERTICAL, 5);

		m_redChannelText = new wxTextCtrl(redChannelSizer->GetStaticBox(), wxID_ANY, wxT("0"), wxDefaultPosition, wxSize(40, -1), 0);
#ifdef __WXGTK__
		if (!m_redChannelText->HasFlag(wxTE_MULTILINE))
		{
			m_redChannelText->SetMaxLength(3);
		}
#else
		m_redChannelText->SetMaxLength(3);
#endif
		redChannelSizer->Add(m_redChannelText, 0, wxALL | wxALIGN_CENTER_VERTICAL, 5);


		channelsSizer->Add(redChannelSizer, 1, wxALIGN_BOTTOM | wxALL | wxEXPAND, 5);

		wxStaticBoxSizer* greenChannelSizer;
		greenChannelSizer = new wxStaticBoxSizer(new wxStaticBox(this, wxID_ANY, wxT("Green")), wxHORIZONTAL);

		m_greenChannelSlider = new wxSlider(greenChannelSizer->GetStaticBox(), wxID_ANY, 0, -200, 200, wxDefaultPosition, wxDefaultSize, wxSL_HORIZONTAL);
		m_greenChannelSlider->SetMinSize(wxSize(200, -1));

		greenChannelSizer->Add(m_greenChannelSlider, 1, wxALL | wxALIGN_CENTER_VERTICAL, 5);

		m_greenChannelText = new wxTextCtrl(greenChannelSizer->GetStaticBox(), wxID_ANY, wxT("0"), wxDefaultPosition, wxSize(40, -1), 0);
#ifdef __WXGTK__
		if (!m_greenChannelText->HasFlag(wxTE_MULTILINE))
		{
			m_greenChannelText->SetMaxLength(3);
		}
#else
		m_greenChannelText->SetMaxLength(3);
#endif
		greenChannelSizer->Add(m_greenChannelText, 0, wxALIGN_CENTER_VERTICAL | wxALL, 5);


		channelsSizer->Add(greenChannelSizer, 1, wxALIGN_BOTTOM | wxALL | wxEXPAND, 5);

		wxStaticBoxSizer* blueChannelSizer;
		blueChannelSizer = new wxStaticBoxSizer(new wxStaticBox(this, wxID_ANY, wxT("Blue")), wxHORIZONTAL);

		m_blueChannelSlider = new wxSlider(blueChannelSizer->GetStaticBox(), wxID_ANY, 0, -200, 200, wxDefaultPosition, wxDefaultSize, wxSL_HORIZONTAL);
		m_blueChannelSlider->SetMinSize(wxSize(200, -1));

		blueChannelSizer->Add(m_blueChannelSlider, 1, wxALL | wxALIGN_CENTER_VERTICAL, 5);

		m_blueChannelText = new wxTextCtrl(blueChannelSizer->GetStaticBox(), wxID_ANY, wxT("0"), wxDefaultPosition, wxSize(40, -1), 0);
#ifdef __WXGTK__
		if (!m_blueChannelText->HasFlag(wxTE_MULTILINE))
		{
			m_blueChannelText->SetMaxLength(3);
		}
#else
		m_blueChannelText->SetMaxLength(3);
#endif
		blueChannelSizer->Add(m_blueChannelText, 0, wxALIGN_CENTER_VERTICAL | wxALL, 5);


		channelsSizer->Add(blueChannelSizer, 1, wxALL | wxEXPAND, 5);


		barSizer->Add(channelsSizer, 1, wxALIGN_BOTTOM | wxEXPAND | wxSHAPED, 5);


		mainSizer->Add(barSizer, 0, wxEXPAND, 5);

		wxBoxSizer* drawAreaSizer;
		drawAreaSizer = new wxBoxSizer(wxVERTICAL);

		m_view = new ImageView(this, m_model, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL);
		m_view->SetForegroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_WINDOW));
		m_view->SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_HIGHLIGHTTEXT));

		drawAreaSizer->Add(m_view, 1, wxEXPAND | wxALL, 0);


		mainSizer->Add(drawAreaSizer, 1, wxEXPAND, 5);


		this->SetSizer(mainSizer);
		this->Layout();
		m_menubar = new wxMenuBar(0);
		fileMenu = new wxMenu();
		wxMenuItem* m_loadImage;
		m_loadImage = new wxMenuItem(fileMenu, wxID_ANY, wxString(wxT("Load Image...")), wxEmptyString, wxITEM_NORMAL);
		fileMenu->Append(m_loadImage);

		wxMenuItem* m_loadConfig;
		m_loadConfig = new wxMenuItem(fileMenu, wxID_ANY, wxString(wxT("Load Config...")), wxEmptyString, wxITEM_NORMAL);
		fileMenu->Append(m_loadConfig);

		fileMenu->AppendSeparator();

		wxMenuItem* m_saveImage;
		m_saveImage = new wxMenuItem(fileMenu, wxID_ANY, wxString(wxT("Save Image...")), wxEmptyString, wxITEM_NORMAL);
		fileMenu->Append(m_saveImage);

		wxMenuItem* m_saveConfig;
		m_saveConfig = new wxMenuItem(fileMenu, wxID_ANY, wxString(wxT("Save Config...")), wxEmptyString, wxITEM_NORMAL);
		fileMenu->Append(m_saveConfig);

		fileMenu->AppendSeparator();

		wxMenuItem* m_exit;
		m_exit = new wxMenuItem(fileMenu, wxID_ANY, wxString(wxT("Exit")) + wxT('\t') + wxT("Alt+F4"), wxEmptyString, wxITEM_NORMAL);
		fileMenu->Append(m_exit);

		m_menubar->Append(fileMenu, wxT("File"));

		m_menu3 = new wxMenu();
		wxMenuItem* m_fullscreen;
		m_fullscreen = new wxMenuItem(m_menu3, wxID_ANY, wxString(wxT("Fullscreen")) + wxT('\t') + wxT("F12"), wxEmptyString, wxITEM_NORMAL);
		m_menu3->Append(m_fullscreen);

		m_menubar->Append(m_menu3, wxT("View"));

		this->SetMenuBar(m_menubar);


		this->Centre(wxBOTH);

		// Connect Events
		this->Connect(wxEVT_UPDATE_UI, wxUpdateUIEventHandler(Frame::OnUpdateUI));
		m_grayscaleButton->Connect(wxEVT_COMMAND_TOGGLEBUTTON_CLICKED, wxCommandEventHandler(Frame::OnButtonClick_ConvertToGrayscale), NULL, this);
		//m_grayscaleButton->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(Frame::OnButtonClick_ConvertToGrayscale), NULL, this);
		m_bichromeButton->Connect(wxEVT_COMMAND_TOGGLEBUTTON_CLICKED, wxCommandEventHandler(Frame::OnButtonClick_Bichrome), NULL, this);
		//m_bichromeButton->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(Frame::OnButtonClick_Bichrome), NULL, this);
		m_pickColourButton->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(Frame::OnButtonClick_PickColour), NULL, this);
		m_keepHueCheckBox->Connect(wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler(Frame::OnCheckBox_KeepOneHue), NULL, this);
		m_hueSlider->Connect(wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler(Frame::OnScrollThumbTrack_HueIntesivity), NULL, this);
		m_hueSliderText->Connect(wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler(Frame::OnText_ChangeHueIntensivity), NULL, this);
		m_raspberriesButton->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(Frame::OnButtonClick_RaspberriesButton), NULL, this);
		m_redChannelSlider->Connect(wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler(Frame::OnScrollThumbTrack_ChangeRedChannel), NULL, this);
		m_redChannelText->Connect(wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler(Frame::OnText_ChangeRedChannel), NULL, this);
		m_greenChannelSlider->Connect(wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler(Frame::OnScrollThumbTrack_ChangeGreenChannel), NULL, this);
		m_greenChannelText->Connect(wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler(Frame::OnText_ChangeGreenChannel), NULL, this);
		m_blueChannelSlider->Connect(wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler(Frame::OnScrollThumbTrack_ChangeBlueChannel), NULL, this);
		m_blueChannelText->Connect(wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler(Frame::OnText_ChangeBlueChannel), NULL, this);
		fileMenu->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler(Frame::OnMenuSelection_LoadImage), this, m_loadImage->GetId());
		fileMenu->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler(Frame::OnMenuSelection_LoadConfig), this, m_loadConfig->GetId());
		fileMenu->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler(Frame::OnMenuSelection_SaveImage), this, m_saveImage->GetId());
		fileMenu->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler(Frame::OnMenuSelection_SaveConfig), this, m_saveConfig->GetId());
		fileMenu->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler(Frame::OnMenuSelection_Exit), this, m_exit->GetId());
		m_menu3->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler(Frame::OnMenuSelection_GoFullscreen), this, m_fullscreen->GetId());
	}

	Frame::~Frame()
	{
		// Disconnect Events
		this->Disconnect(wxEVT_UPDATE_UI, wxUpdateUIEventHandler(Frame::OnUpdateUI));
		m_grayscaleButton->Disconnect(wxEVT_COMMAND_TOGGLEBUTTON_CLICKED, wxCommandEventHandler(Frame::OnButtonClick_ConvertToGrayscale), NULL, this);
		//m_grayscaleButton->Disconnect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(Frame::OnButtonClick_ConvertToGrayscale), NULL, this);
		m_bichromeButton->Disconnect(wxEVT_COMMAND_TOGGLEBUTTON_CLICKED, wxCommandEventHandler(Frame::OnButtonClick_Bichrome), NULL, this);
		//m_bichromeButton->Disconnect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(Frame::OnButtonClick_Bichrome), NULL, this);
		m_pickColourButton->Disconnect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(Frame::OnButtonClick_PickColour), NULL, this);
		m_keepHueCheckBox->Disconnect(wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler(Frame::OnCheckBox_KeepOneHue), NULL, this);
		//m_hueSlider->Disconnect( wxEVT_SCROLL_CHANGED, wxScrollEventHandler( Frame::OnScrollChanged_HueIntesivity ), NULL, this );
		m_hueSlider->Disconnect(wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler(Frame::OnScrollThumbTrack_HueIntesivity), NULL, this);
		m_hueSliderText->Disconnect(wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler(Frame::OnText_ChangeHueIntensivity), NULL, this);
		m_raspberriesButton->Disconnect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(Frame::OnButtonClick_RaspberriesButton), NULL, this);
		//m_redChannelSlider->Disconnect( wxEVT_SCROLL_CHANGED, wxScrollEventHandler( Frame::OnScrollChanged_ChangeRedChannel ), NULL, this );
		m_redChannelSlider->Disconnect(wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler(Frame::OnScrollThumbTrack_ChangeRedChannel), NULL, this);
		m_redChannelText->Disconnect(wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler(Frame::OnText_ChangeRedChannel), NULL, this);
		//m_greenChannelSlider->Disconnect( wxEVT_SCROLL_CHANGED, wxScrollEventHandler( Frame::OnScrollChanged_ChangeGreenChannel ), NULL, this );
		m_greenChannelSlider->Disconnect(wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler(Frame::OnScrollThumbTrack_ChangeGreenChannel), NULL, this);
		m_greenChannelText->Disconnect(wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler(Frame::OnText_ChangeGreenChannel), NULL, this);
		//m_blueChannelSlider->Disconnect( wxEVT_SCROLL_CHANGED, wxScrollEventHandler( Frame::OnScrollChanged_ChangeBlueChannel ), NULL, this );
		m_blueChannelSlider->Disconnect(wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler(Frame::OnScrollThumbTrack_ChangeBlueChannel), NULL, this);
		m_blueChannelText->Disconnect(wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler(Frame::OnText_ChangeBlueChannel), NULL, this);

	}

}
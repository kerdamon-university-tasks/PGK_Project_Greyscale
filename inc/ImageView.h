#pragma once

#include <wx/panel.h>
#include <wx/dcbuffer.h>

#include "inc/Model.h"

class ImageView final : public wxPanel
{
public:

	ImageView(wxWindow* parent, Model newModel, wxWindowID winid = wxID_ANY, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize, long style = 524288 | wxBORDER_NONE)
		:
		wxPanel(parent, winid, pos, size, style),
		m_model{ newModel }
	{}

	void Update() override;

private:

	Model& m_model;
	
};

#pragma once

#include <wx/panel.h>
#include <wx/dcbuffer.h>

#include "inc/Model.h"

namespace GreyscaleConverter
{
	/// Class representing View in MVC design pattern
	///
	/// Extends wxWidget wxPanel class to display live preview on it
	class ImageView final : public wxPanel
	{
	public:

		/// Contructor for ImageView
		///
		/// Creates instance of View, called only once during process od program initialization
		///
		/// @param parent wxImage parent element
		/// @param model reference to Model
		/// @param winid wxImage window id
		/// @param pos position of View (relative)
		/// @param size size of View
		/// @param style style code (wxWidgets)
		ImageView(wxWindow* parent, Model& model, wxWindowID winid = wxID_ANY, const wxPoint& pos = wxDefaultPosition,
		          const wxSize& size = wxDefaultSize, long style = 524288 | wxBORDER_NONE)
			:
			wxPanel(parent, winid, pos, size, style),
			m_model{model}
		{
		}

		/// Updates image displayed on View
		///
		/// @param highQuality flag determining of image should be displayed in high quality
		void UpdateImage(bool highQuality);

	private:

		Model& m_model;
	};
}

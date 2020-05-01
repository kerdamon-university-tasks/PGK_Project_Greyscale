#include "inc/ImageView.h"

void ImageView::Update()
{
	wxImage imageThumbnail = m_model.GetThumbnail();
	
	imageThumbnail.Rescale(wxPanel::GetSize().x, wxPanel::GetSize().y);
	
	wxClientDC clientDc{ this };
	wxBufferedDC bufferedDc{ &clientDc };
	
	bufferedDc.DrawBitmap(wxBitmap(imageThumbnail), 0, 0);
	
	wxPanel::Update();
}

#include "inc/ImageView.h"

namespace GrayscaleConverter
{

	void ImageView::Update()
	{
		auto imageThumbnail = m_model.GetImageThumbnail();
		
		imageThumbnail.Rescale(wxPanel::GetSize().x, wxPanel::GetSize().y);

		wxClientDC clientDc{ this };
		wxBufferedDC bufferedDc{ &clientDc };

		bufferedDc.DrawBitmap(wxBitmap(imageThumbnail), 0, 0);

		wxPanel::Update();
	}

}
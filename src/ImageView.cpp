#include "inc/ImageView.h"

namespace GrayscaleConverter
{

	void ImageView::UpdateImage()
	{
		//auto imageThumbnail = m_model.GetImageThumbnail();
		auto imageThumbnail = m_model.GetImage();

		imageThumbnail.Rescale(wxPanel::GetSize().x, wxPanel::GetSize().y);

		wxClientDC clientDc{ this };
		wxBufferedDC bufferedDc{ &clientDc };

		bufferedDc.DrawBitmap(wxBitmap(imageThumbnail), 0, 0);
	}
}

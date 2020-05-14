#include "inc/ImageView.h"

namespace GrayscaleConverter
{

	void ImageView::UpdateImage()
	{
		//auto imageThumbnail = m_model.GetImageThumbnail();
		auto bitmap = m_model.GetBitmap();

		//imageThumbnail.Rescale(wxPanel::GetSize().x, wxPanel::GetSize().y);

		wxClientDC clientDc{ this };
		wxBufferedDC bufferedDc{ &clientDc };

		//bufferedDc.DrawBitmap(wxBitmap(imageThumbnail), 0, 0);
		bufferedDc.DrawBitmap(bitmap, 0, 0);
	}
}

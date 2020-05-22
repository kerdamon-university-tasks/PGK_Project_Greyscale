#include "inc/ImageView.h"

namespace GreyscaleConverter
{

	void ImageView::UpdateImage()
	{
		auto imageThumbnail = m_model.GetImageThumbnail();
		if (!imageThumbnail.IsOk())
			return;
		
		const auto x = GetSize().x;
		const auto y = GetSize().y;
		if(x > 0 && y > 0)
			imageThumbnail.Rescale(x, y);

		wxClientDC clientDc{ this };
		wxBufferedDC bufferedDc{ &clientDc };

		bufferedDc.DrawBitmap(wxBitmap(imageThumbnail), 0, 0);
	}
}

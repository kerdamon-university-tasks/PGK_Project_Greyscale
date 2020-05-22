#include "inc/ImageView.h"

namespace GreyscaleConverter
{

	void ImageView::UpdateImage(const bool highQuality)
	{
		auto imageThumbnail = m_model.GetImageThumbnail();
		if (!imageThumbnail.IsOk())
			return;
		
		const auto x = GetSize().x;
		const auto y = GetSize().y;
		if(x > 0 && y > 0)
		{
			if (highQuality)
				imageThumbnail.Rescale(x, y, wxIMAGE_QUALITY_HIGH);
			else
				imageThumbnail.Rescale(x, y);
		}
			


		wxClientDC clientDc{ this };
		wxBufferedDC bufferedDc{ &clientDc };

		bufferedDc.DrawBitmap(wxBitmap(imageThumbnail), 0, 0);
	}
}

#include "inc/Model.h"


namespace GrayscaleConverter
{
	Model::Model()
		:
		m_originalImage{ wxImage{} },
		m_imageThumbnail{ wxImage{} }
	{
		m_originalImage = wxImage{};
		m_imageThumbnail = wxImage{};
		wxInitAllImageHandlers();
	}

	void Model::AdjustImageThumbnail()
	{
		const auto imageSize = m_originalImage.GetSize();
		if (imageSize.x > m_maxImageThumbnailSize)
		{
			const auto scaleFactor = static_cast<float>(m_maxImageThumbnailSize) / static_cast<float>(imageSize.x);
			const wxSize newSize(
				static_cast<int>(static_cast<float>(imageSize.x) * scaleFactor),
				static_cast<int>(static_cast<float>(imageSize.y) * scaleFactor)
			);
			m_originalImage.Resize(newSize, wxPoint(0, 0));
		}
	}


	/// Model getters
	const wxImage& Model::GetImageThumbnail() const
	{
		return m_imageThumbnail;
	}

	/// End Model getters


	///// Model setters
	//void Model::SetFixedColor(ColorChannel channel)
	//{
	//	m_fixedColor = channel;
	//}

	//void Model::SetColorTolerance(float tolerance)
	//{
	//	m_colorTolerance = tolerance;
	//}

	//void Model::SetRedChannel(int value)
	//{
	//	m_redChannel = value;
	//}

	//void Model::SetBlueChannel(int value)
	//{
	//	m_blueChannel = value;
	//}

	//void Model::SetGreenChannel(int value)
	//{
	//	m_greenChannel = value;
	//}

	//void Model::SetIsFixedColor(bool flag)
	//{
	//	m_isFixedColor = flag;
	//}

	/// End Model setters


	void Model::LoadImageFromFile()
	{
		//TODO zaklepac
	}

	void Model::SaveImageToFile() const
	{
		//TODO zaklepac
	}

	void Model::ConvertToDuechrome()
	{
		/// TODO tu pewnie beda liczone jakies parametry ktre przekarzemy do funkcji nizej
		m_originalImage = ImageConversion::ConvertToDuechrome(m_originalImage);
	}

	void Model::ConvertToGreyScale()
	{
		/// TODO tu pewnie beda liczone jakies parametry ktre przekarzemy do funkcji nizej
		m_originalImage = ImageConversion::ConvertToGreyScale(m_originalImage);
	}

	void EasterEgg()
	{
	}
}

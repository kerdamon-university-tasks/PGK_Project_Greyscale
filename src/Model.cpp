#include "inc/Model.h"


namespace GrayscaleConverter
{
	Model::Model()
		:
		m_originalImage{ new wxImage{} },
		m_originalImageCopy{ wxImage{} },
		m_imageThumbnail{ wxImage{} },
		m_imageThumbnailCopy{ wxImage{} }
	{
		wxInitAllImageHandlers();
	}

	void Model::AdjustImageThumbnail()
	{
		const auto imageSize = m_originalImage->GetSize();
		if (imageSize.x > m_maxImageThumbnailSize)
		{
			const auto scaleFactor = static_cast<float>(m_maxImageThumbnailSize) / static_cast<float>(imageSize.x);
			const wxSize newSize{
				static_cast<int>(static_cast<float>(imageSize.x)* scaleFactor),
				static_cast<int>(static_cast<float>(imageSize.y)* scaleFactor)
			};
			m_imageThumbnail.Resize(newSize, wxPoint(0, 0));
		}
	}


	/// Model getters
	const wxImage& Model::GetImageThumbnail() const
	{
		return m_imageThumbnail;
	}


	void Model::LoadImageFromFile(const wxString& filePath)
	{
		if (!m_originalImage->LoadFile(filePath))
		{
			/* throw some exception here */
		}
		m_originalImageCopy = m_originalImage->Copy();
		m_imageThumbnail = m_originalImage->Copy();
		AdjustImageThumbnail();
		m_imageThumbnailCopy = m_imageThumbnail.Copy();
	}

	void Model::SaveImageToFile(const wxString& filename)
	{
		switch (m_mode)
		{
			case WorkMode::BICHROME:
				ImageConversion::ConvertToBichrome(m_originalImageCopy);
				break;
			case WorkMode::GREYSCALE:
				ImageConversion::ConvertToGreyScale(m_originalImageCopy);
				break;
			case WorkMode::NONE:
				break;			
		}

		if (!m_originalImageCopy.SaveFile(filename))
		{
			/* rzucenie jakiegos wyjatku */
		};
	}

	void Model::ApplyParametersToImage()
	{
		switch (m_mode)
		{
		case WorkMode::BICHROME:
			ImageConversion::ConvertToBichrome(m_imageThumbnailCopy);
			break;
		case WorkMode::GREYSCALE:
			ImageConversion::ConvertToGreyScale(m_imageThumbnailCopy);
			break;
		case WorkMode::NONE:
			break;
		}
	}

	void EasterEgg()
	{
	}
}

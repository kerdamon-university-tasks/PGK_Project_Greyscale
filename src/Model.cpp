#include "inc/Model.h"


namespace GreyscaleConverter
{
	Model::Model()
	{
		wxInitAllImageHandlers();
	}

	void Model::AdjustImageThumbnail()
	{
		auto width = m_originalImage.GetWidth();
		auto height = m_originalImage.GetHeight();

		const auto longerSide = width > height ? width : height;
		if (longerSide > m_maxImageThumbnailSize)
		{
			const auto scaleFactor = static_cast<float>(m_maxImageThumbnailSize) / static_cast<float>(longerSide);
			
			width = static_cast<int>(static_cast<float>(width) * scaleFactor);
			height = static_cast<int>(static_cast<float>(height) * scaleFactor);
			
			m_imageThumbnail.Rescale(width, height);
		}
	}

	void Model::LoadImageFromFile(const wxString& filePath)
	{
		if (!m_originalImage.LoadFile(filePath, wxBITMAP_TYPE_JPEG))
			wxLogError(_("Couldn't load file!"));

		m_originalImageCopy = m_originalImage.Copy();
		m_imageThumbnail = m_originalImage.Copy();
		AdjustImageThumbnail();
		m_imageThumbnailCopy = m_imageThumbnail.Copy();
	}

	void Model::LoadConfigFromFile(const wxString& filePath)
	{
		//todo zaklepac
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
			default:
				break;			
		}

		if (!m_originalImageCopy.SaveFile(filename))
			wxLogError(_("Couldn't save file!"));

		//todo przetestowac
	}

	void Model::SaveConfigToFile(const wxString& filePath) const
	{
		//todo zaklepac
	}

	void Model::ApplyParametersToThumbnail()
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

	void Model::EasterEgg()
	{
	}
}

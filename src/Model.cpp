#include "inc/Model.h"


namespace GrayscaleConverter
{
	Model::Model()
		:
		m_originalImage{ new wxImage{} },
		m_originalImageCopy{ new wxImage{} },
		m_imageThumbnail{ new wxImage{} },
		m_imageThumbnailCopy{ new wxImage{} }
	{
		wxInitAllImageHandlers();
	}

	void Model::AdjustImageThumbnail()
	{
		const int width = m_originalImage->GetWidth();
		const int height = m_originalImage->GetHeight();

		if (width > 500)
		{
			const auto scaleFactor = 500.f / static_cast<float>(width);
			const wxSize newSize(
				static_cast<int>(static_cast<float>(width)* scaleFactor),
				static_cast<int>(static_cast<float>(height)* scaleFactor)
			);
			m_imageThumbnail->Resize(newSize, wxPoint(0, 0));
		}
	}


	/// Model getters
	const wxImage& Model::GetImageThumbnail() const
	{
		return *m_imageThumbnail;
	}


	bool Model::GetIsResultSaved() const
	{
		return m_isResultSaved;
	}

	bool Model::GetIsConfigSaved() const
	{
		return m_isConfigSave;
	}

	void Model::LoadImageFromFile(const wxString& filePath)
	{
		m_originalImage = new wxImage{ filePath };
		m_originalImageCopy = new wxImage{ *m_originalImage };
		m_imageThumbnail = new wxImage{ *m_originalImage };
		AdjustImageThumbnail();
		m_imageThumbnailCopy = new wxImage{ *m_imageThumbnail };
	}

	void Model::LoadConfigFromFile(const wxString& filePath)
	{
		
	}

	void Model::SaveImageToFile(const wxString& filename)
	{
		switch (m_mode)
		{
			case WorkMode::BICHROME:
				ImageConversion::ConvertToBichrome(*m_originalImageCopy);
				break;
			case WorkMode::GREYSCALE:
				ImageConversion::ConvertToGreyScale(*m_originalImageCopy);
				break;
			case WorkMode::NONE:
				break;			
		}

		if (!m_originalImageCopy->SaveFile(filename))
		{
			/* rzucenie jakiegos wyjatku */
		};
	}

	void Model::SaveConfigToFile(const wxString& filePath) const
	{
		
	}

	void Model::ApplyParametersToImage()
	{
		switch (m_mode)
		{
		case WorkMode::BICHROME:
			ImageConversion::ConvertToBichrome(*m_imageThumbnailCopy);
			break;
		case WorkMode::GREYSCALE:
			ImageConversion::ConvertToGreyScale(*m_imageThumbnailCopy);
			break;
		case WorkMode::NONE:
			break;
		}
	}

	void EasterEgg()
	{
	}
}

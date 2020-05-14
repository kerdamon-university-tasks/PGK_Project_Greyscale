#include "inc/Model.h"


namespace GrayscaleConverter
{
	Model::Model()
	{
		//wxImage::AddHandler(new wxPNGHandler);
		//wxImage::AddHandler(new wxJPEGHandler);
	}

	void Model::AdjustImageThumbnail()
	{
		const int width = m_originalImage.GetWidth();
		const int height = m_originalImage.GetHeight();

		if (width > 500)
		{
			const auto scaleFactor = 500.f / static_cast<float>(width);
			const wxSize newSize(
				static_cast<int>(static_cast<float>(width)* scaleFactor),
				static_cast<int>(static_cast<float>(height)* scaleFactor)
			);
			m_imageThumbnail.Resize(newSize, wxPoint(0, 0));
		}
	}


	/// Model getters
	const wxImage& Model::GetImageThumbnail() const
	{
		return m_imageThumbnail;
	}


	bool Model::GetIsResultSaved() const
	{
		return m_isResultSaved;
	}

	bool Model::GetIsConfigSaved() const
	{
		return m_isConfigSave;
	}

	void Model::LoadImageFromFile(wxString filePath)
	{
		if (!m_originalImage.LoadFile(filePath, wxBITMAP_TYPE_JPEG))
		{
			wxLogError(_("Nie gasi"));
		}
		m_originalBitmap = wxBitmap(m_originalImage);

		//m_originalImage = image;
		//m_originalImageCopy = wxImage{ m_originalImage };
		//m_imageThumge{ m_originalImage };
		//AdjustImageThumbnailbnail = wxIma();
		//m_imageThumbnailCopy = wxImage{ m_imageThumbnail };
	}

	void Model::LoadConfigFromFile(const wxString& filePath)
	{
		
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

		//if (!m_originalImageCopy->SaveFile(filename))
		//{
			/* rzucenie jakiegos wyjatku */
		//};
	}

	void Model::SaveConfigToFile(const wxString& filePath) const
	{
		
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

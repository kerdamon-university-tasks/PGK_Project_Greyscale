#include <wx/log.h>
#include <fstream>
#include <wx/translation.h>
#include <wx/wfstream.h>

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
			
			m_imageThumbnail.Rescale(width, height, wxIMAGE_QUALITY_HIGH);
		}
	}

	void Model::LoadImageFromFile(const wxString& filePath)
	{
		if (!m_originalImage.LoadFile(filePath))
			wxLogError(_("Couldn't load file!"));

		m_originalImageCopy = m_originalImage.Copy();
		m_imageThumbnail = m_originalImage.Copy();
		AdjustImageThumbnail();
		m_imageThumbnailCopy = m_imageThumbnail.Copy();
		m_imageThumbnailMixed = m_imageThumbnail.Copy();
	}

	std::istream& rd2EOL(std::istream& str)
	{
		int ch;

		while ((ch = str.get()) != EOF && ch != '\n');
		return str;
	}
	
	void Model::LoadConfigFromFile(const wxString& filePath)
	{
		std::fstream f;

		int tempMode;
		unsigned char bichromeRed;
		unsigned char bichromeGreen;
		unsigned char bichromeBlue;
		
		f.open(filePath.ToStdString(), std::ios::in);
		f >> tempMode >> rd2EOL;
		f >> bichromeRed >> bichromeGreen >> bichromeBlue >> rd2EOL;
		f >> m_isHueKept >> m_keptHue >> m_keptHueTolerance >> rd2EOL;
		f >> m_redChannel >> m_greenChannel >> m_blueChannel >> rd2EOL;
		f >> m_mixingFactor >> rd2EOL;
		f.close();

		m_mode = static_cast<WorkMode>(tempMode);
		m_bichromeColour = wxColour{ bichromeRed, bichromeGreen, bichromeBlue };
	}

	void Model::SaveImageToFile(const wxString& filename)
	{
		switch (m_mode)
		{
			case WorkMode::BICHROME:
				m_originalImageCopy = m_originalImage.Copy();
				ImageConversion::ConvertToBichrome(m_originalImageCopy,m_bichromeColour, m_isHueKept, m_keptHue, m_keptHueTolerance);
				break;
			case WorkMode::GREYSCALE:
				m_originalImageCopy = m_originalImage.Copy();
				ImageConversion::ConvertToGreyScale(m_originalImageCopy, m_redChannel, m_greenChannel, m_blueChannel, m_isHueKept, m_keptHue, m_keptHueTolerance);
				break;
			case WorkMode::ORIGINAL:
			case WorkMode::NOT_LOADED:
			default:
				break;			
		}

		if (!m_originalImageCopy.SaveFile(filename))
			wxLogError(_("Couldn't save file!"));
	}

	void Model::SaveConfigToFile(const wxString& filePath) const
	{
		std::fstream f;

		f.open(filePath.ToStdString(), std::ios::out);
		f << static_cast<int>(m_mode) << std::endl;
		f << m_bichromeColour.Red() << " " << m_bichromeColour.Green() << " " << m_bichromeColour.Blue() << " " << std::endl;
		f << m_isHueKept << " " << m_keptHue << " " << m_keptHueTolerance << " " << std::endl;
		f << m_redChannel << " " << m_greenChannel << " " << m_blueChannel << " " << std::endl;
		f << m_mixingFactor << std::endl;
		f.close();
	}

	void Model::ApplyParametersToThumbnail()
	{
		m_isResultSaved = false;
		
		switch (m_mode)
		{
		case WorkMode::BICHROME:
			m_imageThumbnailCopy = m_imageThumbnail.Copy();
			ImageConversion::ConvertToBichrome(m_imageThumbnailCopy, m_bichromeColour, m_isHueKept, m_keptHue, m_keptHueTolerance);
			MixConvertedWithOriginal();
			break;
		case WorkMode::GREYSCALE:
			m_imageThumbnailCopy = m_imageThumbnail.Copy();
			ImageConversion::ConvertToGreyScale(m_imageThumbnailCopy, m_redChannel, m_greenChannel, m_blueChannel, m_isHueKept, m_keptHue, m_keptHueTolerance);
			MixConvertedWithOriginal();
			break;
		case WorkMode::ORIGINAL:
			m_imageThumbnailCopy = m_imageThumbnail.Copy();
			MixConvertedWithOriginal();
			break;
		case WorkMode::NOT_LOADED:
			m_isResultSaved = true;
		default:
			break;
		}
	}

	void Model::EasterEgg()
	{
	}

	void Model::MixConvertedWithOriginal()
	{
		if (m_mode == WorkMode::NOT_LOADED)
			return;
		
		auto* const originalData{ m_imageThumbnail.GetData() };
		auto* const convertedData{ m_imageThumbnailCopy.GetData() };
		auto* const mixedData{ m_imageThumbnailMixed.GetData() };

		const int dataSize{ m_imageThumbnail.GetWidth() * m_imageThumbnail.GetHeight() * 3 };

		const double factor = m_mixingFactor / 100.0;
		
		for(int i = 0; i < dataSize; i += 3)
		{
			mixedData[i] = (1.0 - factor) * convertedData[i] + factor * originalData[i];
			mixedData[i + 1] = (1.0 - factor) * convertedData[i + 1] + factor * originalData[i + 1];
			mixedData[i + 2] = (1.0 - factor) * convertedData[i + 2] + factor * originalData[i + 2];
		}
	}
}

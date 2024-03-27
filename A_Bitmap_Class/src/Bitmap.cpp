
#include "Bitmap.h"
#include "BitmapFileHeader.h"
#include "BitmapInfoHeader.h"
namespace caveofprogramming {

Bitmap::Bitmap(int width, int height): m_width(width), m_height(height), m_pPixels{new uint8_t[width*height*3]{}}  {
	// TODO Auto-generated constructor stub

}

bool Bitmap::write(string filename) {

    BitmapInfoHeader infoHeader;
    BitmapFileHeader fileHeader;

    fileHeader.fileSize= sizeof(BitmapInfoHeader) + sizeof(fileHeader) + m_width*m_height*3;
    fileHeader.dataOffset=sizeof(BitmapInfoHeader) + sizeof(fileHeader);

    infoHeader.width = m_width;
    infoHeader.height= m_height;

    ofstream file;
    file.open(filename.c_str(),ios::out|ios::binary);
    if(!file)
    {
        return false;
    }

    file.write((char *)&fileHeader, sizeof(fileHeader));
    file.write((char *)&infoHeader, sizeof(infoHeader));
    file.write((char *)m_pPixels.get(), m_width*m_height*3);

    file.close();
    if(!file)
    {
        return false;
    }

	return true;
}

void Bitmap::setPixel(int x, int y, uint8_t red, uint8_t green, uint8_t blue) {

}

Bitmap::~Bitmap() {
	// TODO Auto-generated destructor stub
}

} /* namespace caveofprogramming */

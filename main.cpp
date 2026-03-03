//----------------------------------------------------------
// CS161 Assignment Starter Code
// Copyright Andrew Scholer (ascholer@chemeketa.edu)
// Neither this code, nor any works derived from it
//    may be republished without approval.
//----------------------------------------------------------

#include <iostream>
#include <string>

using namespace std;

// Paste your function implementations here

string getImageSource(string tag)
{
  size_t start = tag.find("source=\"");
  start += 8;

  size_t end = tag.find("\"", start);
  return tag.substr(start, end - start);
}

string underscoresToSpaces(string str)
{
  for (int i = 0; i < str.length(); i++) {
    if (str[i] == '_') {
      str[i] = ' ';
    }
  }
  return str;
}

int getImageWidth(string tag)
{
  size_t start = tag.find("width=\"");
  start += 7;

  size_t end = tag.find("px", start);
  string num = tag.substr(start, end - start);
  return stoi(num);
}

int getImageHeight(string tag)
{
  size_t start = tag.find("height=\"");
  start += 8;

  size_t end = tag.find("px", start);
  string num = tag.substr(start, end - start);
  return stoi(num);
}

int getVerticalPadding(string tag)
{
  size_t start = tag.find("padding=\"");
  if (start == string::npos) {
    return 0;
  }
  start += 9;

  size_t end = tag.find("\"", start);
  string padding = tag.substr(start, end - start);

  size_t spacePos = padding.find(" ");
  if (spacePos == string::npos) {
    size_t pxPos = padding.find("px");
    return stoi(padding.substr(0, pxPos));
  } else {
    size_t pxPos = padding.find("px");
    return stoi(padding.substr(0, pxPos));
  }
}

int getHorizontalPadding(string tag)
{
  size_t start = tag.find("padding=\"");
  if (start == string::npos) {
    return 0;
  }
  start += 9;

  size_t end = tag.find("\"", start);
  string padding = tag.substr(start, end - start);

  size_t spacePos = padding.find(" ");
  if (spacePos == string::npos) {
    size_t pxPos = padding.find("px");
    return stoi(padding.substr(0, pxPos));
  } else {
    size_t pxPos = padding.find("px", spacePos);
    return stoi(padding.substr(spacePos + 1, pxPos - (spacePos + 1)));
  }
}

int main()
{
  cout << "Enter a tag: ";
  string tag;
  getline(cin, tag); // read a full line of input including spaces

  // Some sample inputs you can copy-paste to test your main
  // <image source="puppy.jpg" width="100px" height="200px">
  // <image source="cat_pounce.gif" height="400px" width="300px" padding="10px">
  // <image width="400px" height="250px" padding="10px 5px"
  // source="little_red_snake.mpeg">

  cout << "Tag:" << tag << endl;
  // Add your code here to print out information about the tag
  string filename = getImageSource(tag);
  string readable = underscoresToSpaces(filename);
  int width = getImageWidth(tag);
  int height = getImageHeight(tag);
  int vPad = getVerticalPadding(tag);
  int hPad = getHorizontalPadding(tag);

  int finalWidth = width + 2 * hPad;
  int finalHeight = height + 2 * vPad;

  cout << "\nFilename: " << filename << " (" << readable << ")" << endl;
  cout << "Width: " << width << endl;
  cout << "Height: " << height << endl;
  cout << "Vertical padding: " << vPad << endl;
  cout << "Horizontal padding: " << hPad << endl;
  cout << "Final dimensions: " << finalWidth << "x" << finalHeight << endl;
}

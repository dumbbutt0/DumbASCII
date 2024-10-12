#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <opencv2/opencv.hpp>   //image/video processing library

using namespace std;

const string simple ="░▒▓█@#S%?*+;:,. ", Complex="█▓▒░$@B%8&WM#*abcdejfQGUYlmno0pqrstuvwxyz/|()1{}[]?-_+~<>i!lI;:,\"^`'. ";

//Image to ascii conversion
//Mat is the primary data structure for images.
vector<string> image2ascii(const cv::Mat& image, int width, int height, const string& asciiChars)
{
    cv::Mat resized;
     //resize image
    cv::resize(image, resized, cv::Size(width,height));

    vector<string> asciiArt;
    //loop through pixels
    for (int i=0; i < resized.rows; i++){
        string line;
        for (int j =0; j < resized.cols; j++){
            uchar pixel = resized.at<uchar>(i,j);
            //Map pixel to ascii char
            int index = pixel* asciiChars.length() / 256;
            if (index >= asciiChars.length()) index = asciiChars.length() -1;
            line += asciiChars[index];
        }
        asciiArt.push_back(line);
    }
    return asciiArt;
}

/* 'argc' is the number of command-line arguments (including the program name)
   'argv' is an array of C-strings containing the arguments  */
int conversion(int argc, char** argv)
{
    //check for required arguments
    if (argc < 2){
        cerr << "Usage: ./DumbASCII <image_path> [width] [height] [shade] [outfile]" << endl;
        cerr << "Shade should be either 'simple' or 'complex.\n";
        return 1;
    }
    //Handling CLI arguments
    string imagepath = argv[1]; //the first argv is the image path
    //default run settings
    int outwidth = 100;
    int outheight = 0;  //setting height to 0 forces auto-calculations later
    string asciiChars =simple;  // set default ascii chars to the simple var defined up top
    bool savefile =false;
    string outfile;

    //optional argument parsing
    if (argc >= 3) outwidth = stoi(argv[2]);// The second argument sets the output width
    if (argc >= 4) outheight = std::stoi(argv[3]); // The third argument sets the output height

    if (argc >=5){
        string shade = argv[4];// The fourth argument is either "simple" (default) or "Complex"
        if (shade == "complex") asciiChars = Complex;
    }
    if (argc >= 6){
        savefile  = true;
        outfile = argv[5];
    }

    //Loading our image
    // Use OpenCV's imread function to load the image in grayscale mode
    cv::Mat image = cv::imread(imagepath, cv::IMREAD_GRAYSCALE);
    if(image.empty()){
        cerr << "Error loading your image at "<< imagepath << endl;
        return 1;
    }

    if(outheight == 0){
        // Calculate the aspect ratio of the image (height / width)
        float ratio = static_cast<float>(image.rows)/image.cols;
         // The out height is calculated based on the aspect ratio, scaled by 0.55 to account for the typical aspect ratio of ASCII characters in a monospaced font
         outheight = static_cast<int>(ratio * outwidth * 0.55);
    }

    //Image2ASCII
    //returns a vector of strings where each string represents one row of the ASCII art
    vector<string> ASCII =  image2ascii(image, outwidth, outheight, asciiChars);

    //output ASCII
    if(savefile){
        ofstream outFile(outfile);
        if(!outFile){
            cerr << "There was an error writing to " << outfile << endl;
            return 1;
        }// wrote each line of ASCII to a file
        for (const auto& line : ASCII) outFile << line <<"\n";
        outFile.close();
    }else{
        for (const auto& line : ASCII) cout <<line <<"\n";
    }
    return 0;
}

int main(int argc, char** argv)
{
    return conversion(argc, argv);
}

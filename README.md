# DumbASCII

### **Features**
- Convert any image into ASCII art.
- Two shading levels: `simple` and `complex` ASCII character sets.
- Adjustable output dimensions (width/height) and automatic aspect ratio adjustment.
- Supports grayscale images with detailed pixel mapping to ASCII characters.

### **Preview**

![Sonic ASCII](preview/sonic-ascii.png)  
*(Example of Sonic image converted into ASCII art)*

---

## **Installation**

1. **Clone the repository**
   ```bash
   git clone https://github.com/yourusername/DumbASCIIArt.git
   cd DumbASCIIArt
   ```

2. **Install Dependencies**
   Make sure you have [OpenCV](https://opencv.org/) installed on your system. On Linux, you can install it using the following command:
   ```bash
   sudo apt-get install libopencv-dev
   ```

3. **Build the Program**
   Compile the program using `g++`. Ensure OpenCV is properly linked:
   ```bash
   g++ DumbASCII.cpp -o ascii_art `pkg-config --cflags --libs opencv4`
   ```

---

## **Usage**

Run the program with the following syntax:
```bash
./ascii_art <image_path> [width] [height] [shade] [outfile]
```

- **image_path**: Path to the image file (supports `.jpg`, `.png`, etc.).
- **width** (optional): Desired width of the ASCII output. Default is 100.
- **height** (optional): Desired height. If set to `0`, the height is auto-calculated to maintain aspect ratio.
- **shade** (optional): Choose between `simple` (default) and `complex` ASCII character sets.
- **outfile** (optional): Specify the output file to save the ASCII art. If not provided, output is printed to the console.

### **Example**

Convert an image (`sonic.jpg`) to ASCII art with complex shading and a width of 50 characters:
```bash
./ascii_art sonic.jpg 50 0 complex output.txt
```

---

## **ASCII Shading Levels**

- **Simple ASCII Character Set**:
  ```plaintext
  ░▒▓█@#S%?*+;:,. 
  ```
- **Complex ASCII Character Set**:
  ```plaintext
  .:-=+*#%@$@B%8&WM#*abcdejfQGUYlmno0pqrstuvwxyz▓▒░█▓█
  ```

---

## **Contributing**

Contributions are welcome! Please follow these steps:

1. **Fork the repository**.
2. **Create a new branch** for your feature (`git checkout -b feature-branch`).
3. **Commit your changes** (`git commit -m "Add new feature"`).
4. **Push to the branch** (`git push origin feature-branch`).
5. **Open a Pull Request**.

---

## **License**

This project is licensed under the MIT License. See the `LICENSE` file for details.

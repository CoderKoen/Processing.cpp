#include <string>
#include <iostream>
#include <fstream>

typedef std::ofstream PrintWriter;

// Output

// Prints with newline
void println(std::string text)
{
    std::cout << text << std::endl;
}

// Prints with no newline
void print(std::string text)
{
    std::cout << text;
}

// T is type and N is the array size
template <typename T, std::size_t N>
void printArray(const T (&array)[N])
{
    for (std::size_t i = 0; i < N; i++)
    {
        print("[" + std::to_string(i) + "] " + std::to_string(array[i]) + " ");
        println("");
    }
}

//
void createOutput(const std::string &filename)
{
    PrintWriter outputFile(filename);

    if (!outputFile.is_open())
    {
        std::cerr << "Error creating file: " << filename << std::endl;
        return;
    }

    outputFile.close();
}

// Makes a file that you can write to
PrintWriter createWriter(const std::string &filename)
{
    PrintWriter writer(filename);
    if (!writer.is_open())
    {
        std::cerr << "Error creating file: " << filename << std::endl;
    }
    return writer;
}

// Input
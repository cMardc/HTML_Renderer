#include "HTMLRenderer.h"
#include <iostream>

int main(int argc, char** argv) {
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <path_to_html_file>" << std::endl;
        return 1;
    }

    HTMLRenderer render_object;
    std::string path = argv[1]; // Use the second argument as the path to the HTML file

    std::cout << render_object.renderFile(path);
    return 0;
}

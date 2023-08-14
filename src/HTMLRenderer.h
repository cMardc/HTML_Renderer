
#pragma once

#include <string>
#include <vector>
#include <fstream>
#include <stack>
#include <string_view>
#include <iostream>
#include <sstream>
#include "../lib/CustomizableConsole.h"



//*====================================================================================================================================================


// * CLASS FOR HEADER FILE


/*
* @class HTMLRenderer
* @brief HTMLRenderer class to render file or content using functions and configurations.
*
* This is class to call rendering functions for this library.
* Anyone using this library, can easily render any HTML using this class in their code
* Also, you can compile this and turn it into a simple command line tool to view HTML from terminal
* There are developers that use terminal more than GUI (Mostly Linux users), so with this tool they can easily view HTML, and not Plain-HTML.
* 
*/
class HTMLRenderer {

public:

    /* 
    * @brief Default constructor for HTMLRenderer
    */
    HTMLRenderer();                       

    /*
    * @brief Default destructor for HTMLRenderer.
    */            
    ~HTMLRenderer();                                                
    
    /*
    * @brief Renders given HTML content.
    * @param content - Is HTML content that will be rendered
    * @return - This function returns rendered version of given content
    */
    std::string renderHTML(const std::string content);      

    /* 
    * @brief Render contents of a HTML file from a given path.
    * @param filePath - path of HTML file that will be rendered (const std::string) 
    * @return - This function returns a string that is rendered version of HTML file
    */
    std::string renderFile(const std::string filePath);     

};

//*=====================================================================================================================================================

// * FUNCTIONS FOR CLASS



HTMLRenderer::HTMLRenderer() {
    
}

HTMLRenderer::~HTMLRenderer() {

}



std::string HTMLRenderer::renderHTML(const std::string content) {
    std::string output;
    const size_t size_of_content = content.size();

    bool inside_tag = false;
    bool inside_value = false;
    std::string current_value = "";
    std::string current_tag = "";

    for (size_t i = 0; i < size_of_content; i++) {
        const char current_char = content[i];

        if (current_char == '<') {
            inside_tag = true;
            inside_value = false;
            if (!current_value.empty()) {
                if (current_tag == "h1") {
                    current_value = "~" + current_value + "~";
                } 
                else if (current_tag == "h2") {
                    current_value = "-" + current_value + "-";
                }
                else if (current_tag == "h3") {
                    current_value = "_" + current_value + "_";
                }
                else if(current_tag == "h4") {
                    current_value = "=" + current_value + "=";
                }
                else if(current_tag == "h5") {
                    current_value = "#" + current_value + "#";
                }
                else if(current_tag == "p") {
                    current_value = "@" + current_value + "@";
                }
                else if(current_tag == "div") {
                    current_value = "=========================================";
                }
                else if(current_tag == "/div") {
                    current_value = "-=======================================-";
                }
                else if(current_tag == "small") {
                    current_value = "&" + current_value + "&";
                }
                else if(current_tag == "button") {
                    current_value = "{" + current_value + "}";
                }
                else if(current_tag == "a") {
                    current_value = "^" + current_value + "^";
                }
                else if(current_tag == "img") {
                    current_value = ";" + current_value + ";";
                }
                else if(current_tag == "title") {
                    c_draw_text_box(5, '+', '|', '-', current_value.c_str());
                }
                else if(current_tag == "br") {
                    current_value = "\n";
                }
                else if(current_tag == "hr") {
                    current_value = "----------------------------------";
                }
                else if(current_tag == "i") {
                    current_value = "%" + current_value + "%";
                }
                else if(current_tag == "video") {
                    current_value = ":" + current_value + ":";
                }
                output += current_value + " \n";
                current_value = "";
            }
            current_tag = "";
        } else if (current_char == '>') {
            inside_tag = false;
            inside_value = false;
        } else if (inside_tag) {
            current_tag += current_char;
        } else if (!inside_tag && current_char != '\n' && current_char != '\r' && current_char != '\t') {
            inside_value = true;
            current_value += current_char;
        }
    }

    return output;
}





std::string HTMLRenderer::renderFile(const std::string filePath) {
    std::ifstream inputFile(filePath);

    if (!inputFile.is_open()) {
            std::cerr << "Failed to open file: " << filePath << std::endl;
            return ""; // Return empty string indicating failure
        }

    std::string arg;

    std::string line;

    while(getline(inputFile, line)) {
        arg += line;
        arg += "\n";
    }

    return this->renderHTML(arg);
}

//*====================================================================================================================================================





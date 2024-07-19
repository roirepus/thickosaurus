**Overview**

Welcome to the Intelligent PDF Reader project! This innovative application enhances the reading experience by providing real-time word definitions through two powerful API integrations. With this tool, users can select a word within a PDF and choose between fetching its definition from the Merriam-Webster Dictionary API or obtaining a contextual explanation from the ChatGPT API. The definitions are displayed in a user-friendly floating window, streamlining the reading process.

**Features**

Seamless Integration: Easily select and define words without leaving the PDF reader.
Dual Definition Sources: Option to fetch definitions from Merriam-Webster or context-based explanations from ChatGPT.
Efficient API Handling: Utilizes libcurl for making robust HTTP requests and nlohmann/json for parsing JSON responses.
User-Friendly Interface: Displays definitions in an unobtrusive floating window for an uninterrupted reading experience.

**Technologies Used**

Programming Languages: C++, Python
APIs: Merriam-Webster Dictionary API, OpenAI ChatGPT API
Libraries and Frameworks:
libcurl for HTTP requests
nlohmann/json for JSON parsing
Poppler for PDF processing
Development Tools: Neovim, GCC, GDB
Operating System: Linux (Arch Linux)

**Installation**

**Prerequisites**
Arch Linux or another compatible Linux distribution
libcurl: Install using sudo pacman -S curl
nlohmann/json: Download from the GitHub repository or install via your package manager
Poppler: Install using sudo pacman -S poppler
API Keys: Obtain API keys from Merriam-Webster and OpenAI

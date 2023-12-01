#ifndef components
#define components

#include "ftxui/component/component.hpp"

namespace InputComponent {
ftxui::Component main(ftxui::StringRef content,
                      std::string placeholder,
                      ftxui::InputOption option);
}

namespace ModalComponent {
ftxui::Component main(std::string title,
                      ftxui::Component body,
                      ftxui::Component footer);
}

namespace TableComponent {
ftxui::Element main(std::vector<std::vector<std::string>> data,
                    std::vector<std::string> header);
}

#endif
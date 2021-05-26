#pragma once
#include <unordered_map>
#include <string>
#include <vector>

class menu {
    
    std::unordered_map <std::string, size_t> m_indexes;
    std::vector<menu> m_options;
    std::string m_name;
    bool m_disabled;
    bool m_selected;
    int m_id;

    static int ID;
    
public:
    menu(int id = 0, std::string name = "root");
    menu(menu&&) noexcept = default;
    menu(const menu&) = default;
    menu& operator=(menu && ) = default;
    menu& operator=(const menu & ) = default;
    menu& operator[](const std::string& name);
    menu& option(const int index);
    menu& setDissabled(bool dissabled);
    std::string getName() const;
    std::vector<menu>::iterator begin();
    std::vector<menu>::iterator end();
    long getNameLength() const;
    int getItemsCount() const;
    int getSelected() const;
    int signal() const;
    void setSelected(const bool value);
    bool isDisabled() const;
    bool isSelected() const;
};
